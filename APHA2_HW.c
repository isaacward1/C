#include <stdio.h>
 
 int main()
 {
   const int numStudents = 9;
   printf("Number of students in the class: %d\n\n", numStudents);

   int seat1 = 1;
   char name1 = 'B';
   float score1 = 79.54;

   int seat2 = 2;
   char name2 = 'M';
   float score2 = 82.13;

   int seat3 = 3;
   char name3 = 'T';
   float score3 = 74.61;

   int seat4 = 4;
   char name4 = 'J';
   float score4 = 91.12;

   int seat5 = 5;
   char name5 = 'P';
   float score5 = 78.83;

   int seat6 = 6;
   char name6 = 'E';
   float score6 = 97.17;

   int seat7 = 7;
   char name7 = 'H';
   float score7 = 85.65;

   int seat8 = 8;
   char name8 = 'R';
   float score8 = 65.42;

   int seat9 = 9;
   char name9 = 'X';
   float score9 = 70.26;

   printf("%d %c %.1f", seat1, name1, score1);
   printf("%5d %c %.1f", seat2, name2, score2);
   printf("%5d %c %.1f\n", seat3, name3, score3);
   printf("%d %c %.1f", seat4, name4, score4);
   printf("%5d %c %.1f", seat5, name5, score5);
   printf("%5d %c %.1f\n", seat6, name6, score6);
   printf("%d %c %.1f", seat7, name7, score7);
   printf("%5d %c %.1f", seat8, name8, score8);
   printf("%5d %c %.1f\n\n", seat9, name9, score9);

  return 0;

 }