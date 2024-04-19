#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a + b + c != 180){
        printf("NO");
        return 0;
    }

    printf("YES\n");

    if(a == 90 || b == 90 || c == 90){
        printf("RIGHT");
    }
    else if(a < 90 && b < 90 && c < 90){
        printf("ACUTE");
    }
    else{
        printf("OBTUSE");
    }

    return 0;
}
