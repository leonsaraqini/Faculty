#include <stdio.h>

int prodEvenPosition(int number){
    if(number < 100) {
        return  ((number / 10) % 10);
    }
    return  ((number / 10) % 10)  * prodEvenPosition(number / 100 );
}


int main() {
    int number;
    scanf("%d\n",&number);
    printf("%d\n",prodEvenPosition(number));
    return 0;
}
