#include <stdio.h>

int ascending(int *arrPtr, int n) {
    if (n <= 1) {
        return 1; 
    }
    return (*(arrPtr + n ) > *(arrPtr + n - 1)) ? ascending(arrPtr, n - 1) : 0; 
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (ascending(a, n-1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
