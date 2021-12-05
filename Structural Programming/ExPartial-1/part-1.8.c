/*Read from SI two integers a and b. Write a program that will print all numbers from a to b (a < b), such as the number created from all the digits from next to the first to the next to last digit in the original number (the digits that will remain if we remove the first and the last digit from the original number), reversed (read from right to left) is divisible with the number created as the sum of the first and the last digit. For single and two digit numbers, the number created from the middle digits is 0, and these numbers are not printed. At the end print out the count of such numbers.

Example. For the number 82675 the number created from the digits from the next to the first up to the next to last digit, reversed is 762, and the sum of the first and the last digit is (8 + 5) = 13. When printing out the numbers, next to each number that is satisfying the condition, print the equation of the condition in the following form:

original_number -> (reversed_middle == (last_digit + first_digit) * quotient)

for example: 291 -> (9 == (1 + 2) * 3) 84575 -> (754 == (5 + 8) * 58)*/

#include <stdio.h>

int main()
{
    int a,b,i,tmp,firstDig,lastDig,rev,rev2,quotient,firstDig2,revoff=0,tmp2=1,f=0,div,tmp4;
    scanf("%d %d\n",&a,&b);
    for(i=a;i<b;i++){
        tmp=i;
       
        firstDig=i;
        while(firstDig>9){
            firstDig/=10;
            tmp2*=10;
        }
        lastDig=tmp%10;
        rev=(tmp%tmp2)/10;
        div=tmp2/100;
        if(rev<=div){
            tmp4=((tmp*10)+1)+(tmp2*10);
            while(tmp4){
                rev2=tmp4%10;
                revoff=revoff*10+rev2;
                tmp4/=10;
            }
            rev=(revoff%tmp2)/10;
            quotient=rev/(lastDig+firstDig);
            if(rev==(lastDig+firstDig)*quotient && rev!=0){
                printf("%d -> (%d == (%d + %d) * %d) \n",i,rev,lastDig,firstDig,quotient);
                f++;
            }
            revoff=0;
            tmp2=1;

        }else{
            while(rev){
                rev2=rev%10;
                revoff=revoff*10+rev2;
                rev/=10;
            }
            quotient=revoff/(lastDig+firstDig);
            if(revoff==(lastDig+firstDig)*quotient && revoff!=0){
                printf("%d -> (%d == (%d + %d) * %d) \n",i,revoff,lastDig,firstDig,quotient);
                f++;
            }
            revoff=0;
            tmp2=1;
        }

    }
    printf("%d",f);
    return 0;

}