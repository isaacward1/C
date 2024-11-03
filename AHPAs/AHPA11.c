#include <stdio.h>
#include <string.h>
#define listSize 15

int finalExams[listSize] = {90, 82, 65, 79, 67, 82, 94, 64, 88, 78, 92, 61, 96, 83, 74};
int *gradePtr;
void switcher(int *gradePtr, int size);


void switcher(int *gradePtr, int size) {

for (int i = 0; i < size; i++)
{
    if (gradePtr[i] < 70)
    {
        gradePtr[i] += 10;
    }
}

}


int main(void) {

gradePtr = finalExams;


printf("Scores before changing:\n");
for (int i = 0; i < listSize; i++)
{
    printf("%d ", gradePtr[i]);
}

// call switcher func
switcher(gradePtr, listSize);


printf("\n\nScores after changing:\n");
for (int i = 0; i < listSize; i++)
{
    printf("%d ", gradePtr[i]);
}

printf("\n");


return 0;
}       