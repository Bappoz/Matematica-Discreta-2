#include "../../include/modular.h"
#include "../../include/euclides.h"
#include "../../include/ehprimo.h"
#include "../../include/phi.h"
#include <stdio.h>

long long expoente_modular(long long base, long long exp, long long mod){
    long long resultado_mod = 1;
    
    long long exp_fixo = exp;
    long long base_fixa = base;
    base %= mod;

    while(exp > 0){

        if (exp % 2 == 1) resultado_mod = (resultado_mod * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    printf("O resto do %lld^%lld no mod(%lld)= %lld\n", base_fixa, exp_fixo, mod, resultado_mod);
    return resultado_mod;
}



long long aplicar_teorema_modular(long long base, long long exp, long long mod){
    if(mod == 0) return 0;

    if(mdc(base, mod) != 1) return expoente_modular(base, exp, mod);

    long long exp_reduzido;
    if(ehPrimo(mod)){
        // Usar fermat
        printf("Modulo %lld eh primo. Usando Teorema de Fermat.\n", mod);
        exp_reduzido = exp % (mod - 1);
    }
    else{
        // Usar Euler
        printf("Modulo %lld eh composto. Usando Teorema de Euler.\n", mod);
        long long phi_do_mod = phi(mod);
        exp_reduzido = exp % phi_do_mod;
    }

    printf("Expoente reduzido de %lld para %lld.\n\n", exp, exp_reduzido);
    return expoente_modular(base, exp_reduzido, mod);
}

