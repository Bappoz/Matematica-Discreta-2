#ifndef EUCLIDES_H
#define EUCLIDES_H

// MDC entre dois valores
long long mdc(long long a, long long b);

// Mdc estendido de euclides para achar o x e y
long long mdc_estendido(long long a, long long b, long long *x, long long *y);

//Retorna o inverso modular nos casos de divisão
long long inverso_modular(long long a, long long mod);

long long mmc(long long a, long long b);

#endif