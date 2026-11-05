#include<stdio.h>
int main () {
   int n;
   printf("enter you number: ");
   scanf("%d", &n);
   float fact=1;
   for (int i=1; i<=n; i++) {
    fact=fact*i;
   }
   printf("your numebr is %f\n", fact);
    return 0;
}