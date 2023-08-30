#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "course_include.cpp"
#define MAX 3
#define MIN 2
void tree_maker();
void add()
{
	FILE *stud = fopen("student_list.txt","a");
	printf("\n Expected to enter Student's registration information");
	printf("\n\n Enter Enrollment no: ");
	char enno[11];
	scanf("%s",&enno);
	printf("\n Enter name:");
	char name[100];
	fflush(stdin);
	scanf("%[^\n]%*c", name);
	int j=0;
	while(name[j]!='\0')
	{
		if(name[j]==' ')
		{
			name[j] = ',';
		}
		j++;
	}
	fprintf(stud,"%s %s",enno,name);
	char tempyear[3];
	tempyear[0] = enno[2];
	tempyear[1] = enno[3];
	tempyear[2] = '\0';
	int year = atoi(tempyear);
	FILE *fy = fopen("fy.txt","r");
    FILE *sy = fopen("sy.txt","r");
    FILE *ty = fopen("ty.txt","r");
    FILE *ly = fopen("ly.txt","r");
    printf("\n\n Following are the courses available from different years for your batch, please select atmost 5 courses");
	if(year<=19)
    {
    	printf("\n\n\nCourses that can be opted from fy: \n");
    	char slot[2];
    	char course[100];
    	while(fgets(course,100,fy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from sy:\n");
    	while(fgets(course,100,sy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from ty:\n");
    	while(fgets(course,100,ty)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from ly:\n");
    	while(fgets(course,100,ly)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    }
    else if(year==20)
    {
    	printf("\n\n\nCourses that can be opted from fy: \n");
    	char slot[2];
    	char course[100];
    	while(fgets(course,100,fy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from sy:\n");
    	while(fgets(course,100,sy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from ty:\n");
    	while(fgets(course,100,ty)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	
    }
    else if(year==21)
    {
    	printf("\n\n\nCourses that can be opted from fy: \n");
    	char slot[2];
    	char course[100];
    	while(fgets(course,100,fy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	printf("\n\n\nCourses that can be opted from sy:\n");
    	while(fgets(course,100,sy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	
    }
    else if(year==22)
    {
    	printf("\n\n\nCourses that can be opted from fy: \n");
    	char slot[2];
    	char course[100];
    	while(fgets(course,100,fy)!=NULL)
    	{
    		printf("%s\n",course);
    	}
    	
    }
    printf("\n Slotwise enter the courses you want to opt. Enter one course for each slot. If none, type NULL\n");
    j=0;
    int i=0;
	for(i=0;i<8&&j<5;i++)
    {
    	char temp[100];
    	printf("\n Slot %c:  ",'A'+i);
    	scanf("%s",temp);
    	if(strlen(temp)==6)
    	{
    		j++;
    		fprintf(stud," %c %s",'A'+i,temp);
    	}
    	else if(strcmp(temp,"NULL")!=0)
    	{
    		printf("\nInvalid, Enter again\n");
    		i--;
    	}
		else
		{
			fprintf(stud," %c %s",'A'+i,temp);
		}
			
    }
    while(i<8)
    {
    	fprintf(stud," %c %s",'A'+i,"NULL");
		i++;
	}
    printf("\n\n Successfuly opted for <=5 courses");
    fprintf(stud,"\n");
    fclose(fy);
    fclose(sy);
    fclose(ty);
    fclose(ly);
    fclose(stud);
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

void d_elete (int enno, struct BTreeNode *myNode) 
{
  struct BTreeNode *tmp;
  if (!delValFromNode(enno, myNode)) {
    printf("Not present\n");
    return;
  } else {
    if (myNode->count == 0) {
      tmp = myNode;
      myNode = myNode->linker[0];
      free(tmp);
    }
  }
  root = myNode;
  return;
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
int encode(char *s)
{
  char buff[7];
  char branch[4];
  buff[0] = s[2];
  buff[1] = s[3];
  buff[2] = s[7];
  buff[3] = s[8];
  buff[4] = s[9];
  buff[6] = '\0';
  branch[0] = s[4];
  branch[1] = s[5];
  branch[2] = s[6];
  branch[3] = '\0';
  if(strcmp(branch,"CSE")==0)
  {
    buff[5] = '1';
  }
  if(strcmp(branch,"ECE")==0)
  {
    buff[5] = '2';
  }
  if(strcmp(branch,"EEE")==0)
  {
    buff[5] = '3';
  }
  if(strcmp(branch,"CHE")==0)
  {
    buff[5] = '4';
  }
  if(strcmp(branch,"CIV")==0)
  {
    buff[5] = '5';
  }
  if(strcmp(branch,"MEC")==0)
  {
    buff[5] = '6';
  }
  if(strcmp(branch,"MIN")==0)
  {
    buff[5] = '7';
  }
  if(strcmp(branch,"MET")==0)
  {
    buff[5] = '8';
  }
  return atoi(buff);
}
void de_lete(char *s)
{
  int encoded_s;
  encoded_s = encode(s);
  int pos;
  int flag = search(encoded_s,&pos,root);
  if(flag)
  {
    FILE *dest = fopen("student_list.txt","r");
    FILE *temp = fopen("temp_list.txt","w");
    char c = fgetc(dest);
    while(c!=EOF)
    {
      fputc(c,temp);
      c = fgetc(dest);
    }
    fclose(temp);
    fclose(dest);
    dest = fopen("student_list.txt","w");
    temp = fopen("temp_list.txt","r");
    char buff[500];
    while(fgets(buff,500,temp))
    {
      char compare[11];
      strncpy(compare,buff,10);
      compare[10] = '\0';
      if(strcmp(compare,s)!=0)
      {
        fprintf(dest,buff);
      }
    }
    fclose(dest);
    fclose(temp);
    root = NULL;
    tree_maker();

  }
  else
  {
    printf("\n\nNot Present");
  }
  
}
void traversal(struct BTreeNode *myNode) 
{
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->linker[i]);
      char s[10];
      int buff; 
      buff = myNode->enno[i+1];
      for(int j=5;buff>0;j--)
      {
        s[j] = buff%10 + '0';
        buff = buff/10;
      }
      char branch[4];
      if(s[5]=='1')
      {
        strcpy(branch,"CSE");
      }
      if(s[5]=='2')
      {
        strcpy(branch,"ECE");
      }
      if(s[5]=='3')
      {
        strcpy(branch,"EEE");
      }
      if(s[5]=='4')
      {
        strcpy(branch,"CHE");
      }
      if(s[5]=='5')
      {
        strcpy(branch,"CIV");
      }
      if(s[5]=='6')
      {
        strcpy(branch,"MEC");
      }
      if(s[5]=='7')
      {
        strcpy(branch,"MIN");
      }
      if(s[5]=='8')
      {
        strcpy(branch,"MET");
      }

      printf("BT%c%c%s%c%c%c  ",s[0],s[1],branch,s[2],s[3],s[4]);
    }
    traversal(myNode->linker[i]);
  }
}
void write_in_student_list()
 {
  FILE *dest = fopen("student_list.txt","r");
  FILE *temp = fopen("temp_list.txt","w");
  char c = fgetc(dest);
  while(c!=EOF)
  {
    fputc(c,temp);
    c = fgetc(dest);
  }
  fclose(temp);
  fclose(dest);
  dest = fopen("student_list.txt","w");
  temp = fopen("temp_list.txt","r");
  char buff[500];
  while(fgets(buff,500,temp))
  {
    char compare[11];
    strncpy(compare,buff,10);
    compare[10] = '\0';
    int encoded_compare;
    if(compare[0]=='B') 
    encoded_compare = encode(compare);
    else
    encoded_compare = 0;
    int buff2;
    if(search(encoded_compare,&buff2,root))
    {
      fprintf(dest,buff);
    }
  }
  fclose(dest);
  fclose(temp);

}

void tree_maker()
{
  FILE *src = fopen("student_list.txt","r");
	char s[11];
	int k=0;
	while(fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s\n",s)==1)
	{
    char buff[7];
    char branch[4];
    buff[0] = s[2];
    buff[1] = s[3];
    buff[2] = s[7];
    buff[3] = s[8];
    buff[4] = s[9];
    buff[6] = '\0';
    branch[0] = s[4];
    branch[1] = s[5];
    branch[2] = s[6];
    branch[3] = '\0';
    if(strcmp(branch,"CSE")==0)
    {
      buff[5] = '1';
    }
    if(strcmp(branch,"ECE")==0)
    {
      buff[5] = '2';
    }
    if(strcmp(branch,"EEE")==0)
    {
      buff[5] = '3';
    }
    if(strcmp(branch,"CHE")==0)
    {
      buff[5] = '4';
    }
    if(strcmp(branch,"CIV")==0)
    {
      buff[5] = '5';
    }
    if(strcmp(branch,"MEC")==0)
    {
      buff[5] = '6';
    }
    if(strcmp(branch,"MIN")==0)
    {
      buff[5] = '7';
    }
    if(strcmp(branch,"MET")==0)
    {
      buff[5] = '8';
    }
    insertion(atoi(buff));
  }
}

void _delete(char* s)
{
  int encoded_s;
  encoded_s = encode(s);
  //d_elete(encoded_s,root);
  de_lete(s);
  //write_in_student_list();
  traversal(root);
  root = NULL;
  list();
}
main()
{
	while(1)
	{
		printf("\n\n1.Add\n2.Delete\n3.Exit\n");
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			add();
		}
		if(x==2)
		{
      tree_maker();
      traversal(root);
      printf("\n\nEnter the enrollment number to be deleted: \n");
      char s[11];
      scanf("%s",s);
      _delete(s);
		}
		if(x==3)
		{
			break;
		}
	}
}
