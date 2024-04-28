#include <stdio.h>


int main() {
    int n;
    
    scanf("%d", &n);
    
    int flag = 0;
    
    for(int i = 0; i < n; i++){
        int number;
        
        scanf("%d", &number);
        
        if(number % 2 == 0){
            flag++;
            break;
        }
    }
    
    if(flag){
        printf("NO");
    }else{
        printf("YES");
    }
    return 0;
    
} 