#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash_table.h"

#define PRIMO1 131
#define PRIMO2 137

void constroi_hash(Hashtable *hash_table, int capacidade) {
    hash_table->cidades = (Cidade *)malloc(capacidade * sizeof(Cidade));
    hash_table->capacidade = capacidade;
    hash_table->tamanho = 0;
}

int funcao_hash(int codigo_ibge, int capacidade, int tentativa) {
    return (codigo_ibge % capacidade + tentativa * (PRIMO1 - (codigo_ibge % PRIMO2))) % capacidade;
}

void insere_cidade(Hashtable *hash_table, Cidade cidade) {
    int index = hash_function(cidade.codigo_ibge, hash_table->capacidade, 0);

    while (hash_table->cidades[index].codigo_ibge != 0) {
        index = (index + 1) % hash_table->capacidade;
    }

    hash_table->cidades[index] = cidade;
    hash_table->tamanho++;
}

Cidade *procura_cidade(Hashtable *hash_table, int codigo_ibge) {
    int index = hash_function(codigo_ibge, hash_table->capacidade, 0);

    while (hash_table->cidades[index].codigo_ibge != 0) {
        if (hash_table->cidades[index].codigo_ibge == codigo_ibge) {
            return &hash_table->cidades[index];
        }
        index = (index + 1) % hash_table->capacidade;
    }

    return NULL;
}
