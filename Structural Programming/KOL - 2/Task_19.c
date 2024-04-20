#include <stdio.h>
#include <string.h>
#include <ctype.h>
// DO NOT CHANGE HERE

#define MAX 100
void wtf() {
    FILE *f = fopen("datnum.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();

    FILE *f = fopen("datnum.txt", "r");

    char line[MAX], maxLine[MAX];

    float maxRatio = 0;

    while(fgets(line, MAX, f) != NULL){
        int letter = 0;
        int digit = 0;

        for(int i = 0; i < (int)strlen(line); i++){
            if(isalpha(line[i]))
                letter++;

            if(isdigit(line[i]))
                digit++;
        }

        if(!letter)
            continue;

        float ratio = (float) digit / letter;

        if(maxRatio <= ratio){
            maxRatio = ratio;
            strcpy(maxLine, line);
        }
    }

    puts(maxLine);

    fclose(f);
    return 0;
}