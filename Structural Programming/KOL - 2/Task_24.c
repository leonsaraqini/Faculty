#include <stdio.h>

int changeNumber(int number, int k, int ten){
    if(number < 10){
        if(number > k) return number * ten;
        return 0;
    }

    if(number % 10 > k) return (number % 10) * ten + changeNumber(number / 10, k, ten * 10);
    return changeNumber(number / 10, k, ten);
}

int main() {
    int n;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int k;

    scanf("%d", &k);

    int max = -1;

    for(int i = 0; i < n; i++){
        a[i] = changeNumber(a[i], k, 1);

        if(a[i] > max)
            max = a[i];
    }

    printf("%d", max);



    return 0;
}
