#include <stdio.h>

void readArray(int a[], int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void doubleNextValueInArray(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            a[i] += a[i + 1];
            a[i + 1] = 0;
        }
    }
}

void reorderArray(int a[], int n){
    for(int i = 0; i < n; i++){
        if(a[i] == 0){

            for(int j = i + 1; j < n; j++){
                if(a[j] != 0){
                   a[i] = a[j];
                   a[j] = 0;
                   break;
                }
            }
        }
    }
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main() {
    int n, a[100];

    scanf("%d", &n);

    readArray(a, n);

    doubleNextValueInArray(a, n);

    reorderArray(a, n);

    printArray(a, n);

    return 0;
}
