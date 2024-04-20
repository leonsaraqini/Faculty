#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

void wtf() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}


int main() {
    wtf();

    FILE *f = fopen("text.txt", "r");

    char line[MAX];
    float maxRatio = 0;
    int row = 0;
    int index = 0;

    while(fgets(line, MAX, f) != NULL){
        int upper = 0;
        int lower = 0;

        for(int i = 0; i < strlen(line); i++){
            if(isalpha(line[i])){
                if(isupper(line[i]))
                    upper++;
                else
                    lower++;
            }
        }

        float ratio = (float) upper / lower;

        printf("%.2f ", ratio);

        fputs(line, stdout);

        if(maxRatio < ratio){
            maxRatio = ratio;
            row = index;
        }

        index++;
    }

    printf("%d", row);

    fclose(f);

    return 0;
}