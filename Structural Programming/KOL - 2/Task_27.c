#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n;

    scanf("%d %d", &m, &n);

    int matrix[100][100];


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int a[50], l = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int flag = 0;

            for(int k = 0; k < n; k++){
                if(k == j)
                    continue;

                if(matrix[i][k] == matrix[i][j]){
                    flag++;
                    break;
                }
            }

            if(!flag)
                a[l++] = matrix[i][j];
        }
    }

    if(!l){
        printf("N");
    }else{
        for(int i = 0; i < l; i++){
            printf("%d ", a[i]);
        }
    }

    return 0;
}
