#ifndef CONVERSOR_H
#define CONVERSOR_H
#include <stdlib.h>

typedef struct{
    long long *dados;
    size_t tamanho;
} BlocoDados;


BlocoDados codificar(const char *mensagem);
char *decodificar(BlocoDados blocos);

#endif
