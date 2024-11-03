#include <stdio.h>
#include <string.h>

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
int attempts = 0;

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
    attempts++;
    
}
printf("You guess it. good job.\n");
printf("This many attempts: %d", attempts);

return 0;
}