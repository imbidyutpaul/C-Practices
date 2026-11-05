#include<stdio.h>
void calculate(float value);

int main () {
    float value;
    printf("enter price: ");
    scanf("%f", &value);
    printf("your price is %f\n", value);
    calculate(value);
    return 0;
}
void calculate (float value) {
    value = value + (0.18 * value);
    printf("final price is: %f\n", value);
}