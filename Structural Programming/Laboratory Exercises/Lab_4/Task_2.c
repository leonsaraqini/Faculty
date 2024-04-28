#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int number;
        
        scanf("%d", &number);
        
        if(number % 2 == 0){
            printf("%d ", number + 1);
        }else{
            printf("%d ", number - 1);
        }
        
    }
    
    return 0;
}
