#include <stdio.h>

int main()
{
    float mass, height;
    
    scanf("%f %f", &mass, &height);
    
    float heightInMeters = height / 100.00;
    
    printf("%.2f", mass / (heightInMeters * heightInMeters));

    return 0;
}