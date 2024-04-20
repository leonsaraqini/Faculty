#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 80

void wtf() {
    FILE *f = fopen("sifra.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();    
    
    FILE *f = fopen("sifra.txt", "r");
    
    char c;
    
    while((c = fgetc(f)) != EOF){
        if(isalpha(c))
            c = 'a' + (tolower(c) - 'a' + 3) % 26;
        
        putchar(c);    
    }
    
    fclose(f);
    
    return 0;
}