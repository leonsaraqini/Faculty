#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int factorial(int number){
    if(number == 0)
        return 1;

    return number * factorial(number - 1);
}

int checkSumOfFactorials(int number){
    if(!number)
        return 0;
    
    return factorial(number % 10)+ checkSumOfFactorials(number / 10);
}

int main() {
    int n;

    scanf("%d \n", &n);

    printf("Strong numbers: \n");

    for(int i = 0; i < n; i++){
        int number;

        scanf("%d", &number);

        if(number == checkSumOfFactorials(number))
            printf("%d\n", number);

    }
    return 0;
}
