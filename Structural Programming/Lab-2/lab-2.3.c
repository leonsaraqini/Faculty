//Write a program that for a three digit number read from SI will check if it is palindrome or not, and will print out an appropriate message. The message is "Palindrome" if it is, and "Not palindrome" if it's not. If the number is not three digit number, write the message "Wrong input".

#include <stdio.h>
int main()
{
  int pal;
  scanf("%d",&pal);

  if(pal>=100 && pal<=999){
    if(pal/100 == pal%10)
    {
    printf("Palindrome");
    }
    else
    {
    printf("Not palindrome");
    }
  }
  else{
  printf("Wrong input");
  }

   return 0;
}