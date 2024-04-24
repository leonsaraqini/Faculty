#include <stdio.h>
#include <string.h>
#define WEEKS 4
#define DAYS 5

// here the struct WorkingWeek

typedef struct WorkingWeek WW;

struct WorkingWeek{
    int hours[DAYS];
};

// here the struct Worker

typedef struct Worker W;

struct Worker{
    char name[50];
    WW weeks[WEEKS];
};
// here the functions
int maxWeek(W *w){
    int numberOfWeek = 0;
    int maxWorkingHours = 0;

    for(int i = 0; i < WEEKS; i++){
        int tmpMaxWorkingHours = 0;

        for(int j = 0; j < DAYS; j++){
            tmpMaxWorkingHours += w->weeks[i].hours[j];
        }

        if(tmpMaxWorkingHours > maxWorkingHours){
            maxWorkingHours = tmpMaxWorkingHours;
            numberOfWeek = i + 1;
        }
    }

    return numberOfWeek;
}

void table(W *w, int n){
    printf("Wor\t1\t2\t3\t4\tTotal\n");

    for(int i = 0; i < n; i++){
        int total = 0;

        printf("%s\t", w[i].name);

        for(int j = 0; j < WEEKS; j++){
            int sumOfHours = 0;

            for(int k = 0; k < DAYS; k++){
                sumOfHours += w[i].weeks[j].hours[k];
            }
            printf("%d\t", sumOfHours);

            total += sumOfHours;
        }
        printf("%d\n",total);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    W workers[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", workers[i].name);
        int j;
        for (j = 0; j < WEEKS; ++j) {
            int k;
            for (k = 0; k < DAYS; ++k) {
                scanf("%d", &workers[i].weeks[j].hours[k]);
            }

        }
    }
    printf("TABLE\n");
    table(workers, n);
    printf("MAX WEEK OF WORKER: %s\n", workers[n / 2].name);
    printf("%d\n", maxWeek(&workers[n / 2]));
    return 0;
}
