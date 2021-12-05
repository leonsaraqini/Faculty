/*Three natural numbers А, B and C are entered from the SI.

Write a program that will check if the three entered numbers can represent the values of the angles (in degrees) of a triangle. If the values can represent angles of a triangle print YES in the first line of the standard output followed by type of the triangle (RIGHT, ACUTE or OBTUSE) in the next line. If triangle is not possible with the tree given angles print NO in a single line.

Examples:

Example 1:

60 40 80

YES

ACUTE

Example 2:

100 50 30

YES

OBTUSE

Example 3:

100 50 50

NO*/

#include <stdio.h>

int main(){
    int a,b,c,sum=180;
    scanf("%d %d %d",&a,&b,&c);

    if(a+b+c!=sum){
        printf("NO");
    }else{
        printf("YES\n");
        if(a>90 || b>90 || c>90){
            printf("OBTUSE");
        }else if(a==90 || b==90 || c==90){
            printf("RIGHT");
        }else{
            printf("ACUTE");
        }

    }
    return 0;
}