#include<stdio.h>
#include<math.h>

void printRow(int n){
    if(n == 0)
        return;
    
    printRow(n - 1);

    printf("%d ", n);
}

void printUpsideDownTriangle(int n){
    if(n == 0)
        return;

    printRow(n);
    printf("\n");

    printUpsideDownTriangle(n - 1);
}



int main () {
    int n;

    scanf("%d", &n);

    printUpsideDownTriangle(n);


    return 0;
}