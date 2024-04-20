#include <stdio.h>
#include <ctype.h>

int countLeastDig(int number, int leastDig){
    if(number == 0) return 0;

    return (number % 10 == leastDig) + countLeastDig(number / 10, leastDig);
}

int main() {
    int n;

    scanf("%d\n", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        int count = countLeastDig(a[i], a[i] % 10);
        printf("%d ",  count);
    }



    return 0;
}
