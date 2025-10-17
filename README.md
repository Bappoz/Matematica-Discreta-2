# Projeto: Matemática Discreta 2 — Implementação (Questão 1)

Este repositório contém implementações em C relacionadas ao enunciado da disciplina de Matemática Discreta 2. O objetivo é implementar ferramentas de criptografia/criptoanálise (RSA, Pollard Rho, operações modulares, etc.) organizadas em módulos reutilizáveis.

ATENÇÃO: neste momento a implementação cobre apenas a Questão 1. As demais questões ainda serão adicionadas.

## O que está implementado (estado atual)

- Etapa 1 — Fatoração usando o método Rho de Pollard (`src/tools/pollard.c`)
- Etapa 2 — Geração de chaves RSA mínimas (`src/tools/chave_acesso.c`)
- Etapa 3 — Criptografia / Decodificação de mensagens curtas (`src/tools/modular.c`, `src/tools/conversor.c`)
- Utilitários: `euclides.c` (MDC e inverso modular), `ehprimo.c`, `efeito_hacker.c` (simula efeito visual), `conversor.c` (codifica/decodifica texto em blocos)
- Script de compilação para Windows: `compilar.bat`
- Makefile (Linux/Git Bash) atualizado para compilar todos os .c sob `src/`

### Arquivos principais

- `src/Questions/Question1_rsa.c` — programa principal que orquestra as 3 etapas (Fluxo para a Questão 1).
- `src/tools/` — implementações das funções usadas (pollard, modular, euclides, etc.).
- `include/` — headers públicos para os módulos.

## Requisitos

- GCC (MinGW/MSYS2 em Windows, ou gcc no Linux). Certifique-se de que `gcc` esteja no PATH.
- Make (opcional) se for compilar com `make` em ambientes que o suportem.

## Como compilar

Windows (CMD/PowerShell):

1. Abra um terminal na pasta do repositório.
2. Execute:

```
./compilar.bat
```

--------------------------------------------------------------------

Git Bash / Linux:

```
./compilar.bat
# ou, usando make (se disponível):
# make
```

Nota: o `Makefile` também foi ajustado para incluir `-Iinclude` e compilar todos os `*.c` sob `src/` quando o `make` estiver disponível.

## Como executar

Depois de compilado, execute o programa gerado:

```
./src/bin/programa_rsa.exe
```

O programa pedirá dois números (N1 e N2) e uma mensagem para criptografar. Ele executa três etapas:

1. Fatoração de N1 e N2 com Pollard Rho — o objetivo é obter p (fator de N1) e q (fator de N2).
2. Geração de chaves RSA a partir de p e q (e = 65537, d calculado pelo inverso modular).
3. Codificação da mensagem em blocos, criptografia e decodificação para verificar o processo.

## Regras / Validações que o programa aplica (importante)

- Ambos os fatores resultantes p e q devem ser primos e distintos (p != q).
- `p` e `q` devem ser maiores que 2 (o programa rejeita pares com 2).
- `phi(n) = (p-1)*(q-1)` deve ser maior que 1.
- `mdc(e, phi(n))` deve ser 1 (caso contrário o inverso modular não existe).
- O módulo `n = p*q` deve ser maior que o maior bloco gerado pelo codificador. No esquema atual cada caractere é mapeado para um código entre 0 (espaço) e 36 (A..Z). Portanto, para mensagens simples de letras maiúsculas e espaços, é necessário `n > 36` (na prática use primos maiores para qualquer teste real).

Se alguma dessas validações falhar o programa aborta com uma mensagem indicando o motivo.

## Por que algumas entradas falham (exemplos e explicação)

- Se você fornecer N1=100 e N2=102, o Pollard Rho retorna fatores triviais (2), ou p=q=2, o que resulta em `phi(n)=1` e `n=4`. Isso quebra o esquema RSA aqui (expoente reduzido vira 0, informação se perde) — por isso o programa rejeita esses casos.
- Se `n <= maior_bloco` (por exemplo n=21 e um bloco = 25) a criptografia perde informação e a decodificação produzirá caracteres inválidos (`?`). Por isso há validação antes da criptografia.


# PROJETO DE CRIPTOGRAFIA RSA

Aluno: Lucas Andrade Zanetti
Matrícula: 241039645
Curso: Engenharia de Software - FCTE
