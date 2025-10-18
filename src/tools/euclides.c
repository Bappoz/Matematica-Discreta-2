/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Arquivo .c resposável pelas funções relacionadas a lógica euclidiana: mdc, mdc_estendido, inverso_modular e mmc
 */

#include "../../include/euclides.h"   
#include <stdio.h>      

// Implementação simples do algoritmo de Euclides
long long mdc(long long a, long long b) {
    printf("[MDC] Calculando mdc(%lld, %lld)...\n", a, b);
    while (b != 0) {
        long long resto = a % b;
        long long quociente = a / b;
        /* imprimir a = b * quociente + resto antes de atualizar a e b */
        printf("[MDC] %lld = %lld * %lld + %lld\n", a, b, quociente, resto);
        a = b;
        b = resto;
    }
    printf("[MDC] Resultado: %lld\n\n", a);
    return a;
}

long long mdc_estendido(long long a, long long b, long long *x, long long *y){
    printf("[MDC Estendido] Iniciando mdc_estendido(%lld, %lld)\n", a, b);
    if(b == 0){
        *x = 1;
        *y = 0;
        printf("[MDC Estendido] base: retorna d=%lld, x=%lld, y=%lld\n", a, *x, *y);
        return a;
    }
    long long x1, y1;
    long long d = mdc_estendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    printf("[MDC Estendido] passo: a=%lld, b=%lld -> d=%lld, x=%lld, y=%lld\n", a, b, d, *x, *y);
    return d;
}

long long inverso_modular(long long a, long long mod){
    printf("[Inverso Modular] Calculando inverso de %lld mod %lld...\n", a, mod);
    long long x1, y1;
    long long d = mdc_estendido(a, mod, &x1, &y1);
    if( d != 1){
        printf("[Inverso Modular] Nao existe inverso modular.\n");
        return -1;
    }
    if ( x1 < 0 ) x1 += mod;
    printf("[Inverso Modular] Resultado: %lld\n", x1);
    return x1;

}

long long mmc(long long a, long long b){
    if(a == 0 || b == 0)return 0;
    long long g = mdc(a, b);
    long long result = (a / g) * b; // evita overflow
    printf("[MMC] mmc(%lld, %lld) = (a/g)*b = (%lld/%lld)*%lld = %lld\n", a, b, a, g, b, result);
    return result;
}

