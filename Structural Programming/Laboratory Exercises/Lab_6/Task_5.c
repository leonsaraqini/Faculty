#include <stdio.h>


int findGreaterThanK(int number,int k,int coefficient) {
    if (number < 10) {
       return number > k ? number * coefficient : 0;
    }
    return (number % 10) > k ?
    (number % 10 * coefficient) + findGreaterThanK(number / 10 , k ,coefficient * 10) :
    findGreaterThanK(number / 10 , k ,coefficient);
}

int findSum(int number){
    if(number < 10) {
        return number;
    }
    return number % 10 + findSum(number / 10);
}


int main() {
    int n,k;
    scanf("%d", &k);
     scanf("%d", &n);
   
    for (int i = 0; i < n; i++) {
      int number;
      scanf("%d\n",&number);
      int founded=findGreaterThanK(number,k,1);
      printf("%d : %d\n",founded ,findSum(founded));
    }

  
    return 0;
}
