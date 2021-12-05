/*Read from SI two integers a and b. Write a program that will print all numbers from a to b (a < b), such as the number created as a product of the digits from the next to the first to the next to last digit (middle digits = the digits that will remain if we remove the first and the last digit from the original number) is divisible with the number created from the last and the first digit. Do not print the numbers where the product of the middle digits is 0. At the end print the count of such numbers.

When printing out the numbers, next to each number that satisfies the condition, print the equation of that condition, for example: 55650 -> (150 == 50 * 3), where 150 = 5 * 6 * 5 and 50 is constructed from 5 (the first digit) and the 0 (the last digit of the number)*/

#include <stdio.h>

int main() {
    int a,b,i,tmp,firstDig,div=1,lastDig,mid,mid2,mid3=0,tmpmid,midsum,temmid,midtem=1,midtem2,midtem3,f=0;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++){
        tmp=i;
        firstDig=i;
        while(firstDig>10){
            firstDig/=10;
            div*=10;
        }
        lastDig=tmp%10;
        mid=(tmp%div)/10;
        if(mid<=(div/100)){
            mid2=((tmp*10)+1)+(div*10);
            while(mid2){
                tmpmid=mid2%10;
                mid3=mid3*10+tmpmid;
                mid2/=10;
            }
            mid=(mid3%div)/10;
        }
        midsum=mid;
        while(midsum){
           temmid=midsum%10;
           midtem*=temmid;
           midsum/=10;
        }
        if(midtem==0){
            midtem=1;
            mid3=0;
            div=1;
            continue;
        }else{
            midtem2=(firstDig*10)+lastDig;
            midtem3=midtem/midtem2;
            if(midtem==midtem2*midtem3){
                printf("%d -> (%d == %d * %d)\n",i,midtem,midtem2,midtem3);
                f++;
            }
            midtem=1;
            mid3=0;
            div=1;
        }
    }
    printf("%d",f);

    return 0;
}