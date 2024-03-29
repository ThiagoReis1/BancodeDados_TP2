#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

// Definição da estrutura do registro
struct Registro {
    int id;
    string titulo;
    int ano;
    string autores;
    int citacoes;
    string atualizacao;
    string snippet;
    int tamanho;
};

// Função usada pra criar um registro
Registro* criarRegistro(int id, string titulo, int ano, string autores, int citacoes, string atualizacao, string snippet) {
    Registro* registro = new Registro();
    registro->id = id;
    registro->titulo = titulo;
    registro->ano = ano;
    registro->autores = autores;
    registro->citacoes = citacoes;
    registro->atualizacao = atualizacao;
    registro->snippet = snippet;
    registro->tamanho = registro->titulo.size() + 4 + sizeof(int) + sizeof(int) + registro->autores.size() + sizeof(int) + sizeof(int) + registro->atualizacao.size() + registro->snippet.size();
    return registro;
}

// Função para imprimir um registro
void imprimeRegistro(Registro registro) {
    cout << "------------------------" << endl;
    cout << "ID: " << registro.id << endl;
    cout << "Titulo: " << registro.titulo << endl;
    cout << "Ano: " << registro.ano << endl;
    cout << "Autores: " << registro.autores << endl;
    cout << "Citacoes: " << registro.citacoes << endl;
    cout << "Atualizacao: " << registro.atualizacao << endl;
    cout << "Snippet: " << registro.snippet << endl;
    cout << "Tamanho do registro em bytes: " << registro.tamanho << endl;
    cout << "------------------------" << endl;
}

// Função para remover caracteres unicode de uma string
string remove_unicode(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < 0 || str[i] > 127) {
            str[i] = ' '; // substitui por um espaço em branco
        }
    }
    return str;
}

// Função para converter uma linha do arquivo de entrada em um registro
Registro* converter_linha_registro(string entry_line){
    vector<string> fields;
    string field = "";
    
    string line = remove_unicode(entry_line);

    for (int i = 0; i < line.size()-1; i++){    
            
        if (line[i] == '"'){
            i++;
            while(!(line[i] == '"' && line[i+1] == ';') && i < line.size()-2){
                field += line[i];
                i++;
            }
            fields.push_back(field);
            field = "";
        } else if (line[i] == 'N' || (line[i] == ';' && line[i+1] == ';')){
            fields.push_back("NULL");
        }
    }

    if (fields.size() != 7){
        return NULL;
    }
    try{
       return criarRegistro(stoi(fields[0]), fields[1], stoi(fields[2]), fields[3], stoi(fields[4]), fields[5], fields[6]);
    }
    catch(const std::exception& e){
        return NULL;
    }
}

// definição do bloco




#endif // REGISTRO_H