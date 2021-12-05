/*Using the characters + and - form a square image with "width" n (n > 2) that represent square of the chars -, enclosed by a square of chars + (view examples). For given n, print the appropriate image.

Attention: do not print additional characters as empty spaces, or unnecessary new line... The image ends with new line char. Do not use any matrix or arrays because n is not limited.
*/
#include <stdio.h>
int main()
{
    int n,i,tmp,n2,tmp2,tmp3;
    scanf("%d",&n);
    tmp=n;
    for(i=1;i<=n;i++){
        if(i>1 && i<tmp){
            tmp2=tmp-2;
            printf("+");
            while (tmp2){
                printf("-");
                tmp2--;
            }
            printf("+\n");

        }else{
            while(n){
                printf("+");
                n--;
            }
            printf("\n");
            n=tmp;
        }

    }
    return 0;

}