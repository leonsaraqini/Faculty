#include <stdio.h>

int main()
{
    int number;
    
    scanf("%d", &number);
    
    int firstPart = number / 1000000;
    int secondPart = (number % 1000000) / 1000;
    int thirdPart = number % 1000;
    
    if(firstPart == 70 || firstPart == 71 || firstPart == 72){
        printf("%03d/%03d-%03d T-mobile",firstPart, secondPart, thirdPart);
    }else if(firstPart == 75 || firstPart == 76 || firstPart == 77 || firstPart == 78){
        printf("%03d/%03d-%03d A1",firstPart, secondPart, thirdPart);
    }else{
        printf("%03d/%03d-%03d LycaMobile",firstPart, secondPart, thirdPart);
    }

    return 0;
}