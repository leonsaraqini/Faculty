#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



bool sweetNumber(int n, int m){
    while(n <= m){
       int flag = 0;
       int tmp = n;

       while(tmp){
           if((tmp % 10) % 2 != 0){
               flag++;
               break;
           }
           tmp /= 10;
       }

       if(!flag){
           printf("%d", n);
           return false;
       }
       
       n++;
    }

    return true;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    if(sweetNumber(n,m))
        printf("NSN");


    return 0;
}
