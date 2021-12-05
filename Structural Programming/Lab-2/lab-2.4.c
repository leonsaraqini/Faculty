/*Write a program that reads mobile phone number from SI in the following format XXYYYZZZ (ex. 71298486). The program should print the number in the following format: XXX/YYY-ZZZ (ex. 071/298-486) and should print the name of the operator following these rules:

    070/071/072 - T-mobile,
    075/076/077/078 - A1
    079 - LycaMobile */

#include <stdio.h>
#include <math.h>
int main()
{
   int number,x,y,z;
   scanf("%d",&number);
   x=number/pow(10,6);
   y=(number % 1000000)/1000;
   z=number%1000;
   if(x>=70 && x<=72){
    printf("%03d/%03d-%03d T-mobile",x,y,z);
   }
   else if(x>=75 && x<=78){
    printf("%03d/%03d-%03d A1",x,y,z);
   }
   else if(x==79){
    printf("%03d/%03d-%03d LycaMobile",x,y,z);
   }
   else{
    printf("Nmuber does not exist!");
   }
   return 0;
}
