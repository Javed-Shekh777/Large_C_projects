#include <stdlib.h>
#include <stdio.h>
#include "./school.h"

void main()
{
     int choice, id;
     while (1)
     {
          printf("\n---------------------------------- SCHOOL MANAGEMENT SYSTEM -----------------------\n\n");
          printf("_________________________________________________________________________________+\n");
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
          printf("| Course management                                                               |\n");
          printf("|\t9. For Exam.                                                            |\n");
          printf("|\t10. Add Course.                                                            |\n");
          printf("|\t11. Update Course.                                                        |\n");
          printf("|\t12. Delete Course.                                                        |\n");
          printf("|\t13. View Avalable Courses.                                                |\n");
          printf("|\t14. Assign Course to Teacher.                                             |\n");
          printf("|\t15. Assign Course to Student.                                             |\n");
          printf("|\t16. Exit.                                                                 |\n");
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
               menu();
               break;
          case 10:
               break;
          case 11:
               break;
          case 12:
               break;
          case 13:
               break;
          case 14:
               break;
          case 16:
               exit(1);
               break;
          default:
               break;
          }
     }
}