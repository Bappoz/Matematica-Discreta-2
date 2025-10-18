#include "../../../include/ehprimo.h"
#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(long long n){
    printf("[ehPrimo] Testando primalidade de %lld...\n", n);
    if(n <= 1) {
        printf("[ehPrimo] %lld nao e primo.\n", n);
        return false;
    }
    if(n <= 3) {
        printf("[ehPrimo] %lld e primo.\n", n);
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0) {
        printf("[ehPrimo] %lld nao e primo.\n", n);
        return false;
    }
    for(long long i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) {
            printf("[ehPrimo] %lld nao e primo.\n", n);
            return false;
        }
    }
    printf("[ehPrimo] %lld e primo.\n", n);
    return true;
}
