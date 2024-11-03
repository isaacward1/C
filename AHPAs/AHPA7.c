#include <stdio.h>
#include <string.h>

char temptype;
float temp;

float CtoF(float temp) {
float converted;
converted = temp * 1.8 + 32;
printf("Given a Celcius temperature of %.2f, ", temp);
printf("the equivalent Fahrenheit temperature is %.2f", converted);  
}

float FtoC(float temp) {
float converted;
converted = (temp - 32)/1.8;
printf("Given a Fahrenheit temperature of %.2f, ", temp);
printf("the equivalent Celcius temperature is %.2f", converted);   
}


int main() {

printf("What type of temperature will you be entering (c/f)?: "); scanf (" %c", &temptype);
printf("What what temperature value should be converted?: "); scanf (" %f", &temp);

if (temptype == 'c')
{CtoF(temp);}
else if (temptype == 'f')
{FtoC(temp);}

return 0;
}