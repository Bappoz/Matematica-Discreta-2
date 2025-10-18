/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Questão 01: Criptografia RSA
 */

#include "../../include/pollard.h"
#include "../../include/chave_acesso.h"
#include "../../include/conversor.h"
#include "../../include/modular.h"
#include "../../include/efeito_hacker.h"
#include "../../include/ehprimo.h"
#include "../../include/euclides.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // --- ETAPA 1: FATORAÇÃO (O Criptoanalista) ---
    printf("====================================================\n");
    printf("     ETAPA 1: Fatoracao com Metodo Rho de Pollard\n");
    printf("====================================================\n\n");
    
    long long N1, N2;
    /* Ler N1 e N2 do usuário de forma segura */
    char buf[128];
    printf("N1: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Entrada inválida para N1\n");
        return 1;
    }
    N1 = strtoll(buf, NULL, 10);

    printf("N2: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Entrada inválida para N2\n");
        return 1;
    }
    N2 = strtoll(buf, NULL, 10);
    // (Aqui você pode colocar o código que pede para o usuário digitar N1 e N2)
    
    printf("Fatorando N1 = %lld...\n", N1);
    long long p = pollard(N1); // Chama a função do pollard.c

    printf("\nFatorando N2 = %lld...\n", N2);
    long long q = pollard(N2); // Chama a função do pollard.c

    if (p == -1 || q == -1) {
        printf("Falha na fatoracao. Encerrando.\n");
        return 1;
    }
    if (!ehPrimo(p) || !ehPrimo(q) || p==q || p<=2 || q<=2) {
        fprintf(stderr, "Pares invalidos: p=%lld, q=%lld. Use primos distintos e maiores que 2.\n", p, q);
        return 1;
    }

    printf("\n--- Primos RSA Definidos ---\n");
    printf("p = %lld (fator de N1)\n", p);
    printf("q = %lld (fator de N2)\n", q);
    printf("-----------------------------\n\n");


    // --- ETAPA 2: GERAÇÃO DE CHAVES (O Criptógrafo) ---
    printf("====================================================\n");
    printf("           ETAPA 2: Geracao de Chaves RSA\n");
    printf("====================================================\n\n");
    
    long long n, e, d;
    // Chama a função do chave_acesso.c
    if (!gerar_chaves(p, q, &n, &e, &d)) {
        printf("Falha ao gerar chaves. Encerrando.\n");
        return 1;
    }

    long long phi_n = (p - 1) * (q - 1); // phi(n) é necessário para a explicação
    printf("Chave Publica: {e=%lld, n=%lld}\n", e, n);
    printf("Chave Privada: {d=%lld, n=%lld}\n", d, n);
    printf("-----------------------------\n\n");


    // --- ETAPA 3: CRIPTOGRAFIA E DECODIFICAÇÃO (O Usuário) ---
    printf("====================================================\n");
    printf("      ETAPA 3: Criptografia e Decodificacao\n");
    printf("====================================================\n\n");

    char mensagem[300];
    printf("Digite uma frase para criptografar(Tudo Maisculo): ");
    if (fgets(mensagem, sizeof(mensagem), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler a mensagem\n");
        return 1;
    }
    // remover newline final, se houver 
    size_t len = strlen(mensagem);
    if (len > 0 && mensagem[len-1] == '\n') mensagem[len-1] = '\0';

    // 1. Codificar texto para blocos (usando conversor.c)
    BlocoDados blocos_originais = codificar(mensagem);
    /* Validações: garantir que n é grande o suficiente para representar todos os blocos */
    if (blocos_originais.dados == NULL || blocos_originais.tamanho == 0) {
        fprintf(stderr, "Erro: mensagem vazia ou codificacao falhou.\n");
        return 1;
    }

    long long max_block = 0;
    for (size_t i = 0; i < blocos_originais.tamanho; i++) {
        if (blocos_originais.dados[i] > max_block) max_block = blocos_originais.dados[i];
    }
    if (n <= max_block) {
        fprintf(stderr, "Erro: n = %lld eh pequeno demais para a mensagem (maior bloco = %lld).\n", n, max_block);
        fprintf(stderr, "Solucao: use primos p,q maiores (ou mude o esquema de codificacao).\n");
        free(blocos_originais.dados);
        return 1;
    }

    if (phi_n <= 1) {
        fprintf(stderr, "Erro: phi(n) = %lld inválido. Verifique p e q.\n", phi_n);
        free(blocos_originais.dados);
        return 1;
    }
    if (mdc(e, phi_n) != 1) {
        fprintf(stderr, "Erro: e=%lld não é coprimo com phi(n)=%lld.\n", e, phi_n);
        free(blocos_originais.dados);
        return 1;
    }
    
    // 2. Criptografar cada bloco (usando modular.c)
    printf("--- Criptografando ---\n");
    long long *blocos_cifrados = malloc(blocos_originais.tamanho * sizeof(long long));
    for (size_t i = 0; i < blocos_originais.tamanho; i++) {
        long long bloco_M = blocos_originais.dados[i];
        char prefixo_codificacao[100];

        sprintf(prefixo_codificacao, "Criptografando Bloco M=%-4lld: ", bloco_M);
        efeito_hacker(prefixo_codificacao, 1200);

        blocos_cifrados[i] = aplicar_teorema_modular(bloco_M, e, n, phi_n);
    }

    // 3. Decodificar cada bloco cifrado (usando modular.c)
    printf("\n--- Decodificando ---\n");
    long long *blocos_decodificados = malloc(blocos_originais.tamanho * sizeof(long long));
    for (size_t i = 0; i < blocos_originais.tamanho; i++) {
        long long bloco_C = blocos_cifrados[i];
        char prefixo_decodificacao[100];
        sprintf(prefixo_decodificacao, "Criptografando Bloco M=%-4lld: ", bloco_C);
        efeito_hacker(prefixo_decodificacao, 1200);

        blocos_decodificados[i] = aplicar_teorema_modular(bloco_C, d, n, phi_n);
    }
    
    // 4. Converter blocos decodificados de volta para texto (usando conversor.c)
    BlocoDados blocos_para_texto = {blocos_decodificados, blocos_originais.tamanho};
    char* mensagem_final = decodificar(blocos_para_texto);

    printf("\n--- RESULTADO FINAL ---\n");
    printf("Mensagem Decodificada: %s\n", mensagem_final);
    printf("====================================================\n");

    // Limpeza da memória
    free(blocos_originais.dados);
    free(blocos_cifrados);
    free(blocos_decodificados);
    free(mensagem_final);

    return 0;
}