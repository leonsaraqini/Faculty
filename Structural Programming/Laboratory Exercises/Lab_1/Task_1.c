#include <stdio.h>

int main()
{
    int totalGrades = 0;
    int grade;
    
    int i = 5;
    while(i-- != 0){
        scanf("%d", &grade);
        totalGrades += grade;
    }
    
    float averageGrade = totalGrades / 5.00;
    
    printf("%.2f", averageGrade);

    return 0;
}