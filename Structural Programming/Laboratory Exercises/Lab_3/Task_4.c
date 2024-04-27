#include <stdio.h>

float power(float r, int n){
    int p = 1;

    for(int i = 0; i < n; i++){
        p *= r;
    }

    return (float)p;
}

int main()
{
    int m;

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        int n;
        scanf("%d", &n);

        int firstElem = 0;
        int secondElem = 0;

        int sG = 0;
        int sA = 0;

        for(int j = 0; j < n; j++){
            int digit;
            scanf("%d", &digit);

            if(!j){
                firstElem = digit;
            }else if(j == 1){
                secondElem = digit;
            }

            sG += digit;
            sA += digit;

        }

        int d = secondElem - firstElem;
        float r = secondElem / firstElem;

        float resultA = (n / 2.00) * ((2 * firstElem) + (n - 1) * d);

        float resultG = (firstElem * (power(r, n) - 1)) / (float)(r - 1);

        if(resultA == sA && resultG == sG || firstElem == secondElem){
            printf("BOTH ARITHMETIC AND GEOMETRIC PROGRESSION\n");
        }else if(resultA == sA){
            printf("ARITHMETIC PROGRESSION\n");
        }else if(resultG == sG){
            printf("GEOMETRIC PROGRESSION\n");
        }else{
            printf("THE SEQUENCE IS NOT A PROGRESSION\n");
        }

    }

    return 0;
}
