/*From SI the number of students N, and then N pairs of integers are read, where the first number is the students' points, and the second is the max. points. Write a program where for each pair (points, max points), will print the student's success in percentage and his grade following these rules:

    if the student has 90% or more - "10".
    if the student has 80% or more - "9".
    if the student has 70% or more - "8".
    if the student has 60% or more - "7".
    if the student has 50% or more - "6".
    If the student has less than 50% print "FAIL".
*/

#include <stdio.h>
#include <math.h>
int main(){
     int numStudents,i,grade,pMin,pMax;
     float success;
     scanf("%d",&numStudents);
     for(i=1;i<=numStudents;i++){
        scanf("%d %d",&pMin,&pMax);
        success=((float)pMin/pMax)*100;

        if(success>=90.00)
        {
            grade=10;
            printf("%.2f %d\n",success,grade);
        }
        else if(success>=80.00)
        {
            grade=9;
            printf("%.2f %d\n",success,grade);
        }
        else if(success>=70.00)
        {
            grade=8;
            printf("%.2f %d\n",success,grade);
        }
        else if(success>=60.00)
        {
            grade=7;
            printf("%.2f %d\n",success,grade);
        }
        else if(success>=50.00)
        {
            grade=6;
            printf("%.2f %d\n",success,grade);
        }
        else
        {
            printf("%.2f FAIL\n",success);
        }
        }
    return 0;
}