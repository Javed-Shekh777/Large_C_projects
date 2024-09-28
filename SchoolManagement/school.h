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

// Structure for Teacher
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

// Structure for Attendence
struct Attendence
{
    int student_id; // Semicolon instead of comma
    char student_name[40];
    char class_name[40];
    char date[15];
    char status[10];
};

// Structure for Fees
struct Fees
{
    int student_id; // Semicolon instead of comma
    char student_name[40];
    char class_name[40];
    int total_amount;
    int paid_amount;
     char date[15];
    char status[10];
};

//  Student functions (student.c)
void addStudent();
void readStudent(int);
void updateStudent(int);
void deleteStudent(int);

// Teacher functions (teacher.c)
void addTeacher();
void readTeacher(int);
void updateTeacher(int);
void deleteTeacher(int);

// Exam functions (exam.c)
void menu();
// void Register();
// void mainMenuDisplay();
// int Login();
// void CreateQuestions();
// int getQuestions();
// void userTest(int);
// void generate_marksheet(int);
// void reviewQuestions(int[], char[], int,int);

// Attendence functions (attendence.c)
void makeAttendence();
void viewAttendence(char[]);

// Fees functions (attendence.c)
void makeFees();
void viewFees(char[]);

#endif
