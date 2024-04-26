#include <stdio.h>

int main()
{
    int secondsRead;
    
    scanf("%d", &secondsRead);
    
    float hour = secondsRead / 3600.00;
    
    float minute = (hour - (int)hour) * 60.00;
    
    float second = (minute - (int)minute) * 60.00;
    
    printf("%d:%02d:%02.f", (int)hour, (int)minute,  second);

    return 0;
}