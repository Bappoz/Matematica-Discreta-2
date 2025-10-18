/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Arquivo .c resposável pelas lógicas de exponenciação modular
 */

#include "../../include/modular.h"
#include "../../include/euclides.h"
#include "../../include/ehprimo.h"
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
    printf("\n");
    printf("O resto do %lld^%lld no mod(%lld)= %lld\n", base_fixa, exp_fixo, mod, resultado_mod);
    printf("\n");
    return resultado_mod;
}



long long aplicar_teorema_modular(long long base, long long exp, long long mod, long long phi_de_n) {
    
    printf("\n--- Calculando (%lld^%lld) %% %lld ---\n", base, exp, mod);

    long long exp_reduzido = exp;


    // 1. Pequeno Teorema de Fermat (caso acadêmico, pois n=p*q nunca é primo)
    if (ehPrimo(mod)) {
        printf("-> Condicao: O modulo n=%lld e primo.\n", mod);
        printf("-> Metodo Selecionado: Pequeno Teorema de Fermat.\n");
        long long redutor = mod - 1;
        exp_reduzido = exp % redutor;
        printf("-> Calculo: Expoente reduzido via Divisao Euclidiana: %lld %% %lld = %lld.\n", exp, redutor, exp_reduzido);
    }
    // 2. Teorema de Euler (caso principal do RSA)
    else if (mdc(base, mod) == 1) {
        printf("-> Condicao: mdc(M,n) = mdc(%lld, %lld) = 1.\n", base, mod);
        printf("-> Metodo Selecionado: Teorema de Euler.\n");
        
        // USA O PHI PRÉ-CALCULADO! MUITO MAIS RÁPIDO!
        long long redutor = phi_de_n;
        printf("Phi(n): %lld\n", phi_de_n);
        exp_reduzido = exp % redutor;
        printf("Expoente Reduzido: %lld\n", exp_reduzido);
    }
    // 3. Nenhuma redução possível
    else {
        printf("-> Condicao: mdc(M,n) = mdc(%lld, %lld) != 1. Nenhuma reducao de expoente via Fermat/Euler.\n", base, mod);
        printf("-> Metodo Selecionado: Exponenciacao por Quadrados com expoente original.\n");
    }
    
    // A chamada final para o cálculo passo a passo
    printf("-> Executando calculo final...\n");
    return expoente_modular(base, exp_reduzido, mod);
}