#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud
{
    char enno[11];
    struct stud* next;
};
struct course
{
    char code[7];
    struct stud* sptr;
    int num_stud;
};
struct course* l1;
struct course* l2;
struct course*l3;
void create()
{
    FILE* ptr = fopen("exam_list.txt","r");
	int i =0;
	struct course* head = NULL;
	struct stud* stucurr = NULL;
	char str[10000];
	if(fgets(str,10000,ptr)!=NULL)
    {
        i=0;	
        struct course* temp = (struct course*)malloc(sizeof(struct course));
        if(head==NULL)
        {
            head = temp;
        }
        temp->num_stud=0;
        temp->sptr=NULL;
        strncpy(temp->code,str,6);
        head->code[6] = '\0';
        int k=7;
        while(str[k])
        {
            printf("\n entered");
            struct stud* stemp = (struct stud*)malloc(sizeof(struct stud));
            stemp->next = NULL;
            if(i==0)
            {
                head->sptr = stemp;
                stucurr = stemp;
                i++;
            }
            else
            {
                stucurr->next = stemp;
                stucurr = stemp;
            }
            strncpy(stemp->enno,str+k,10);
            stemp->enno[10] = '\0';
            head->num_stud++;
            k=k+11;
        }
        l1 = head;
    }
	i =0;
	head = NULL;
	stucurr = NULL;
	if(fgets(str,10000,ptr)!=NULL)
    {
        i=0;	
        struct course* temp = (struct course*)malloc(sizeof(struct course));
        if(head==NULL)
        {
            head = temp;
        }
        temp->num_stud=0;
        temp->sptr=NULL;
        strncpy(temp->code,str,6);
        head->code[6] = '\0';
        int k=7;
        while(str[k])
        {
            struct stud* stemp = (struct stud*)malloc(sizeof(struct stud));
            stemp->next = NULL;
            if(i==0)
            {
                head->sptr = stemp;
                stucurr = stemp;
                i++;
            }
            else
            {
                stucurr->next = stemp;
                stucurr = stemp;
            }
            strncpy(stemp->enno,str+k,10);
            stemp->enno[10] = '\0';
            head->num_stud++;
            k=k+11;
        }
        l2 = head;
    }
	i =0;
	head = NULL;
	stucurr = NULL;
    if(fgets(str,10000,ptr)!=NULL)
    {
        i=0;	
        struct course* temp = (struct course*)malloc(sizeof(struct course));
        if(head==NULL)
        {
            head = temp;
        }
        temp->num_stud=0;
        temp->sptr=NULL;
        strncpy(temp->code,str,6);
        head->code[6] = '\0';
        int k=7;
        while(str[k])
        {
            struct stud* stemp = (struct stud*)malloc(sizeof(struct stud));
            stemp->next = NULL;
            if(i==0)
            {
                head->sptr = stemp;
                stucurr = stemp;
                i++;
            }
            else
            {
                stucurr->next = stemp;
                stucurr = stemp;
            }
            strncpy(stemp->enno,str+k,10);
            stemp->enno[10] = '\0';
            head->num_stud++;
            k=k+11;
        }
        l3 = head;
    }			
				
			
	fclose(ptr);
}
void allot(int row,int column)
{
    int r = 1;
    int c = 1;
    struct stud* ptr = l1->sptr;
    while(ptr!=NULL && !(r >row))
    {
        printf("\nEnrollment no: %s Seat: R%d C%d A",ptr->enno,r,c);
        c++;
        ptr = ptr->next;
        if(c>column)
        {
            c=1;
            r++;
        }
    }
    r = 1;
    c = 1;
    ptr = l2->sptr;
    while(ptr!=NULL && !(r>row))
    {
        printf("\nEnrollment no: %s Seat: R%d C%d B",ptr->enno,r,c);
        c++;
        ptr = ptr->next;
        if(c>column)
        {
            c=1;
            r++;
        }
    }
    r = 1;
    c = 1;
    ptr = l3->sptr;
    while(ptr!=NULL && !(r>row))
    {
        printf("\nEnrollment no: %s Seat: R%d C%d C",ptr->enno,r,c);
        c++;
        ptr = ptr->next;
        if(c>column)
        {
            c=1;
            r++;
        }
    }
}
void print(struct course* head)
{
    struct stud* ptr = head->sptr;
    printf("\n%s",head->code);
    while(ptr!=NULL)
    {
        printf(" %s",ptr->enno);
        ptr = ptr->next;
    }
}
int main()
{
    printf("\n Exam Allotment: \nEnter the classroom and its info:");
    printf("\nName:  ");
    char name[10];
    scanf("%s",name);
    printf("\nRows:  ");
    int rows;
    scanf("%d",&rows);
    printf("\nColumns:  ");
    int columns;
    scanf("%d",&columns);
    create();
    print(l1);
    allot(rows,columns);
}