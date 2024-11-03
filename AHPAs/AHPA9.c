#include <stdio.h>
#include <string.h>


void refillRequest(int tankNum);
void carArrived(int pumpNum);

char fillYesNo;
int pumpNum;
int tankVols[4] = {100, 75, 50, 150};

void refillRequest(int tankNum) {
    switch (tankNum)
    {
    case 0:
        tankVols[tankNum] = 100;
        break;
    case 1:
        tankVols[tankNum] = 75;
        break;
    case 2:
        tankVols[tankNum] = 50;
        break;
    case 3:
        tankVols[tankNum] = 150;
        break;
    } 
}

void carArrived(int pumpNum) {
    int tankNum = pumpNum - 1;
    printf("\nUsing pump #%d...\n\n", pumpNum);
    tankVols[tankNum] -= 10;
}

int main() {

printf("\n");

for (;;)
{
printf("Would you like to fill your tank? (y/n): "); scanf (" %c", &fillYesNo);
if (fillYesNo == 'n') {break;}
printf("What pump would you like to use (1-4): "); scanf (" %d", &pumpNum);

carArrived(pumpNum);

for (int i = 0; i < 4; i++)
{

    if (tankVols[i] < 20)
    {
        refillRequest(i);
        printf("Refilling tank #%d...\n", i + 1);
    }
    printf("Current volume for tank #%d: %d\n", i+1, tankVols[i]);
    
}
printf("\n");
}

return 0;
}       