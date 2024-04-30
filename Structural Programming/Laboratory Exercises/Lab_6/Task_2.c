#include <stdio.h>



int countEvenRecursive(int number){
    if(number < 10) {
     return number % 2 == 0 ?  1 : 0; 
    }
    return ((number % 10 ) % 2 )== 0 ? 1 + countEvenRecursive(number / 10) :  countEvenRecursive(number / 10);
}

int main() {
    int n;
    scanf("%d", &n);
   
    for (int i = 0; i < n; i++) {
      int number;
      scanf("%d\n",&number);
      printf("%d\n",countEvenRecursive(number));
    }

  
    return 0;
}
