#include "../../../include/phi.h"
#include <stdio.h>


long long phi(long long mod){
    long long resultado = mod;

    for (long long i = 2; i * i < mod; i++){

        if(mod % i == 0){
            resultado = resultado - resultado / i; 
            // formula de Euler => resultado - resultado / i => resultado * (1-1/p)

            while(mod % i == 0) mod /= i;
        }
    }

    // Para quando mod tiver um fator primo maior que a raiz quadrade
    if(mod > 1) resultado = resultado - resultado/mod;

    printf("%lld", resultado);
    return resultado;
}
