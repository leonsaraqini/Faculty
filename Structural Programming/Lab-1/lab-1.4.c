//Write a program that for given integer (number of seconds) read from standard input, will print out the hours, minutes and seconds.

#include <stdio.h>
int main() {
	int s, hours, min, sec;
	scanf("%d", &s);
	hours = (s/3600);
	min = (s -(3600*hours))/60;
	sec = (s -(3600*hours)-(min*60));
    printf("%d:%02d:%02d\n",hours,min,sec);
    return 0;
}