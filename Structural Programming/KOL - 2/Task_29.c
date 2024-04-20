#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

//ne menuvaj!
void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int findNumber(char *line, int ten, int i){
    if(i == 0){
        if(isdigit(line[i]))
            return (line[i] - '0') * ten;

        return 0;
    }

    if(isdigit(line[i]))
        return ((line[i] - '0') * ten) + findNumber(line, ten * 10, i - 1);
    else
        return findNumber(line, 1, i - 1);
}

int main() {
    wtf();

    FILE *f = fopen("input.txt", "r");

    char line[MAX];

    while(fgets(line, MAX, f) != NULL){

        int sum = findNumber(line, 1, (int)strlen(line) - 1);

        for(int i = 0; i < strlen(line) - 1; i++){
            if(isalpha(line[i]))
                putchar(line[i]);
        }
        printf("%d\n",sum);
        
    }

    fclose(f);
    return 0;
}
