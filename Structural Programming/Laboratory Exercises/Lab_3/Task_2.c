#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        
        int pointsTaken;
        int maxPoints;
        
        scanf("%d %d", &pointsTaken, &maxPoints);
        
        float percentage = ((float)pointsTaken / maxPoints) * 100.00;
        
        if(percentage < 50){
            printf("%.2f FAIL\n", percentage);
        }else if(percentage < 90){
            printf("%.2f %d\n", percentage,(int)(percentage/10)+1);
        }else{
            printf("%.2f %d\n", percentage, 10);
        }
    }

    return 0;
}