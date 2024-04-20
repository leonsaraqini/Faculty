#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printLine(int n, int i, int j){
    if(n == i)
        return;

    printf("%d", j + 1);

    return printLine(n , i + 1, j + 1);
}

void piramide(int n, int i){
    if(i == 0)
        return;

    printLine(n, i - 1 ,0);

    printf("\n");

    return piramide(n, i - 1);
}


int main() {
    int n;

    scanf("%d", &n);

    piramide(n, n);

    return 0;
}
