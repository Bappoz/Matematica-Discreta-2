#include "euclides.h"
#include <stdio.h>

int mdc(int a, int b){
    while(b != 0){
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}




int main(){

    int a = 8;
    int b = 4;

    int result = mdc(a, b);
    printf("%d", result);

    return 0;

}