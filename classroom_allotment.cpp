#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
	
int main()
{
	struct course* head = create();
	// while(1)
	// {
	// 	printf("\nEnter choice\n1. Print\n2. Delete Course\n3. Exit\n");
	// 	int d;
	// 	scanf("%d",&d);
	// 	if(d==1)
	// 	{
	// 		print(head);
	// 	}
	// 	if(d==2)
	// 	{
	// 		printf("\n\n Enter the subject to be deleted: ");
	// 		char s[7];
	// 		scanf("%s",s);
	// 		head = del(head,s);
	// 	}
	// 	if(d==3)
	// 	{
	// 		break;
	// 	}
	// }
	struct classroom* hhead = makell();
	//printclass(hhead);
	
	allotment(head,hhead);
	printclass(hhead);
	printallotment(head);
}
		
			
			
		