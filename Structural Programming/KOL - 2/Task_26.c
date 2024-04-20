#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    int n;

    scanf("%d", &n);

    int matrix[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int newMatrix[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j]){
                newMatrix[i][j] = matrix[i][j];
                continue;
            }

            int sum = 0;

            if(i > 0)
                sum += matrix[i - 1][j];

            if(i < n - 1)
                sum += matrix[i + 1][j];

            if(j > 0)
                sum += matrix[i][j - 1];

            if(j < n - 1)
                sum += matrix[i][j + 1];

            if(sum >= 3)
                newMatrix[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", newMatrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
