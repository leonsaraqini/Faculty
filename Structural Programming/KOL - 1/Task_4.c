#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main() {
    int n;

    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int k, l;

        scanf("%d %d\n", &k, &l);
        
        float percentage = ((float) k / l) * 100.00;
        
        if(percentage < 50){
            printf("%.2f FAIL\n", percentage);
        }
        else if(percentage == 100){
            printf("%.2f 10\n", percentage);
        }
        else{
            printf("%.2f %d\n", percentage, ((int)percentage / 10) + 1);    
        }
    }

    return 0;
}
