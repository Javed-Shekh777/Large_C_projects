#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#define NUMBER 100

void main()
{
    int guessNumber, randomNumber, noOfAttemps = 0;

    srand(time(NULL));
    printf("-------------------- Welcome To You In Number Guessing Game -----------------------------------\n\n");
    randomNumber = rand() % 100 +1;

    do
    {
        printf("\nPlease enter a number between (1 to %d) : ", NUMBER);
        scanf("%d", &guessNumber);
        noOfAttemps++;
        if (guessNumber < randomNumber)
        {
            printf("\nGuess a Greter number \n");
        }
        else if (guessNumber > randomNumber)
        {
            printf("\nGuess a Lower number ");
        }
        else
        {
            printf("\n\n!!Congratulation , You have guessed successfully number. \n in %d attempts.", noOfAttemps);
        }
         

    } while (guessNumber != randomNumber);

    printf("\n\n\t\tThanks for playing the game.....");
    printf("\n\n\t\t\tDeveloped by : Javed Akhtar");
}