#include "../../../include/ehprimo.h"
#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(long long n){
	if(n <= 1) return false;

    else if(n <= 3) return true;

    else if(n % 2 == 0 || n % 3 == 0) return false;

    for(long long i = 5; i * i < n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}
