#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "./school.h"
#define MAX_QUESTIONS 20


FILE *fptr = NULL;
char buffer[256] = "";

struct UserInfo
{
    char username[40];
    char password[16];
    char email[40];
};

struct QuestionInfo
{
    char question[200];
    char options[4][30];
    char correctOption;
};

struct QuestionInfo questions[MAX_QUESTIONS];
 

void menu()
{
    int choice;
    int count;
    int isLoggedIn;
    while (1)
    {
        mainMenuDisplay();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Register();
            break;
        case 2:

            isLoggedIn = Login();
            if (isLoggedIn)
            {
                int noOfQuestions = getQuestions();
                userTest(noOfQuestions);
            }
            break;
        case 3:
            CreateQuestions();
            break;
        case 4:

            count = getQuestions();
            for (int i = 0; i < count; i++)
            {
                printf("Question: %s", questions[i].question);
                printf("%s", questions[i].options[0]);
                printf("%s", questions[i].options[1]);
                printf("%s", questions[i].options[2]);
                printf("%s", questions[i].options[3]);
                printf("Correct Answer: %c\n\n", questions[i].correctOption);
            }
            getch();
            break;
        case 5:
            system("cls");
            printf("Program is closing...");
            exit(1);
        default:
            system("cls");
            printf("Invalid choice entered..\n\n\t\t\t Press any key to continue...");
            getch();
        }
    }
}

void mainMenuDisplay()
{
    system("cls");
    printf("\n\t\t\t\t---------- Welcome To Your Computer Based Test  ----------\n");

    printf("+-----------------------------------------------------------------------------------------+\n");
    printf("|                                                                                         |\n");
    printf("|*********************************Instruction********************************************|\n");
    printf("|                                                                                         |\n");
    printf("|             1 Examinee can only select one subject at a time                            |\n");
    printf("|             2 There are total %d question and each question carries equal marks of 1    |\n", MAX_QUESTIONS);
    printf("|             3 There are no negative marking                                             |\n");
    printf("|             4 Each questions are compulsory for final submission                        |\n");
    printf("|                                                                                         |\n");
    printf("|_________________________________________________________________________________________|\n");
    printf("|                                                                                         |\n");
    printf("|       Please Choose any Option...                                                       |\n");
    printf("|                                                                                         |\n");
    printf("|              1. User Register                                                           |\n");
    printf("|              2. User Login                                                              |\n");
    printf("|              3. Create Questions                                                        |\n");
    printf("|              4. Print Questions                                                         |\n");
    printf("|              5. Exit                                                                    |\n");
    printf("|                                                                                         |\n");
    printf("+-----------------------------------------------------------------------------------------+\n");
    printf("\nPlease enter your choice : ");
}

void Register()
{
    system("cls");

    char cpassword[16], psw[16] = {""};
    struct UserInfo user;
    int len = 0;

    printf("+----------------------- Welcome to User Registration ------------------------------ +\n");
    printf("Please enter following user details....\n\n");
    fflush(stdin);
    printf("Enter Username (whitesace not allowed): ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';

    printf("Enter Email : ");
    fgets(user.email, sizeof(user.email), stdin);
    user.email[strcspn(user.email, "\n")] = '\0';

    printf("Note --> Password must be greater than 5 characters..\n\n");

    do
    {
        printf("Enter Password : ");
        fgets(user.password, sizeof(user.password), stdin);
        user.password[strcspn(user.password, "\n")] = '\0';
        len = strlen(user.password);
        system("cls");

    } while (len <= 4);

    fptr = fopen("users.txt", "a");

    if (fptr == NULL)
    {
        system("cls");
        printf("\nSomething went wrong..\n\t\t while registering user...");
        exit(1);
    }

    if (fseek(fptr, 0, SEEK_END) && ftell(fptr) == 0)
    {
        fprintf(fptr, "%-20s %-30s %-15s\n", "Username", "Email", "Password");
        fprintf(fptr, "------------------------------------------------------------\n");
    }

    fprintf(fptr, "%-20s %-30s %-15s\n", user.username, user.email, user.password);

    fclose(fptr);

    system("cls");
    printf("\n\n\t\t\t\t User Registered Successfully !!!!");

    getch();
}

int Login()
{
    struct UserInfo users[20];
    char username[40], password[16];
    int counter = 0, found = 0;

    system("cls");
    printf("+----------------------- Welcome to Login Page ------------------------------ +\n");
    printf("Please enter following user details....\n\n");
    fflush(stdin);

    printf("Enter Username : ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter Password : ");
    fgets(password, sizeof(password), stdin);

    password[strcspn(password, "\n")] = '\0';

    fptr = fopen("users.txt", "r");
    if (fptr == NULL)
    {
        system("cls");
        printf("\nSomething went wrong..\n\t\t while login user...");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        char *token = strtok(buffer, " ");
        strcpy(users[counter].username, token);

        token = strtok(NULL, " ");
        strcpy(users[counter].email, token);

        token = strtok(NULL, " ");
        strcpy(users[counter].password, token);
        users[counter].password[strcspn(users[counter].password, "\n")] = '\0'; // Remove newline from password
        counter++;
    }
    fclose(fptr);

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            system("cls");
            printf("\t\t\t\t\tLogin successfuly welcome %s", users[i].username);
            found = 1;
            return found;
        }
    }
    if (!found)
    {
        system("cls");
        printf("\nInvalid username or password.");
        getch();
        return found;
    }

    return found;
}

