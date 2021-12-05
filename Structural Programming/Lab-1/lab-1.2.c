//Write a program that for a given amount of money, will print the minimum bills and coins needed to make the payment. The amount is integer read from standard input. The result should be printed in 9 lines, the number of bills or coins for each of them.

#include <stdio.h>
int main(){
   int b;
   scanf("%d",&b);
       printf("%d x 5000\n",b/5000);
       b=b%5000;

       printf("%d x 1000\n",b/1000);
       b=b%1000;

       printf("%d x 500\n",b/500);
       b=b%500;

       printf("%d x 100\n",b/100);
       b=b%100;

       printf("%d x 50\n",b/50);
       b=b%50;

       printf("%d x 10\n",b/10);
       b=b%10;

       printf("%d x 5\n",b/5);
       b=b%5;
       printf("%d x 2\n",b/2);
       b=b%2;

       printf("%d x 1\n",b/1);
       b=b%1;
       return 0;
}