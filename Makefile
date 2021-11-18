CC = gcc

CFLAGS = -c -fdiagnostics-color=always -g

INCLUDE = ./include
SOURCE  = ./src
OUT = ./out

defaults: final

final: out funcoes main linkar

debug: out conversoes funcoes main linkar

out: 
	@echo "Fazendo out"
	@rm -rf $(OUT) final
	@mkdir -p $(OUT)

conversoes: $(SOURCE)/conversoes.c $(INCLUDE)/conversoes.h
	@echo "Compilando conversoes.c"
	$(CC) -o $(OUT)/conversoes.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/conversoes.c 

funcoes: $(SOURCE)/funcoes.c $(INCLUDE)/funcoes.h
	@echo "Compilando funcoes.c"
	$(CC) -o $(OUT)/funcoes.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/funcoes.c

main: $(SOURCE)/main.c
	@echo "Compilando main.c"
	$(CC) -o $(OUT)/main.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/main.c

linkar: $(OUT)
	@echo "Linkando os objetos"
	$(CC) -o final $(OUT)/*