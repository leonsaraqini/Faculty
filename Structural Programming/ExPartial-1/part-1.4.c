/*From SI are read N pairs of integers, where the first number is the students' points, and the second is the max. points. Write a program where for each pair (points, max points), will print the students success in percentage and his grade following these rules:

    if the student has 90% or more - "10".
    if the student has 80% or more - "9".
    if the student has 70% or more - "8".
    if the student has 60% or more - "7".
    if the student has 50% or more - "6".
    If the student has less than 50% print "FAIL".
*/

#include <stdio.h>

int main(){
    int n;
    float points,maxPoints,percentage;
    scanf("%d",&n);
    while(n){
        scanf("%f %f",&points,&maxPoints);
        percentage=(points/maxPoints)*100;
        if(percentage>=90 && percentage<=100){
            printf("%.02f 10\n",percentage);
        }else if(percentage>=80){
            printf("%.02f 9\n",percentage);
        }else if(percentage>=70){
            printf("%.02f 8\n",percentage);
        }else if(percentage>=60){
            printf("%.02f 7\n",percentage);
        }else if (percentage >= 50) {
            printf("%.02f 6\n", percentage);
        } else {
            printf("%.02f FAIL\n",percentage);
        }
       n--;
    }

    return 0;
}