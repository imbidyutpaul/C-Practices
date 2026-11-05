#include<stdio.h>

    int main(){
    int marks;
    printf("Enter you marks: ");
    scanf("%d", &marks);
    if (marks >= 90) {
        printf("You got A++\n");
    }
    else if ( marks <90 && marks >=80) {
        printf("You got A+\n");
    }
    else if ( marks < 80 && marks >= 60) {
        printf("You got A\n");
    }
    else if ( marks < 60 && marks >= 45) {
        printf("You got B\n");
    }
    else {
        printf("Sorry bro, you fail");
    }
    return 0;
}