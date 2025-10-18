#include "../../include/pollard.h"
#include "../../include/euclides.h"
#include "../../include/ehprimo.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Multiplicação modular segura para evitar overflow em 64-bit
// Utilizado simplesmente para evitar bugs de overflow, possibilitando números extremamente grandes
static long long mul_mod(long long a, long long b, long long mod){
    unsigned long long ua = (unsigned long long)((a % mod + mod) % mod);
    unsigned long long ub = (unsigned long long)((b % mod + mod) % mod);
    unsigned long long res = 0ULL;
    while(ub){
        if(ub & 1ULL) res = (res + ua) % (unsigned long long)mod;
        ua = (ua + ua) % (unsigned long long)mod;
        ub >>= 1ULL;
    }
    return (long long)res;
}

long long int g(long long x, long long n){
    // g(x) = x^2 + 1 (mod n) usando mul_mod para evitar overflow
    long long sq = mul_mod(x, x, n);
    long long out = (sq + 1) % n;
    if(out < 0) out += n;
    return out;
}


long long pollard(long long n){
    if (n % 2 == 0) return 2;

    long long x = 2; long long y = 2;
    long long d = 1;
    int contador = 1;
    printf("Iteracao |        x        |       y     |   |y - x|  | mdc(|y-x|, N)\n");
    printf("----------------------------------------------------------------------\n");

    while(d == 1){  
        //printf("X%d = %lld, Y%d = %lld\n\n", contador, x, contador, y);

        x = g(x, n);
        //printf("G(x) = %lld\n", x);
        y = g(g(y, n), n);
        //printf("G(y) = %lld\n", y);

    long long diff = llabs(y - x);
        d = mdc(diff, n);
        printf("%8d | %15lld | %11lld | %10lld | %lld\n", contador, x, y, diff, d);
        printf("\n");
        contador++;
    }

    if( d == n ){
        printf("----------------------------------------------------------------------\n");
            printf("Falha: O algoritmo encontrou o fator trivial %lld.\n", n);
            printf("Isso ocorre quando a semente (x0=2) e a funcao g(x) geram um ciclo azarado para este numero.\n");
        return -1;
    }

    while(!ehPrimo(d)){
        printf("Fator encontrado (%lld) nao e primo. Fatorando novamente...\n", d);
        long long novo = pollard(d);
        if(novo == -1) return -1;
        d = novo;
    }

    printf("----------------------------------------------------------------------\n");
    printf("O fator primo encontrado de acordo com o metodo de Pollard e: %lld\n", d);
    return (int)d;
}


