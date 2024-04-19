#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void change(int *a, int *b){
    if(*a > *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void printDiffV2(int a, int b, int c){
    change(&a, &b);
    change(&a, &c);
    change(&b, &c);

    printf("%d %d %d\n", a, b, c);
}
void printDiff(int a, int b){
    change(&a, &b);

    printf("%d %d\n", a, b);
}

int main() {
    int a, b, c;

    while (scanf("%d %d %d\n", &a, &b, &c)){
        int firstDiff = a - b;
        int secondDiff = a - c;
        int thirdDiff = b - c;

        if(abs(firstDiff) < abs(secondDiff) && abs(firstDiff) < abs(thirdDiff))
            printDiff(a, b);
        else if(abs(secondDiff) < abs(firstDiff) && abs(secondDiff) < abs(thirdDiff))
            printDiff(a, c);
        else if(abs(thirdDiff) < abs(firstDiff) && abs(thirdDiff) < abs(secondDiff))
            printDiff(b, c);
        else
            printDiffV2(a, b, c);


    }
    return 0;
}
