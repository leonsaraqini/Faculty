#include<stdio.h>
#include<math.h>

int main () {

    int n, m;

    scanf("%d %d", &n, &m);

    int matrix[n][m];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }

    }

    int newMatrix[n][m];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            
            int sum = 0;

            if(j - 1 >= 0 && matrix[i][j - 1] > 0)
                sum += matrix[i][j - 1];

            if(j + 1 < m && matrix[i][j + 1] > 0)
                sum += matrix[i][j + 1];

            if(i - 1 >= 0 && matrix[i - 1][j] > 0)
                sum += matrix[i - 1][j];

            if(i + 1 < n && matrix[i + 1][j] > 0)
                sum += matrix[i + 1][j];

            newMatrix[i][j] = sum;
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