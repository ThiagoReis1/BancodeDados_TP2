
void seek2(const string& titulo) {
    // Abertura do arquivo de dados organizado por hashing
    ifstream arquivo_Dados("arquivo_de_dados.bin", ios::binary | ios::in);
    string indice_secundario = "indice_secundario.bin";

    // Busca pelo registro com o título especificado
    Registro* registro_busca = buscar_registro_bpt(indice_secundario, arquivo_Dados, gerar_inteiro(remove_unicode(titulo)));

    if(registro_busca != nullptr) {
        delimitador();

        cout << "\nRegistro com título " << titulo << " encontrado! " << endl;
        cout << "Campos do Registro:" << endl;
        imprimeRegistro(*registro_busca);
        cout << endl;
        delimitador();

    } else {
        delimitador();

        cout << "Registro com título " << titulo << " não encontrado!" << endl;
        delimitador();

    }

    // Libera a memória alocada para o registro
    delete registro_busca;

    // Fechamento do arquivo de dados organizado por hashing
    arquivo_Dados.close();
}