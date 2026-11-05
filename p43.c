#include<stdio.h>
//declaration
void printhello();

int main() {
    printhello();
    printhello();
    printhello(); //function call
    return 0;
}
//function definition 
void printhello() {
    printf("hello!\n");
}