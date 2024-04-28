#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int n;

        scanf("%d", &n);

        int a[n];

        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]);
        }

        int count = 0;
        int difference;

        if(n % 2 == 0){
            difference = n / 2;
        }else{
            difference = (n / 2) + 1;
            count--;
        }

        for(int j = 0, k = n - 1; j < difference; j++, k--){
            if(a[j] == a[k])
                count += 2;
        }

        float percentage = ((float)count / n) * 100.00;
        printf("%.2f%%\n", percentage);

    }

    return 0;
}