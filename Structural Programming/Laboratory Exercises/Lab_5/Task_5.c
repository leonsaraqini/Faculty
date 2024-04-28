#include <stdio.h>
void matrix(int n, int array[100][100]){
    int i,j,count=0,j1,i1;
    for(i=0;i<n;i++){
     for(j=0;j<n;j++){
         if(i==j && array[i][j]!=0){
             array[i][j]=0;
             count++;
         }
         if(array[i][j]!=array[j][i]){
             array[j][i]=array[i][j];
             count++;
         }
         
     }   
     
    }
    printf("%d",count);

}

int main() {

    int n,array[100][100],i,j;
    scanf("%d\n",&n);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            scanf("%d ",&array[i][j]);
        }
    }
    matrix(n,array);
    return 0;
}