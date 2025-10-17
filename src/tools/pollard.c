#include "../../include/pollard.h"
#include "../../include/euclides.h"
#include <stdio.h>
#include <math.h>


long long int g(int x, int n){
    return ((x * x) + 1) % n;
}


int pollard(int n){
    if (n % 2 == 0) return 2;

    long long x = 2; long long int y = 2;
    int d = 1;
    int contador = 0;
    while(d == 1){

        printf("X%d = %lld, Y%d = %lld\n\n", contador, x, contador, y);

        x = g(x, n);
        printf("G(x) = %lld\n", x);
        y = g(g(y, n), n);
        printf("G(y) = %lld\n", y);

        long long int diff = x - y;
        if(diff < 0) diff = -(diff);
        printf("|%lld - %lld| = %lld\n\n", x, y, diff);
        
        d = mdc(diff, n);
        printf("\n");
        contador++;
    }

    if( d == n ){
        return -1;
    }

    return d;
}


