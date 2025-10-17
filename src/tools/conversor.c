#include "../../include/conversor.h"
#include "../../include/modular.h"
#include "../../include/euclides.h"
#include "../../include/ehprimo.h"
#include "../../include/phi.h"
#include "../../include/efeito_hacker.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


BlocoDados codificar(const char *mensagem) {
    size_t len = strlen(mensagem);
    // Cada caractere se torna um bloco.
    long long *blocos = malloc(len * sizeof(long long));
    if (!blocos) return (BlocoDados){NULL, 0};

    size_t contador_de_blocos = 0;

    for (size_t i = 0; i < len; i++) {
        char caracter = mensagem[i];
        int codigo = -1; // Inicia com valor inválido

        if (caracter == ' ') {
            codigo = 0;
        } else if (isupper((unsigned char)caracter)) {
            codigo = caracter - 'A' + 11;
        }

        // Se o caractere for válido, adicione seu código como um novo bloco.
        if (codigo != -1) {
            blocos[contador_de_blocos++] = (long long)codigo;
        }
        // Ignora outros caracteres (pontuação, etc.)
    }
    

    return (BlocoDados){blocos, contador_de_blocos};
}


char* decodificar(BlocoDados blocos) {
    // Alocação exata: 1 caractere por bloco + 1 para o '\0'
    char *mensagem = malloc(blocos.tamanho + 1);
    if (!mensagem) return NULL;

    for (size_t i = 0; i < blocos.tamanho; i++) {
        long long bloco = blocos.dados[i]; // Bloco é o próprio código
        int codigo = (int)bloco;

        if (codigo == 0) {
            mensagem[i] = ' ';
        } else if (codigo >= 11 && codigo <= 36) {
            mensagem[i] = (char)(codigo - 11 + 'A');
        } else {
            mensagem[i] = '?'; // Caractere para código inválido
        }
    }

    mensagem[blocos.tamanho] = '\0'; // Adiciona o terminador nulo
    return mensagem;
}
