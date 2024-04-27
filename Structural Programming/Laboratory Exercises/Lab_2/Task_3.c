#include <stdio.h>

void Palindrome(int number){
    int firstDig = number / 100;
    int lastDig = number % 10;
    
    if(firstDig == lastDig){
        printf("Palindrome");
    }else{
        printf("Not palindrome");
    }
    
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    if(n >= 100 && n <= 999){
        Palindrome(n);
    }else{
        printf("Wrong input");
    }

    return 0;
}
