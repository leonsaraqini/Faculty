#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int getValueBlue(int matrix[100][100], int i, int j, int n){
    int sum = 0;

    int k = i - 1;
    int l = j + 1;

    for( ; l < n; l++){
        sum += matrix[i][l];
    }

    for(; k > -1; k--){
        sum += matrix[k][j];
    }

    return sum;
}

int getValueRed(int matrix[100][100], int i, int j, int n){
    int sum = 0;

    int k = i + 1;
    int l = j - 1;

    for( ; l > -1; l--){
        sum += matrix[i][l];
    }

    for(; k < n; k++){
        sum += matrix[k][j];
    }

    return sum;
}

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
            if(i != j && i + j != n - 1)

                newMatrix[i][j] = matrix[i][j];
                
            else{

                if(i == j){
                    newMatrix[i][j] = getValueBlue(matrix, i, j, n);
                }
                else{
                    newMatrix[i][j] = getValueRed(matrix, i, j, n);
                }

            }
            
            if(i == j && i + j == n - 1 && n % 2 != 0)
                newMatrix[i][j] = getValueBlue(matrix, i, j, n) + getValueRed(matrix, i, j, n);

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
