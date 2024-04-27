#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    float PM10 = 0, PM2_5 = 0;
    int countPair = 0;
    
    
    for(int i = 0; i < n; i++){
        int first , second;
        
        scanf("%d %d", &first, &second);
        
        if(first == -1 && second == -1){
            continue;
        }
        
        PM10 += first;
        PM2_5 += second;
        
        countPair++;
    }
    
    if(!PM10 && !PM2_5){
        printf("PM10: Can not be calculated \nPM2.5: Can not be calculated");    
    }else{
        PM10 /= countPair;
        PM2_5 /= countPair;
        printf("PM10: %.2f\nPM2.5: %.2f", PM10, PM2_5); 
    }
    
    

    return 0;
}