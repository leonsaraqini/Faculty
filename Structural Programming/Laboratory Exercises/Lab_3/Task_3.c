#include <stdio.h>

int main()
{
    int n, m, k;
    
    int output = 0;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i = 10; i != 0; n--){
        if(!n)
            break;
            
        int count = 0;
        int tmp = n;
        
        while(tmp){
            int digit = tmp % 10;
            
            if(digit == m)
                count++;
            
            tmp /= 10;    
        }
        
        if(count == k){
            printf("%d\n", n);
            i--;
            output = 1;
        }
    }
    
    if(!output){
        printf("WRONG PARAMETERS");
    }

    return 0;
}