#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int sc;

struct student
{
				int rno;
				char name;
				int age;
				int p;
				int c;
				int m;
				int tm;
				float pct;
				char g;
}s[100];

void title()
{
	system("cls");
	printf("\n\t\t\t_______________________________________________________");
	printf("\n\n\n\t\t\t\tA . B . C . SCHOOL , PREETNAGAR , DELHI");
	printf("\n\n\t\t\t_______________________________________________________");
}

void menu()
{
	printf("\n\n\n\t1) ADD STUDENT.");
	printf("\n\n\t2) MODIFY STUDENT.");
	printf("\n\n\t3) VIEW STUDENTS.");
	printf("\n\n\t4) ADD MARKS.");
	printf("\n\n\t5) GENERATE RESULT.");
	printf("\n\n\t6) VIEW RESULT.");
	printf("\n\n\t7) EXIT.");
}

void addStudent()
{
	char ans;
	int r;

	title();
	printf("\n\n");
	printf("\nEnter student's name    :  ");
	scanf("%s",&s[sc].name);
	printf("\nEnter age                       :  ");
	scanf("%d",&s[sc].age);
	printf("\nAdmission fee diposited  (Y\\N)   :  ");
	fflush(stdin);
	scanf("%c",&ans);
	if((ans=='Y')||(ans=='y'))
	{
		r=sc+1001;
		s[sc].rno=r;
		printf("\nStudent enrolled with Roll-No.  : %d",r);
		sc++;
	}
	else
	{
		printf("\n Admission not possible without Fee.");
	}
	getch();
}


void modifyStudent()
{
	/*
int n;
char ch;
title();
printf("\n\n\tEnter roll no.  :  ");
again : scanf("%d",&n);
n=n-1001;
printf("\n Name:- %s  Age:- %d  ",s[n].name,s[n].age);
printf("\n\nEnter n/N for Name \n\n\ta/A for Age \n\n\tc/C for Cancel");
fflush(stdin);
scanf("%c",&ch);

if ((ch = 'n')||(ch = 'N'))
{
	printf("\n Enter name :  ");
	scanf("%s",s[n].name);
	printf("Name has been changed sucesfully..");
	getch();
}
else if((ch='a')||(ch='A'))
{
	printf("\n Enter Age  :  ");
	scanf("%d",s[n].age);
	printf("\nAge has been change succesfully..");
	getch();
}
else if((ch='c')||(ch='C'))
return;
else
{
	printf("\nWrong option..............TRy again...");
goto again;
}
*/
}


void viewStudents()
{
	title();
	int i;
	printf("\n\n\n\n\n\t\t\tLIST  OF  STUDENTS  ENROLLED");
    printf("\n\t\t_______________________________________________\n");
	printf("\n\n\tS.NO.        ROLL-NO.    NAME                                          AGE  ");
	for(i=0;i<sc;i++)
	{
		printf("\n\t %d            %5d            %-12s            %d ",i+1,s[i].rno,s[i].name,s[i].age);
	}
	getch();
}

void addMarks()
{
	/*
int n;
char ch;
while((ch != 'n')&&(ch != 'N'))
{
title();
printf("\n\n\tEnter roll no.  :  ");
scanf("%d",&n);
n=n-1001;
printf("Enter physics,chemistry,maths marks for roll no.  %d    ",n+1001);
scanf("\n%d\n%d\n%d\n",&s[n].p,&s[n].c,&s[n].m);
s[n].tm=0;
s[n].pct=0;
printf("\n Marks added succesfully.");
printf("\n\nWant to continue.........y/n");
fflush(stdin);
scanf("%c",&ch);
}
*/
}

void generateResult()
{
	/*
int i;
for(i=0;i<sc;i++)
{
	s[i].tm=s[i].p+s[i].c+s[i].m;
	s[i].pct=s[i].tm/3;
	if(s[i].pct>=80)
		s[i].g='A';
	else if((s[i].pct<80)&&(s[i].pct>=70))
		s[i].g='B';
	else if((s[i].pct<70)&&(s[i].pct>=60))
		s[i].g='C';
	else if((s[i].pct<60)&&(s[i].pct>=50))
		s[i].g='D';
	else
		s[i].g='E';
}
printf("Result Created.!!");
getch();
*/
}

void viewResult()
{
	/*
int i;
title();
printf("\n\n");
printf("**************************************************************************************************");
printf("\n\tS.NO.   R.NO.    NAME   AGE    PHYSICS   CHEMISTRY   MATHS    TOTAL   PCT     GRADE");
printf("**************************************************************************************************");
for(i=0;i<sc;i++)
{
	printf("\n\t %d            %5d            %-12s            %2d      %3d  %3d %3d  %3d  %3d %  %c",i+1,s[i].name,s[i].rno,s[i].age,s[i].p,s[i].c,s[i].m,s[i].tm,s[i].pct,s[i].g);
}
getch();
*/
}


int main()
{
			int op=0,i;
			sc=0;
			FILE *fp1,*fp2;
			struct student temp;
				fp1=fopen("Data1.txt","wb");
				fp2=fopen("Count1.txt","wb");
				fread(&sc,sizeof(sc),1,fp2);

							for (i=0;i<sc;i++)
							{
								fread(&temp,sizeof(temp),1,fp1);
								s[i]=temp;
							}
		fclose(fp1);
		fclose(fp2);

	while (op != 7)
	{
            title();
		    menu();
			printf("\n\n\n\tEnter any option (1.......7) :  ");
			scanf("%d",&op);
			switch (op)
			{
				case 1:addStudent();
				break;
				case 2:modifyStudent();
				break;
				case 3:viewStudents();
				break;
				case 4:addMarks();
				break;
				case 5:generateResult();
				break;
				case 6:viewResult();
				break;
			}
		}

	fp1=fopen("Data1.txt","rb");
	fp2=fopen("Count1.txt","rb");
	fread(&sc,sizeof(sc),1,fp2);

	for (i=0;i<sc;i++)
	{
		fread(&temp,sizeof(temp),1,fp1);
		s[i]=temp;
	}
	fclose(fp1);
	fclose(fp2);


printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fp1=fopen("Data1.txt","wb");
	fp2=fopen("Count1.txt","wb");
	fwrite(&sc,sizeof(sc),1,fp2);

	for (i=0;i<sc;i++)
	{
		s[i]=temp;
		fwrite(&temp,sizeof(temp),1,fp1);
	}
	fclose(fp1);
	fclose(fp2);

return 0;
}