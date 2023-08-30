#include<stdio.h>
#include<string.h>
void list()
{
	FILE *dest = fopen("course_list.txt","w");
	FILE *src = fopen("student_list.txt","r");
	FILE *fy = fopen("fy.txt","r");
    FILE *sy = fopen("sy.txt","r");
    FILE *ty = fopen("ty.txt","r");
    FILE *ly = fopen("ly.txt","r");
    char course[7];
    char slot;
    char enno[11];
    char temp[7];
 	while (fscanf(fy, "%c %s\n",&slot,course) == 2)
	{
		printf("\n %c",slot);
		rewind(src);
		if(strcmp(course,"NULL")!=0)
		{
			fprintf(dest,"%c %s",slot,course);
			if(slot=='A')
			{
				int k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				while(k ==2)
				{
					printf("\n%d",k);	
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='B')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='C')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='D')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='E')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='F')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='G')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				}
			}
			else if(slot=='H')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				}
			}
			fprintf(dest,"\n");
		}
		else
		{
			fprintf(dest,"%c NULLLL",slot);
			fprintf(dest,"\n");
		}
	}
	while (fscanf(sy, "%c %s\n",&slot,course) == 2)
	{
		printf("\n %c",slot);
		rewind(src);
		if(strcmp(course,"NULL")!=0)
		{
			fprintf(dest,"%c %s",slot,course);
			if(slot=='A')
			{
				int k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				while(k ==2)
				{
					printf("\n%d",k);	
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='B')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='C')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='D')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='E')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='F')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='G')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				}
			}
			else if(slot=='H')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				}
			}
			fprintf(dest,"\n");
		}
		else
		{
			fprintf(dest,"%c NULLLL",slot);
			fprintf(dest,"\n");
		}
	}
	while (fscanf(ty, "%c %s\n",&slot,course) == 2)
	{
		printf("\n %c",slot);
		rewind(src);
		if(strcmp(course,"NULL")!=0)
		{
			fprintf(dest,"%c %s",slot,course);
			if(slot=='A')
			{
				int k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				while(k ==2)
				{
					printf("\n%d",k);	
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='B')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='C')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='D')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='E')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='F')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='G')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				}
			}
			else if(slot=='H')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				}
			}
			fprintf(dest,"\n");
		}
		else
		{
			fprintf(dest,"%c NULLLL",slot);
			fprintf(dest,"\n");
		}
	}
	while (fscanf(ly, "%c %s\n",&slot,course) == 2)
	{
		printf("\n %c",slot);
		rewind(src);
		if(strcmp(course,"NULL")!=0)
		{
			fprintf(dest,"%c %s",slot,course);
			if(slot=='A')
			{
				int k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				while(k ==2)
				{
					printf("\n%d",k);	
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='B')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='C')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='D')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='E')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='F')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s",enno,temp);
				}
			}
			else if(slot=='G')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s",enno,temp);
				}
			}
			else if(slot=='H')
			{
				int k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				printf("\n Value of k second time: %d",k);
				while(k ==2)
				{
					printf("\n%d",k);	
					printf("\n%c",slot);
					printf("\n%s %s",course,temp);
					if(strcmp(temp,course)==0)
					{
						fprintf(dest," %s",enno);
						printf("\n %s",enno);
					}
					k = fscanf(src,"%s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",enno,temp);
				}
			}
			fprintf(dest,"\n");
		}
		else
		{
			fprintf(dest,"%c NULLLL",slot);
			fprintf(dest,"\n");
		}
	}
	fclose(fy);
    fclose(sy);
    fclose(ty);
    fclose(ly);
    fclose(src);
    fclose(dest);
}
int main()
{
	list();
}