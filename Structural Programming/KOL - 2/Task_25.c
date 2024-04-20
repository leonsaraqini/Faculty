#include <stdio.h>

int checkNum(int num, int flag){
    if(num < 10){
        if(num % 2 != 0)
            return 1;
        else
            return 0;
    }

    if(flag){
        if((num % 10) % 2 == 0)
            return checkNum(num / 10, 0) + 1;
        else
            return checkNum(num / 10, 0) + 0;
    }

    return checkNum(num / 10, flag);

}

int main() {
    int n;

    scanf("%d", &n);
    int flag = 0;

    for(int i = 0; i < n; i++){
        int num;

        scanf("%d", &num);

        if(checkNum(num, 1) == 2){
            printf("%d\n", num);
            flag++;
        }
    }

    if(!flag)
        printf("No such elements!");

    return 0;
}
