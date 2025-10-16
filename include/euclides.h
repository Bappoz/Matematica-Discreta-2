#ifndef EUCLIDES_H
#define EUCLIDES_H

// MDC entre dois valores
int mdc(int a, int b);

// Mdc estendido de euclides para achar o x e y
int mdc_estendido(int a, int b, int *x, int *y);

//Retorna o inverso modular nos casos de divisão
int inverso_modular(int a, int mod);



#endif