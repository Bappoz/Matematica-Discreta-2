Pasta src/bin — executáveis gerados

Propósito

Esta pasta contém os arquivos executáveis (binários) gerados durante a compilação dos exercícios (por exemplo, `rsa.exe`, `chaves_periodicas.exe`). O objetivo é separar o código-fonte (`src/`) dos artefatos de build.

Boas práticas

- Não comitar arquivos `.exe` neste repositório. Eles são artefatos de build e podem variar por plataforma. Use `.gitignore` para ignorar `src/bin/*.exe`.
- Mantenha a pasta no repositório com um arquivo placeholder se necessário (por exemplo `.gitkeep`) caso você queira que a pasta exista no repositório mesmo vazia.
- Para executar os programas localmente após compilar, rode os scripts de compilação na raiz do projeto (`compilar.bat` no Windows ou `compilar.sh` no Linux/Git Bash). Eles compilam os binários e os colocam nesta pasta.

Como usar

1. Compile o exercício desejado usando os scripts de compilação.
2. Execute o binário correspondente, por exemplo:

Windows:

```
src\bin\rsa.exe
```

Linux/Git Bash (se binários compatíveis):

```
./src/bin/rsa
```

Observação

Se preferir que a pasta seja rastreada pelo Git, adicione um arquivo `src/bin/.gitkeep` e commit. Assim a pasta fica visível mesmo se todos os binários estiverem ignorados.
