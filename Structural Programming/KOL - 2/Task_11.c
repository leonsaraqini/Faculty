#include <stdio.h>


int main() {
    int matrix[100][100];

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int newMatrix[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int number = 0;

            if(i > 0 && matrix[i - 1][j] > 0)
                number += matrix[i - 1][j];

            if(i < n - 1 && matrix[i + 1][j] > 0)
                number += matrix[i + 1][j];

            if(j > 0 && matrix[i][j - 1] > 0)
                number += matrix[i][j - 1];

            if(j < m - 1 && matrix[i][j + 1] > 0)
                number += matrix[i][j + 1];

            newMatrix[i][j] = number;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", newMatrix[i][j]);
        }
        printf("\n");
    }





    return 0;
}
