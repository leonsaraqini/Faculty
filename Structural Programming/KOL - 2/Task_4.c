#include <stdio.h>

int countOfDigit(int number, int digit){
    int count = 0;
    int position = 1;

    while(number){
        int dig = number % 10;

        if(dig == digit && position % 2 == 0)
            count++;

        position++;
        number /= 10;
    }

    return count;
}

int main() {
    int a,b,c;

    while(scanf("%d %d %d", &a, &b, &c) == 3){
        int countA = countOfDigit(a, c);
        int countB = countOfDigit(b, c);

        if(countA > countB)
            printf("%d\n", a);
        else if(countA < countB)
            printf("%d\n", b);
        else 
            printf("%d\n", a);

        

    }

    return 0;
}
