#include <stdio.h>
#include <string.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("rectangle.in", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    // vashiot kod ovde
    FILE *f = fopen("rectangle.in", "r");

    int n;

    fscanf(f, "%d", &n);
    int a[n];
    int k, l, overallCount = 0;

    for(int i = 0; i < n; i++)
        fscanf(f, "%d", &a[i]);

    for(int i = 0; i < n / 2 + 1; i++){
        int count = 0;

        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j])
                count++;
        }

        if(count > overallCount){
            overallCount = count;
            k = a[i];
        }

        if(count == overallCount){
            if(k < a[i]){
                l = k;
                k = a[i];
            }else if(l == 0 || l > a[i]){
                l = a[i];
            }
        }
    }

    for(int i = 0; i < l; i++){

        for(int j = 0; j < k; j++){
            printf("* ");
        }

        printf("\n");
    }

    fclose(f);
    return 0;
}
