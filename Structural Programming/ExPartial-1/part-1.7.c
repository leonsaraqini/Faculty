//Read from SI one integer n. From the integers smaller than n, find the one with maximum sum of divisors. Do not count the number itself in the sum of divisors.

#include <stdio.h>
int main()
{
    int n,f,i,n2,m,sum=0,tmp=0,np;
    scanf("%d",&n);
    n2=n-1;
    for(i=n2;i>0;i--){
        m=i;
        f=m-1;
        while(f){
            if(m%f==0){
                sum+=f;
            }
            f--;
        }

        if(sum>tmp){
            tmp=sum;
            np=m;
            sum=0;
        }else{
        sum=0;
        }
    }
    printf("%d",np);
return 0;
}