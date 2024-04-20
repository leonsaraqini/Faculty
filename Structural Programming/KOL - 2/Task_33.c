#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile(char * file) {
    FILE *f = fopen(file, "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile("input.txt");

    FILE *f = fopen("input.txt", "r");

    char line[20],maxLine[20];

    while (fgets(line, 20, f) != NULL){
        if(strcmp(line, "#") == 0)
            break;

        if(strlen(line) < 4)
            continue;

        int flag = 0;

        for(int i = 0; i < strlen(line) / 2 + 1; i++){
            for (int j = i + 1; j < strlen(line); j++) {
                if(line[i] == line[j])
                    flag++;
            }
        }

        if(flag)
            continue;

        if(strlen(line) >= strlen(maxLine))
            strcpy(maxLine,line);
    }

    puts(maxLine);
    return 0;
}