#include "cidade.h"
#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#define TAMANHO 6000

typedef struct {
    int chave;
    Cidade cidade;
} Objeto;

typedef struct {
    Objeto *table;
} HashTable;

#endif