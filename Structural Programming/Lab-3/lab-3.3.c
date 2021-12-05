/*Three number n, m and k are read from SI.

You task is to write a program that prints the first ten numbers in descending order from the interval from 0 - n, that contain the digit m, k times.

If there are no such number, print a message WRONG PARAMETERS. */

#include<stdio.h>

int main (){
int i,n,m,k;
scanf("%d %d %d", &n, &m, &k);
int firstTen = 0;

for (i=n;i>0;i--){
if (firstTen==10){
break;
}
int tmp = i;
int counter = 0;
while (tmp){
int lastDigit = tmp%10;
if (lastDigit==m){
++counter;
}
tmp/=10;
}
if (counter==k){
printf("%d\n", i);
firstTen++;
}

}

if (firstTen==0){
printf("WRONG PARAMETERS");
}
return 0;
}