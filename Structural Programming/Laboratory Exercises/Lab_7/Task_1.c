#include<stdio.h>
#include<math.h>

void increment(int *a){
    *a += 1;
}

void decrement(int *a){
    *a -= 1;
}

void compare (int *a, int *b, char operator, int *result){

    switch (operator) {
        case '>' :
            *result = *a > *b;
            break;
        case '<':
            *result = *a < *b;
            break;
        default:
            *result = *a == *b;
    }
}


int main () {
    int a, b;

    scanf("%d %d", &a, &b);

    increment(&a);
    printf("Incremented a: %d\n", a);

    decrement(&b);
    printf("Decremented b: %d\n", b);

    int result;

    compare(&a, &b, '>', &result);
    printf("%d > %d -> %d\n", a, b, result);

    compare(&a, &b, '<', &result);
    printf("%d < %d -> %d\n", a, b, result);

    compare(&a, &b, '=', &result);
    printf("%d = %d -> %d\n", a, b, result);

    return 0;
}


