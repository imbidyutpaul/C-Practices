#include<stdio.h>

    int main(){
    int age;
    printf("Enter you age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Congratulation you are adult\n");
        printf("You can vote\n");
        printf("You can see adult video\n");
        printf("you can apply for driving licence\n");
    }
    else {
        printf("Sorry bro, you are not adult\n");
    }
printf("Thank you for you amulya samay\n");
    return 0;
}