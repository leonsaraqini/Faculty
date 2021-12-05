/*A natural number n is read from standard input. After that n numbers are being read as well from standard input.

Your task is to print to standard output only the two-digit even numbers.
*/

#include <stdio.h>
#include <math.h>
int main(){
     int i,n,num;
     scanf("%d",&n);
     for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num%2==0 && num>=10 && num<99){
            printf("%d\n",num);
            
        }

     }
     return 0;
}