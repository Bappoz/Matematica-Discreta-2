/*
 * Aluno: Lucas Andrade Zanetti
 * Matrícula: 241039645
 * Disciplina: Matemática Discreta II
 * Professor: Cristiane Loesch de Souza Costa
 *
 * Função auxiliar: Dá um efeito de hacker/criptografia (Para diversão)
 */

#include "../../../include/efeito_hacker.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
// Função de delay para Windows (milissegundos)
void esperar_ms(int milissegundos) {
    Sleep(milissegundos);
}
#else
#include <unistd.h>
// Função de delay para Linux/macOS (milissegundos)
void esperar_ms(int milissegundos) {
    usleep(milissegundos * 1000);
}
#endif



void efeito_hacker(const char *prefixo, int duracao_ms) {
    // Caracteres que serão usados na animação
    const char *hacker_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;':,.<>/?";
    int num_hacker_chars = strlen(hacker_chars);

    // Número de caracteres aleatórios a serem exibidos por quadro
    int largura_animacao = 30;

    // Calcula o tempo final
    clock_t inicio = clock();
    double duracao_seg = duracao_ms / 1000.0;

    while (((double)(clock() - inicio) / CLOCKS_PER_SEC) < duracao_seg) {
        // 1. Move o cursor para o início da linha
        printf("\r%s", prefixo);

        // 2. Imprime uma sequência de caracteres aleatórios
        for (int i = 0; i < largura_animacao; i++) {
            printf("%c", hacker_chars[rand() % num_hacker_chars]);
        }

        // 3. Força a exibição imediata do que está no buffer
        fflush(stdout);

        // 4. Pequeno delay para controlar a velocidade da animação
        esperar_ms(50); // 50ms entre cada "quadro" da animação
    }

    // 5. Limpa a linha para a saída final
    printf("\r%s", prefixo);
    for (int i = 0; i < largura_animacao + 5; i++) printf(" "); // Imprime espaços para limpar
    printf("\r%s", prefixo); // Volta o cursor
    fflush(stdout);
}