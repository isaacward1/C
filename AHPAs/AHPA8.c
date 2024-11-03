#include <stdio.h>
#include <string.h>

struct studentInfo
{
   char studentFname[100];
   char studentLname[100];
   int studentAge;
   char studentID[20];
   float studentGPA;
   char onCampus[20];
   char paidCurrent[20];
} students[2];

int main() {

// scanf (" %i", &students[0].studentAge);
printf("Enter student first name: "); scanf ("%s", &students[0].studentFname);
printf("Enter student last name: "); scanf ("%s", &students[0].studentLname);
printf("Enter student age: "); scanf ("%i", &students[0].studentAge);
printf("Enter student ID: "); scanf ("%s", &students[0].studentID);
printf("Enter student GPA: "); scanf ("%f", &students[0].studentGPA);
printf("Does the student live on campus?: "); scanf ("%s", &students[0].onCampus);
printf("Has the student paid for the current sem?: "); scanf ("%s", &students[0].paidCurrent);

students[1] = students[0];

printf("\nEnter student #2 first name: "); scanf ("%s", &students[1].studentFname);
printf("Enter student #2 last name: "); scanf ("%s", &students[1].studentLname);

if (strcmp(students[0].onCampus, "yes") == 0){strcpy(students[1].onCampus, "no");}
else if (strcmp(students[0].onCampus, "no") == 0){strcpy(students[1].onCampus, "yes");}

if (strcmp(students[0].paidCurrent, "yes") == 0){strcpy(students[1].paidCurrent, "no");}
else if (strcmp(students[0].paidCurrent, "no") == 0){strcpy(students[1].paidCurrent, "yes");}


for (int i = 0; i < 2; i++)
{
printf("\n--- Info for Student %d ---\n", i + 1);
    printf("First name: %s\n", students[i].studentFname);
    printf("Last name: %s\n", students[i].studentLname);
    printf("Age: %d\n", students[i].studentAge);
    printf("USF ID: %s\n", students[i].studentID);
    printf("GPA: %.2f\n", students[i].studentGPA);
    printf("Lives On Campus?: %s\n", students[i].onCampus);
    printf("Has Paid for Current Semester?: %s\n\n", students[i].paidCurrent);
}

return 0;
}