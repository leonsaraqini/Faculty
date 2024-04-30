#include<stdio.h>
#include<math.h>

int afterDigitGreater(int n){
    if(n < 10)
        return 1;

    return ((n % 10) > (n / 10) % 10) * afterDigitGreater(n / 10);
}



int main () {
    int n;

    scanf("%d ", &n);

    for(int i = 0; i < n; i++){
        int number;

        scanf("%d", &number);

        if(afterDigitGreater(number))
            printf("DA\n");
        else
            printf("NE\n");
    }


    return 0;
}