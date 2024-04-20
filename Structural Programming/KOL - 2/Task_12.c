#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char c[50];

    fgets(c, sizeof(c), stdin);
    c[strlen(c) - 1] = '\0';

    char newCharacter[50];

    for(int i = 0; c[i] != '\0'; i++){

        if(!isalpha(c[i])){
            
            putchar(c[i]);
            
            for(int j = i + 1; c[j] != '\0'; j++){
                putchar(c[j]);
                if(!isalpha(c[j])) break;
            }
            
            return 0;
        }
    }
    
    printf("No digits");
    
    return 0;
}
