#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct student{
    char studentName[20];
    char studentId[20];
    char studentDept[20];
    char studentAddress[50];
    char studentContactNum[15];
    float studentCGPA;

}student;

int main()
{
    char option;

    while (option != '0')
    {
        system("cls");

        printf("\t\t\t\t-------------Student Record Management System---------------\n");
        printf("\n\n\t\t\t\t\t1.Create Student Account");
        printf("\n\t\t\t\t\t2.Display All Students Information");
        printf("\n\t\t\t\t\t3.Update Student Information");
        printf("\n\t\t\t\t\t4.Search Student Information");
        printf("\n\t\t\t\t\t5.Sort Students by Name");
        printf("\n\t\t\t\t\t6.Sort Students by CGPA");
        printf("\n\t\t\t\t\t7.Delete Student Information");
        printf("\n\t\t\t\t\t0.EXIT From PROGRAM");

        printf("\n\n\n\t\t\tENTER YOUR OPTION : ");
        scanf("%c" , &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;

        case '2':
            displayInfo();
            break;

        case '3':
            updateInfo();
            break;

        case '4':
            searchInfo();
            break;

        case '5':
            sortbyName();
            break;

        case '6':
            sortbyCGPA();
            break;

        case '7':
            deleteInfo();
            break;

        case '0':
            printf("\n\n\t\t\t~~~~~~~~THANK YOU~~~~~~~~~");
            break;

        default:
            printf("\n\n\t\t\tInvalid Option, Please Enter Again...!\n");

        }

    }

    return 0;
}


void createAccount()
{
    FILE *fp1 = fopen("studentInfo.bin" , "ab+");

    if(fp1 == NULL)
    {
        printf("\n\n\t\t\tOOPS SOMETHING WENT WRONG...!\n");
    }

    student studentInformation;

    system("cls");

    printf("\n\t\t\t~~~~~~~~~ Create Student Account ~~~~~~~~~~\n");
    printf("\n\t\t\tEnter Student's Name : ");

    getchar();
    gets(studentInformation.studentName);

    printf("\t\t\tEnter Student's ID : ");
    gets(studentInformation.studentId);

    printf("\t\t\tEnter Student's Department : ");
    gets(studentInformation.studentDept);

    printf("\t\t\tEnter Student's Address : ");
    gets(studentInformation.studentAddress);

    printf("\t\t\tEnter Student's Contact Number : ");
    gets(studentInformation.studentContactNum);

    printf("\t\t\tEnter Student's Current CGPA : ");
    scanf("%f", &studentInformation.studentCGPA);

    fwrite(&studentInformation , sizeof(studentInformation) , 1 , fp1);

    printf("\n\n\t\t\tAbove Information have been stored sucessfully.\n");
    printf("\n\n\t\t\tEnter any key to continue.......");

    getch();

    fclose(fp1);
}


void displayInfo()
{
    FILE *fp1 = fopen("studentInfo.bin" , "rb");

    if (fp1 == NULL)
    {
        printf("\n\t\t\tOOPS SOMETHING WENT WRONG...!\n");
    }

    student stundentInformation;

    system("cls");

    printf("\t\t\t\t\t~~~~~~~~~ All Students Information ~~~~~~~~~\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fp1) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", stundentInformation.studentName, stundentInformation.studentId, stundentInformation.studentDept, stundentInformation.studentAddress, stundentInformation.studentContactNum, stundentInformation.studentCGPA);
    }

    printf("\n\n\t\tEnter any key to continue.......");

    getch();

    fclose(fp1);
}



