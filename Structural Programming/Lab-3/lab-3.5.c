/*A natural number 'N' is read from the standard input. Then, N pairs of integers (air measurements of PM10 and PM2.5 particles from the corresponding measuring station for a given municipality) are read. Your task is to calculate the mean value of PM10 and PM2.5 particles only from those measuring stations that are in use. One measuring station is considered to be out of use if it sends a pair of measurements -1 -1.

Note: The result should be printed with 2 decimal places.

Example 1:

Input:

5 (number of pairs of integers)

35 56 (the first pair)

-1 -1 (the second pair ...)

0 0

102 189

200 225

Output:

PM10: 84.25 (the mean value of PM10 particles)

PM2.5: 117.50 (the mean value of PM2.5 particles)

Example 2:

Input:

1

-1 -1

Output:

PM10: Can not be calculated

PM2.5: Can not be calculated */

#include <stdio.h>

int main() {
    int n,a,b,sum=0,sum1=0;
    float pro,pro2,f=0;
    scanf("%d",&n);
    while(n){
        scanf("%d %d",&a,&b);
        if(a==-1 && b==-1){
            n--;
            continue;
        }else{
            sum+=a;
            sum1+=b;
            f++;
            n--;
        }
    }
    pro=sum/f;
    pro2=sum1/f;
    if(sum==0 && sum1==0){
        printf("PM10: Can not be calculated\n");
        printf("PM2.5: Can not be calculated\n");
    }else{
        printf("PM10: %.02f\n",pro);
        printf("PM2.5: %.02f\n",pro2);

    }


    return 0;
}
