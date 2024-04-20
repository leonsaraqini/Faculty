#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 81

void writeToFile();

int main() {

    writeToFile();

    FILE *f = fopen("text.txt", "r");
    char line[MAX],c;

    int length, s;

    while(fgets(line, MAX, f) != NULL){
        length = (int) strlen(line);

        for(int i = 0; i < length; i++){
            c = line[i];

            if(isalpha(c)){
                putchar(c);
                s = 0;
            }

            if(isspace(c))
                s++;

            if(s == 1 && isspace(c))
                putchar('\n');
        }
    }

    fclose(f);


    return 0;
}

void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}
