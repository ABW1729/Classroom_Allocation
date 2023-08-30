#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3
#define MIN 2
int encode(char *s,int no_of_stud)
{

  char buff[6];
  if(s[0]== 'N')
  {
	return 0;
  }
  char branch[4];
  buff[1] = s[3];
  buff[2] = s[4];
  buff[3] = s[5];
  if(no_of_stud>0)
  {
	buff[4] = '1';
  }
  else
  {
	buff[4] = '0';
  }
  buff[5] = '\0';
  branch[0] = s[0];
  branch[1] = s[1];
  branch[2] = s[2];
  branch[3] = '\0';
  if(strcmp(branch,"MAL")==0)
  {
    buff[0] = '1';
  }
  if(strcmp(branch,"HUL")==0)
  {
    buff[0] = '2';
  }
  if(strcmp(branch,"CSL")==0)
  {
    buff[0] = '3';
  }
  if(strcmp(branch,"MAT")==0)
  {
    buff[0] = '4';
  }
  if(strcmp(branch,"PHY")==0)
  {
    buff[0] = '5';
  }
  if(strcmp(branch,"CHE")==0)
  {
    buff[0] = '6';
  }
  if(strcmp(branch,"CSS")==0)
  {
    buff[0] = '7';
  }
  if(strcmp(branch,"MEC")==0)
  {
    buff[0] = '8';
  }
  return atoi(buff);
}
struct BTreeNode 
{
  int enno[MAX + 1], count;
  struct BTreeNode *linker[MAX + 1];
};

struct BTreeNode *root;

struct BTreeNode *createNode(int enno, struct BTreeNode *child) 
{
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->enno[1] = enno;
  newNode->count = 1;
  newNode->linker[0] = root;
  newNode->linker[1] = child;
  return newNode;
}

void addValToNode(int enno, int pos, struct BTreeNode *node,struct BTreeNode *child) 
{
  int j = node->count;
  while (j > pos) 
  {
    node->enno[j + 1] = node->enno[j];
    node->linker[j + 1] = node->linker[j];
    j--;
  }
  node->enno[j + 1] = enno;
  node->linker[j + 1] = child;
  node->count++;
}

