//An integer N is read from the standard input. Write a program that will print the first number greater than N that has equal number of odd and even digits (zero is counted as an even digit).

#include <stdio.h>

int main() {
    int n,i,tmp,num;
    scanf("%d",&n);
    for(i=n+1;;i++){
        int even=0,odd=0;
        tmp=i;
     while(tmp){
         num=tmp%10;
         tmp/=10;
         if(num%2==0){
             even++;
         }
         else{
             odd++;
         }
     }
        if(even==odd){
            printf("%d",i);
            break;
        }
    }
    return 0;
}