#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int middleProduct(int n){
    if(n < 10)
        return 1;

    return (n % 10) * middleProduct(n / 10);
}

int firstDig(int n){
    if(n < 10)
        return n;

    return firstDig(n / 10);
}

int main() {
    int n, m;
    int count = 0;

    scanf("%d %d\n", &n, &m);

    for(int i = n; i <= m; i++){
        int product = middleProduct(i / 10);

        int remainingDigits = (firstDig(i) * 10) + (i % 10);

        int otherSide = product / remainingDigits;

        if(product % remainingDigits == 0 && product != 0){
            printf("%d -> (%d == %d * %d)\n", i, product, remainingDigits, otherSide);

            count++;
        }
    }

    printf("%d", count);

    return 0;
}
