/*Write a program that for a date read from SI (in the format DD MM YYYY) will print on standard output a message YES if the date is correct and possible, or NO if the date is not correct.

When deciding whether the date is correct or not correct, you have to consider the following factors:

    is the month between January and December (1-12)
    does the number for days correspond with the number of days in the specified month
    if the month is February, is the year leap?
        Leap years are those years who are divisible with 400, or they are divisible with 4, but not with 100
*/

#include <stdio.h>
int main()
{
   int days,month,year;
   scanf("%d %d %d",&days,&month,&year);
   if(month<=12 && month>0 && days<=31 && days>0){
     if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)&& days<=31)
     {
      printf("YES");
     }

     else if((month==4||month==6 || month==9 || month==11 )&& days<=30)
     {
      printf("YES");
     }

     else if(month==2 && days<=29)
        {
       if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
          {
        printf("YES");
       }
       else if(days<=28)
       {
       printf("YES");
       }
       else{
        printf("NO");
       }

     }
     else
     {
     printf("NO");
     }

   }
   else
    {
   printf("NO");
   }

   return 0;
}