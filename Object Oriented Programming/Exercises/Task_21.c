#include<stdio.h>
#include<string.h>

typedef struct SkiLift{
    char name[15];
    int maxNumOfUsers;
    int isFunction;
}SkiLift;

typedef struct SkiCenter{
    char name[20];
    char country[20];
    SkiLift lifts[20];
    int numOfSkiLifts;
}SkiCenter;

void biggestCapacity(SkiCenter *sc, int n){
    int maxCapacity = 0;
    int maxSkiLifts = 0;
    char name[20];
    char country[20];

    for(int i = 0; i < n; i++){
        int capacity = 0;

        for(int j = 0; j < sc[i].numOfSkiLifts; j++){
            if(!sc[i].lifts[j].isFunction) continue;

            capacity += sc[i].lifts[j].maxNumOfUsers;
        }
        
        if(capacity > maxCapacity || (capacity == maxCapacity && maxSkiLifts < sc[i].numOfSkiLifts)){
            maxSkiLifts = sc[i].numOfSkiLifts;
            maxCapacity = capacity;
            strcpy(name, sc[i].name);
            strcpy(country, sc[i].country);
        }

    }

    printf("%s\n%s\n%d", name, country, maxCapacity);
}

int main() {
    int n;

    scanf("%d", &n);

    SkiCenter skiCenters[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", skiCenters[i].name, skiCenters[i].country, &skiCenters[i].numOfSkiLifts);

        for(int j = 0; j < skiCenters[i].numOfSkiLifts; j++){
            scanf("%s %d %d", skiCenters[i].lifts[j].name, &skiCenters[i].lifts[j].maxNumOfUsers, &skiCenters[i].lifts[j].isFunction);
        }
    }

    biggestCapacity(skiCenters, n);
    return 0;
}
