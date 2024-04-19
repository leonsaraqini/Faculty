#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    char c = ',';
    int sumOfHidden = 0, currNumber = 0;
    
    while (c != '!'){
        scanf("%c", &c);
        
        if(c <= '9' && c >= '0'){
            int digit= c - '0';
            currNumber = 10 * currNumber + digit;
        }else{
            sumOfHidden += currNumber;
            currNumber = 0;
        }
    }
    printf("%d ", sumOfHidden);
    return 0;
}
