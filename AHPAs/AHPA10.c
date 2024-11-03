#include <stdio.h>
#include <string.h>

int main(void) {

int theArray[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int num1; int num2; int num3;
int sumArray = 0;
int *p;
p = &theArray[0];

for (int i = 1; i < 10; i++)
{
    sumArray += p[i];
}
p[0] = sumArray;

printf("Enter a number: "); scanf (" %d", &num1);
printf("Enter a number: "); scanf (" %d", &num2);
printf("Enter a number: "); scanf (" %d", &num3);

printf("\nOriginal array contents:\n");
for (int i = 0; i < 10; i++)
{
    printf("%d ", p[i]);
}

p[3] = num1;
p[6] = num2;
p[9] = num3;

sumArray = 0;
for (int i = 1; i < 10; i++)
{
    sumArray += p[i];
}
p[0] = sumArray;


printf("\nUpdated array contents:\n");
for (int i = 0; i < 10; i++)
{
    printf("%d ", p[i]);
}

return 0;
}