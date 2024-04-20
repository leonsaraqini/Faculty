#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("sp.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}
void rff() {
    FILE *f = fopen("output.txt", "r");
    char c;
    while((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
}

int main() {
    wtf();



    FILE *r = fopen("sp.txt", "r");
    FILE *w = fopen("output.txt", "w");

    int k;
    fscanf(r, "%d", &k);

    char c;
    while((c = fgetc(r)) != EOF){
        if(tolower(c) == 'a' || tolower(c) == 'e' ||
        tolower(c) == 'i' || tolower(c) == 'o'
        || tolower(c) == 'u')

            for(int i = 0; i < k; i++)
                fputc(c, w);

        else if(c == '\n')
            continue;
        else
            fputc(c, w);
    }

    fclose(r);
    fclose(w);

    rff();

    return 0;

}




