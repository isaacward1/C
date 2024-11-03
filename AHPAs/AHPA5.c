#include <stdio.h>
#include <string.h>

int main() {

FILE *message_file;
message_file = fopen("clearMessage.txt", "r");

if (message_file == NULL) { 
    printf("failure"); 
    return 1;
    }

int curr_char; // fgetc returns an int
char storage[50];

int i = 0;
while ((curr_char = fgetc(message_file)) != EOF){
    if ((65 <= curr_char && curr_char <= 90) || (97 <= curr_char && curr_char <= 122) )
    {
        storage[i] = (char) curr_char + 3;
        i += 1;
    }
    else { 
        storage[i] = (char) curr_char;
        i += 1;
        }
}

FILE *output_file;
output_file = fopen("secretMessage.txt", "w");

if (output_file == NULL) { 
    printf("failure"); 
    return 1;
    }

fprintf (output_file, "%s", storage);

fclose(message_file);
fclose(output_file);

return 0;
}