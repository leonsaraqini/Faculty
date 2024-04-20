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

    int count = 0;

    for(int i = 0; i < n; i++){
        count += matrix[i][i];
        for(int j = i + 1; j < n; j++){
            count += matrix[i][j] ^ matrix[j][i];
        }
    }

    printf("%d", count);

    return 0;
}
