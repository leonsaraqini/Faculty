#include <stdio.h>
#include <string.h>

typedef struct Transaction{
    int day;
    int month;
    int year;
    int amount;
    char currency[3];
}Transaction;

void printMKDTransactions(Transaction *t, int n){
    int index = 1;
    int total = 0;

    for(int i = 0; i < n; i++){
        if(strcmp(t[i].currency, "MKD") != 0)
            continue;
        
        if(t[i].amount < 1000)
            continue;

        if(t[i].year < 2013 || t[i].year > 2015)
            continue;

        total += t[i].amount;

        printf("%d. %02d/%02d/%d %d %s\n", index++, t[i].day, t[i].month, t[i].year, t[i].amount, t[i].currency);
    }

    printf("Total: %d MKD", total);
}

int main() {
    int n;
    scanf("%d", &n);

    Transaction t[n];

    for(int i = 0; i < n; i++){
        scanf("%d/%d/%d %d %s", &t[i].day, &t[i].month, &t[i].year, &t[i].amount, t[i].currency);
    }

    printMKDTransactions(&t, n);

    return 0;
}
