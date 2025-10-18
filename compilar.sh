#!/bin/bash
echo "Qual exercicio voce quer compilar?"
echo "1 - Question1_rsa"
echo "2 - Question2_chaves"
echo "3 - Question3_algo"
read -p "Digite o numero: " escolha

if [ "$escolha" = "1" ]; then
    gcc src/Questions/Question1_rsa.c src/tools/pollard.c src/tools/euclides.c src/tools/conversor.c src/tools/modular.c src/tools/utils/efeito_hacker.c src/tools/utils/ehprimo.c src/tools/chave_acesso.c -o src/bin/rsa
    if [ $? -ne 0 ]; then
        echo "Erro na compilacao."
    else
        echo "Compilacao concluida!"
        echo "Para executar, digite: ./src/bin/rsa"
    fi

elif [ "$escolha" = "2" ]; then
    gcc src/Questions/Question2_chaves.c src/tools/euclides.c -o src/bin/chaves_periodicas
    if [ $? -ne 0 ]; then
        echo "Erro na compilacao."
    else
        echo "Compilacao concluida!"
        echo "Para executar, digite: ./src/bin/chaves_periodicas"
    fi

elif [ "$escolha" = "3" ]; then
    gcc src/Questions/Question3_eficiencia.c ... -o src/bin/eficiencia
    if [ $? -ne 0 ]; then
        echo "Erro na compilacao."
    else
        echo "Compilacao concluida!"
        echo "Para executar, digite: ./src/bin/eficiencia"
    fi

elif [ "$escolha" = "4" ]; then
    gcc src/Questions/Question4_bonus.c ... -o src/bin/bonus
    if [ $? -ne 0 ]; then
        echo "Erro na compilacao."
    else
        echo "Compilacao concluida!"
        echo "Para executar, digite: ./src/bin/bonus"
    fi

else
    echo "Opcao invalida!"
fi