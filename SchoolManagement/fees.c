#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "./school.h"

void makeFees()
{
    char class[40], date[15];
    int total;

    fflush(stdin);
    printf("\nPlease enter your class name : ");
    fgets(class, sizeof(class), stdin);
    class[strcspn(class, "\n")] = '\0';

    fflush(stdin);
    printf("\nEnter Date (DD-MM-YYYY): ");
    fgets(date, sizeof(date), stdin);
    class[strcspn(date, "\n")] = '\0';

    fflush(stdin);
    printf("\nEnter total amount of fees: ");
    scanf("%d", &total);

    int i, size;

    printf("\nHow many students Fees you want to add : ");
    scanf("%d", &size);
    struct Fees fees[size];
    FILE *fptr;
    fptr = fopen("fees.txt", "a");
    if (fptr == NULL)
    {
        printf("File not oepned...");
        return;
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fprintf(fptr, "%-10s %-30s %-30s %-15s %-10s %-10s %s\n", "Student_ID", "Student_Name", "Class_Name", "Date", "Total_mount", "Paid_amount", "Status");
        fprintf(fptr, "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < size; i++)
    {

        printf("\n\nEnter %d student fees details...\n", i + 1);
        fflush(stdin);
        printf("\nPlease enter student id : ");
        scanf("%d", &fees[i].student_id);

        fflush(stdin);
        printf("\nPlease enter student name : ");
        fgets(fees[i].student_name, sizeof(fees[i].student_name), stdin);
        fees[i].student_name[strcspn(fees[i].student_name, "\n")] = '\0';

        fflush(stdin);
        printf("\nPlease enter paid amount : ");
        scanf("%d", &fees[i].paid_amount);

        strcpy(fees[i].class_name, class);
        fees[i].class_name[strcspn(fees[i].class_name, "\n")] = '\0';
        strcpy(fees[i].date, date);
        fees[i].date[strcspn(fees[i].date, "\n")] = '\0';
        fees[i].total_amount = total;
        if (fees[i].total_amount == fees[i].paid_amount)
        {
            strcpy(fees[i].status, "PAID");
        }
        else if (fees[i].total_amount >= fees[i].paid_amount)
        {
            strcpy(fees[i].status, "PENDING");
        }

        system("cls");
    }

    for (i = 0; i < size; i++)
    {
        fprintf(fptr, "%-10d %-30s %-30s %-15s %-10d %-10d %s\n", fees[i].student_id, fees[i].student_name, fees[i].class_name, fees[i].date, fees[i].total_amount, fees[i].paid_amount, fees[i].status);
    }
    fclose(fptr);

    printf("\n\nStudent Fees has been filled successfully!!!");
}

void viewFees(int id)
{
    // system("cls");

    if (!id)
    {
        return;
    }

    FILE *fptr;
    fptr = fopen("fees.txt", "r");
    if (fptr == NULL)
    {
        printf("\nFile not oepned....");
        return;
    }

    struct Fees fees;

    char buffer[300];
    int found = 0;
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    //  "%d %30[^\n] %d %10[^\n] %d %40[^\n] %90[^\n] %s"

    // %-10d %-30s %-30s %-15s %-10d %-10d %s

    while (fscanf(fptr, "%d %30[^\n] %30[^\n] %10[^\n] %d %d %s", &fees.student_id, fees.student_name, fees.class_name, fees.date, &fees.total_amount, &fees.paid_amount, fees.status) != EOF)
    {
        if (fees.student_id == id)
        {
            system("cls");
            found = 1;
            printf("\n\nStudent Fees Record found..\n\n");
            printf("|----------------------------------------------------------------------------------------------------------------------------------------|\n");
            printf("| %-10s | %-30s | %-30s | %-15s | %-10s | %-10s |  %s  |\n", "Student_ID", "Student_Name", "Class_Name", "Date", "Total_amount", "Paid_amount", "Status");
            printf("|________________________________________________________________________________________________________________________________________|\n");
            printf("| %-10d | %-30s | %-30s | %-15s |     %d     |    %d     | %-9s|\n", fees.student_id, fees.student_name, fees.class_name, fees.date, fees.total_amount, fees.paid_amount, fees.status);
            printf("|----------------------------------------------------------------------------------------------------------------------------------------|\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent record not found of %d ", id);
        getch();
    }
    getch();
}

// strcmp(fees.class_name, parameter) == 0 || strcmp(fees.status, parameter) == 0