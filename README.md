# Projeto: Matemática Discreta 2 — Implementação em C

Este repositório contém implementações em C para as principais questões de criptografia e aritmética da disciplina. O código é modular, com scripts interativos para compilar e rodar cada questão separadamente.

## Como compilar e rodar

- **Windows:**
  - Execute `compilar.bat` no terminal. O script perguntará qual questão deseja compilar (1, 2, 3 ou 4). Basta digitar o número e o programa correspondente será compilado e executado automaticamente.
- **Linux/Git Bash:**
  - Dê permissão de execução primeiro: `chmod +x compilar.sh` (e se usar Makefile: `chmod +x Makefile`)
  - Execute `./compilar.sh` ou `make`. Ambos permitem escolher a questão pelo terminal, de forma semelhante ao `.bat`.
- Os scripts compilam e executam apenas o exercício selecionado, facilitando testes, organização e correção.
- **Caso Esteja usando terminal bash no Windows**
  - Na raiz do projeto execute `./compilar.bat` no terminal. O script perguntará qual questão deseja compilar (1, 2, 3 ou 4). Basta digitar o número e o programa correspondente será compilado e executado automaticamente.

## O que faz cada questão

### Questão 1 — RSA e Pollard Rho

- Solicita dois números compostos N1 e N2 (entre 100 e 9999) e uma mensagem.
- Fatora N1 e N2 usando o método de Pollard Rho (x₀ = 2, y₀ = 2, g(x) = x² + 1 mod n), exibindo as iterações essenciais.
- Gera as chaves RSA (n, e, d) a partir dos primos encontrados.
- Codifica, criptografa e decodifica a mensagem em blocos, mostrando o processo.
- Prints mostram: iterações do Pollard, fatores, chaves e blocos.

### Questão 2 — Ciclos e MMC

- Recebe do usuário uma lista de ciclos periódicos (ex: 2, 4, 6, 8).
- Calcula o ano de sincronização usando o MMC dos valores, mostrando o passo a passo do cálculo.
- Exibe o resultado final e, se não houver ano possível dentro do limite, informa ao usuário.

### Questão 3 — Eficiência de Algoritmos

- Compara a eficiência de diferentes algoritmos de MDC (Euclides, subtração, etc.) e de exponenciação modular.
- Mede e exibe o tempo de execução e o número de operações de cada método para diferentes entradas.
- Ajuda a visualizar qual algoritmo é mais eficiente em cada situação.

### Questão 4 — Resposta Objetiva

- A resposta objetiva e explicação detalhada da questão 4 está no arquivo [`docs/Q4_Answer.md`](docs/Q4_Answer.md).
- Consulte esse arquivo para a justificativa teórica e exemplos.

## Exemplos de N1 e N2 para Questão 1

| N1   | Fatores de N1 | N2   | Fatores de N2 |
| ---- | ------------- | ---- | ------------- |
| 221  | 13 × 17       | 899  | 29 × 31       |
| 143  | 11 × 13       | 437  | 19 × 23       |
| 323  | 17 × 19       | 667  | 23 × 29       |
| 391  | 17 × 23       | 713  | 23 × 31       |
| 2021 | 43 × 47       | 7429 | 61 × 73       |

Evite números com mais de dois fatores primos (ex: 1001), pois o Pollard pode encontrar divisores compostos e o programa pode não funcionar como esperado.

## Organização dos arquivos

- `src/Questions/Question1_rsa.c` — RSA e Pollard Rho (fatoração, geração de chaves, criptografia)
- `src/Questions/Question2_chaves.c` — MMC de ciclos periódicos
- `src/Questions/Question3_eficiencia.c` — Eficiência de algoritmos
- `src/Questions/Question4_bonus.c` — (se aplicável)
- `src/tools/` — Funções auxiliares (fatoração, MDC, modular, primalidade, etc.)
- `include/` — Headers dos módulos
- `docs/Q4_Answer.md` — Resposta detalhada da questão 4

## Sobre os scripts de compilação

- **compilar.bat** (Windows): Pergunta qual questão deseja compilar/rodar. Compila apenas o arquivo necessário e executa o programa correspondente.
- **compilar.sh** (Linux/Git Bash): Funciona de forma semelhante ao `.bat`, interativo e fácil de usar.
- **Makefile**: Permite compilar cada questão individualmente com `make questao1`, `make questao2`, etc., ou todas de uma vez com `make all`.

## Observações

- O código segue o roteiro da professora, com prints apenas do necessário para entendimento do processo.
- Scripts de compilação permitem escolher facilmente qual questão compilar e rodar, tornando o uso prático e organizado.
- Para dúvidas sobre a questão 4, consulte o arquivo `Q4_Answer.md`.

---

Aluno: Lucas Andrade Zanetti — Engenharia de Software - FCTE
