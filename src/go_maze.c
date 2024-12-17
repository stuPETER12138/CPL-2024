//
// Created by wu on 24-12-16.
//
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
    while(1){
        printf("hello world\n");
        getch();
        if(getch() == 'q'){
            break;
        }
    }
    return 0;
}
