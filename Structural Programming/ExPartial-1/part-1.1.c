//From SI read characters until you read the char !. In these characters are hidden integers (smaller than 100). Write a program that will read all characters and print the sum of all integers hidden in the text.

#include <stdio.h>

int main() {
    char c='.';
    int sumOfHidden=0,currNumber=0;
    while (c!='!'){
        scanf("%c",&c);
        if(c<='9' && c>='0'){
            int digit= c-'0';
            currNumber=10*currNumber+digit;
        }else{
            sumOfHidden+=currNumber;
            currNumber=0;
        }
    }
    printf("%d",sumOfHidden);
    return 0;
}