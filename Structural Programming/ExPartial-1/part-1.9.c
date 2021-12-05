/*Read from SI unknown number of triplets of integers (three integers). The reading ends when the program can not read successfully read three integers. For each triplet of integers print out the two of them that have the minimum difference between them. First print the smaller one, and then the bigger integer. If two pairs of integers in the triplet have equal difference, than print out all the integers, ordered from the smallest to the largest.

Example: if 5 1 7 is entered -> 5 - 1 = 4, 7 - 5 = 2, 7 - 1 = 6 -> 2 is the smallest difference -> 5 7 should be printed

Input:

5 1 7
10 2 18

Output:

5 7
2 10 18 */

#include <stdio.h>

int main() {
    int a,b,c,tmp=0,z1,z,z2;
    while(scanf("%d %d %d",&a,&b,&c)){
        if(a>c){
            tmp=a;
            a=c;
            c=tmp;
        }
        if(a>b){
            tmp=a;
            a=b;
            b=tmp;
        }
        if(b>c){
            tmp=b;
            b=c;
            c=tmp;
        }
        if(a==b){
            printf("%d %d\n",a,b);
        }else if(b==c){
            printf("%d %d\n",b,c);
        }else{
            z=b-a;
            z1=c-b;
            z2=c-a;
            if(z==z1 || z1==z2 || z==z2){
                printf("%d %d %d\n",a,b,c);
            }else{
                if(z2<=z && z2<=z1){
                    printf("%d %d\n",a,c);
                }else if(z1<=z2 && z1<=z){
                    printf("%d %d\n",b,c);
                }else{
                    printf("%d %d\n",a,b);
                }
            }
        }



    }

    return 0;
}
