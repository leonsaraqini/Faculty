#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void changeWord(char *word, int x){
    if(*word == 0) return;

    if(isalpha(*word)){
        char first;

        if(isupper(*word))
            first = 'A';
        else
            first = 'a';

        *word = first + (*word + x - first) % 26;
    }

    changeWord(++word, x);
}

int main() {
    int n, x;

    scanf("%d %d\n", &n, &x);

    char word[80];

    for(int i = 0; i < n; i++){
        fgets(word, sizeof(word), stdin);
        word[strlen(word)-1]='\0';
        changeWord(word, x);
        printf("%s\n", word);
    }


    return 0;
}
