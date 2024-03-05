# Definição de variáveis
SRC_DIR := CodigoPrincipal
CSV_FILE := ../artigo.csv

# Regra de compilação do programa upload
upload: $(SRC_DIR)/upload.cpp
	g++ $^ -o $@

# Regra de compilação do programa menu
menu: $(SRC_DIR)/menu.cpp
	g++ $^ -o $@

# Regra para preparar o upload do arquivo artigo.csv
Preparar: upload
	./upload $(CSV_FILE)

# Regra para rodar o programa menu
Rodar: menu
	./menu

# Regra para limpar arquivos gerados
clean:
	rm -f upload menu
