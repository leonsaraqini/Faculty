#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int number;
        
        scanf("%d", &number);
        
        if(number > 9 && number < 100 && number % 2 == 0)
          printf("%d\n", number);
    }

    return 0;
}
