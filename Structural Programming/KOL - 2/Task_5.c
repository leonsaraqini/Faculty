#include <stdio.h>
#include <string.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("numbers.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int significantDigit(int n){
    if(n < 10)
        return n;
    
    return significantDigit(n / 10);
}

int main()
{
    wtf();

    FILE *f = fopen("numbers.txt", "r");

    while(!feof(f)){
        int n;
        fscanf(f, "%d", &n);

        if(n == 0) break;
        
        int finalSignificantDigit = 0;
        int finalNumber = 0;
        
        for(int i = 0; i < n; i++){
            int number;

            fscanf(f, "%d", &number);

            int mostSignificantDigit = significantDigit(number);
            
            if(mostSignificantDigit > finalSignificantDigit){
                finalSignificantDigit = mostSignificantDigit;
                finalNumber = number;
            }
        }

        printf("%d\n", finalNumber);
    }

    fclose(f);

    return 0;
}