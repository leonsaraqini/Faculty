//Write a program that will compute the basic mathematical operation (+, -, *, /, %) on two numbers read from standard input.

#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("a * b = %d\n",a*b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n",a%b);
    return 0;
}