#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main(void) {

char str[MAX_LEN];

int year;
float total;
int releases;
int average;
char title[MAX_LEN];

char title_list[MAX_LEN][MAX_LEN] = {};
int avg_list[MAX_LEN] = {};

char starwars_list[10][MAX_LEN] = {};
char (*ptr)[MAX_LEN];
ptr = starwars_list;

FILE *movieReleases;
movieReleases = fopen("AHPA #12 - Movie Data.txt", "r");
if (movieReleases == NULL) { printf("opening file failure\n"); return 1;}

fgets(str, MAX_LEN, movieReleases);
int counter = 0;
int starwars_count = 0;

while (fgets (str, MAX_LEN, movieReleases) != NULL ) { // for each line
sscanf(str,"%d %f %d %d %[^\n]",&year,&total,&releases,&average,title);

strcpy(title_list[counter], title);
avg_list[counter] = (int) average;

if (strstr(title, "Star Wars") && starwars_count < 10)
{
    strcpy(ptr[starwars_count], title);
    starwars_count++;
}


counter++;
}

int total_avgs[MAX_LEN] = {};
for (int i = 0; i < 50; i++)
{
    int titlelen = strlen(title_list[i]);
    total_avgs[titlelen] += avg_list[i];  
}

/*
the sample output is actually incorrect. 
the total avgs should be shifted one position up
(i.e. Length of 5 should have a sum avg of '19029432', 6 should be '101141769', etc.)
*/
for (int i = 0; i < 50; i++)
{
    printf("%d : $%d\n", i, total_avgs[i]);
}

int max = total_avgs[0];
int max_ind = 0;
for (int i = 0; i < 50; i++) // find max total avg and length
{
    if (total_avgs[i] > max) {
            max = total_avgs[i];
            max_ind = i;
        }
}

printf("\nThe movie title length that made the most money was: %d\n", max_ind);
printf("Total income of movies with this length: $%d\n\n", max);

printf("Star Wars Movies In List: \n");
for (int i = 0; i < 5; i++)
{
    printf("%d. %s\n", i, ptr[i]);
}

fclose(movieReleases);
return 0;
}