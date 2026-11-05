#include<stdio.h>
int main () {
   int sum = 0;
   int n, m;
   printf("enter first number: ");
   scanf("%d", &n);
   printf("enter second number: ");
   scanf("%d", &m);
   
   if(n > m) {
       printf("Error: first number should be less than or equal to second number\n");
       return 1;
   }
   
   for (int i = n; i <= m; i++) {
      sum = sum + i;
   }
   
   printf("sum is %d\n", sum);
   return 0;
}