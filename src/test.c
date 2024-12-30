#include <stdio.h>

int main(){
    int count = 0;
    for (int i = 1; i < 4; i++){
        for (int ii = 0; ii < 4; ii++){
            for (int iii = 0; iii < 4; iii++){
                if (i != ii && ii != iii && i != iii){
                    int num = i * 100 + ii * 10 + iii;
                    printf("%d\n", num);
                    count +=1;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}