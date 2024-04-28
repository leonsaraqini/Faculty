#include<stdio.h>
#include<math.h>

int powerOfTen(int number){
    int ten = 1;

    for(int i = 0; i < number; i++){
        ten *= 10;
    }

    return ten;
}

int digitCount(int number){
    int count = 0;

    for(int i = number ; i != 0; i /= 10){
        count++;
    }

    return count;
}

int getHalfOf (int number, char part){
    if(number < 10 || (number <= 10 && part == 'R'))
        return number;

    int count = digitCount(number);

    int ten = powerOfTen(count / 2);

    if(part == 'L' && count % 2 != 0)
        return number / (ten * 10);
    else if(part == 'R')
        return number % ten;
    else
        return number / ten;
}

void printInRange (int a, int b, char part){
    for(int i = a; i <= b; i++){
        int half = getHalfOf(i, part);
        int count = digitCount(i);

        if(half % count == 0)
            printf("%d\n", i);

    }
}

int main () {

    int a,b;

    scanf("%d %d", &a, &b);

    printf("LEFT PARTS TEST:\n");
    printInRange(a,b,'L');

    printf("RIGHT PARTS TEST:\n");
    printInRange(a,b,'R');

    return 0;
}