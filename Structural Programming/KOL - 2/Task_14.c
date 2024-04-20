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

    int above = matrix[0][1];
    int below = matrix[1][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;

            if(i < j){
                if(matrix[i][j] > above)
                    above = matrix[i][j];
            }else{
                if(matrix[i][j] < below)
                    below = matrix[i][j];
            }

        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                printf("%d ", matrix[i][j]);
            }
            else if(i < j){
                printf("%d ", above);
            }
            else{
                printf("%d ", below);
            }
        }

        printf("\n");
    }

    return 0;
}
