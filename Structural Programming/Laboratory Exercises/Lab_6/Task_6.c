#include <stdio.h>

int sumEvenPosition(int number){
    if(number < 100) {
        return  ((number / 10) % 10);
    }
    return  ((number / 10) % 10)  + sumEvenPosition(number / 100 );
}


int main() {
    int number;
    scanf("%d\n",&number);
    printf("%d\n",sumEvenPosition(number));
    return 0;
}
