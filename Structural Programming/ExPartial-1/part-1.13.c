//Sweet number is number that contains only even digits (0, 2, 4, 6, 8). In given range (m and n read from SI) find the smallest "sweet number". If there is no such number, print NSN.

#include <stdio.h>

int main(){
    int a,b,i,tmp, r=0;
    scanf("%d%d",&a,&b);
    for(i=a;i<=b;i++){
        tmp=i;
        while(tmp){
            if(tmp%2){
                r=0;
                break;
            }else r=1;
            tmp/=10;
        }
        if(r){
            printf("%d",i);
            break;
        }

    }
    if(!r)printf("NSN");
    return 0;
}