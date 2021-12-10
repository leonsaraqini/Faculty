/*An integer N is read from SI. Afterwards N arrays of integers (with maximum length of 100 elements) are read from SI. For each array, firstly the size of the array is read, and then the elements of the array.

Your task is to write a program which for each array read from SI will print the percentage of equal symmetric numbers in the array. Symmetric elements in an array are the first and the last, the second and element before the last, etc.

If the array has odd number of elements, then the middle element is considered both symmetric and equal.

Input:

3
5 7 2 5 2 8
6 1 2 3 3 1 1
8 8 4 8 3 2 1 4 8

Output and explanation:

60.00% (2,2,5 are symmetrical and equal -> 3/5 elements -> 60%)
66.67% (1,1,3,3 are symmetrical and equal -> 4/6 elements -> 66.67%)
50.00% (8,8,4,4 are symmetrical and equal -> 4/8 elements -> 50.00%)
*/

#include <stdio.h>
#define MAX 100
int main() {
     int n,m,i;
    int a[MAX];
     scanf("%d\n",&n);
     while(n){
         scanf("%d ",&m);
         for(i=0;i<m;i++){
             scanf("%d ",&a[i]);
         }
         float sym=0;
         if(m%2==0){
             for(i=0;i<(m/2);i++){
                 if(a[i]==a[(m-1)-i]){
                     sym+=2;
                 }
             }
         }else{
             sym=1;
             for(i=0;i<((m-1)/2);i++){
                 if(a[i]==a[(m-1)-i]){
                     sym+=2;
                 }
             }
         }
         float rez=(sym/m)*100;
         printf("%.2f%%\n",rez);
         n--;
     }
    return 0;
}