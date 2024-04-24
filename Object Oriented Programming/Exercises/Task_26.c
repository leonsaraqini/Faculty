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
        if(strcmp(t[i].currency, "USD") != 0)
            continue;

        if(t[i].amount > 5000)
            continue;

        if(t[i].month > 3)
            continue;

        total += t[i].amount;

        printf("%d. %02d/%02d/%d %d %s\n", index++, t[i].day, t[i].month, t[i].year, t[i].amount, t[i].currency);
    }

    printf("Total: %d USD", total);
}

int main() {
    int n;
    scanf("%d", &n);

    Transaction t[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d %d/%d/%d", t[i].currency, &t[i].amount, &t[i].day, &t[i].month, &t[i].year);
    }

    printMKDTransactions(&t, n);

    return 0;
}
