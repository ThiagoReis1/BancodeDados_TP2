#ifndef BUCKET_HPP
#define BUCKET_HPP

#include <iostream>
#include <vector>
#include "bloco.hpp"
#include "MetricasAux.hpp"

using namespace std;

// Definição da estrutura do bucket
struct Bucket {
    int quatidade_blocos;
    int ultimo_bloco;
    Bloco* blocos[NUMERO_BLOCOS];
};

// Função para destruir um bucket
void destruirBucket(Bucket* bucket) {
    for (int i = 0; i < NUMERO_BLOCOS; i++) {
        destruirBloco(bucket->blocos[i]);  // Desalocar o bloco
    }
    delete bucket;  // Desalocar o bucket em si
}

// Função para criar um bucket, criar os blocos e escrever no arquivo de dados, em seguida desaloca o bucket e os blocos da memória principal
void criarBucket(ofstream &dataFile) {
    Bucket* bucket = new Bucket();
    bucket->quatidade_blocos = 0;
    bucket->ultimo_bloco = 0;
    for (int i = 0; i < NUMERO_BLOCOS; i++) {
        bucket->blocos[i] = criarBloco();

        bucket->quatidade_blocos++;
        // Criar um buffer temporário para armazenar o cabeçalho e os dados
        char buffer[TAMANHO_BLOCO];
        // Copiar o cabeçalho para o início do buffer
        memcpy(buffer, bucket->blocos[i]->cabecalho, sizeof(BlocoCabecalho));
        // Copiar os dados para o restante do buffer
        memcpy(buffer + sizeof(BlocoCabecalho), bucket->blocos[i]->dados, TAMANHO_BLOCO - sizeof(BlocoCabecalho));
        // Escrever o buffer no arquivo
        dataFile.write(buffer, TAMANHO_BLOCO);
    }
    destruirBucket(bucket); // Desalocar o bucket e os blocos da memória principal
}

#endif