#ifndef SCHOOL_H
#define SCHOOL_H

// Structure for student
struct Student
{
    int student_id;
    char name[40];
    int age;
    int Class;
    char address[100];
    char contact_number[13];
};

struct Teacher
{
    int teacher_id;
    char name[40];
    int age;
    char gender[7];
    int experience;
    char address[100];
    char contact_number[13];
};

// Function prototypes
void addStudent();
void readStudent(int);
void updateStudent(int);
void deleteStudent(int);
void addTeacher();
void readTeacher(int);
void updateTeacher(int);
void deleteTeacher(int);


void Register();
void mainMenuDisplay();
int Login();
void CreateQuestions();
int getQuestions();
void userTest(int);
void generate_marksheet(int);
void reviewQuestions(int[], char[], int,int);

#endif
