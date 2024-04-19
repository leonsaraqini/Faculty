#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



int main() {
    int n;

    int countOverall = 0;
    int number;

    scanf("%d", &n);

    while (--n > 2){
        int countInside = 0;
        
        for(int i = 1; i < n; i++){
            if(n % i == 0)
                countInside += i;
        }

        if(countInside > countOverall){
            countOverall = countInside;
            number = n;
        }
    }

    printf("%d", number);
    return 0;
}
