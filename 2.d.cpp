#include<stdio.h>
#include<string.h>
struct student
{
	char name[25];
	int rno;
	int marks;
}s[5],temp;
int main()
{
	int i, rno, choice, flag = 0;
	int j, small, pos;
	char name[25],r;
	printf("Enter details of each student one by one.");
	for (i = 0; i < 5; i++)
	{
		printf("\n\nFor student %d",i+1);
		printf("\nEnter Name: ");
		scanf("%s",s[i].name);
		printf("Enter Roll Number: ");
		scanf("%d",&s[i].rno);
		printf("Enter Marks : ");
		scanf("%d",&s[i].marks);
	}
	do{
	printf("\nWhich operation would you like to perform?");
	printf("\n\n\t1. Search student by name\n\t2. Search student with Roll No\n\t3. Sort Student Records by Marks\n");
	printf("\n\nEnter your choice (1/2/3) : ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the name of the student to be searched: ");
			scanf("%s", &name);
			for (i = 0; i < 5; i++)
			{
				if (strcmp(s[i].name,name) == 0)
				{
					printf("\nMatch found! Student Details are:");
					printf("\nName: %s\nRoll No: %d\nMarks: %d",s[i].name,s[i].rno,s[i].marks);
					flag = 1;
				}
			}
			if (flag == 0)
			printf("Match not found!");
			break;
		case 2:
			printf("\nEnter Roll No to be searched for: ");
			scanf("%d",&rno);
			for (i = 0; i < 5; i++)
			{
				if (rno == s[i].rno)
				{
					printf("\nMatch found! Student details are as follows:");
					printf("\nName: %s\nRoll No: %d\nMarks: %d",s[i].name,s[i].rno,s[i].marks);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				printf("\nMatch not found!");
			}
			break;
		case 3:
			for (i = 0; i < 5; i++)
			{
				small = s[i].marks;
				pos = i;
				for (j = i + 1; j < 5; j++)
				{
					if (s[j].marks < small)
					{
						small = s[j].marks;
						pos = j;
					}
				}
				strcpy(temp.name,s[i].name);
				temp.rno = s[i].rno;
				temp.marks = s[i].marks;
				strcpy(s[i].name,s[pos].name);
				s[i].rno = s[pos].rno;
				s[i].marks = s[pos].marks;
				strcpy(s[pos].name,temp.name);
				s[pos].rno = temp.rno;
				s[pos].marks = temp.marks;
			}
			printf("\n\nThe Records have been sorted.\n");
			for (i = 0; i < 5; i++)
			{
				printf("\nName: %s\t\tRoll No:%d\t\tMark:%d",s[i].name,s[i].rno,s[i].marks);
			}
			break;
		default : printf("Wrong choice !!!");
		}
		printf("\nDo you want to continue (Y,y)->YES\nEnter your choice\n");
		fflush(stdin);
		scanf("%c",&r);
	}while(r=='Y'||r=='y');
	return 0;
}
