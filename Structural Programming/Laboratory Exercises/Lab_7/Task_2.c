#include<stdio.h>
#include<math.h>

float max(float * a, int n){
    float maxNumber = 0;

    for(int i = 0; i < n; i++) {
        if (*(a + i) > maxNumber)
            maxNumber = *(a + i);
    }

    return maxNumber;
}

float min(float * a, int n){
    float minNumber = max(a, n);

    for(int i = 0; i < n; i++) {
        if (*(a + i) < minNumber)
            minNumber = *(a + i);
    }

    return minNumber;
}

void normalize (float * a, int n){
    float minNumber = min(a, n);
    float maxNumber = max(a, n);
    
    for(int i = 0; i < n; i++){
        *(a + i) = (*(a + i) - minNumber) / (maxNumber - minNumber);
    }
}

void sort(float *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(*(a + j) < *(a + j + 1)){
                float tmp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = tmp;
            }
        }
    }
}

int main () {
    int n;

    scanf("%d", &n);

    float a[n];

    for(int i = 0; i < n; i++){
        scanf("%f", a + i);
    }

    printf("MAX -> %.3f\n", max(a, n));
    printf("MIN -> %.3f\n", min(a, n));

    normalize(a, n);
    sort(a, n);

    for(int i = 0; i < n; i++){
        printf("%.3f ", *(a + i));
    }

    return 0;
}


