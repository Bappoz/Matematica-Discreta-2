.PHONY: all rsa chaves algo clean

all:
    @echo "Use: make rsa | make chaves | make algo"

rsa:
    gcc src/Questions/Question1_rsa.c src/tools/pollard.c src/tools/euclides.c src/tools/conversor.c src/tools/modular.c src/tools/utils/efeito_hacker.c src/tools/utils/ehprimo.c src/tools/chave_acesso.c -o src/bin/rsa
    @echo "Compilado: src/bin/rsa"

chaves:
    gcc src/Questions/Question2_chaves.c src/tools/euclides.c -o src/bin/chaves_periodicas
    @echo "Compilado: src/bin/chaves_periodicas"

algo:
    gcc src/Questions/Question3_algo.c ... -o src/bin/algo
    @echo "Compilado: src/bin/algo"

clean:
    rm -f src/bin/rsa src/bin/chaves_periodicas src/bin/algo