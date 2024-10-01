#include <stdlib.h>
#include <stdio.h>
#include "./school.h"

void main()
{
     int choice, id;
     char parameter[40];
     while (1)
     {
          printf("\n---------------------------------- SCHOOL MANAGEMENT SYSTEM -----------------------\n\n");
          printf("__________________________________________________________________________________\n");
          printf("|                                                                                 |\n");
          printf("| Student management                                                              |\n");
          printf("|\t1. Add Student.                                                           |\n");
          printf("|\t2. View Student Details.                                                  |\n");
          printf("|\t3. Edit Student Details.                                                  |\n");
          printf("|\t4. Delete Student.                                                        |\n");
          printf("| Teacher management                                                              |\n");
          printf("|\t5. Add Teacher.                                                           |\n");
          printf("|\t6. View Teacher Details.                                                  |\n");
          printf("|\t7. Edit Teacher.                                                          |\n");
          printf("|\t8. Delete Teacher.                                                        |\n");
          printf("| Attendence management                                                           |\n");
          printf("|\t9. Mark Attendence.                                                       |\n");
          printf("|\t10. View Attendence.                                                      |\n");
          printf("| Fees management                                                                 |\n");
          printf("|\t11. Add Fees.                                                             |\n");
          printf("|\t12. View Fees.                                                            |\n");
          printf("|\t13. For Exam.                                                             |\n");
          printf("|\t14. Exit.                                                                 |\n");
          printf("|_________________________________________________________________________________|\n\n");

          printf("Please enter your choice : ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               addStudent();
               break;
          case 2:
               printf("\n\nPlease enter student ID  : ");
               scanf("%d", &id);
               readStudent(id);
               break;
          case 3:
               printf("\n\nPlease enter student ID  : ");
               scanf("%d", &id);
               updateStudent(id);
               break;
          case 4:
               printf("\n\nPlease enter student ID  : ");
               scanf("%d", &id);
               deleteStudent(id);
               break;
          case 5:
               addTeacher();
               break;
          case 6:
               printf("\n\nPlease enter Teacher ID  : ");
               scanf("%d", &id);
               readTeacher(id);
               break;
          case 7:
               printf("\n\nPlease enter Teacher ID  : ");
               scanf("%d", &id);
               updateTeacher(id);
               break;
          case 8:
               printf("\n\nPlease enter Teacher ID  : ");
               scanf("%d", &id);
               deleteTeacher(id);
               break;
          case 9:
               makeAttendence();
               break;
          case 10:
               fflush(stdin);
               printf("\nPlease enter (Any one options to search data)-----\nBy class name\nBy Student id\nBy Attendence status\n : ");
               printf("\nPlease enter something from above options :");
               fgets(parameter, sizeof(parameter), stdin);
               viewAttendence(parameter);
               break;
          case 11:
               makeFees();
               break;
          case 12:
               //  printf("\n\nPlease enter Teacher ID  : ");
               // scanf("%d", &id);
               // // printf("\nPlease enter (Any one options to search data)-----\nBy class name\nBy Student id\nBy Fees status\n : ");
               // // printf("\nPlease enter something from above options :");
               // // fgets(parameter, sizeof(parameter), stdin);
               // viewFees(id);
               printf("\n\nPlease enter student ID  : ");
               scanf("%d", &id);
               viewFees(id);
               break;
          case 13:
               menu();
               break;
          case 14:
               exit(1);
               break;
          default:
               break;
          }
     }
}