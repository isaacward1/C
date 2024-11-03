/*
* COP 3515 – Fall Semester 2024
*
* Homework #2: Spotting The Hacker
*
* Isaac Ward
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define maxLeng 200
char line[maxLeng];

void parity_func (FILE *wh_file) {
int lc = 1;
while(fgets(line, maxLeng, wh_file)) { // for each line of the file
    char *token = strtok(line, " ");
    int bytes[10] = {};
    char bits[10][9];
    int numOnes;

    int count = 0;
    while (token != NULL) { // transmission and parity bytes
        bytes[count] = atoi(token);
        token = strtok(NULL, " ");
        count++;
    }

    printf("--------------------------------------------------\n");
    printf("Transmission line number: %d\n", lc);
    printf("Data stream: "); for (int i = 0; i < 8; i++) {printf("%d ", bytes[i]);}
    printf("\n");
    printf("Parity byte: %d\n", bytes[8]);
    printf("--------------------------------------------------\n");

// deciding bits and bytes
for (int i = 0; i < 9; i++) { // for each number in the line
    int temp = bytes[i];

    for (int a = 0; a < 8; a++) // for 8 bits of the number, assign 0 or 1
        {
            int x = 1 << (7-a); // raise 2 to the power of a, starts at 2^7
            if (temp >= x)
            {
                temp -= x;
                bits[i][a] = 1;
            } else {
            bits[i][a] = 0; }
        }
}

// display
for (int s = 0; s < 8; s++) {
    int numOnes = 0;
    for (int h = 0; h < 8; h++)
    {
        if (bits[s][h] == 1)
        {
            numOnes++;
        }
    }
    
    printf("data item = %d, ", bytes[s]);
    printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", bits[s][b]);}
    printf("\n");

    int lastBit = bits[8][s];
    // printf("%d + %d = %d\n", numOnes, lastBit, numOnes + lastBit);
    if ((numOnes + lastBit) % 2 == 1) {printf("Error in transmission byte %d\n\n", s + 1);} 
    else {printf("No error in transmission byte %d\n\n", s + 1);}
} 
lc++;

} // for each line of the file

}

void checksum_func (FILE *wh_file) {
int lc = 1;
while(fgets(line, maxLeng, wh_file)) { // for each line of the file
    char *token = strtok(line, " ");
    int bytes[12] = {};
    char bits[12][9];
    int sumItems = 0;
    int remain;
    int afterAdd;

    int count = 0;
    while (token != NULL) { // transmission and checksum bytes
        bytes[count] = atoi(token);
        token = strtok(NULL, " ");
        count++;
    }
    
    for (int d = 0; d < 8; d++){sumItems += bytes[d];}
    bytes[9] = sumItems;
    remain = bytes[9] % 256;
    afterAdd = remain + bytes[8];
    bytes[10] = afterAdd;

    printf("--------------------------------------------------\n");
    printf("Transmission line number: %d\n", lc);
    printf("Data stream: "); for (int i = 0; i < 8; i++) {printf("%d ", bytes[i]);}
    printf("\n");
    printf("Checksum: %d\n", bytes[8]);
    printf("--------------------------------------------------\n");

// deciding bits and bytes
for (int i = 0; i < 11; i++) { // for each number in bytes (data + checksum + final sum)
    int temp = bytes[i] & 255;
    
    for (int a = 0; a < 8; a++) // for 8 bits of the number, assign 0 or 1
        {
            int x = 1 << (7-a); // raise 2 to the power of a, starts at 2^7
            if (temp >= x)
            {
                temp -= x;
                bits[i][a] = 1;
            } else {
            bits[i][a] = 0; }
        }
}


// display
for (int s = 0; s < 8; s++) {

    printf("parityData[%d] = %d, ", s, bytes[s]);
    printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", bits[s][b]);}
    printf("\n");
}

/* only the last 8 bits of the sum binary 
are used and tested against the checksum, thus i did
not print the entire binary for each sum */ 
printf("\n(Sum of data items = %d)\n", bytes[9]);
printf("%d mod 256 = %d, ", bytes[9], remain);
printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", bits[9][b]);}
printf("\n");
printf("Checksum value = %d, ", bytes[8]);
printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", bits[8][b]);}
printf("\n\n");
printf("Sum after adding checksum = %d, ", afterAdd);
printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", bits[10][b]);}
printf("\n");
printf("Sum after complement = %d, ", afterAdd ^ 255);
printf("binary = "); for (int b = 0; b < 8; b++) {printf("%d", (bits[10][b] ^ 1));}
printf("\n\n");

if (afterAdd ^ 255 == 0)
{
    printf("Checksum: No errors in transmission line %d\n\n", lc);
} else {printf("Checksum: Errors found in transmission line %d\n\n", lc);}

lc++;
} // for each line of the file

}

