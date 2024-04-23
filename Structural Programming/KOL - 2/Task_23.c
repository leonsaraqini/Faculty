#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printLine(int n){
   if(n == 0){
        printf("%d ", n + 1);
    } else{
        printLine(n - 1);
        printf("%d ", n + 1);
    }
}

void piramide(int n){
    if(n == 0){
        printLine(n);
        printf("\n");
    }else{
        piramide(n - 1);
        printLine(n);
        printf("\n");
    }
}


int main() {
    int n;

    scanf("%d", &n);

    piramide(n - 1);

    return 0;
}
