#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int changeNumber(int n, int i){
    if(n == 0) return 0;

    return (n % 2 == 0 ? (n % 10) + 1 : (n % 10) - 1) * i + changeNumber(n / 10, i * 10);
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int *maxNumber(int *a){
    int *max = &a[0];

    for(int i = 0; i < 5; i++){
        if(a[i] > *max)
            max = &a[i];
    }

    return max;
}

int main() {
    int a[5];
    int count = 0;
    int n;


    while(scanf("%d", &n) != 0){
        n = changeNumber(n, 1);
        if(count != 5)
            a[count++] = n;
        else{
            int *max = maxNumber(a);

            if(*max > n)
                *max = n;

            bubbleSort(a, 5);
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
