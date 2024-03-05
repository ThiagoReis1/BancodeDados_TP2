void findrec(int id_busca) {
    // Abertura do arquivo de dados organizado por hashing
    ifstream arquivo_Dados("arquivo_de_dados.bin", ios::binary | ios::in);

    // Busca pelo registro com o ID especificado
    Registro* registro_busca = buscar_registro(arquivo_Dados, id_busca);

    // Verifica se o registro foi encontrado e imprime os campos, se encontrado
    if(registro_busca != NULL) {
        delimitador();
        
        cout << "\nRegistro com id " << id_busca << " encontrado! " << endl;
        cout << "Campos do Registros:" << endl;
        imprimeRegistro(*registro_busca);
        cout << endl;
        delimitador();

    } else {
        delimitador();

        cout << "Registro " << id_busca << " não encontrado!" << endl;
        delimitador();

    }

    // Libera a memória alocada para o registro
    delete registro_busca;

    // Fechamento do arquivo de dados organizado por hashing
    arquivo_Dados.close();
}