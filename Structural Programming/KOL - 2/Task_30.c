#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 31

void writeToFile(char * file) {
    FILE *f = fopen(file, "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int isVowel(char c){

    if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i'
    || tolower(c) == 'o' || tolower(c) == 'u')
        return 1;

    return 0;

}

int isPalindrome(char *line, int i, int j){

    if(i >= j){
        if(isVowel(line[i]) || isVowel(line[j])){
            if(tolower(line[i]) != tolower(line[j]))
                return 0;
            else
                return 1;
        }

        return 1;
    }

    if(isVowel(line[i]) || isVowel(line[j])){
        if(tolower(line[i]) != tolower(line[j]))
            return 0;
    }

    return isPalindrome(line, i + 1, j - 1);
}


int main() {

    char *filename = "input.text";

    writeToFile(filename);

    FILE *f = fopen(filename, "r");

    char line[MAX];

    while(fgets(line, MAX, f) != NULL){
        line[strlen(line) - 1] = '\0';
        
        if(strcmp(line, "#") == 0)
            break;

        if(isPalindrome(line, 0, strlen(line) - 1)){
            fputs(line, stdout);
            printf("\n");
        }
            
    }
    return 0;
}
