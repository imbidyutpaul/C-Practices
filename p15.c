#include <stdio.h>

int main() {
    int x;
    printf("Enter your number: ");
    scanf("%d", &x);

    if (x > 9 && x < 1000) {
        printf("Your number is under 9-1000\n"); 
    } else {
        printf("Your number is not under 9-1000\n"); 
    }

    return 0;
}
