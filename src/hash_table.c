#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash_table.h"

#define PRIMO 131
#define PRIMO 137

void constroi_hash(Hashtable *hash_table, int capacidade) {
    hash_table->cidades = (Cidade *)malloc(capacidade * sizeof(Cidade));
    hash_table->capacidade = capacidade;
    hash_table->tamanho = 0;
}