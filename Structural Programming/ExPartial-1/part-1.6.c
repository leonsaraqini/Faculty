//One number is interesting if his flipped number is divisible by the number of digits it contains. The flipped number is composed from the same digits, but in opposite order (ex. 653 is flipped of the number 356). Read from SI one integer n ( n > 9). Find and print the largest integer small than n that is "interesting". If the read number is not valid print a message "The number is invalid". 

#include <stdio.h>
int main()
{
    int n,i,t,tmp2;
    scanf("%d",&n);
    if(n<9){
        printf("The number is invalid");
    }else{
        for(i=n-1;i<n;i--){
            if(i==9){
                printf("%d",i);
                break;
            }
            int tmp=1,tmpcut=0,div=1,f=0;
            tmp2=i;
            while (tmp2){
                t=tmp2%10;
                tmpcut=tmpcut*10+t;
                tmp2/=10;
                f++;
            }
                if(tmpcut%f==0){
                    printf("%d",i);
                    break;
            }
        }
    }
    return 0;
}