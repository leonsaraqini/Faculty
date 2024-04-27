#include <stdio.h>

int main()
{
    int day, month, year;
    
    scanf("%d %d %d", &day, &month, &year);
    
    if(month >= 1 && month <= 12){
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            
            if(day < 1 || day > 31){
                printf("NO");
            }else{
                printf("YES");
            }
            
        }else if(month == 4 || month == 6 || month == 9 || month == 11){
            
            if(day < 1 || day > 30){
                printf("NO");
            }else{
                printf("YES");
            }
            
        }else{
            
            if(day > 29 || day < 1){
                printf("NO");
            }else{
               
               if(day == 29){
                   
                   if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                      printf("YES"); 
                   }else{
                      printf("NO"); 
                   }
                   
               }else{
                   printf("YES");
               } 
            }
        }
        
        
    }else{
        printf("NO");
    }

    return 0;
}