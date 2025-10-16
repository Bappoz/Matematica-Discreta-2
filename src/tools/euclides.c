#include "../../include/euclides.h"   
#include <stdio.h>      

// Implementação simples do algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        int quociente = a / b;
        printf("%d = %d*(%d) + %d\n", a, b, quociente, resto);
        a = b;
        b = resto;
    }
    return a;
}

int mdc_estendido(int a, int b, int *x, int *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int d = mdc_estendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return d;
}

int inverso_modular(int a, int mod){
    int x1, y1;
    int d = mdc_estendido(a, mod, &x1, &y1);
    if( d != 1){
        printf("Não Existe inverso modular");
        return -1;
    }

    if ( x1 < 0) x1 += mod;
    return x1;

}

