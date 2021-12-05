/*A whole number N greater then 0 is entered from the SI followed by N pairs of natural numbers greater than 10. Write a program that for every pair of entered numbers will check if the number obtained by moving the last digit of the first number on its first place is greater that the second number in the pair or not. Print YES if the condition is satisfied or NO if the condition is not satisfied on the standard output in a single line for each pair of numbers.

(Example for moving the last digit of a number on its first place: 1234 -> 4123, 98700 -> 9870). If the numbers 3456 and 6210 are entered as a pair YES should be printed since 6345 > 6210.*/

#include <stdio.h>

int main(){
    int n,a,b,num=10,f,tmp,tmp2=1,tmp4,f2,f3;
    scanf("%d",&n);
    while(n){
        scanf("%d %d",&a,&b);
       tmp=a;
       tmp4=a;
       while(tmp>9){
           tmp/=10;
           tmp2*=10;
       }
       f=tmp4%10;
       f2=tmp4/10;
       f3=tmp2*f+f2;
       if(f3>b){
           printf("YES\n");
       } else{
           printf("NO\n");
       }
       tmp2=1;
       n--;

    }
    return 0;
}