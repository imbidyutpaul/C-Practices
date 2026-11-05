#include<stdio.h>
int main() {
    int n;
    do {
        printf("Enter your number: ");
        scanf("%d", &n);
        if (n%7==0) {
            break;
        }
    } while(1);
printf("Your number is %d", n/7);

    return 0;
}