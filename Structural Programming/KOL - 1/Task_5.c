#include <stdio.h>

void editDate(int date, int * day, int * month, int *year){
    *day = date / 1000000;
    *month = (date / 10000) % 100;
    *year = date % 10000; 
}

int main(){
    int date, n;
    
    scanf("%d", &date);
    scanf("%d", &n);
    
    int day, month, year;
    
    editDate(date, &day, &month, &year);
    
    while(n){
        int innerDate;
        
        scanf("%d",&innerDate);
        
        int innerDay, innerMonth, innerYear;
        
        editDate(innerDate, &innerDay, &innerMonth, &innerYear);
        
        if(year - innerYear < 18){
            printf("NO\n");
        }
        else if(year - innerYear > 18){
            printf("YES\n");
        } 
        else{
            if(innerMonth > month){
                printf("NO\n");
            }
            else if(innerMonth == month){
                
                if(innerDay > day){
                    printf("NO\n");
                }else{
                    printf("YES\n");
                }
                
            }
            else{
                printf("YES\n");
            }
        }
        n--;
    }
    return 0;
}