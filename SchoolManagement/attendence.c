#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "./school.h"

void makeAttendence()
{
    char class[40], date[15];

    fflush(stdin);
    printf("\nPlease enter your class name : ");
    fgets(class, sizeof(class), stdin);
    class[strcspn(class, "\n")] = '\0';

    fflush(stdin);
    printf("\nEnter Date (DD-MM-YYYY): ");
    fgets(date, sizeof(date), stdin);
    class[strcspn(date, "\n")] = '\0';

    int i, size;

    printf("\nHow many students attendence you want to add : ");
    scanf("%d", &size);
    struct Attendence attendence[size];
    FILE *fptr;
    fptr = fopen("attendence.txt", "a");
    if (fptr == NULL)
    {
        printf("File not oepned...");
        return;
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fprintf(fptr, "%-10s %-30s %-30s %-15s %-10s\n", "Student_ID", "Srudent_Name", "Class_Name", "Date", "Status");
        fprintf(fptr, "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < size; i++)
    {
        fflush(stdin);
        printf("\nPlease enter student id : ");
        scanf("%d", &attendence[i].student_id);

        fflush(stdin);
        printf("\nPlease enter student name : ");
        fgets(attendence[i].student_name, sizeof(attendence[i].student_name), stdin);
        attendence[i].student_name[strcspn(attendence[i].student_name, "\n")] = '\0';

        fflush(stdin);
        printf("\nPlease enter student attendence (Present/Absent) : ");
        fgets(attendence[i].status, sizeof(attendence[i].status), stdin);
        attendence[i].status[strcspn(attendence[i].status, "\n")] = '\0';

        strcpy(attendence[i].class_name, class);
        strcpy(attendence[i].date, date);
        system("cls");
    }

    for (i = 0; i < size; i++)
    {
        fprintf(fptr, "%-10d %-30s %-30s %-15s %-10s\n", attendence[i].student_id, attendence[i].student_name, attendence[i].class_name, attendence[i].date, attendence[i].status);
    }
    fclose(fptr);

    printf("\n\nStudent attendence has been done successfully!!!");
}

void viewAttendence(char parameter[])
{
    system("cls");
    if (strcmp(parameter, ""))
    {
        return;
    }
    FILE *fptr;
    fptr = fopen("attendence.txt", "r");
    if (fptr == NULL)
    {
        printf("\nFile not oepned....");
        return;
    }

    if (fseek(fptr, 0, SEEK_END) && ftell(fptr) == 0)
    {
        printf("\nI am sorry no data is available in attendence file\n");
        getch();
        return;
    }

    struct Attendence attendence;

    char buffer[300];
    int found = 0;
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    printf("\n| %-10d %-30s %30s %15s %s |\n", "Student_ID", "Student_Name", "Class_Name", "Date", "Status");
    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

    while (fscanf(fptr, "%d %30[^\n] %30[^\n] %15[^\n] %s", &attendence.student_id, attendence.student_name, attendence.class_name, attendence.date, attendence.status) != EOF)
    {

        if (
            strcmp(attendence.class_name, parameter) == 0 || strcmp(attendence.status, parameter) == 0)
        {
            found = 1;
            printf("| %-10d |%-30s |%30s |%15s %s |\n", attendence.student_id, attendence.student_name, attendence.class_name, attendence.date, attendence.status);
        }
        printf("|________________________________________________________________________________________________________________________________________________________________________|\n");
    }

    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n\n");

    if (!found)
    {
        printf("\nStudent record not found of %s ", parameter);
        getch();
    }
    getch();
}