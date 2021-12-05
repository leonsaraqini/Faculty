/*A natural number n is read from SI. After that n sequences of numbers are being read as well from SI. Each sequence is defined with:

    number M (the count of numbers in the sequence)
    M numbers

Your task is to print on standard output, for each sequence one of the three following messages:

    ARITHMETIC PROGRESSION
    GEOMETRIC PROGRESSION
    THE SEQUENCE IS NOT A PROGRESSION
    BOTH ARITHMETIC AND GEOMETRIC PROGRESSION

A sequence of number is an arithmetic progression if the difference between any number and its predecessor is always the same.

1 2 3 4 5 6 7 8 .. is an arithmetic progression.

A sequence of number is a geometric progression if the quotient between any number and its predecessor is always the same.

1 2 4 8 16 32 ... is a geometric progression. */

#include <stdio.h>

int main() {
    int n,m,m2;
    scanf("%d\n",&n);
    while (n){
        scanf("%d",&m);
        int x1,x2,dif1=0,aritpro,geopro ,minus;
        float dif2=0,pjes;
        scanf("%d %d",&x1,&x2);
        dif1=x1-x2;
        dif2=(float)x1/x2;
        m2=m-2;
                while (m2){
                    aritpro=0,geopro=0; 
                    x1=x2;
                    scanf("%d",&x2);
                    minus=x1-x2;
                    pjes=(float)x1/x2;
                    if(minus==dif1){
                        aritpro=1;
                    }

                    if(pjes==dif2){
                        geopro=1;
                    }
            m2--;
        }
                if(aritpro==1 && geopro==0){
                    printf("ARITHMETIC PROGRESSION\n");
                }
                if(aritpro==0 && geopro==1){
                printf("GEOMETRIC PROGRESSION\n");
                }
                if(aritpro==0 && geopro==0){
                    printf("THE SEQUENCE IS NOT A PROGRESSION\n");
                }
                if(aritpro==1 && geopro==1){
                printf("BOTH ARITHMETIC AND GEOMETRIC PROGRESSION\n");
                }
                n--;
    }
    return 0;
}