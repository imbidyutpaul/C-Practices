// Logical operators
#include<stdio.h>
int main(){
printf("%d\n", 3==3 && 5>1);
printf("%d\n", 3==7 && 5>1);
printf("%d\n", 3==7 || 5>1);
printf("%d\n", 3==89 || 5>10);
printf("%d\n", !(5>100));
printf("%d\n", !((5==2) || (60>9)));
    return 0;
}