void splitNode(int enno, int *pval, int pos, struct BTreeNode *node,struct BTreeNode *child, struct BTreeNode **newNode) 
{
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  while (j <= MAX) 
  {
    (*newNode)->enno[j - median] = node->enno[j];
    (*newNode)->linker[j - median] = node->linker[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) 
  {
    addValToNode(enno, pos, node, child);
  } else {
    addValToNode(enno, pos - median, *newNode, child);
  }
  *pval = node->enno[node->count];
  (*newNode)->linker[0] = node->linker[node->count];
  node->count--;
}

int setValueInNode(int enno, int *pval,struct BTreeNode *node, struct BTreeNode **child) 
{
  int pos;
  if (!node) 
  {
    *pval = enno;
    *child = NULL;
    return 1;
  }

  if (enno < node->enno[1]) 
  {
    pos = 0;
  } 
  else 
  {
    for (pos = node->count;(enno < node->enno[pos] && pos > 1); pos--);
    if (enno == node->enno[pos]) 
    {
      printf("Duplicates not allowed\n");
      return 0;
    }
  }
  if (setValueInNode(enno, pval, node->linker[pos], child)) 
  {
    if (node->count < MAX) 
    {
      addValToNode(*pval, pos, node, *child);
    } 
    else 
    {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}
void insertion(int enno) 
{
  int flag, i;
  struct BTreeNode *child;

  flag = setValueInNode(enno, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

void copySuccessor(struct BTreeNode *myNode, int pos) 
{
  struct BTreeNode *dummy;
  dummy = myNode->linker[pos];

  for (; dummy->linker[0] != NULL;)
    dummy = dummy->linker[0];
  myNode->enno[pos] = dummy->enno[1];
}

void removeVal(struct BTreeNode *myNode, int pos) 
{
  int i = pos + 1;
  while (i <= myNode->count) 
  {
    myNode->enno[i - 1] = myNode->enno[i];
    myNode->linker[i - 1] = myNode->linker[i];
    i++;
  }
  myNode->count--;
}

void rightShift(struct BTreeNode *myNode, int pos) 
{
  struct BTreeNode *x = myNode->linker[pos];
  int j = x->count;

  while (j > 0) 
  {
    x->enno[j + 1] = x->enno[j];
    x->linker[j + 1] = x->linker[j];
  }
  x->enno[1] = myNode->enno[pos];
  x->linker[1] = x->linker[0];
  x->count++;

  x = myNode->linker[pos - 1];
  myNode->enno[pos] = x->enno[x->count];
  myNode->linker[pos] = x->linker[x->count];
  x->count--;
  return;
}

void leftShift(struct BTreeNode *myNode, int pos) 
{
  int j = 1;
  struct BTreeNode *x = myNode->linker[pos - 1];

  x->count++;
  x->enno[x->count] = myNode->enno[pos];
  x->linker[x->count] = myNode->linker[pos]->linker[0];

  x = myNode->linker[pos];
  myNode->enno[pos] = x->enno[1];
  x->linker[0] = x->linker[1];
  x->count--;

  while (j <= x->count) {
    x->enno[j] = x->enno[j + 1];
    x->linker[j] = x->linker[j + 1];
    j++;
  }
  return;
}

void mergeNodes(struct BTreeNode *myNode, int pos) 
{
  int j = 1;
  struct BTreeNode *x1 = myNode->linker[pos], *x2 = myNode->linker[pos - 1];

  x2->count++;
  x2->enno[x2->count] = myNode->enno[pos];
  x2->linker[x2->count] = myNode->linker[0];

  while (j <= x1->count) 
  {
    x2->count++;
    x2->enno[x2->count] = x1->enno[j];
    x2->linker[x2->count] = x1->linker[j];
    j++;
  }

  j = pos;
  while (j < myNode->count) 
  {
    myNode->enno[j] = myNode->enno[j + 1];
    myNode->linker[j] = myNode->linker[j + 1];
    j++;
  }
  myNode->count--;
  free(x1);
}

void adjustNode(struct BTreeNode *myNode, int pos) 
{
  if (!pos) 
  {
    if (myNode->linker[1]->count > MIN) 
    {
      leftShift(myNode, 1);
    }
    else 
    {
      mergeNodes(myNode, 1);
    }
  } else {
    if (myNode->count != pos) {
      if (myNode->linker[pos - 1]->count > MIN) {
        rightShift(myNode, pos);
      } else {
        if (myNode->linker[pos + 1]->count > MIN) {
          leftShift(myNode, pos + 1);
        } else {
          mergeNodes(myNode, pos);
        }
      }
    } else {
      if (myNode->linker[pos - 1]->count > MIN)
        rightShift(myNode, pos);
      else
        mergeNodes(myNode, pos);
    }
  }
}

int delValFromNode(int enno, struct BTreeNode *myNode) 
{
  int pos, flag = 0;
  if (myNode) {
    if (enno < myNode->enno[1]) {
      pos = 0;
      flag = 0;
    } else {
      for (pos = myNode->count; (enno < myNode->enno[pos] && pos > 1); pos--)
        ;
      if (enno == myNode->enno[pos]) {
        flag = 1;
      } else {
        flag = 0;
      }
    }
    if (flag) {
      if (myNode->linker[pos - 1]) {
        copySuccessor(myNode, pos);
        flag = delValFromNode(myNode->enno[pos], myNode->linker[pos]);
        if (flag == 0) {
          printf("Given data is not present in B-Tree\n");
        }
      } else {
        removeVal(myNode, pos);
      }
    } else {
      flag = delValFromNode(enno, myNode->linker[pos]);
    }
    if (myNode->linker[pos]) {
      if (myNode->linker[pos]->count < MIN)
        adjustNode(myNode, pos);
    }
  }
  return flag;
}
void searching(int enno, int *pos, struct BTreeNode *myNode) 
{
  if (!myNode) {
    return;
  }

  if (enno < myNode->enno[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (enno < myNode->enno[*pos] && *pos > 1); (*pos)--)
      ;
    if (enno == myNode->enno[*pos]) {
      printf("%d present in B-tree", enno);
      return;
    }
  }
  searching(enno, pos, myNode->linker[*pos]);
  return;
}
void traversal(struct BTreeNode *myNode) 
{
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->linker[i]);
      char s[5];
	  s[4] = '\0';
      int buff; 
      buff = myNode->enno[i+1];
	  if(buff != 0)
	  {
		
	  buff = buff/10;
	  
      for(int j=3;buff>0;j--)
      {
        s[j] = buff%10 + '0';
        buff = buff/10;
      }
      char branch[4];
      if(s[0]=='1')
      {
        strcpy(branch,"MAL");
      }
      if(s[0]=='2')
      {
        strcpy(branch,"HUL");
      }
      if(s[0]=='3')
      {
        strcpy(branch,"CSL");
      }
      if(s[0]=='4')
      {
        strcpy(branch,"MAT");
      }
      if(s[0]=='5')
      {
        strcpy(branch,"PHY");
      }
      if(s[0]=='6')
      {
        strcpy(branch,"CHE");
      }
      if(s[0]=='7')
      {
        strcpy(branch,"CSS");
      }
      if(s[0]=='8')
      {
        strcpy(branch,"MEC");
      }

      printf("%s%c%c%c ",branch,s[1],s[2],s[3]);
    }
	}
    traversal(myNode->linker[i]);
  }
}
void tree_maker()
{
	FILE* ptr = fopen("course_list.txt","r");
	int i =0;
	char str[10000];
	while(fgets(str,10000,ptr)!=NULL)
	{
		char temp[8];
		strncpy(temp,str+2,6);
		temp[7] = '\0';
		i=0;
		int k = 9;
		while(str[k])
		{i++;k++;}
		
    	insertion(encode(temp,i));
  }
  fclose(ptr);
}
int search(int enno, int *pos, struct BTreeNode *myNode) 
{
  if (!myNode) {
    return 0;
  }

  if (enno < myNode->enno[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (enno < myNode->enno[*pos] && *pos > 1); (*pos)--);
    if (enno == myNode->enno[*pos]) {
      return 1;
    }
  }
  return search(enno, pos, myNode->linker[*pos]);
}
void de_lete(char *s)
{
  int encoded_s;
  encoded_s = encode(s,0);
  int pos;
  int flag = search(encoded_s,&pos,root);
  if(flag)
  {
    FILE *dest = fopen("course_list.txt","r");
    FILE *temp = fopen("temp_list.txt","w");
    char c = fgetc(dest);
    while(c!=EOF)
    {
      fputc(c,temp);
      c = fgetc(dest);
    }
    fclose(temp);
    fclose(dest);
    dest = fopen("course_list.txt","w");
    temp = fopen("temp_list.txt","r");
    char buff[500];
    while(fgets(buff,500,temp))
    {
      char compare[7];
      strncpy(compare,buff+2,6);
      compare[6] = '\0';
      if(strcmp(compare,s)!=0)
      {
        fprintf(dest,buff);
      }
	  else
	  {
		fprintf(dest,"%c NULL\n",buff[0]);
	  }
    }
    fclose(dest);
    fclose(temp);
    root = NULL;
    tree_maker();

  }
}
struct stud
{
	char enno[11];
	struct stud* nptr;
};
struct course
{
	char slot;
	char code[7];
	int num_stud;
	struct course* nptr;
	struct stud* sptr;
	char classroom[7];
};
struct course* create()
{
	FILE* ptr = fopen("course_list.txt","r");
	char buff[100];
	int i =0;
	struct course* head = NULL;
	struct course* corcurr = NULL;
	struct stud* stucurr = NULL;
	char str[10000];
	while(fgets(str,10000,ptr)!=NULL)
	{
		i=0;	
		struct course* temp = (struct course*)malloc(sizeof(struct course));
		if(head==NULL)
		{
			head = temp;
			corcurr = head;
		}
		else
		{
			corcurr->nptr = temp;
			corcurr = temp;
		}
		temp->num_stud=0;
		temp->nptr= NULL;
		strcpy(temp->classroom,"NOT");
		temp->sptr=NULL;
		temp->slot=str[0];
		strncpy(temp->code,str+2,6);
		corcurr->code[6] = '\0';
		int k=9;
		while(str[k])
		{
			struct stud* stemp = (struct stud*)malloc(sizeof(struct stud));
			stemp->nptr = NULL;
			if(i==0)
			{
				corcurr->sptr = stemp;
				stucurr = stemp;
				i++;
			}
			else
			{
				stucurr->nptr = stemp;
				stucurr = stemp;
			}
			strncpy(stemp->enno,str+k,10);
			stemp->enno[10] = '\0';
			corcurr->num_stud++;
			k=k+11;
		}
	}
				
				
			
	fclose(ptr);
	return head;
}
void print(struct course* head)
{
	while(head!=NULL)
	{
		struct stud* ptr = head->sptr;
		printf("\n%c %s %d",head->slot,head->code,head->num_stud);
		while(ptr!=NULL)
		{
			printf(" %s",ptr->enno);
			ptr = ptr->nptr;
		}
		head = head->nptr;
	}
}
struct course* del(struct course* head, char *c)
{
	printf("\n entered func");
	struct course* clptr = head;
	struct course* cdptr = head->nptr;
	if(strcmp(clptr->code,c)==0&&head->sptr==NULL)
	{
		printf("\n This");
		cdptr=head;
		head = head->nptr;
	}
	else
	{
		while(cdptr!=NULL && strcmp(cdptr->code,c)!=0)
		{
			printf("\n Entered while");
			clptr = cdptr;
			cdptr = cdptr->nptr;
			if(cdptr!=NULL)
			printf("\n %s",cdptr->code);
		}
	}
	if(cdptr!=NULL&&cdptr->num_stud ==0)
	{
		struct stud*dptr = cdptr->sptr;
		struct stud* lptr = NULL;
		if(cdptr!=head)
			clptr->nptr = cdptr->nptr;
		free(cdptr);
		if(dptr!=NULL)
		{
			lptr = dptr->nptr;
		}
		while(lptr!=NULL)
		{
			free(dptr);
			dptr = lptr;
			lptr=lptr->nptr;
		}
		free(dptr);
		dptr = NULL;
		printf("\n Deleted");
	}
	else if(cdptr == NULL)
	{
		printf("\n Course not present");
	}
	else
	{
		printf("\n Students have opted for the course, cannot be deleted");
	}
	return head;
}
struct classroom
{
	char name[100];
	int seats;
	struct classroom* next;
};
struct classroom* makell()
{
	
	FILE *src = fopen("classroom_info.txt","r");
	struct classroom* head = NULL;
	struct classroom* ptr = NULL;
	char seats[100];
	char name[100];
	while(fscanf(src,"%s %s",name,seats)==2)
	{
		
		if(head==NULL)
		{
			head = (struct classroom*)malloc(sizeof(struct classroom));
			strcpy(head->name,name);
			head->seats = atoi(seats);
			head->next = NULL;
			ptr = head;
		}
		else
		{
			struct classroom* temp = (struct classroom*)malloc(sizeof(struct classroom));
			strcpy(temp->name,name);
			temp->seats = atoi(seats);
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
		}
	}
	return head;
}
void printclass(struct classroom* head)
{
	while(head!=NULL)
	{
		printf("\n%s %d",head->name,head->seats);
		head = head->next;
	}
}
void allotment(struct course* head, struct classroom* nead)
{
	struct course* ptrhead = head;
	struct classroom* ptrnead = nead;
	while(head!=NULL)
	{
		struct course* ptr1 = head;
		struct course* ptr2 =head;
		struct classroom* ptr5 = nead;
		struct classroom* ptr6 = nead;

		for(int i=0;i<8;i++)
		{
			if((ptr1->num_stud>ptr2->num_stud&&ptr1->num_stud>0)||(strcmp(ptr2->classroom,"NOT")!=0 && strcmp(ptr1->classroom,"NOT")==0))
			{
				
				ptr2 = ptr1;
			}
			ptr1 = ptr1->nptr;
			
		}
		while(ptr6!=NULL)
		{
			if((ptr6->seats<ptr5->seats && ptr6->seats>=ptr2->num_stud)||(ptr5->seats<ptr2->num_stud&&ptr6->seats>ptr5->seats))
			{
				
				ptr5 = ptr6;
			}
			ptr6 = ptr6->next;
		}
		ptr1 = head;
		for(int i=0; i<8; i++)
		{
			if(ptr1->num_stud>0)
			{
				ptr1->num_stud = ptr1->num_stud - ptr5->seats;
				strcpy(ptr1->classroom,ptr5->name);
				//printf("\nClasses with leftover students: \n%s %s %d",ptr1->code,ptr1->classroom,ptr1->num_stud);
			}
			ptr1 = ptr1->nptr;
		} 
		ptr5->seats =0;
		for(int i=0;i<8;i++)
		{
			head = head->nptr;
		}
	}
	while(ptrhead!=NULL)
	{
		if(ptrhead->num_stud>0)
		{
			struct classroom* ptr1 = ptrnead;
			struct classroom* ptr2 = ptrnead;
			while(ptr2!=NULL)
			{
				if(ptr2->seats<ptr1->seats && ptr2->seats>=ptrhead->num_stud)
				{
					ptr1 = ptr2;
				}
				ptr2 = ptr2->next;
			}
			printf("\n%s %s",ptrhead->code,ptr1->name);
		}
		ptrhead = ptrhead->nptr;
		
	}
}
void printallotment(struct course* head)
{
	while(head!=NULL)
	{
		printf("\n%s %s",head->code,head->classroom);
		head = head->nptr;
	}
}
void write(struct course* head)
{
	FILE* src = fopen("course_list.txt","w");
	while(head!=NULL)
	{
		fprintf(src,"%c %s",head->slot,head->code);
		struct stud* ptr = head->sptr;
		while(ptr!=NULL)
		{
			fprintf(src," %s",ptr->enno);
			ptr = ptr->nptr;
		}
		fprintf(src,"\n");
		head = head->nptr;
	}
	fclose(src);
}		
void _delete(char* s)
{
  //d_elete(encoded_s,root);
  de_lete(s);
  //write_in_student_list();
  traversal(root);
  root = NULL;
}
void between(char *s1,char *s2,BTreeNode *myNode)
{
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      between(s1,s2,myNode->linker[i]);
      char s[5];
	  s[4] = '\0';
      int buff; 
      buff = myNode->enno[i+1];
	  
		
	  buff = buff/10;
    //printf("\n\n%d %d %d",buff,encode(s1,0)/10,encode(s2,0)/10);
    if(buff != 0 &&buff>(encode(s1,0)/10)&&buff<(encode(s2,0)/10))
	  {
	  
      for(int j=3;buff>0;j--)
      {
        s[j] = buff%10 + '0';
        buff = buff/10;
      }
      char branch[4];
      if(s[0]=='1')
      {
        strcpy(branch,"MAL");
      }
      if(s[0]=='2')
      {
        strcpy(branch,"HUL");
      }
      if(s[0]=='3')
      {
        strcpy(branch,"CSL");
      }
      if(s[0]=='4')
      {
        strcpy(branch,"MAT");
      }
      if(s[0]=='5')
      {
        strcpy(branch,"PHY");
      }
      if(s[0]=='6')
      {
        strcpy(branch,"CHE");
      }
      if(s[0]=='7')
      {
        strcpy(branch,"CSS");
      }
      if(s[0]=='8')
      {
        strcpy(branch,"MEC");
      }

      printf("%s%c%c%c ",branch,s[1],s[2],s[3]);
    }
	}
    between(s1,s2,myNode->linker[i]);
  }
}
int main()
{
  tree_maker();
	while(1)
	{
		printf("\n\n1.Delete\n2.Between id\n3.Exit\n");
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			printf("\n\nCourse list: \n\n");
			traversal(root);
			printf("\n\nEnter the Subject Code to be deleted: ");
			char s[7];
			scanf("%s",s);
			_delete(s);

		}
    else if(x==2)
    {
			traversal(root);
      printf("\n\nEnter the two course id's: ");
      char s1[7],s2[7];
      scanf("%s",s1);
      scanf("%s",s2);
      between(s1,s2,root);
    }
		else{
			break;
		}
	}
	
}
		
			
			
		