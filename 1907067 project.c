//Bismillah hir rahmanir rahim
//Nusrat Jahan Jonaki
//Roll no:1907067
//CSE Department, Kuet.
//University management project



/*
  create teacher and student structure:
  Admin panel:
  1.Login using function
  2.Create Teacher and student account using function and file
  3.Updating teacher's and student's information using Function + Pointer + File
  4.Assigning courses to teacher using function and file

  Teacher's Panel
  1.Login using Function + File
  2.Provide class test marks using Function + File
  3.Find the student by the given first name using Function+File+pointer
  4.Count of students using Function + File

  Student's Panel
  1.Login using Function + File.
  2.Check the class test marks using Function + File
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char Aus_na[]="Hosne_Ara";//Admin's fixed user name for all the process
char Aus_pa[]="0226760";//Admin's fixed password for all the process


void AdP();
void Adm2();
void teacher();
void  A_Add_teacher();
void ListOfTeacher();
void student();
void A_Add_student();
void ListOfStudent();
void UpTchInfo();
void UpStdInfo();

void TeP();
void TeP2();
void ProvideClsTestMark();
void FindStdByName();
void CntOfStdOwnCrs();

void StP();
void Std();
void checkCTmarks();



FILE *fp;
FILE *fpp;
struct teacher
{

    char name[30];
    char dept[30];
    char course1[30];
    char course2[30];
    char address[30];
    char phone[30];
    char us_na[30];
    char us_pa[30];

} t;
struct student
{

    char name[30];
    char dept[30];
    int roll;
    char address[30];
    char course1[30];
    char course2[30];
    char course3[30];
    char course4[30];
    char CTmarksForC1[30];
    char CTmarksForC2[30];
    char CTmarksForC3[30];
    char CTmarksForC4[30];
    char us_na[30];
    char us_pa[30];
} s;
long sz=sizeof(t);
long szz=sizeof(s);
int main()
{
    int x;
    while(1)
    {
        system("cls");//This is for clear the screen.
        printf("<==University Management System==>\n\n");
        printf("1.Admin Panel.\n");
        printf("2.Teacher Panel.\n");
        printf("3.Student Panel.\n");
        printf("0.Exit.\n");

        printf("\n\nPlease,Enter your choice:");
        scanf("%d",&x);

        switch (x)
        {
        case 0:
            exit(0);
            break;
        case 1:
            AdP();
            break;
        case 2:
            TeP();
            break;
        case 3:
            StP();
            break;
        default:
            printf("Invalid choice............\n");
        }
        printf("\n\n press any key to continue.......");
        getch();
    }

}
void AdP()
{
    char na[300],pa[300];
    system("cls");//This is for clear the screen.
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n");
    printf("Welcome to Admin panel %c %c\n",1,1);
    printf("\nPlease,Enter user's name:");
    fflush(stdin);//This is for clearing the buffer .The process will help us to take the actual input
    gets(na);//"gets" takes input until find a new line
    printf("\nPlease,Enter  password:");
    fflush(stdin);//This is for clearing the buffer .The process will help us to take the actual input
    gets(pa);//"gets" takes input until find a new line

    if((strcmp(na,Aus_na)!=0) || (strcmp(pa,Aus_pa)!=0))//strcmp is used to compare two strings.
    {
        printf("\nOhh NO!!! Incorrect user name or password.\n");
    }
    else
    {
        Adm2();
    }
}
void Adm2()
{

    int x;
    while(1)
    {
        system("cls");//This is for clear the screen.
        printf("<==University Management System==>\n\n");
        printf("<==Admin Panel==>\n\n");
        printf("1.Create and observe Teacher's account.\n");
        printf("2.Create and observe Student's account.\n");
        printf("3.Update teacher's information.\n");
        printf("4.Update student's information.\n");
        printf("0.Return main menu.\n");

        printf("\n\nPlease,Enter your choice:");
        scanf("%d",&x);

        switch(x)
        {
        case 0:
            main();
            break;
        case 1:
            teacher();
            break;
        case 2:
            student();
            break;
        case 3:
            UpTchInfo();
            break;
        case 4:
            UpStdInfo();
        default:
            printf("Invalid choice........");
        }

    }

}
void teacher()
{
    int x;
    system("cls");//This is for clear the screen.
    printf("<==University Management System==>\n\n");
    printf("<==Admin_panel==>\n\n");
    printf("1.Add teacher.\n");
    printf("2.See list of the teachers.\n");
    printf("0.Return main menu.\n");

    printf("\n\nPlease,Enter your choice:");
    scanf("%d",&x);

    switch(x)
    {
    case 0:
        main();
        break;
    case 1:
        A_Add_teacher();
        break;
    case 2:
        ListOfTeacher();
        break;

    default:
        printf("Invalid choice........");

    }
}
void  A_Add_teacher()
{
    system("cls");//This is for clear the screen.
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n");
    printf("\n<==Process going on(Adding_teacher)==>\n\n");
    fp=fopen("tech.txt","a");//this syntax is used to open a file in appending mode.where we can write and for next time running code,the previous writing data will not be deleted
    printf("Please,Enter Name:  ");
    fflush(stdin);
    gets(t.name);
    printf("Please,Enter Department:  ");
    fflush(stdin);
    gets(t.dept);
    printf("Please,Enter Course(First one):  ");
    fflush(stdin);
    gets(t.course1);
    printf("Please,Enter Course(Second one):  ");
    fflush(stdin);
    gets(t.course2);
    printf("Please,Enter Address:  ");
    fflush(stdin);
    gets(t.address);
    printf("Please,Enter phone number:  ");
    fflush(stdin);
    gets(t.phone);
    printf("Please, Be careful on entering user's name and password.\nThese will help you in time of login.\n");
    printf("Please,Enter user_name:  ");
    fflush(stdin);
    gets(t.us_na);
    printf("Please,Enter password:  ");
    fflush(stdin);
    gets(t.us_pa);
    fwrite(&t,sz,1,fp);
    //fwrite helps to write in file ..Takes 4 parameters
    fclose(fp);
    printf("Record saved successfully.............%c",1);
    printf("\nPress any key to continue..............");
    getch();

}
void ListOfTeacher()
{

    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n\n");

    printf("List of the teachers\n");

    fp=fopen("tech.txt","r");//only read mood cause we need not to write anything here..
    printf("%-20s %-20s %-20s %-20s %-20s %20\n","Name","Department","Course1","Course2","Address","Phone Number");
    while(fread(&t,sz,1,fp)==1)
    {
        printf("%-20s %-20s %-20s %-20s %-20s %20\n",t.name, t.dept,t.course1,t.course2,t.address,t.phone);

    }
    fclose(fp);
    printf("\n\n press any key to continue.......");
    getch();
}
void student()
{
    int x;

    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Admin_panel==>\n\n");

    printf("1.Add Student.\n");
    printf("2.See list of the student.\n");
    printf("0.Return main menu.\n");

    printf("\n\nPlease,Enter your choice:");
    scanf("%d",&x);

    switch(x)
    {
    case 0:
        main();
        break;
    case 1:
        A_Add_student();
        break;
    case 2:
        ListOfStudent();
        break;

    default:
        printf("Invalid choice........");
    }
}
void A_Add_student()
{
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n");
    printf("<==Process going on(Adding_student)==>\n\n");
    fpp=fopen("stud.txt","a+");
    printf("Please,Enter Name:  ");
    fflush(stdin);
    gets(s.name);
    printf("Please,Enter Department:  ");
    fflush(stdin);
    gets(s.dept);
    printf("Please,Enter address:  ");
    fflush(stdin);
    gets(s.address);
    printf("Please,Enter roll:  ");
    scanf("%d",&s.roll);
    printf("Please,Enter Course1:  ");
    fflush(stdin);
    gets(s.course1);
    printf("Please,Enter Course2:  ");
    fflush(stdin);
    gets(s.course2);
    printf("Please,Enter Course3:  ");
    fflush(stdin);
    gets(s.course3);
    printf("Please,Enter Course4:  ");
    fflush(stdin);
    gets(s.course4);
    printf("Only teacher can give CT marks.So give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for Course1:  ");
    fflush(stdin);
    gets(s.CTmarksForC1);
    printf("Only teacher can give CT marks.So give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for Course2:  ");
    fflush(stdin);
    gets(s.CTmarksForC2);
    printf("Only teacher can give CT marks.So give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for Course3:  ");
    fflush(stdin);
    gets(s.CTmarksForC3);
    printf("Only teacher can give CT marks.So give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for Course4:  ");
    fflush(stdin);
    gets(s.CTmarksForC4);

    printf("Please, Be careful on entering user's name and password.\nThese will help you time of login.\n");
    printf("Please,Enter user's name:  ");
    fflush(stdin);
    gets(s.us_na);
    printf("Please,Enter password:  ");
    fflush(stdin);
    gets(s.us_pa);
    fwrite(&s,szz,1,fpp);
    fclose(fpp);
    printf("Record saved successfully.............");
    getch();

}
void ListOfStudent()
{
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n\n");

    printf("List of the students\n");

    fpp=fopen("stud.txt","r");
    printf("%-20s %-20s %-20s %-20s\n","Name","Department","Roll","Address");
    while(fread(&s,szz,1,fpp)==1)
    {
        printf("%-20s %-20s %-20d %-20s\n",s.name,s.dept,s.roll,s.address);
    }
    fclose(fpp);
    fpp=fopen("stud.txt","r");
    printf("\n\n");
    printf("%-20s %-20s %-20s %-20s %-20s\n","Name","Course1","Course2","Course3","Course4");
    while(fread(&s,szz,1,fpp)==1)
    {
        printf("%-20s %-20s %-20s %-20s %-20s\n",s.name,s.course1,s.course2,s.course3,s.course4);
    }
    fclose(fpp);
    fpp=fopen("stud.txt","r");
    printf("\n\n");
    printf("%-20s %-20s %-20s %-20s %-20s \n","Name","CT-marksForC1","CT-marksForC2","CT-marksForC3","CT-marksForC4");
    while(fread(&s,szz,1,fpp)==1)
    {
        printf("%-20s %-20s %-20s %-20s %-20s\n",s.name,s.CTmarksForC1,s.CTmarksForC2,s.CTmarksForC3,s.CTmarksForC4);
    }
    fclose(fpp);
    printf("\nPress any key to continue.................");
    getch();
}
void UpTchInfo()
{
    system("cls");
    char na[300];
    int f=0;
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n");
    printf("<==Process going on(Updating_teacher's_Info)==>\n\n");
    fp=fopen("tech.txt","r+");//for updating, we need both read and write
    printf("Enter teacher's name to Update Information: ");
    fflush(stdin);
    gets(na);
    while(fread(&t,sz,1,fp)==1)
    {
        if(strcmp(na,t.name)==0)
        {
            f=1;
            printf("Please,Enter new Name:  ");
            fflush(stdin);
            gets(t.name);
            printf("Please,Enter new Department:  ");
            fflush(stdin);
            gets(t.dept);
            printf("Please,Enter new Course: (1st one) ");
            fflush(stdin);
            gets(t.course1);
            printf("Please,Enter new Course: (2nd one) ");
            fflush(stdin);
            gets(t.course2);
            printf("Please,Enter new Address:  ");
            fflush(stdin);
            gets(t.address);
            printf("Please,Enter new phone number:  ");
            fflush(stdin);
            gets(t.phone);
            printf("Please, Be careful on entering user's name and password.\nThese will help you time of login.\n");
            printf("Please,Enter new user_name:  ");
            fflush(stdin);
            gets(t.us_na);
            printf("Please,Enter new password:  ");
            fflush(stdin);
            gets(t.us_pa);
            fseek(fp,-sz,1);//jeita update korte chai,,oita theke file_pointer ek gor age thake..so,fseek() diye ek gor pichano hoy pointer.jate jei data modify kora hobe,,sei datay file point kore rakhe.
            fwrite(&t,sz,1,fp);
            fclose(fp);
            break;
        }
    }

    if(f==0)
        printf("Sorry!!!Record not found.");
    else
        printf("Record Modified successfully. %c",1);
    printf("\nPress any key to continue.................");
    getch();

}
void  UpStdInfo()

{
    char na[300];
    int f=0;
    system("cls");
    fpp=fopen("stud.txt","r+");
    printf("<==University Management System==>\n\n");
    printf("<==Admin Panel==>\n");
    printf("<==Process going on(Updating_student's_Info)==>\n\n");
    printf("Enter student's name to Update Information: ");
    fflush(stdin);
    gets(na);

    while(fread(&s,szz,1,fpp)==1)
    {
        if(strcmp(na,s.name)==0)
        {
            printf("Please,Enter new Name:  ");
            fflush(stdin);
            gets(s.name);
            printf("Please,Enter new Department:  ");
            fflush(stdin);
            gets(s.dept);
            printf("Please,Enter new address:  ");
            fflush(stdin);
            gets(s.address);
            printf("Please,Enter new roll:  ");
            fflush(stdin);
            scanf("%d",&s.roll);
            printf("Please,Enter new Course1:  ");
            fflush(stdin);
            gets(s.course1);
            printf("Please,Enter new Course2:  ");
            fflush(stdin);
            gets(s.course2);
            printf("Please,Enter new Course3:  ");
            fflush(stdin);
            gets(s.course3);
            printf("Please,Enter new Course4:  ");
            fflush(stdin);
            gets(s.course4);
            printf("Only teacher can give CT marks.If teacher doesn't give yet then give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for course1:  ");
            fflush(stdin);
            gets(s.CTmarksForC1);
            printf("Only teacher can give CT marks.If teacher doesn't give yet then  give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for course2:  ");
            fflush(stdin);
            gets(s.CTmarksForC2);
            printf("Only teacher can give CT marks.If teacher doesn't give yet then give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for course3:  ");
            fflush(stdin);
            gets(s.CTmarksForC3);
            printf("Only teacher can give CT marks.If teacher doesn't give yet then give a message {Not given yet--as ct marks}\nPlease,Enter CTmarks for course4:  ");
            fflush(stdin);
            gets(s.CTmarksForC4);

            printf("Please, Be careful on entering user's name and password.\nThese will help you in time of login.\n");
            printf("Please,Enter new user_name:  ");
            fflush(stdin);
            gets(s.us_na);
            printf("Please,Enter new password:  ");
            fflush(stdin);
            gets(s.us_pa);
            fseek(fpp,-szz,1);//jeita update korte chai,,oita theke file_point ek gor age thake..so,fseek fun()diye ek gor pichano hoy pointer.jate jei data modify kora hobe,,sei datay file point kore rakhe.
            fwrite(&s,szz,1,fpp);
            fclose(fpp);
            f=1;
            break;
        }
    }

    if(f==0)
        printf("Record not found.");
    else
        printf("Record Updated successfully.");
    printf("\nPress any key to continue.................");
    getch();

}
void TeP()
{
    char na[300],pa[300];
    int f=0;
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Teacher Panel==>\n\n");

    printf("Welcome to teacher panel........%c%c\n\n",2,2);

    printf("\n\nPlease login at first to continue:");

    printf("\nPlease,Enter user name:");
    fflush(stdin);
    gets(na);
    printf("\nPlease,Enter password:");
    fflush(stdin);
    gets(pa);

    fp=fopen("tech.txt","r");
    while(fread(&t,sz,1,fp)==1)
    {
        if((strcmp(na,t.us_na)==0) && (strcmp(pa,t.us_pa)==0))
        {
            f=1;
            break;
        }
    }
    fclose(fp);

    if(f==0)
    {
        printf("Incorrect user name or password.\n");
    }
    else
    {
        TeP2(na,pa);
    }

}
void TeP2(char na[300],char pa[300])
{
    int x;
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Teacher's Panel==>\n\n");

    printf("1.Provide class test marks of your course\n");
    printf("2.Find students by the given name\n");
    printf("3.Count of student of your own course\n");
    printf("4.Back\n");
    printf("0.Return to the main menu\n");
    printf("\n\nPlease,Enter your choice:");
    scanf("%d",&x);

    switch (x)
    {
    case 0:
        main(0);
        break;
    case 1:
        ProvideClsTestMark(na,pa);
        break;
    case 2:
        FindStdByName();
        break;
    case 3:
        CntOfStdOwnCrs(na,pa);
        break;
    case 4:
        TeP();
        break;
    default:
        printf("Invalid choice...........");
    }
}
void ProvideClsTestMark(char na[300],char pa[300])
{
    char Crs1[300],Crs2[300];
    int x=0;
    printf("<==University Management System==>\n\n");
    printf("<==Teacher Panel==>\n\n");
    fp=fopen("tech.txt","r");
    while(fread(&t,sz,1,fp)==1)
    {
        if((strcmp(na,t.us_na)==0) && (strcmp(pa,t.us_pa)==0))
        {
            strcpy(Crs1,t.course1);
            strcpy(Crs2,t.course2);
        }
    }
    fclose(fp);
    int n=0;
    fpp=fopen("stud.txt","r+");
    while(fread(&s,szz,1,fpp)==1)
    {
        n++;
    }
    fclose(fpp);
    int a[n];
    int i=0;
    for(i=0; i<n; i++)
    {
        a[i]=0;
    }
    int p=0;
    for(i=0; i<n; i++)
    {
        int q=0;
        fpp=fopen("stud.txt","r+");
        while(fread(&s,szz,1,fpp)==1)
        {
            if(a[q]!=1)
            {
                if(strcmp(Crs1,s.course1)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course1);
                    fflush(stdin);
                    gets(s.CTmarksForC1);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
                else if(strcmp(Crs1,s.course2)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course2);
                    fflush(stdin);
                    gets(s.CTmarksForC2);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
                else if (strcmp(Crs1,s.course3)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course3);
                    fflush(stdin);
                    gets(s.CTmarksForC3);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;

                }
                else if(strcmp(Crs1,s.course4)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course4);
                    fflush(stdin);
                    gets(s.CTmarksForC4);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
            }
            q++;
        }
        fclose(fpp);
        a[p]=1;
        p++;
    }
    for(i=0; i<n; i++)
    {
        a[i]=0;
    }
    p=0;
    for(i=0; i<n; i++)
    {
        int q=0;
        fpp=fopen("stud.txt","r+");
        while(fread(&s,szz,1,fpp)==1)
        {
            if(a[q]!=1)
            {
                if(strcmp(Crs2,s.course1)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course1);
                    fflush(stdin);
                    gets(s.CTmarksForC1);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
                else if(strcmp(Crs2,s.course2)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course2);
                    fflush(stdin);
                    gets(s.CTmarksForC2);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
                else if (strcmp(Crs2,s.course3)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course3);
                    fflush(stdin);
                    gets(s.CTmarksForC3);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;

                }
                else if(strcmp(Crs2,s.course4)==0)
                {
                    printf("Please give ct marks to %s of %s\n",s.name,s.course4);
                    fflush(stdin);
                    gets(s.CTmarksForC4);
                    fseek(fpp,-szz,1);
                    fwrite(&s,szz,1,fpp);
                    break;
                }
            }
            q++;
        }
        fclose(fpp);
        a[p]=1;
        p++;
    }
    getch();
    TeP2(na,pa);
}
void FindStdByName(char naa[300],char pa[300])
{
    char na[300];

    int f=0;
    printf("Enter name to search: ");
    fflush(stdin);
    gets(na);
    fpp=fopen("stud.txt","r");
    printf("%-20s %-20s %-20s %-20s\n","Name","Department","Roll","Address");
    while(fread(&s,szz,1,fpp)==1)
    {
        if(strcmp(na,s.name)==0)
        {
            f=1;
            printf("%-20s %-20s %-20d %-20s\n",s.name,s.dept,s.roll,s.address);
        }
    }
    fclose(fpp);
    fpp=fopen("stud.txt","r");
    printf("\n\n");
    printf("%-20s %-20s %-20s %-20s %-20s\n","Name","Course1","Course2","Course3","Course4");
    while(fread(&s,szz,1,fpp)==1)
    {
        if(strcmp(na,s.name)==0)
        {
            printf("%-20s %-20s %-20s %-20s %-20s\n",s.name,s.course1,s.course2,s.course3,s.course4);
        }
    }
    fclose(fpp);
    fpp=fopen("stud.txt","r");
    printf("\n\n");
    printf("%-20s %-20s %-20s %-20s %-20s \n","Name","CT-marksForC1","CT-marksForC2","CT-marksForC3","CT-marksForC4");
    while(fread(&s,szz,1,fpp)==1)
    {
        if(strcmp(na,s.name)==0)
        {
            printf("%-20s %-20s %-20s %-20s %-20s\n",s.name,s.CTmarksForC1,s.CTmarksForC2,s.CTmarksForC3,s.CTmarksForC4);
        }
    }
    fclose(fpp);

    if(f==0)
        printf("Record not found.");
    else
        printf("Record found successfully.");
    getch();
    TeP2(naa,pa);
}
void CntOfStdOwnCrs(char na[300],char pa[300])
{
    char Crs1[300],Crs2[300];
    printf("<==University Management System==>\n\n");
    printf("<==Teacher Panel==>\n\n");
    fp=fopen("tech.txt","r");
    while(fread(&t,sz,1,fp)==1)
    {
        if((strcmp(na,t.us_na)==0) && (strcmp(pa,t.us_pa)==0))
        {
            strcpy(Crs1,t.course1);
            strcpy(Crs2,t.course2);
        }
    }
    fclose(fp);
    int cnt1=0,cnt2=0;
    fpp=fopen("stud.txt","r+");

    while(fread(&s,szz,1,fpp)==1)
    {
        if((strcmp(Crs1,s.course1)==0))
        {
            cnt1++;
        }
        else if((strcmp(Crs1,s.course2)==0))
        {
            cnt1++;
        }
        else if((strcmp(Crs1,s.course3)==0))
        {
            cnt1++;
        }
        else if((strcmp(Crs1,s.course4)==0))
        {
            cnt1++;
        }
    }
    fclose(fpp);
    fpp=fopen("stud.txt","r+");
    while(fread(&s,szz,1,fpp)==1)
    {
        if((strcmp(Crs2,s.course1)==0))
        {
            cnt2++;
        }
        else if((strcmp(Crs2,s.course2)==0))
        {
            cnt2++;
        }
        else if((strcmp(Crs2,s.course3)==0))
        {
            cnt2++;
        }
        else if((strcmp(Crs2,s.course4)==0))
        {
            cnt2++;
        }
    }
    fclose(fpp);
    printf("Total number of students under course %s is %d.\n\n",Crs1,cnt1);
    printf("Total number of students under course %s is %d.\n\n",Crs2,cnt2);
    getch();
    TeP2(na,pa);
}
void StP()
{
    char na[300],pa[300];
    int f=0;
   // system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Student's Panel==>\n\n");

    printf("Welcome to student's panel........%c%c\n\n",2,2);

    printf("\n\nPlease login at first to continue:");

    printf("\nPlease,Enter user name:");
    fflush(stdin);
    gets(na);
    printf("\nPlease,Enter password:");
    fflush(stdin);
    gets(pa);

    fpp=fopen("stud.txt","r");
    while(fread(&s,szz,1,fpp)==1)
    {
        if((strcmp(na,s.us_na)==0) && (strcmp(pa,s.us_pa)==0))
        {
            f=1;
            break;
        }
    }
    fclose(fpp);

    if(f==0)
    {
        printf("Incorrect user name or password.\n");
    }
    else
    {
        Std(na,pa);
    }

}
void Std(char na[300],char pa[300])
{

    int x;
    system("cls");
    printf("<==University Management System==>\n\n");
    printf("<==Student's Panel==>\n\n");

    printf("1.Check the class test marks of your own\n");
    printf("4.Back\n");
    printf("0.Return to the main menu\n");
    printf("\n\nPlease,Enter your choice:");
    scanf("%d",&x);
    switch (x)
    {
    case 0:
        main(0);
        break;
    case 1:
        checkCTmarks(na,pa);
        break;
    case 4:
        getch();
        StP();
        break;
    default:
        printf("Invalid choice...........");
    }
}
void checkCTmarks(char na[],char pa[])
{
    fpp=fopen("stud.txt","r");
    while(fread(&s,szz,1,fpp)==1)
    {
        if((strcmp(na,s.us_na)==0) && (strcmp(pa,s.us_pa)==0))
        {
            printf("<=====Please,see with full screen to observe the actual senario=====>.\n\n");
            printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s \n","Course1","Course2","Course3","Course4","CT-marksForC1","CT-marksForC2","CT-marksForC3","CT-marksForC4");
            printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s %-20s \n",s.course1,s.course2,s.course3,s.course4,s.CTmarksForC1,s.CTmarksForC2,s.CTmarksForC3,s.CTmarksForC4);
            break;
        }
    }
    fclose(fpp);
}
