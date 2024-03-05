#include <iostream>
#include <fstream>
#include <cstring>
#include "../CodigoAuxiliar/Base_Insercao_Hash.hpp"
#include "../CodigoAuxiliar/ArvoreBPlus.hpp"
#include <chrono>
#include <unistd.h>


using namespace std;


int main(int argc, char const *argv[]){   


    // Criação do arquivo de dados
    ofstream arquivo_de_dados("arquivo_de_dados.bin", ios::binary | ios::out);
    if (!arquivo_de_dados) {
        cerr << "Erro ao criar o arquivo de dados!" << endl;
        return 1;
    }

    // Criação a base onde os dados serao no arquivo_de_dados, craindo todos os buckets e blocos
   Criar_Base(arquivo_de_dados);
    cout << "A base foi criada criada com sucesso!" << endl;

    //Abertura do arquivo de entrada
    ifstream arquivo_csv("artigo.csv", ios::in);
    if(!arquivo_csv){
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    //Abertura do arquivo de dados organizado por hashing
    ifstream arquivo_Dados("arquivo_de_dados.bin", ios::binary | ios::in);
    if(!arquivo_Dados){
        cerr << "Erro ao abrir o arquivo de dados!" << endl;
        return 1;
    }

    cout << "Inserindo registros no arquivo de dados..." << endl;

    ArvoreBPlus arvore_primaria(MAX_KEYS);
    ArvoreBPlus arvore_secundaria(MAX_KEYS);
    // Leitura dos registros do arquivo de entrada
    if (arquivo_csv.is_open()) {
        string line;
        while (getline(arquivo_csv, line)){
            Registro* r = converter_linha_registro(line);
            if(r != NULL){
                int addr = inserir_registro_bucket(r,arquivo_Dados,arquivo_de_dados);
                RegArvore* reg1 = new RegArvore(r->id, addr);
                RegArvore* reg2 = new RegArvore(gerar_inteiro(r->titulo), addr);

                arvore_primaria.insert(reg1);
                arvore_secundaria.insert(reg2);

                delete reg1;
                delete reg2;
            }
            delete r;
        }
    }
    cout << "Arquivo de dados criado com sucesso!" << endl;
    arvore_primaria.salvar_ArvoreBPlus(arvore_primaria, "indice_primario.bin");
    arvore_secundaria.salvar_ArvoreBPlus(arvore_secundaria, "indice_secundario.bin");
    cout << "Indice primario e secundario criado com sucesso!" << endl;

    arvore_primaria.apagarArvore(arvore_primaria.getraiz());
    arvore_secundaria.apagarArvore(arvore_secundaria.getraiz());
    

    
    arquivo_csv.close(); //Fechar o arquivo csv que foi recebido
    arquivo_Dados.close(); //Fechar o arquivo de entrada de dados que foi usado para leitura
    arquivo_de_dados.close(); // Fechar o arquivo de dados que foi usado para escrita e leitura


    cout << "Os arquivos estão pronto agora é só testar "<< endl;



    return 0;
}