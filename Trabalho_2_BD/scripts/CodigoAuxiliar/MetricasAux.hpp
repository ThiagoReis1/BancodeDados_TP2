#ifndef METRICASAUX_HPP
#define METRICASAUX_HPP

const int TAMANHO_BLOCO = 4096; // 4KB = 4096 bytes 
const int NUMERO_BUCKETS = 15000; //Quantidade de buckets
const int NUMERO_BLOCOS = 12; // Quantidade de blocos por bucket
const int MAX_KEYS = 510; // Quantidade máxima de chaves por bloco na árvore B+


void delimitador(){
    cout << "\n############################################################### " << endl;
}

#endif