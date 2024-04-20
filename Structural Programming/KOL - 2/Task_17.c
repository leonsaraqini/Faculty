#include <stdio.h>
#include <string.h>
#include <ctype.h>

// DO NOT CHANGE!
#define MAX 23

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while ((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int checkWord(char *word, int length){
    for(int i = 0; i < length; i++){
        if((tolower(word[i]) >= 'a' && tolower(word[i]) <= 'f')
             || isdigit(word[i]))
            continue;
        else
            return 0;
    }

    return 1;
}

int main()
{

    wtf();

    FILE *f = fopen("input.txt", "r");
    char line[MAX];

    int count = 0;

    while(fgets(line, MAX, f) != NULL){
        int length = (int) strlen(line) - 1;

        line[length] = '\0';

        char *word = line;

         if(!checkWord(word, length) || word[0] == '\0')
             continue;

         for(int i = 0; i < length; i++){
             if(islower(word[i]) && isalpha(word[i]))
                 putchar(toupper(word[i]));
             else
                 putchar(word[i]);
         }
         putchar('\n');

        count++;
    }

    printf("Total: %d", count);

    fclose(f);


    return 0;
}




