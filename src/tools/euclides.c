#include "../../include/euclides.h"   
#include <stdio.h>      

// Implementação simples do algoritmo de Euclides
long long mdc(long long a, long long b) {
    //prlong longf("\n Resolvendo MDC: \n");
    while (b != 0) {
        long long resto = a % b;
        //long long quociente = a / b;
        //print longf("%d = %d*(%d) + %d\n\n", a, b, quociente, resto);
        a = b;
        b = resto;
    }
    return a;
}

long long mdc_estendido(long long a, long long b, long long *x, long long *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long d = mdc_estendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return d;
}

long long inverso_modular(long long a, long long mod){
    long long x1, y1;
    long long d = mdc_estendido(a, mod, &x1, &y1);
    if( d != 1){
        printf("Não Existe inverso modular");
        return -1;
    }

    if ( x1 < 0 ) x1 += mod;
    return x1;

}

