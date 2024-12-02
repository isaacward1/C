/*
 * COP 3515
 * Homework #1
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {

FILE *files[3];
char filelist[3][50] = {"Proposed passwords #1.txt", "Proposed passwords #2.txt", "Proposed passwords #3.txt"};
for (int i = 0; i < 3; i++) { files[i] = fopen(filelist[i], "r"); }

if (files[0]  == NULL || files[1]  == NULL || files[2] == NULL) // test if files can be opened
{
    printf("something went wrong");
    return 1;
}

for (int a = 0; a < 3; a++) // for each file
{

const int maxLeng = 200;
char line[maxLeng];
int flags[7] = {0};
int f = 0;
bool allowPassphrase = true;
bool allowOptional = true;

    while(fgets(line, maxLeng, files[a])) { // while there are lines in the file

        if (line[0] >= 48 && line[0] <= 57)
        {
            flags[f] = atoi(line);
            f++;
        }
    }
    // print the reqs
    printf("\n--- Processing password file #%d ---\n", a+1);
    printf("Maximum password length: %d\n", flags[0]);
    printf("Minimum password length: %d\n", flags[1]);
    if (flags[2] == 0)
    {
        printf("Pass phrases are NOT allowed\n");
        allowPassphrase = false;

        if (flags[3] == 0)
        {
            printf("Optional Tests are NOT allowed\n");
            allowOptional = false;
        }
        else
        {
            printf("Optional Tests are accepted\n");
        }
    }
    else
    {
        printf("Pass phrases are accepted\n");
        
        if (flags[4] == 0)
        {
            printf("Optional Tests are NOT allowed\n");
            allowOptional = false;
        }
        else
        {
            printf("Optional Tests are accepted\n");
        }
    }
    printf("-----------------------------------\n");

// 2nd round; evaluate passwords

fclose(files[a]);
files[a] = fopen(filelist[a], "r");

while(fgets(line, maxLeng, files[a])) {
if (line[0] > 57) {

printf("\nPotential password: %s", line);


int failedTests[8] = {0};
int passedTests[8] = {0};
passedTests[2] = 3;

int numPassed = 1;

bool hasLetter = false;
bool hasNum = false;
bool hasSym = false;

int lineLength = strlen(line) - 2;

if (allowPassphrase == false && allowOptional == false) { // normal password start

if (lineLength >= flags[1]) // test #1
{ 
    passedTests[0] = 1; numPassed++;
} else
{
    failedTests[0] = 1;
printf("The password must be at least %d characters long.\n", flags[1]);
}

if (lineLength <= flags[0]) // test #2
{
    passedTests[1] = 2;
    numPassed++;
} else
{
failedTests[1] = 2;
printf("The password must be fewer than %d characters.\n", flags[0]);
}  

for (int p = 0; p < strlen(line) - 2; p++) // test #3
{
if (line[p] == line[p+1] && line[p+2] == line[p+1])
{
printf("The password may not contain sequence of three or more repeated characters.\n");
failedTests[2] = 3;
passedTests[2] = 0;
numPassed--;
break;
}
}

for (int p = 0; p < strlen(line); p++) { // test #4
if (isalpha(line[p])) {hasLetter = true;}
if (isdigit(line[p])) {hasNum = true;}
if (ispunct(line[p])) {hasSym = true;}
}
if (hasLetter && hasNum && hasSym)
{
    passedTests[3] = 4; 
    numPassed++;
} else
{
    failedTests[3] = 4;
    printf("The password must contain letters, numbers, AND symbols.\n");
}

printf("Failed tests: ");
    for (int i = 0; i < 8; i++) {
        if (failedTests[i] != 0)
        printf("[%d] ", failedTests[i]);
    } printf("(%d/4)\n", 4 - numPassed);

       printf("Passed tests: ");
    for (int i = 0; i < 8; i++) {
        if (passedTests[i] != 0)
        printf("[%d] ", passedTests[i]);
    } printf("(%d/4)\n", numPassed);

printf("Is a Pass phrase?: false\n");
if (numPassed != 4) {printf ("Strong?: false\n");} 
else {printf ("Strong?: true\n");}

} // normal password end


else // allow passphrases; allow optional tests
{
bool isStrong = false;
int MinTestsToPass = flags[5];


if (strchr(line, ' ')) // if this is a passphrase, do some shit
{
if (lineLength >= flags[3]) // if passphrase is greater than min chars
{    
isStrong = true;
}
else
{
printf("The Pass phrase must be at least %d characters long.\n", flags[3]);
}
printf("Is a Pass phrase?: true\n");
if (isStrong == true) {printf ("Strong?: true\n");} 
else {printf ("Strong?: false\n");}

}


else // if it's not a passphrase, eval for options
{
isStrong = true;
int opTestsPassed = 0;

int oneLower = 0;
int oneUpper = 0;
int twoDigits = 0;
int twoSpecials = 0;

if (lineLength >= flags[1]) // test #1
{ 
    passedTests[0] = 1; numPassed++;
} else
{
    failedTests[0] = 1;
    isStrong = false;
    printf("The password must be at least %d characters long.\n", flags[1]);
}

if (lineLength <= flags[0]) // test #2
{
    passedTests[1] = 2; numPassed++;
} else
{
    failedTests[1] = 2;
    isStrong = false;
    printf("The password must be fewer than %d characters.\n", flags[0]);
}  

for (int p = 0; p < strlen(line) - 2; p++) // test #3
{
if (line[p] == line[p+1] && line[p+2] == line[p+1])
{
printf("The password may not contain sequence of three or more repeated characters.\n");
isStrong = false;
failedTests[2] = 3;
passedTests[2] = 0;
numPassed--;
break;
}

}

for (int p = 0; p < strlen(line); p++) { // test #4
if (isalpha(line[p])) {hasLetter = true;}
if (isdigit(line[p])) {hasNum = true;}
if (ispunct(line[p])) {hasSym = true;}
}
if (hasLetter && hasNum && hasSym)
{
    passedTests[3] = 4; 
    numPassed++;
} else
{
    failedTests[3] = 4;
    isStrong = false;
    printf("The password must contain letters, numbers, AND symbols.\n");
}

// test #5,6,7,8

for (int i = 0; i < strlen(line); i++) {
    if (97 <= (line[i]) && 122 >= (line[i])){oneLower += 1;}
    if (65 <= (line[i]) && 90 >= (line[i])){oneUpper += 1;}
    if (isdigit(line[i])){twoDigits += 1;}
    if (ispunct(line[i])){twoSpecials += 1;}
}

if (oneLower != 0) {passedTests[4] = 5; numPassed++; opTestsPassed++;} 
else {failedTests[4] = 5; printf("The password must contain at least one lowercase letter.\n");}

if (oneUpper != 0) {passedTests[5] = 6; numPassed++; opTestsPassed++;} 
else {failedTests[5] = 6; printf("The password must contain at least one uppercase letter.\n");}

if (twoDigits >= 2) {passedTests[6] = 7; numPassed++; opTestsPassed++;} 
else {failedTests[6] = 7; printf("The password must contain at least two numbers.\n");}

if (twoSpecials >= 2) {passedTests[7] = 8; numPassed++; opTestsPassed++;} 
else {failedTests[7] = 8; printf("The password must contain at least two special characters.\n");}

printf("Failed tests: ");
    for (int i = 0; i < 8; i++) {
        if (failedTests[i] != 0)
        printf("[%d] ", failedTests[i]);
    } printf("(%d/8)\n", 8 - numPassed);

       printf("Passed tests: ");
    for (int i = 0; i < 8; i++) {
        if (passedTests[i] != 0)
        printf("[%d] ", passedTests[i]);
    } 
    printf("(%d/8)\n", numPassed);

printf("Is a Pass phrase?: false\n");
if (isStrong == true && (opTestsPassed >= MinTestsToPass)) 
{printf ("Strong?: true\nTotal optional tests passed: %d\n", opTestsPassed);} 
else {printf ("Strong?: false\nTotal optional tests passed: %d (%d Required)\n", opTestsPassed, MinTestsToPass);}

}

} // passphrase/optional tests end

        }
    }
}

fclose(files[0]); fclose(files[1]); fclose(files[2]); return 0;
} // holy mess
