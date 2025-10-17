#include "../../include/chave_acesso.h"
#include "../../include/phi.h"
#include "../../include/euclides.h"
#include "../../include/ehprimo.h"
#include <stdio.h>


long long gerar_chaves(long long p, long long q, long long *n_ptr, long long *e_ptr, long long *d_ptr){
    if(!ehPrimo(p) || !ehPrimo(q)){
        printf("Erro: p e q devem ser números primos distintos.\n");
        return 0;
    }
    long long n = p*q;
    long long phi_n = (p - 1)*(q - 1);

    long long e = 65537; // Padrão industrial

    if (mdc(e, phi_n) != 1) return 0;

    long long d = inverso_modular(e, phi_n);
    if(d == -1) return 0;

    *n_ptr = n;
    *e_ptr = e;
    *d_ptr = d;

    return 0;

}
