//
// Created by wu on 24-12-16.
//
#include <stdio.h>

int main(){
    int number = 0;
    printf("请告诉我和值：");
    int number_sum;
    scanf("%d", &number_sum);
    for(int a = 1; a <= 9; a++){
        for(int b = 1; b <= 9; b++){
            for(int c = 1; c <= 9; c++){
                int sum = 0;
                sum = 122 * a + 212 * b + 221 * c;
                if(sum == number_sum){
                    number = 100 * a + 10 * b + c;
                }
            }
        }
    }
    if(number == 0){
        printf("你算错了！");
    }else{
        printf("你想的数是：%d", number);
    }
    return 0;
}
