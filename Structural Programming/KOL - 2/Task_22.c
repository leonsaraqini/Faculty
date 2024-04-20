#include <stdio.h>

int changes(int * a, int i, int j){
    if(i >= j) return 0;
    int maxNum = a[i] > a[j] ? a[i] : a[j];

    if(a[i] != maxNum){
        a[i] = a[j] = maxNum;
        return 1 + changes(a, i + 1, j - 1);
    }
    else{
        a[i] = a[j] = maxNum;
        return changes(a, i + 1, j - 1);
    }

}

int main() {
    int n;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int k;

    scanf("%d", &k);

    int countOfChanges = changes(a, 0, n - 1);

    printf("%d\n", countOfChanges);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