void CreateQuestions()

{
    system("cls");

    char username[30], password[15];
    fflush(stdin);
    printf("Please Enter Username(ADMIN): ");
    scanf("%s", &username);
    fflush(stdin);
    printf("Please Enter Password : ");
    scanf("%s", &password);

    if (strcmp(username, "Javed") != 0 && strcmp(password, "12345") != 0)
    {
        system("cls");
        printf("\n\nInvlaid details entered...\n\n\t\t\tOR You are not ADMIN\n\nPress any ket to continue...");
        getch();
        return;
    }

    printf("--------------- Welcome to ADMIN DASHBOARD ------------------------\n");
    printf("-------------------------------------------------------------------\n");

    int count = 0, i, temp = 0;
    printf("\nHow many questions you want to add (max = 20) : ");
    scanf("%d", &count);

    if (count == 0)
        return;

    temp = count;

    struct QuestionInfo book[count];
    i = 0;
    while (count > 0)
    {
        fflush(stdin);
        printf("Please Enter %d question\n", i + 1);
        fgets(book[i].question, sizeof(book[i].question), stdin);
        book[i].question[strcspn(book[i].question, "\n")] = '\0';
        printf("Please Enter 4 options for %d question\n", i + 1);
        for (int j = 0; j < 4; j++)
        {

            fgets(book[i].options[j], sizeof(book[i].options[j]), stdin);
            book[i].options[j][strcspn(book[i].options[j], "\n")] = '\0';
        }
        printf("Please enter correct option number (e.g. A,B,C,D) : ");

        scanf("%c", &book[i].correctOption);

        count--;
        i++;
    }

    i = 0;
    fptr = fopen("questions.txt", "a");

    if (fptr == NULL)
    {
        printf("Something went wront...\nPress any key to continue...");
        getch();
        exit(1);
    }

    while (temp > 0)
    {

        fprintf(fptr, "%s\n", book[i].question);

        for (int j = 0; j < 4; j++)
        {

            fprintf(fptr, "%c. %s\n", 65 + j, book[i].options[j]);
        }
        fprintf(fptr, "%c\n", book[i].correctOption);
        temp--;
        i++;
    }

    fclose(fptr);
    return;
}

//  Getting All question that's are stored in question.txt file
int getQuestions()
{

    system("cls"); // To clean the screen

    int counter = 0;

    fptr = fopen("questions.txt", "r");

    if (fptr == NULL)
    {
        printf("Something went wrong..");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fptr))
    {
        // Read the question
        strcpy(questions[counter].question, buffer);

        // Read option A
        fgets(buffer, sizeof(buffer), fptr);
        strcpy(questions[counter].options[0], buffer);

        // Read option B
        fgets(buffer, sizeof(buffer), fptr);
        strcpy(questions[counter].options[1], buffer);

        // Read option C
        fgets(buffer, sizeof(buffer), fptr);
        strcpy(questions[counter].options[2], buffer);

        // Read option D
        fgets(buffer, sizeof(buffer), fptr);
        strcpy(questions[counter].options[3], buffer);

        // Read the correct answer (like 'A', 'B', 'C', or 'D')
        fgets(buffer, sizeof(buffer), fptr);
        sscanf(buffer, "%c", &questions[counter].correctOption);

        counter++;
    }

    if (counter > 0)
    {
        return counter;
    }
    return counter;
}

