#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int changeNumber(int n, int number){
    if(n < 10)
        return number;

    return 10 * changeNumber(n / 10, number);
}


int main() {
    int n;

    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        int k, l;

        scanf("%d %d\n", &k, &l);

        k = changeNumber(k, k % 10) + k / 10;

        if(k > l)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
