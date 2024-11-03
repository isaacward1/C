#include <stdio.h>
#include <string.h>

int main(){

enum flavors {vanilla, chocolate, mint, strawberry} index; // default enum variable names

char flavor1_type[12]; printf("Enter icecream flavor #1: "); scanf("%11s", flavor1_type);
char flavor2_type[12]; printf("\nEnter icecream flavor #2: "); scanf("%11s", flavor2_type);
char flavor3_type[12]; printf("\nEnter icecream flavor #3: "); scanf("%11s", flavor3_type);
char flavor4_type[12]; printf("\nEnter icecream flavor #4: "); scanf("%11s", flavor4_type);

float flavor1_C1; printf("\nEnter corner 1 sales of %s: ", flavor1_type); scanf("%f",&flavor1_C1);
float flavor2_C1; printf("\nEnter corner 1 sales of %s: ", flavor2_type); scanf("%f",&flavor2_C1);
float flavor3_C1; printf("\nEnter corner 1 sales of %s: ", flavor3_type); scanf("%f",&flavor3_C1);
float flavor4_C1; printf("\nEnter corner 1 sales of %s: ", flavor4_type); scanf("%f",&flavor4_C1);

float flavor1_C2; printf("\nEnter corner 2 sales of %s: ", flavor1_type); scanf("%f",&flavor1_C2);
float flavor2_C2; printf("\nEnter corner 2 sales of %s: ", flavor2_type); scanf("%f",&flavor2_C2);
float flavor3_C2; printf("\nEnter corner 2 sales of %s: ", flavor3_type); scanf("%f",&flavor3_C2);
float flavor4_C2; printf("\nEnter corner 2 sales of %s: ", flavor4_type); scanf("%f",&flavor4_C2);

float corner1Sales[4];
float corner2Sales[4];

index = vanilla; corner1Sales[index] = flavor1_C1; corner2Sales[index] = flavor1_C2;
float total1 = corner1Sales[index] + corner2Sales[index];

index = chocolate; corner1Sales[index] = flavor2_C1; corner2Sales[index] = flavor2_C2;
float total2 = corner1Sales[index] + corner2Sales[index];

index = mint; corner1Sales[index] = flavor3_C1; corner2Sales[index] = flavor3_C2;
float total3 = corner1Sales[index] + corner2Sales[index];

index = strawberry; corner1Sales[index] = flavor4_C1; corner2Sales[index] = flavor4_C2;
float total4 = corner1Sales[index] + corner2Sales[index];

float totalsales = total1 + total2 + total3 + total4;


printf("\nTotal %s sales: %.2f", flavor1_type, total1);
printf("\nTotal %s sales: %.2f", flavor2_type, total2);
printf("\nTotal %s sales: %.2f", flavor3_type, total3);
printf("\nTotal %s sales: %.2f\n", flavor4_type, total4);
printf("\nBob's Ice Cream total sales: %.2f\n", totalsales);

return 0;
}