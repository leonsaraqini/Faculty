#include <stdio.h>
#include <ctype.h>



int main() {
    int n, m;

    scanf("%d %d\n", &n, &m);

    int matrix[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int k, l;

    scanf("%d %d", &k, &l);

    if(matrix[k][l] != 1){
        matrix[k][l] = 1;
        
        for(int i = l - 1; i > -1; i--){
            if(matrix[k][i] == 1)
                break;

            matrix[k][i] = 1;
        }

        for(int i = l + 1; i < m; i++){
            if(matrix[k][i] == 1)
                break;

            matrix[k][i] = 1;
        }

        for(int i = k + 1; i < n; i++){
            if(matrix[i][l] == 1)
                break;

            matrix[i][l] = 1;
        }

        for(int i = k - 1; i > -1; i--){
            if(matrix[i][l] == 1)
                break;

            matrix[i][l] = 1;
        }

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }





    return 0;
}
