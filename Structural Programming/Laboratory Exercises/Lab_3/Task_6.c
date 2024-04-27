#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    for(int even = 0, odd = 0; ;even = 0, odd = 0){
        int tmp = ++n;
        
        while(tmp){
            int digit = tmp % 10;
            
            if(digit % 2 == 0 || digit == 0)
                even++;        
            else
                odd++;
            
            tmp /= 10;    
        }
        
        if(even == odd){
            printf("%d", n);
            break;
        }
    }
    
    

    return 0;
}