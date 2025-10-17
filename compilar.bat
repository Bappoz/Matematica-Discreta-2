@echo off
REM Script de compilação para Windows (requer GCC no PATH)

echo Compilando o projeto RSA...

REM Cria o diretorio bin se ele nao existir
if not exist src\bin mkdir src\bin

REM Comando de compilacao (adiciona -Iinclude para headers)
gcc -Wall -Wextra -std=c11 -I"include" ^
	src\tools\pollard.c ^
	src\Questions\Question1_rsa.c ^
	src\tools\modular.c ^
	src\tools\euclides.c ^
	src\tools\conversor.c ^
	src\tools\chave_acesso.c ^
	src\tools\utils\efeito_hacker.c ^
	src\tools\utils\ehprimo.c ^
	src\tools\utils\phi.c ^
	-o src\bin\programa_rsa.exe -lm

if %ERRORLEVEL% NEQ 0 (
	echo Erro na compilacao.
) ELSE (
	echo Compilacao concluida!
	echo Para executar, abra o terminal e digite: src\bin\programa_rsa.exe
)
pause