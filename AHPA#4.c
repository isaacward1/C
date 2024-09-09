
#include <stdio.h>
#include <string.h>


int withdraw_amt; // global var

// atm machine algo func, holy mess
int machine_alg() {
    int temp = withdraw_amt;
        if (temp > 100)
        {
            temp -= 100;
            printf("$100 bill\n");
        }
        if (temp >= 100)
        {
            temp -= 100;
            printf("$100 bill\n");
        }
        if (temp > 50)
        {
            temp -= 50;
            printf("$50 bill\n");
        }
        if (temp > 20)
        {
            temp -= 20;
            printf("$20 bill\n");
        }
        if (temp > 20)
        {
            temp -= 20;
            printf("$20 bill\n");
        }
        if (temp > 20)
        {
            temp -= 20;
            printf("$20 bill\n");
        }
        if (temp > 20)
        {
            temp -= 20;
            printf("$20 bill\n");
        }
        if (temp > 10)
        {
            temp -= 10;
            printf("$10 bill\n");
        }
        if (temp > 5)
        {
            temp -= 5;
            printf("$5 bill\n");
        }
        if (temp >= 1)
        {
            temp -= 1;
            printf("$1 bill\n");
        }
        if (temp >= 1)
        {
            temp -= 1;
            printf("$1 bill\n");
        }
        if (temp >= 1)
        {
            temp -= 1;
            printf("$1 bill\n");
        }
        if (temp >= 1)
        {
            temp -= 1;
            printf("$1 bill\n");
        }
        if (temp >= 1)
        {
            temp -= 1;
            printf("$1 bill\n");
        }
}

// main func
int main() {

char person_name;
char account_name;
int total_left;

// person a checking, savings is row 0
int accounts[2][2] = 
{500, 1000, 
750, 325};

printf("Enter your name: "); scanf(" %c", &person_name);
printf("%c\n\n", person_name);

printf("Would you like to withdraw from (c)hecking or (s)avings?: "); scanf(" %c", &account_name);
printf("%c\n\n", account_name);

printf("How much would you like to withdraw?: "); scanf(" %d", &withdraw_amt);
printf("%d\n\n", withdraw_amt);

// check if withdraw amount is 200 or less, if not set to 200
if (withdraw_amt > 200)
{
    printf("The maximum withdraw amount is $200; Defaulting to $200\n\n");
    withdraw_amt = 200;
}

// call atm machine alg
machine_alg();

// account selection for deduction
switch (person_name)
{
case 'a':
    switch (account_name)
    {
    case 'c':
        // guy has 500 in this acc
        total_left = accounts[0][0] - withdraw_amt;
        break;
    case 's':
        // guy has 1000 in this acc, cha-ching
        total_left = accounts[0][1] - withdraw_amt;
        break;
    }
    break;
case 'b':
    switch (account_name)
    {
    case 'c':
        // guy has 750 in this acc
        total_left = accounts[1][0] - withdraw_amt;
        break;
    case 's':
        // guy has 325 in this acc
        total_left = accounts[1][1] - withdraw_amt;
        break;
    }
    break;
}

printf("Amount in account after withdrawl: $%d\n\n", total_left);

return 0;
}
