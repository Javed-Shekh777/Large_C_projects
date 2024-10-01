#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "./school.h"

void addStudent()
{
    FILE *fptr;

    int count = 0, i, j, temp = 0;
    printf("\nHow many students you want to add : ");
    scanf("%d", &count);

    if (count == 0)
        return;

    temp = count;

    struct Student student[count];

    fptr = fopen("student.txt", "a");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nPlease enter %d student Details....\n", i + 1);
        fflush(stdin);
        printf("\nPlease enter Student id : ");
        scanf("%d", &student[i].student_id);
        fflush(stdin);

        printf("\nPlease enter Student name : ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';
        fflush(stdin);

        printf("\nPlease enter Student age : ");
        scanf("%d", &student[i].age);
        fflush(stdin);

        printf("\nPlease enter Student Class : ");
        scanf("%d", &student[i].Class);
        fflush(stdin);

        printf("\nPlease enter Student address : ");
        fgets(student[i].address, sizeof(student[i].address), stdin);
        student[i].address[strcspn(student[i].address, "\n")] = '\0';
        fflush(stdin);

        printf("\nPlease enter Student contact number : ");
        fgets(student[i].contact_number, sizeof(student[i].contact_number), stdin);
        student[i].contact_number[strcspn(student[i].contact_number, "\n")] = '\0';
        fflush(stdin);

        system("cls");
    }
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fprintf(fptr, "%-10s %-30s %-5s %-10s %-100s %s\n", "Id", "Student_Name", "Age", "Class", "Address", "Contact");
        fprintf(fptr, "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < count; i++)
    {
        fprintf(fptr, "%-10d %-30s %-5d %-10d %-100s %s\n", student[i].student_id, student[i].name, student[i].age, student[i].Class, student[i].address, student[i].contact_number);
    }

    fclose(fptr);
    printf("\n\n Student added successfully!!!");
    getch();
}

void readStudent(int id)
{
    FILE *fptr;
    struct Student student;
    int found = 0;
    fptr = fopen("student.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening a file..");
        return;
    }
    char buffer[256];
    fgets(buffer, sizeof(buffer), fptr); // Skip the header
    fgets(buffer, sizeof(buffer), fptr);

    while (fscanf(fptr, "%d %30[^\n] %d %d %90[^\n] %s", &student.student_id, student.name, &student.age, &student.Class, student.address, student.contact_number) != EOF)
    {

        if (student.student_id == id)
        {
            found = 1;
            printf("Student Id is : %d\n", student.student_id);
            printf("Student name is : %s\n", student.name);
            printf("Student age is : %d\n", student.age);
            printf("Student class is : %d\n", student.Class);
            printf("Student address is : %s\n", student.address);
            printf("Student phone number is : %s\n\n", student.contact_number);
            break;
        }
    }
    if (!found)
    {
        printf("Student not found.");
    }
    fclose(fptr);
}

void updateStudent(int id)
{

    
    FILE *fptr;
    FILE *temp;
    struct Student student;
    int found = 0;

    fptr = fopen("student.txt", "r");
    temp = fopen("stu.txt", "a");

    if (temp == NULL || fptr == NULL)
    {
        printf("\nError opening file ");
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fptr); // Skip the header
    fgets(buffer, sizeof(buffer), fptr);

    fseek(temp, 0, SEEK_END);
    if (ftell(temp) == 0)
    {
        fprintf(temp, "%-10s %-30s %-5s %-10s %-100s %s\n", "Id", "Student_Name", "Age", "Class", "Address", "Contact");
        fprintf(temp, "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    while (fscanf(fptr, "%d %30[^\n] %d %d %90[^\n] %s", &student.student_id, student.name, &student.age, &student.Class, student.address, student.contact_number) != EOF)
    {

        if (student.student_id == id)
        {
            found = 1;
            printf("\n\nMake chages in given fields.....\n");
            fflush(stdin);
            printf("\nPlease enter Student id : ");
            scanf("%d", &student.student_id);
            fflush(stdin);

            printf("\nPlease enter Student name : ");
            fgets(student.name, sizeof(student.name), stdin);
            student.name[strcspn(student.name, "\n")] = '\0';
            fflush(stdin);

            printf("\nPlease enter Student age : ");
            scanf("%d", &student.age);
            fflush(stdin);

            printf("\nPlease enter Student Class : ");
            scanf("%d", &student.Class);
            fflush(stdin);

            printf("\nPlease enter Student address : ");
            fgets(student.address, sizeof(student.address), stdin);
            student.address[strcspn(student.address, "\n")] = '\0';
            fflush(stdin);

            printf("\nPlease enter Student contact number : ");
            fgets(student.contact_number, sizeof(student.contact_number), stdin);
            student.contact_number[strcspn(student.contact_number, "\n")] = '\0';
            fflush(stdin);
        }

        fprintf(temp, "%-10d %-30s %-5d %-10d %-100s %s\n", student.student_id, student.name, student.age, student.Class, student.address, student.contact_number);

        // fprintf(temp, "%-10s %-30s %-5s %-10s %-100s %s\n", student.student_id, student.name, student.age, student.Class, student.address, student.contact_number);
    }

    fclose(fptr);
    fclose(temp);

    printf("\nbyyyy");

    if (!found)
    {
        printf("\nStudent not found!!\n");
        remove("student.txt");
        rename("stu.txt", "student.txt");

    }
    else
    {
        remove("student.txt");
        rename("stu.txt", "student.txt");
        system("cls");
        printf("\nStudent updated successfully!!");
    }
}

void deleteStudent(int id)
{

    printf("%d", id);
    FILE *fptr;
    FILE *temp;
    struct Student student;
    int found = 0;

    fptr = fopen("student.txt", "r");
    temp = fopen("stu.txt", "a");

    if (temp == NULL || fptr == NULL)
    {
        printf("\nError opening file ");
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fptr); // Skip the header
    fgets(buffer, sizeof(buffer), fptr);

    fseek(temp, 0, SEEK_END);
    if (ftell(temp) == 0)
    {
        fprintf(temp, "%-10s %-30s %-5s %-10s %-100s %s\n", "Id", "Student_Name", "Age", "Class", "Address", "Contact");
        fprintf(temp, "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    while (fscanf(fptr, "%d %30[^\n] %d %d %90[^\n] %s", &student.student_id, student.name, &student.age, &student.Class, student.address, student.contact_number) != EOF)
    {

        if (student.student_id != id)
        {
            fprintf(temp, "%-10d %-30s %-5d %-10d %-100s %s\n", student.student_id, student.name, student.age, student.Class, student.address, student.contact_number);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fptr);
    fclose(temp);

    if (!found)
    {
        printf("\n\nStudent record not found.\n");
        remove("stu.txt");
    }
    else
    {
        remove("student.txt");
        rename("stu.txt", "student.txt");
        printf("\nStudent record deleted successfully\n\n");
    }
}
