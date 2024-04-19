#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int middleNumber(int n, int ten){
    if(n < 10)
        return 0;

    return ten * (n % 10) + middleNumber(n / 10, ten * 10);
}

int firstDigit(int n){
    if(n < 10)
        return n;

    return firstDigit(n / 10);
}

int reverseNumber(int n, int ten){
    if(n < 10)
        return n * ten;

    return ten * (n % 10) + reverseNumber(n / 10, ten / 10);
}

int countOfDigits(int n){
    if(n < 10)
        return 1;

    return 10 * countOfDigits(n / 10);
}

int main() {
    int n, m;
    int count = 0;

    scanf("%d %d\n", &n, &m);

    for(int i = n; i <= m; i++){

        int middleNum = middleNumber(i / 10, 1);
        int tens = countOfDigits(i / 10);

        middleNum = reverseNumber(middleNum, tens / 10);

        int firstDig = firstDigit(i);
        int lastDig = i % 10;
        int quotient = middleNum / (lastDig + firstDig);

        if(middleNum % (lastDig + firstDig) == 0 && quotient != 0){
            printf("%d -> (%d == (%d + %d) * %d)\n", i, middleNum, lastDig, firstDig, quotient);
            count++;
        }

    }

    printf("%d", count);

    return 0;
}
