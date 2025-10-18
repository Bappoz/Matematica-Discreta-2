@echo off
echo Qual exercicio voce quer compilar?
echo 1 - Question1_rsa
echo 2 - Question2_chaves
echo 3 - Question3_algo
echo .
set /p escolha=Digite o numero: 
echo.
if "%escolha%"=="1" (
    gcc src\Questions\Question1_rsa.c src\tools\pollard.c src\tools\euclides.c src\tools\conversor.c src\tools\modular.c src\tools\utils\efeito_hacker.c src\tools\utils\ehprimo.c src\tools\chave_acesso.c -o src\bin\rsa.exe
	if %ERRORLEVEL% NEQ 0 (
		echo Erro na compilacao.
	) ELSE (
		echo Compilacao concluida!Executando...
		echo.
		echo Inicializando Criptografia RSA
		echo.
		src\bin\rsa.exe
	)

) else if "%escolha%"=="2" (
    gcc src\Questions\Question2_chaves.c src\tools\euclides.c -o src\bin\chaves_periodicas.exe
    if %ERRORLEVEL% NEQ 0 (
		echo Erro na compilacao.
	) ELSE (
		echo Compilacao concluida!Executando...
		echo.
		echo Inicializando Problema das Chaves Periodicas
		echo.
		src\bin\chaves_periodicas.exe
	)

) else if "%escolha%"=="3" (
    gcc src\Questions\Question3_algo.c -o bin\eficiencia.exe
	if %ERRORLEVEL% NEQ 0 (
		echo Erro na compilacao.
	) ELSE (
		echo Compilacao concluida!Executando...
		echo.
		echo Inicializando Criptografia RSA
		echo.
		src\bin\eficiencia.exe
	)


) else (
    echo Opcao invalida!
)

