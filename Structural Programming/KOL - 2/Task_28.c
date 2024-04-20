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

    int finalResult = -1;
    int index;

    for(int i = 0; i < n; i++){
        int sum = 0;

        for(int j = 0; j < m; j++){
            sum += matrix[j][i];
        }

        if(finalResult == -1){
            finalResult = sum;
            index = i;
        }else if(sum < finalResult){
            finalResult = sum;
            index = i;
        }
    }

    printf("%d", index);

    return 0;
}
