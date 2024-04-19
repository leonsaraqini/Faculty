#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int z;

    scanf("%d", &z);

    int count = 0;
    int countPairs = 0;

    while(true){
        int a, b;
        scanf("%d %d\n", &a, &b);

        if(a == 0 && b == 0)
            break;

        if(a + b == z)
            countPairs++;

        count++;
    }
    
    float percentage = ((float)countPairs / count) * 100.00; 

    printf("You entered %d pair of numbers whose sum is %d\n", countPairs, z);
    printf("The percentage of pairs with sum %d is %.2f%%",z ,percentage);

    return 0;
}
