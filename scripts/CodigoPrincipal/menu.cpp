#include <iostream>
#include <limits>
#include <string>
#include "../CodigoAuxiliar/ArvoreBPlus.hpp"
#include "../CodigoAuxiliar/Base_Insercao_Hash.hpp"
#include "seek1.hpp"
#include "seek2.hpp"
#include "findrec.hpp"


using namespace std;






// Função para limpar o buffer do teclado
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função para exibir o menu e obter a escolha do usuário
char exibirMenu() {
    char escolha;
    
    cout << "Menu:" << endl;
    cout << "a) findrec" << endl;
    cout << "b) seek1" << endl;
    cout << "c) seek2" << endl;
    cout << "x) Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> escolha;
    
    // Limpa o buffer do teclado para evitar problemas com entradas inválidas
    limparBuffer();
    
    return escolha;
}

int main() {
    char opcao;
    int id_busca;
    string titulo;
    
    do {
        // Exibe o menu e obtém a escolha do usuário
        opcao = exibirMenu();
        
        // Verifica a escolha do usuário e executa a operação correspondente
        switch (opcao) {
            case 'a': {
                cout << "Executando findrec..." << endl;
                
                cout << "Digite o ID que deseja buscar usando o findrec: ";
                cin >> id_busca;
                findrec(id_busca);
                break;
            }
            case 'b':
                cout << "Executando seek1..." << endl;
                
                cout << "Digite o ID que deseja buscar usando o seek1: ";
                cin >> id_busca;
                seek1(id_busca);
                break;
            case 'c':
                cout << "Executando seek2..." << endl;
                
                cout << "Digite o título que deseja buscar usando o seek2: ";
                getline(cin >> ws, titulo);
                seek2(titulo);
                break;
            case 'x':
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha novamente." << endl;
        }
    } while (opcao != 'x');

    return 0;
}
