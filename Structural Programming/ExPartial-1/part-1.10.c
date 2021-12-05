//Write a program in which from the standard input you read one positive integer z, and afterwards you read one after another pairs of integers (a, b). Thereby, the loop should end if you read the pair (0, 0). The program should calculate how many times the integer z is equal to the sum of the pairs a and b, as well as the percentage of the pairs (a,b) that give sum equal to z (NOTE: the pair (0,0) is not taken into account when doing calculations!).

#include <stdio.h>

int main() {
    int z,a,b,f=0,s=0;
    float m,p;
    scanf("%d",&z);
    while(z){
        scanf("%d %d",&a,&b);
        if(a==0 && b==0){
            break;
        }
        if(z==a+b){
            f++;
        }
        s++;
    }
        m=(float)f/s;
        p=m*100;
        printf("You entered %d pair of numbers whose sum is %d\n",f,z);
        printf("The percentage of pairs with sum %d is %.02f%%",z,p);
    return 0;
}
