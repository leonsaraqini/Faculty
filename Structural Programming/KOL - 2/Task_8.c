#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int n, m;

    scanf("%d %d\n", &n, &m);

    int matrix[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int j = 0; j < m; j++){
        int sumFirstHalf = n % 2 == 0 ? 0 : matrix[n/2][j];
        int sumSecondHalf = 0;

        for(int i = 0; i < n; i++){

            if(n / 2 > i)
                sumFirstHalf += matrix[i][j];
            else
                sumSecondHalf += matrix[i][j];

        }

        matrix[n/2][j] = abs(sumFirstHalf - sumSecondHalf);

        if(n % 2 == 0)
            matrix[n / 2 - 1][j] =  abs(sumFirstHalf - sumSecondHalf);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
