#include<stdio.h>
void table(int n);

int main() {
    int n;
    printf("enter your number: ");
    scanf("%d", &n);
    table(n); //argument
    return 0;
}

void table(int n) { //parameter
    for (int i=1; i<=10; i++) {
        printf("%d\n", i*n);
    }
}

