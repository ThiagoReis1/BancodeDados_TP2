#include "../CodigoAuxiliar/MetricasAux.hpp"

void seek1(int id_busca) {
    // Abertura do arquivo de dados organizado por hashing
    ifstream arquivo_Dados("arquivo_de_dados.bin", ios::binary | ios::in);
    string indice_primario = "indice_primario.bin";

    // Busca pelo registro com o ID especificado
    Registro* registro_busca = buscar_registro_bpt(indice_primario, arquivo_Dados, id_busca);

    if (registro_busca != nullptr) {
        delimitador();
        cout << "\nRegistro com id " << id_busca << " encontrado! " << endl;
        cout << "Campos do Registro:" << endl;
        imprimeRegistro(*registro_busca);
        cout << endl;
        delimitador();


        // Libera a memória alocada para o registro
        delete registro_busca;
    } else {
        delimitador();

        cout << "Registro " << id_busca << " não encontrado!" << endl;
        delimitador();

    }

    // Fechamento do arquivo de dados organizado por hashing
    arquivo_Dados.close();
}
