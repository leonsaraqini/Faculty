#include<stdio.h>
#include<math.h>

#include<stdio.h>
#include<math.h>

void printRow(char c, int n){
    if(n == 0)
        return;

    printf("%c", c);

    printRow(c, n - 1);
}

void downwardTriangle(int n){
    if(n == 0)
        return;

    (n % 2 == 0) ? printRow('#', n) : printRow('*', n);
    printf("\n");

    downwardTriangle(n - 1);
}



int main () {
    int n;

    scanf("%d", &n);

    downwardTriangle(n);

    return 0;
}


