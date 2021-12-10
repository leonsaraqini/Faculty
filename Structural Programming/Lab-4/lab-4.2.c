/*A number N and N elements of an array are read from SI.

The array should be transformed in a new array where all the even elements should be increased by 1, and all the odd elements decreased by 1.

The transformed array should be printed to standard output and all the elements of the array should be separated with space between them.*/

#include <stdio.h>
#define MAX 100
int main() {
    int n,k,i,a[MAX];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d ",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            printf("%d ",a[i]+1);
        }else{
            printf("%d ",a[i]-1);
        }
    }
    return 0;
}