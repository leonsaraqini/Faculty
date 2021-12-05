//From SI read one number that represents the today's date in format DDMMYYYY (DD-day, MM-month, YYYY-year). Then read one integer N, after you read N dates of birth in the given format. For each of the N read dates your program should print "YES" if on today's date (read in the beginning) the person with that date have more or equal to 18 years, otherwise should print "NO".

#include <stdio.h>

int main(){
    int date,d,m,y,n,date2,d2,m2,y2;
    scanf("%d",&date);
    scanf("%d",&n);
    d=date/1000000;
    m=(date/10000)%100;
    y=date%10000;
    while(n){
        scanf("%d",&date2);
        d2=date2/1000000;
        m2=(date2/10000)%100;
        y2=date2%10000;
        if(y-y2>18){
            printf("YES\n");
        }else if(y-y2==18){
            if(m2>m){
                printf("NO\n");
            }else if(m==m2){
                if(d2>d){
                    printf("NO\n");
                }else{
                    printf("YES\n");
                }
            }else{
                printf("YES\n");
            }
        }else{
            printf("NO\n");
        }
        n--;
    }
    return 0;
}