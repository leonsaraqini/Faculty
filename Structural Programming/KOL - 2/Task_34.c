#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    float matrix[n][n];
    float a[100];
    int k = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &matrix[i][j]);
            
            if(i == 0 || i == n - 1 || i + j == n - 1){
                a[k++] = matrix[i][j];
            }
        }
    }
    
    for(int i = 0; i < k; i++){
        printf("%.2f ", a[i]);
    }
    
    printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == n - 1 || i + j == n - 1){
                printf("%.2f ", a[--k]);
            }
            else{
                printf("%.2f ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    
    
    return 0;
}
