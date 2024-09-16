#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {

printf("Multiplication Table:\n");

for (int d = 1; d <= 12; d++)
{
    for (int i = 1; i <= 12; i++)
    {
        printf("%4d", i * d);
    }
     printf("\n");
}
printf("\n");

int userGuess;
int guessAnswer = (rand() % 10) + 1; // **rand() is not seeded so always returns same "random" number

while (userGuess != guessAnswer)
{
    printf("Enter your guess (1-10): "); scanf ("%d", &userGuess);
    if (userGuess > guessAnswer)
    {
        printf("Too high!\n");
    }
    if (userGuess < guessAnswer)
    {
        printf("Too low!\n");
    }
    
}
printf("You guess it. good job.\n");

return 0;
}