void updateInfo()
{
    FILE *fp1 = fopen("studentInfo.bin", "rb");

    FILE *temp = fopen("temp.bin", "wb");

    student studentInformation, tempInformation;

    int choice , flag = 0;

    if (fp1 == NULL || temp == NULL)
    {
        printf("\n\t\t\tError. SOMETHING WENT WRONG...!\n");
    }

    system("cls");

    printf("\t\t\t\t~~~~~~~~~ Update Student's Information ~~~~~~~~~~\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fp1) == 1)
    {
        if (strcmp(studentInformation.studentId , tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Dept.\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student Contact No.\n\t\t\t5.Update Student CPGA");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("\n\t\t\tEnter the Name to be Updated : ");
                getchar();
                gets(tempInformation.studentName);
                strcpy(studentInformation.studentName, tempInformation.studentName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Department to be Updated : ");
                getchar();
                gets(tempInformation.studentDept);
                strcpy(studentInformation.studentDept, tempInformation.studentDept);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Address to be Updated : ");
                getchar();
                gets(tempInformation.studentAddress);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Contact No. to Update : ");
                getchar();
                gets(tempInformation.studentContactNum);
                strcpy(studentInformation.studentContactNum, tempInformation.studentContactNum);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's CGPA to Update : ");
                scanf("%f", &tempInformation.studentCGPA);
                studentInformation.studentCGPA = tempInformation.studentCGPA;

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fp1);

    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent ID is not found");
    }

    printf("\n\n\t\t\tEnter any key to continue.......");
    getch();
}

void searchInfo()
{

    FILE *fp1 = fopen("studentInfo.bin" , "rb");

    student studentInformation;

    int choice, flag = 0;
    char studentID[20], studentDept[20];

    if (fp1 == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t~~~~~~~~~~ Search Student Information ~~~~~~~~~~~~\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Department");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student ID : ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fp1) == 1)
        {
            if (strcmp(studentInformation.studentId, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent Name : %s\n\t\t\tStudent ID : %s\n\t\t\tStudent Dept. : %s\n\t\t\tStudent Address : %s\n\t\t\tStudent Contact No. : %s\n\t\t\tStudent CGPA : %.2f\n", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student Dept. : ");
        getchar();
        gets(studentDept);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&studentInformation, sizeof(studentInformation), 1, fp1) == 1)
        {
            if (strcmp(studentInformation.studentDept, studentDept) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fp1);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}


void sortbyName()
{
    FILE *fp1 = fopen("studentInfo.bin" , "rb");

    if (fp1 == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    student *s , s1;

    fseek(fp1 , 0 , SEEK_END);
    int n = ftell(fp1)/sizeof(student);
    s = (student*)calloc(n , sizeof(student));

    rewind(fp1);
    for(int i=0 ; i<n ; i++){
        fread(&s[i] , sizeof(student) , 1 , fp1);
    }

    fclose(fp1);

    for(int i=0; i<n ; i++){
        for(int j=i+1; j<n ; j++){
            if(strcmp(s[i].studentName , s[j].studentName) > 0){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    fp1 = fopen("studentInfo.bin" , "wb");

    for(int i=0 ; i<n ; i++){
        printf("\n%-20s%-20s" ,s[i].studentId , s[i].studentName );
        printf("%.2f" , s[i].studentCGPA);
        fwrite(&s[i] , sizeof(student) , 1 , fp1);
        }

    fclose(fp1);

}


void sortbyCGPA()
{
    FILE *fp1 = fopen("studentInfo.bin" , "rb");

    if (fp1 == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    student *s , s1;

    fseek(fp1 , 0 , SEEK_END);
    int n = ftell(fp1)/sizeof(student);
    s = (student*)calloc(n , sizeof(student));

    rewind(fp1);
    for(int i=0 ; i<n ; i++){
        fread(&s[i] , sizeof(student) , 1 , fp1);
    }

    fclose(fp1);

    for(int i=0; i<n ; i++){
        for(int j=i+1; j<n ; j++){
            if(s[i].studentCGPA < s[j].studentCGPA){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    fp1 = fopen("studentInfo.bin" , "wb");

    for(int i=0 ; i<n ; i++){
        printf("\n%-20s%-20s" ,s[i].studentId , s[i].studentName );
        printf("%.2f" , s[i].studentCGPA);
        fwrite(&s[i] , sizeof(student) , 1 , fp1);
        }

    fclose(fp1);
}



void deleteInfo()
{
    FILE *fp1 = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fp1 == NULL || temp == NULL)
    {
        printf("\n\t\t\tError. SOMETHING WENT WRONG...!\n");
    }

    system("cls");

    printf("\t\t\t\t~~~~~~~~~ Delete Student Information ~~~~~~~~~~\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fp1) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fp1);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any key to continue.......");
    getch();
}


















