void twodim_parity_func (FILE *wh_file) {

int gridc = 0;
int bytes[5][10][10] = {};
int bits[8][8] = {};
int vertParityByte;
int horizParityByte;
int checkParityByte;

while (gridc < 5) {
int row = 0;

    while (fgets(line, maxLeng, wh_file) && row < 8) {
    char *token = strtok(line, " ");
    int column = 0;

    while (token != NULL && column < 10) {
        bytes[gridc][row][column] = atoi(token);
        token = strtok(NULL, " ");
        column++;
    } row++; 
    }

    // start display
    printf("--------------------------------------------------\n");
    printf("Transmission block %d/5\n", gridc + 1);
    printf("Data streams:\n"); 
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {printf("%-3d ", bytes[gridc][row][col]);}
        printf("[V: %d] [H: %d]", bytes[gridc][row][8], bytes[gridc][row][9]);
        printf("\n");
    } printf("--------------------------------------------------\n");

    // vertical
    for (int row = 0; row < 8; row ++) {
    int parity_bits[8] = {};
    printf("||| Vertical processing block (%d), line (%d)\n", gridc+1, row+1);

    // danger zone start
    for (int col = 0; col < 8; col++) { // for each number in the column
        // int bits[8][8] = {};

            // bits conversion of each vert element
            int temp = bytes[gridc][col][row];
            int numOnes = 0;
            for (int a = 0; a < 8; a++) // for 8 bits of the number, assign 0 or 1
            {
                int x = 1 << (7-a); // starts at 2^7
                if (temp >= x)
                {
                    temp -= x;
                    bits[col][a] = 1;
                } else {
                bits[col][a] = 0; }
            } 
    }

    for (int b = 0; b < 8; b++) {
    int numOnes = 0;
        for (int r = 0; r < 8; r++) {
            // printf("%d", bits[r][b]);
            if (bits[r][b] == 1) {numOnes++;}
        }
        // printf(" - Num ones: %d\n", numOnes);
        if ((numOnes + 1) % 2 == 0) {parity_bits[b] = 1;}
        else {parity_bits[b] = 0;} 
            }
        // printf("Parity bits = ");
        // for (int b = 0; b < 8; b++) { printf("%d", parity_bits[b]);}
        // printf("\n");
// danger zone end

    int vertchecksum = 0;
    for (int b = 0; b < 8; b++) {
        if (parity_bits[b] == 1) {vertchecksum += 1 << b;}
        }

    checkParityByte = vertchecksum;
    vertParityByte = bytes[gridc][row][8];
    printf("\tcheckParityByte = %d, ", checkParityByte);
    printf("vertParityByte = %d\n", vertParityByte);
    if (checkParityByte == vertParityByte) 
    {printf("\tPASSED vertical parity, No errors\n");}
    else {printf("\tFAILED vertical parity, Error found\n");}
    printf("\n");
    }

    // horizontal
    for (int row = 0; row < 8; row ++) {
    int parity_bits[8] = {};
    printf("--- Horizontal processing block (%d), line (%d)\n", gridc+1, row+1);
    for (int col = 0; col < 8; col++) {
        int bits[8] = {};
        // printf("val%d = %d, ", col + 1, bytes[gridc][row][col]);

            // bits conversion of each vert element
            int temp = bytes[gridc][row][col];
            // printf("%d, ", temp); // remove
            int numOnes = 0;
            for (int a = 0; a < 8; a++) // for 8 bits of the number, assign 0 or 1
            {
                int x = 1 << (7-a); // raise 2 to the power of a, starts at 2^7
                if (temp >= x)
                {
                    temp -= x;
                    bits[a] = 1;
                } else {
                bits[a] = 0; }
            }
            for (int b = 0; b < 8; b++) {
                // printf("%d", bits[b]);
                if (bits[b] == 1) {numOnes++;}
            }
            if ((numOnes + 1) % 2 == 0) {parity_bits[col] = 1;}
            else {parity_bits[col] = 0;}     
    }
    
    int horichecksum = 0;
    for (int b = 0; b < 8; b++) {
        if (parity_bits[b] == 1) {horichecksum += 1 << b;}
        }

    checkParityByte = horichecksum;
    horizParityByte = bytes[gridc][row][9];
    printf("\tcheckParityByte = %d, ", checkParityByte);
    printf("horizParityByte = %d\n", horizParityByte);
    if (checkParityByte == horizParityByte) 
    {printf("\tPASSED horizontal parity, No errors\n");}
    else {printf("\tFAILED horizontal parity, Error found\n");}
    printf("\n");
    }

    gridc++;
}

}

int main(void) {

/////////////////////////////// Parity Check ///////////////////////////////
FILE *parity_file;
parity_file = fopen("White House Transmission Data - Parity.txt", "r");
if (parity_file == NULL) { printf("opening file failure\n"); return 1;}

printf("\n\n** Part 1 - Parity Check Processing **\n");
parity_func(parity_file);
fclose(parity_file);



////////////////////////////////// Checksum ///////////////////////////////
FILE *checksum_file;
checksum_file = fopen("White House Transmission Data - Checksum.txt", "r");
if (checksum_file == NULL) { printf("opening file failure\n"); return 1;}

printf("\n\n** Part 2 - Checksum Processing **\n");
checksum_func(checksum_file);
fclose(checksum_file);



/////////////////////////////// Two-Dimensional PC ///////////////////////////////
FILE *parity2D_file;
parity2D_file = fopen("White House Transmission Data - 2D Parity.txt", "r");
if (parity2D_file == NULL) { printf("opening file failure\n"); return 1;}

printf("\n\n** Part 3 - Two-dimensional Parity Processing **\n");
twodim_parity_func(parity2D_file);
fclose(parity2D_file);

return 0;
}