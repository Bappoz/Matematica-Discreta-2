/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Questão 03: Questão Bonus de Correção de Código e Quetão de V ou F
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int mdcComPassos(int a, int b){
    int resto;
    while(b != 0){ // [1] Corrijido
        resto = a % b;
        printf("Algoritmo de Euclides: %d mod %d = %d\n", a, b, resto);
        a = b;
        b = resto; // [2] Corrijido
    }
    return a; 
}

int inversoModular(int a, int m){
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    int A = a, B = m;

    mdcComPassos(a, m); // [3] Corrijido

    while (m != 0) {
        q = a / m;
        
        // Atualiza a, m
        t = m;
        m = a % m;
        a = t;

        // Atualiza x0, x1 (coeficientes de Bézout)
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if(x1 < 0){
        x1 += m0; // [4] Corrijido
    }

    printf("\nSubstituindo, temos que o inverso de %d em %d é %d.\n\n", A, B, x1);
    return x1;
}

int powMod(int base, int exp, int mod) {
    long long res = 1;
    long long b = base % mod; 

    while (exp > 0) {
        // [5] Corrijido: Verifica se o bit atual do expoente é 1 (se exp é ímpar)
        if (exp % 2 != 0) { // Equivalente a (exp % 2 != 0)
            res = (res * b) % mod;
        }
        b = (b * b) % mod; 
        
        exp >>= 1; 
    }
    return (int)res;
}

int main() {
#ifdef WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int H, G, Zn, x, n1;

    // Coleta de entradas do usuário
    printf("Insira H: ");
    scanf("%d", &H);
    printf("Insira G: ");
    scanf("%d", &G);
    printf("Insira Zn: ");
    scanf("%d", &Zn);
    printf("Insira x: ");
    scanf("%d", &x);
    printf("Insira n1: ");
    scanf("%d", &n1);
    printf("\n");

    // --- Início dos Cálculos ---

    // [6] Corrjido: Calcula a = H / G (mod Zn)
    int inverso = inversoModular(G, Zn);
    
    // LINHA 73 (corrigida)
    int a = ((H * inverso) % Zn); 

    printf("Fazendo a multiplicação modular: %d * %d mod %d = %d\n", H, inverso, Zn, a);
    printf("Sendo %d o inverso de %d.\n", inverso, G);


    // [7] Corrijido: Calcula o resultado final a^x (mod n1)
    int resultado = powMod(a, x, n1);

    printf("Valor final da congruência: %d\n", resultado);

    return 0;
}

// Entrada H: 7, G: 3, Zn: 11, x: 10, n1: 13
/*
Saída Gerada:
Insira H: 7
Insira G: 3
Insira Zn: 11
Insira x: 10
Insira n1: 13

Algoritmo de Euclides: 3 mod 11 = 3
Algoritmo de Euclides: 11 mod 3 = 2
Algoritmo de Euclides: 3 mod 2 = 1
Algoritmo de Euclides: 2 mod 1 = 0

Substituindo, temos que o inverso de 3 em 11 é 4.

Fazendo a multiplicação modular: 7 * 4 mod 11 = 6
Sendo 4 o inverso de 3.
Valor final da congruência: 4
*/