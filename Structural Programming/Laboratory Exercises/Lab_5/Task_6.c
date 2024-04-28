#include<stdio.h>
#include<math.h>

int main () {
    
    int n;
    
    scanf("%d", &n);
    
    int matrix[n][n];
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
        
    }
    
    int largestUpper = matrix[0][1];
    int smallestLower = matrix[1][0];
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            
            if(i == j)
                continue;
            
            if(i < j && matrix[i][j] >= largestUpper)
                largestUpper = matrix[i][j];
            
            if(i > j && matrix[i][j] <= smallestLower)
                smallestLower = matrix[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            if(i == j)
                printf("%d ", matrix[i][j]);
            else if(i < j)
                printf("%d ", largestUpper);
            else
                printf("%d ", smallestLower);
        }
        
        printf("\n");
    }
    
	return 0;
}