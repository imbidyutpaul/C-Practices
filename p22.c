#include<stdio.h>
int main() {
    int marks;
    printf("Enter your amrks (0-100): ");
    scanf("%d", &marks);
    
    if (marks >=0 && marks < 30) {
    printf("FAIL\n");
   
    } else if (marks >= 30 && marks <=100) {
    printf("PASS\n");
    
    } else {
        printf("Wrong marks\n");
    }
   
    return 0;
}