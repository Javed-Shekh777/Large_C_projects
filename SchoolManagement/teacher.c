#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "./school.h"

void addTeacher()
{
    system("cls");
    int size = 0, i;
    printf("\nPlease how many teachers you want to delete? :  ");
    scanf("%d", &size);

    if (size == 0)
    {
        return;
    }

    struct Teacher teacher[size];

    for (i = 0; i < size; i++)
    {
        printf("\n Please enter %d teacher data...\n", i + 1);
        fflush(stdin);
        printf("\nPlease enter teacher id : ");
        scanf("%d", &teacher[i].teacher_id);

        printf("Please enter teacher name : ");
        fflush(stdin);
        fgets(teacher[i].name, sizeof(teacher[i].name), stdin);
        teacher[i].name[strcspn(teacher[i].name, "\n")] = '\0';

        fflush(stdin);
        printf("\nPlease enter teacher age : ");
        scanf("%d", &teacher[i].age);

        fflush(stdin);
        printf("\nPlease enter teacher gender (male/female) : ");
        fgets(teacher[i].gender, sizeof(teacher[i].gender), stdin);
        teacher[i].gender[strcspn(teacher[i].gender, "\n")] = '\0';

        printf("\nPlease enter teacher experience : ");
        scanf("%d", &teacher[i].experience);

        fflush(stdin);
        printf("\nPlease enter teacher address : ");
        fgets(teacher[i].address, sizeof(teacher[i].address), stdin);
        teacher[i].address[strcspn(teacher[i].address, "\n")] = '\0';
        fflush(stdin);

        printf("\nPlease enter teacher contact number : ");
        fgets(teacher[i].contact_number, sizeof(teacher[i].contact_number), stdin);
        teacher[i].contact_number[strcspn(teacher[i].contact_number, "\n")] = '\0';
        fflush(stdin);
        system("cls");
    }

    FILE *fptr;

    fptr = fopen("teacher.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening file.");
        return;
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fprintf(fptr, "%-10s %-30s %-5s %-10s %-10s %-100s %s\n", "Id", "Teacher_Name", "Age", "Gender", "Experience", "Address", "Contact");
        fprintf(fptr, "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < size; i++)
    {
        fprintf(fptr, "%-10d %-30s %-5d %-10s %-10d %-100s %s\n", teacher[i].teacher_id, teacher[i].name, teacher[i].age, teacher[i].gender, teacher[i].experience, teacher[i].address, teacher[i].contact_number);
    }

    fclose(fptr);
    printf("\n\n Student added successfully!!!");
    getch();
}

void readTeacher(int id)
{
    if (!id)
    {
        return;
    }
    system("cls");
    FILE *fptr;

    fptr = fopen("teacher.txt", "r");
    if (fptr == NULL)
    {
        printf("file not opened.");
        return;
    }

    struct Teacher teacher;
    int found = 0;

    char buffer[500];
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    while (fscanf(fptr, "%d %30[^\n] %d %10[^\n] %d %90[^\n] %s", &teacher.teacher_id, teacher.name, &teacher.age, teacher.gender, teacher.experience, teacher.address, teacher.contact_number) != EOF)
    {
        if (teacher.teacher_id == id)
        {
            found = 1;
            system("cls");

            printf("\nTeacher found...\nTeacher Data is.........\n ");
            printf("Techer Id is : %d\n", teacher.teacher_id);
            printf("Techer Name is : %s\n", teacher.name);
            printf("Techer Age is : %d\n", teacher.age);
            printf("Techer Gender is : %s\n", teacher.gender);
            printf("Techer Experiece is : %d\n", teacher.experience);
            printf("Techer Address is : %s\n", teacher.address);
            printf("Techer Contact number is : %s\n", teacher.contact_number);
            break;
        }
    }

    fclose(fptr);
    if (!found)
    {
        printf("Student not found.");
        return;
    }
    return;
}

void updateTeacher(int id)
{
    if (!id)
    {
        return;
    }
    system("cls");
    int found = 0;
    struct Teacher teacher;
    FILE *fptr, *temp;

    fptr = fopen("teacher.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fptr == NULL || temp == NULL)
    {
        printf("File not opened..");
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fptr); // Skip the header
    fgets(buffer, sizeof(buffer), fptr);

    fprintf(temp, "%-10s %-30s %-5s %-10s %-10s %-100s %s\n", "Id", "Teacher_Name", "Age", "Gender", "Experience", "Address", "Contact");
    fprintf(temp, "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fscanf(fptr, "%d %30[^\n] %d %10[^\n] %d %90[^\n] %s", &teacher.teacher_id, teacher.name, &teacher.age, teacher.gender, teacher.experience, teacher.address, teacher.contact_number) != EOF)
    {
        if (teacher.teacher_id = id)
        {
            found = 1;

            fflush(stdin);
            printf("\nPlease enter teacher id : ");
            scanf("%d", &teacher.teacher_id);

            printf("Please enter teacher name : ");
            fflush(stdin);
            fgets(teacher.name, sizeof(teacher.name), stdin);
            teacher.name[strcspn(teacher.name, "\n")] = '\0';

            fflush(stdin);
            printf("\nPlease enter teacher age : ");
            scanf("%d", &teacher.age);

            fflush(stdin);
            printf("\nPlease enter teacher gender (male/female) : ");
            fgets(teacher.gender, sizeof(teacher.gender), stdin);
            teacher.gender[strcspn(teacher.gender, "\n")] = '\0';

            printf("\nPlease enter teacher experience : ");
            scanf("%d", &teacher.experience);

            fflush(stdin);
            printf("\nPlease enter teacher address : ");
            fgets(teacher.address, sizeof(teacher.address), stdin);
            teacher.address[strcspn(teacher.address, "\n")] = '\0';
            fflush(stdin);

            printf("\nPlease enter teacher contact number : ");
            fgets(teacher.contact_number, sizeof(teacher.contact_number), stdin);
            teacher.contact_number[strcspn(teacher.contact_number, "\n")] = '\0';
            fflush(stdin);
        }

        fprintf(temp, "%-10d %-30s %-5d %-10s %-10d %-100s %s\n", teacher.teacher_id, teacher.name, teacher.age, teacher.gender, teacher.experience, teacher.address, teacher.contact_number);
    }

    fclose(fptr);
    fclose(temp);

    if (found)
    {
        remove("teacher.txt");
        rename("temp.txt", "teacher.txt");
        system("cls");
        printf("\nTeacher data updated successfully!!");
    }
    else
    {
        printf("\nTeacher not found.");
        remove("student.txt");
        rename("temp.txt", "teacher.txt");
    }
}

void deleteTeacher(int id)
{
    if (!id)
    {
        return;
    }
    FILE *fptr, *temp;

    fptr = fopen("teacher.txt", "r");
    temp = fopen("temp.txt", "w");
    struct Teacher teacher;

    int found = 0;
    if (fptr == NULL || temp == NULL)
    {
        printf("file not opened..");
        return;
    }

    char buffer[400];
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    while (fscanf(fptr, "%d %30[^\n] %d %10[^\n] %d %100[^\n] %s", &teacher.teacher_id, teacher.name, &teacher.age, teacher.gender, &teacher.experience, teacher.address, teacher.contact_number) != EOF)
    {
        if (teacher.teacher_id != id)
        {
            fprintf(temp, "%-10d %-30s %-5d %-10s %-10d %-100s %s\n", teacher.teacher_id, teacher.name, teacher.age, teacher.gender, teacher.experience, teacher.address, teacher.contact_number);
        }
        else
        {
            found = 1;
        }
    }

    fclose(temp);
    fclose(fptr);

    if (found)
    {
        remove("teacher.txt");
        rename("temp.txt", "teacher.txt");
        printf("\nStudent record deleted successfully\n\n");
    }
    else
    {
        remove("teacher.txt");
        rename("temp.txt", "teacher.txt");
        printf("\nStudent record not found. \n\n");
    }
}