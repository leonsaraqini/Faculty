//Write a program that computes average grade of semester.
// The program reads 5 integers and should print out the average as floating point number with two decimal places.

#include <stdio.h>

int main(){
    int a, b, c, d, e;
    float g;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    g=(a+b+c+d+e)/5.0;
    printf("%.2lf",g);
    return 0;
}