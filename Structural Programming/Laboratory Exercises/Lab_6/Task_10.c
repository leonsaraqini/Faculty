#include<stdio.h>
#include<math.h>

void printLine(int n){
    if(n == 0)
        return;

    printLine(n - 1);

    printf("%d", n);
}

void printTriangle(int n){
    if(n == 0)
        return;

    printTriangle(n - 1);

    printLine(n);

    printf("\n");

}



int main () {
    int n;

    scanf("%d", &n);

    printTriangle(n);


    return 0;
}