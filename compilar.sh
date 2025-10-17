#!/bin/bash
# Script de compilação para Linux e macOS

echo "Compilando o projeto RSA..."

# Cria o diretório bin se ele não existir
mkdir -p src/bin

# Comando de compilação
gcc src/tools/pollard.c src/Questions/Question1_rsa src/tools/modular.c src/tools/euclides.c src/tools/conversor.c src/tools/chave_acesso.c src/tools/utils/efeito_hacker.c src/tools/utils/ehprimo.c  -o src/bin/programa_rsa.exe -lm

echo "Compilacao concluida!"
echo "Para executar, digite: ./src/bin/programa_rsa"