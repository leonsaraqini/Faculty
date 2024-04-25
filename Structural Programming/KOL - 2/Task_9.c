#include <stdio.h>

int Odd(int a[], int n){
    if(n == 0){
        return 0;
    }

    if(a[n-1] % 2 == 0)
        return Odd(a, n - 1);
    else
        return Odd(a, n - 1) + 1;
}

int main() {
    int n;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("%d", Odd(a,n));



    return 0;
}
