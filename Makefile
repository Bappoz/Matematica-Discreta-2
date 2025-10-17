
CC = gcc

CFLAGS = -g -Wall
# -g -> Debug
# -Wall -> Para mostrar todos os avisos

BIN_DIR = src/bin

EXEC = $(BIN_DIR)/programa_rsa

# Find all .c sources under src/tools and src/Questions
SRCS := $(shell find src -name '*.c' -print)

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR = -Iinclude

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(SRCS) -o $(EXEC) -lm
	@echo "Programa '$(EXEC)' compilado com sucesso"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

# Limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(EXEC)
	@echo "Arquivos compilados foram removidos."