#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int flip(int n, int ten){
    if(n < 10)
        return n;

    return (n % 10) * ten + flip(n / 10, ten / 10);
}

int countOfDigits(int n){
    if(n == 0){
        return 0;
    }
    
    return 1 + countOfDigits(n / 10);
}

int countOfTens(int n , int ten){
    if(n < 9){
        return ten;
    }
    
    return ten * countOfTens(n / 10 , ten * 10);
}


int main() {
    int n;

    scanf("%d", &n);


    while(--n >= 9){
        int ten = countOfTens(n);
        int count = countOfDigits(n);

        int flippedNumber = flip(n, ten);

        if(flippedNumber % count == 0){
            printf("%d", n);
            return 0;
        }
    }

    printf("The number is invalid");
    return 0;
}
