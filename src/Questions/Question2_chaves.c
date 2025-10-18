#include "../../include/euclides.h"
#include <stdio.h>


int main(){
    
    int N;
    long long ciclos[10];
    const int LIMITE_ANO = 50;
    printf("Entre um valor inteiro: ");
    scanf("%d", &N);

    if( N < 1 || N > 10){
        printf("N deve ser um inteiro entre 1 e 10\n");
        return 1;
    }

    for(int i = 0; i < N; i++){
        printf("Insira o valor %d do ciclo: ", i);
        scanf("%lld", &ciclos[i]);

        if(ciclos[i] < 2 || ciclos[i] > 20) return 1;

    }
    printf("\nCiclo gerado: ");
    for(int j = 0; j < N; j++ ){
        printf("%lld, ", ciclos[j]);
    }

    long long mmc_total = ciclos[0];

    for(int i = 1; i < N; i++){
        mmc_total = mmc(mmc_total, ciclos[i]);

        if(mmc_total > LIMITE_ANO){
            break;
        }
    }
    
    printf("\n\n--- Resultado ---\n");

    if(mmc_total > LIMITE_ANO){
        printf("Nao ha ano possivel dentro do limite de 50 anos.\n");
        printf("(O primeiro ano sincronizado seria %lld, que e maior que %d.)\n", mmc_total, LIMITE_ANO);
    }else{
        printf("O primeiro ano sincronizado e: %lld\n", mmc_total);
    }

    return 0;
}