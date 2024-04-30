#include <stdio.h>


int checkRecursive(int number) {
    if (number < 10) {
        return 1;
    }
    return (number % 10 >= number / 10 % 10) ? 0 : checkRecursive(number / 10);
}


int main() {
    int n;
    scanf("%d", &n);
   
    for (int i = 0; i < n; i++) {
      int number;
      scanf("%d\n",&number);
      printf("%d\n",checkRecursive(number));
    }

  
    return 0;
}