void userTest(int noOfQuestions)
{
    system("cls"); // To clean the screen

    char answer;
    int wrongAns[noOfQuestions];
    char wrongOptions[noOfQuestions];

    printf("\n\n Total Questions  : %d\n\n", noOfQuestions);
    int score = 0;
    int i, j;

    for (i = 0; i < noOfQuestions; i++)
    {
        wrongAns[i] = -1; // Initializing whole array with value of  -1
    }

    for (i = 0; i < noOfQuestions; i++)
    {

        printf("\t\nQ%d: %s\n", i + 1, questions[i].question); // Printing question

        for (j = 0; j < 4; j++) // Printing all options
        {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %C", &answer);

        system("cls"); // To clean the screen ans remove previous question and reply

        char capans = toupper(answer); // converting answer to uppercase

        if (capans == questions[i].correctOption) // checking that answer is right or wrong
        {
            score++; // Incrementing the score of user
        }
        else
        {
            wrongAns[i] = 1; // Storing wrong ans answers
            wrongOptions[i] = capans;
        }
    }

    char yesNo;
    printf("\n             *Congratulation! For completion of sectional CBT *               \n\n");
    printf("If you want to review your test/exam ");
    printf("then press 'Y' otherwise 'N': ");
    fflush(stdin);
    scanf("%c", &yesNo);
    fflush(stdin);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        reviewQuestions(wrongAns, wrongOptions, noOfQuestions,score); // Review Questions function calling
    }
    else
    {
        return;
    }

    return;
}

void reviewQuestions(int wrongAnswers[], char wrongOptions[], int noOfQuestions,int score)
{
    system("cls");
    printf("\n________________________________ Review Your Answers ______________________________________\n\n");
    int i;

    for (int i = 0; i < noOfQuestions; i++)
    {
        
        printf("\nQ%d. %s\n", i+1,questions[i].question);
        for (int j = 0; j < 4; j++)
        {
        printf("%s                                                                          \n", questions[i].options[j]);
        }
        printf("+____________________________________________________________________________________________+\n");
        if (wrongAnswers[i] == 1)
        {
        printf("+ Wrong Answer is :%c                                                  Correct Option : %c     +\n", wrongOptions[i], questions[i].correctOption);
        }
        else
        {
        printf("+                                                                      Correct Option : %c    +\n", questions[i].correctOption);
        }
        printf("+____________________________________________________________________________________________+\n\n");
    }

    char yesNo;
    printf("\n__________________________________________________________________________________________________\n\n");
    printf("If you want to generate your marsheet ");
    printf("then press 'Y' otherwise 'N': ");
    fflush(stdin);
    scanf("%c", &yesNo);
    fflush(stdin);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        generate_marksheet(score); // Marksheet Printing function calling
    }
    else
    {
        return;
    }
}

// Generating result/ Marksheet for user
void generate_marksheet(int totalScore)
{
	system("cls");
    int percentage, incans;
    char persign = '%';
    percentage = (totalScore * 100) / 20;
    incans = 20 - totalScore;

    // A Frame to print the marksheet
    printf("\n\n\n|************************************************************************************|\n");
    printf("|                                    RESULT                                          |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("|                               COMPUTER BASED TEST                                  |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                       SECTIONAL PRACTICE ZONE-WISE RESULT                          |\n");
    printf("|====================================================================================|\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                Detailed - Report                                   |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Total Questions                                             20               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Total Attempt                                               20               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Correct Answers                                              %d               |\n", totalScore);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Incorrect Answers                                            %d              |\n", incans);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Marks obtained                                             %d/20              |\n", totalScore);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Percentage                                                  %d%c              |\n", percentage, persign);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");

    /// Checking for grades
    if (percentage >= 81 && percentage <= 100)
    {
        printf("|                   RESULT : PASS IN FIRST DIVISION                                  |\n");
        printf("|                   GRADE  : A+                                                      |\n");
    }
    if (percentage >= 60 && percentage <= 80)
    {
        printf("|                   RESULT : PASS IN FIRST DIVISION                                  |\n");
        printf("|                   GRADE  : A                                                       |\n");
    }
    else if (percentage >= 41 && percentage <= 59)
    {
        printf("|                   RESULT : PASS IN SECOND DIVISION                                 |\n");
        printf("|                   GRADE  : B                                                       |\n");
    }
    else if (percentage >= 31 && percentage <= 40)
    {
        printf("|                   RESULT : PASS IN THIRD DIVISION                                  |\n");
        printf("|                   GRADE  : C                                                       |\n");
    }
    else if (percentage >= 1 && percentage <= 30)
    {
        printf("|                   RESULT : Fail                                                    |\n");
        printf("|                   GRADE  : D                                                       |\n");
    }
    printf("|                                                                                    |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                               (JA AUTHORITY)       |\n");
    printf("|                                                              Er. Javed Akhtar      |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|            This CBT result digitally Verified with dedicated server!               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|    You can take your retest for same or another section!! Best Regards for future  |\n");
    printf("|____________________________________________________________________________________|\n\n\n");
    getch();
}
