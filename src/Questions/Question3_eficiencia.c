/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Questão 03: A Razão de Eficiência de um Número
 */

#include <stdio.h>
#include <math.h> 


void calcular_razao_eficiencia(int N) {
    // Caso de borda N = 1, tratado separadamente
    if (N == 1) {
        printf("===================================================\n");
        printf("     Analise da Razao de Eficiencia de N = 1\n");
        printf("===================================================\n\n");
        printf("--- Passo 1: Fatoracao Prima (Trial Division) ---\n");
        printf("  (N=1 nao possui fatores primos)\n");
        
        printf("\n--- Passo 2: Calculos Finais de tau e sigma ---\n");
        printf("  tau(1) [Total de Divisores]:   1\n");
        printf("  sigma(1) [Soma dos Divisores]: 1\n");
        
        printf("\n--- Passo 3: Razao de Eficiencia (sigma / tau) ---\n\n");
        printf("                  1 / 1 = 1.00\n");
        printf("===================================================\n");
        return;
    }

    long long tau_total = 1;
    long long sigma_total = 1;
    int tmp = N; // Copia N para poder modificar durante a fatoração

    printf("===================================================\n");
    printf("     Analise da Razao de Eficiencia de N = %d\n", N);
    printf("===================================================\n\n");
    
    printf("--- Passo 1: Fatoracao Prima (Trial Division) ---\n");

    // Loop de Fatoração: testa divisores d de 2 até sqrt(tmp)
    for (int d = 2; d * d <= tmp; d++) {
        if (tmp % d == 0) {
            int expoente = 0;
            // Encontramos um fator primo 'd', agora contamos quantas vezes ele aparece
            while (tmp % d == 0) {
                expoente++;
                tmp /= d;
            }
            
            // Imprime o fator e expoente
            printf("  Fator primo: %d, Expoente: %d\n", d, expoente);

            // Calcula os termos de tau e sigma para este fator
            long long termo_tau = (expoente + 1);
            // (p^(a+1) - 1) / (p - 1)
            long long termo_sigma = (long long)(pow(d, expoente + 1) - 1) / (d - 1);

            // Imprime os cálculos intermediários, como pedido
            printf("    -> Termo tau(N):   (expoente + 1) = (%d + 1) = %lld\n", expoente, termo_tau);
            printf("    -> Termo sigma(N): (fator_primo^(expoente+1) - 1) / (fator_primo - 1) = %lld\n", termo_sigma);

            // Acumula os resultados totais
            tau_total *= termo_tau;
            sigma_total *= termo_sigma;
        }
    }

    // Caso Especial: se tmp sobrou e é maior que 1, ele é o último fator primo
    if (tmp > 1) {
        int d = tmp;
        int expoente = 1;

        printf("  Fator primo: %d, Expoente: %d\n", d, expoente);

        // Calcula os termos de tau e sigma para este fator
        long long termo_tau = (expoente + 1);
        long long termo_sigma = (long long)(pow(d, expoente + 1) - 1) / (d - 1);

        // Imprime os cálculos intermediários
        printf("    -> Termo tau(N):   (expoente + 1) = (%d + 1) = %lld\n", expoente, termo_tau);
        printf("    -> Termo sigma(N): (fator_primo^(expoente+1) - 1) / (fator_primo - 1) = %lld\n", termo_sigma);
        
        // Acumula os resultados totais
        tau_total *= termo_tau;
        sigma_total *= termo_sigma;
    }

    printf("\n\n--- Passo 2: Calculos Finais de tau e sigma ---\n");
    printf("   tau(N) [Total de Divisores]:   %lld\n", tau_total);
    printf("   sigma(N) [Soma dos Divisores]: %lld\n\n", sigma_total);

    // --- Passo 3: Cálculo da Razão de Eficiência ---
    
    // Usando (double) para forçar a divisão em ponto flutuante
    double razao = (double)sigma_total / (double)tau_total;

    printf("\n--- Passo 3: Razao de Eficiencia (sigma / tau) ---\n\n");
    printf("                 %lld / %lld = %.2f\n", sigma_total, tau_total, razao);
    printf("===================================================\n");
}


int main() {
    int N;

    printf("Digite um inteiro N (1 <= N <= 100000): ");
    scanf("%d", &N);

    // Validação da entrada
    if (N < 1 || N > 100000) {
        printf("Erro: O valor de N deve estar entre 1 e 100000.\n");
        return 1;
    }

    calcular_razao_eficiencia(N);

    return 0; 
}