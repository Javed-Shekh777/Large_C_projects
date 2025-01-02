#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

 

float balance = 1000.0; // Initial balance
 

void login();
void menu();
void checkBalance();
void withdraw();
void deposite();

void main()
{
     printf("Welcome to the ATM Simulation!\n");
    login();  // User login
    menu(); // Show the menu options
}

void menu()
{
    int choice;

    do
    {

        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            checkBalance();
            break;
        case 2:
            system("cls");
            deposite();
            break;
        case 3:
            system("cls");
            withdraw();
            break;
        case 4:
            system("cls");
            printf("Thank you for using the ATM. Goodbye!\n");
            break;
        default:
            system("cls");
            printf("Wrong choice entered...");
        }
    }while (choice != 4);
    
}

void login(){
    char correct_password[] = "1234";
    char entered_password[20];
    int i = 0;
    char ch;
    printf("\nPlease enter 4 digit ATM PIN : ");

      while (1) {
        ch = getch(); 
        if (ch == '\r') { // If Enter is pressed
            entered_password[i] = '\0';
            break;
        } else if (ch == '\b') { // Handle Backspace
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            entered_password[i++] = ch;
            printf("*"); // Show '*' for each entered character
        }
    }

     if (strcmp(correct_password, entered_password) == 0) {
        printf("\nLogin successful!\n");
    } else {
        printf("\nIncorrect PIN. Try again.\n");
        login(); // Retry login
    }
}

void checkBalance()
{
    printf("You current Balance is : %f", balance);
}

void withdraw() {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Please collect your cash. Remaining balance: Rs%.2f\n", balance);
    } else if (amount > balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid amount. Try again.\n");
    }
}

void deposite()
{
    float amount;
    printf("How many money you want to Deposit : ");
    scanf("%f",&amount);
    if (amount > 0) {
        balance += amount;
        printf("Amount deposited successfully. New balance: Rs%.2f\n", balance);
    } else {
        printf("Invalid amount. Try again.\n");
    }

}