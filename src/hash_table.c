#include <stdlib.h>
#include <string.h>
#include "../include/hash_table.h"

void constroi_hash(Hashtable *hash_table, int capacidade) {
    hash_table->cidades = (Cidade *)malloc(capacidade * sizeof(Cidade));
    hash_table->capacidade = capacidade;
    hash_table->tamanho = 0;
}

int funcao_hash(int codigo_ibge, int capacidade, int tentativa) {
    return (codigo_ibge % capacidade + tentativa * (1 + codigo_ibge % (capacidade - 1))) % capacidade;
}

void insere_cidade(Hashtable *hash_table, Cidade cidade) {
    int index = funcao_hash(cidade.codigo_ibge, hash_table->capacidade, 0);

    while (hash_table->cidades[index].codigo_ibge != 0) {
        index = (index + 1) % hash_table->capacidade;
    }

    hash_table->cidades[index] = cidade;
    hash_table->tamanho++;
}

Cidade *procura_cidade(Hashtable *hash_table, int codigo_ibge) {
    int index = funcao_hash(codigo_ibge, hash_table->capacidade, 0);

    while (hash_table->cidades[index].codigo_ibge != codigo_ibge) {
        index = (index + 1) % hash_table->capacidade;

        if (hash_table->cidades[index].codigo_ibge == 0) {
            return NULL;
        }
    }

    return &hash_table->cidades[index];
}

void free_hashtable(Hashtable *hash_table) {
    free(hash_table->cidades);
    hash_table->capacidade = 0;
    hash_table->tamanho = 0;
}
