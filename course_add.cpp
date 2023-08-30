#include<stdio.h>
#include<string.h>
void inject()
{
    FILE *fy = fopen("fy.txt","w");
    FILE *sy = fopen("sy.txt","w");
    FILE *ty = fopen("ty.txt","w");
    FILE *ly = fopen("ly.txt","w");
    printf("\n Expecting to Enter the Courses of First Year");
    printf("\n Note: If slot empty, input 'NULL'");
    int i;
    for(i=0;i<8;i++)
    {
        printf("\n Enter the subject for Slot %c\n",'A'+i);
        char sub[7];
        scanf("%s",&sub);
        fprintf(fy,"%c %s \n",'A'+i,sub);
    }
    printf("\n\n\n Expecting to Enter the Courses of Second Year");
    printf("\n Note: If slot empty, input 'NULL'");
    for(i=0;i<8;i++)
    {
        printf("\n Enter the subject for Slot %c\n",'A'+i);
        char sub[7];
        scanf("%s",&sub);
        fprintf(sy,"%c %s \n",'A'+i,sub);
    }
    printf("\n\n\n Expecting to Enter the Courses of Third Year");
    printf("\n Note: If slot empty, input 'NULL'");
    for(i=0;i<8;i++)
    {
        printf("\n Enter the subject for Slot %c\n",'A'+i);
        char sub[7];
        scanf("%s",&sub);
        fprintf(ty,"%c %s \n",'A'+i,sub);
    }
	printf("\n\n\n Expecting to Enter the Courses of Fourth Year");
    printf("\n Note: If slot empty, input 'NULL'");
    for(i=0;i<8;i++)
    {
        printf("\n Enter the subject for Slot %c\n",'A'+i);
        char sub[7];
        scanf("%s",&sub);
        fprintf(ly,"%c %s \n",'A'+i,sub);
    }
    fclose(fy);
    fclose(sy);
    fclose(ty);
    fclose(ly);
}
int main()
{
    inject();
}