#include <stdio.h>

int changeNumber(int number, int k){
    if(number < 10){
        if(number > k)
            return number;
        else
            return 0;
    }

    if(number % 10 > k) 
        return  10 *  changeNumber(number / 10, k) + (number % 10);
    else
        return changeNumber(number / 10, k);
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
        a[i] = changeNumber(a[i], k);

        if(a[i] > max)
            max = a[i];
    }

    printf("%d", max);



    return 0;
}
