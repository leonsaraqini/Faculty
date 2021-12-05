/*Write a program that reads from standard input two floating point numbers (mass in kg and height in cm) and computes and prints out to standard output the body mass index using the following forumla:

$BMI = \frac{masa}{visina * visina}$

The height should be converted from centimeters to meters.*/

#include <stdio.h>
int main () {
   
    float m, h, BMI ;
    scanf("%f %f", &m, &h);
    h=h/100;
    BMI = m/(h*h);
    printf("%.2f\n", BMI);
   
    return 0;
}