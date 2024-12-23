//
// Created by wu on 24-12-16.
//
#include <stdio.h>

int main(){
    printf("Input a three-digit number: ");
    int num = 0;
    scanf("%d", &num);
    int a = 0, b = 0, c = 0;
    a = num / 100;
    b = num / 10 % 10;
    c = num % 10;
    int sum = 0;
    sum = 122 * a + 212 * b + 221 * c;
    printf("sum: %d\n", sum);
    return 0;
}
