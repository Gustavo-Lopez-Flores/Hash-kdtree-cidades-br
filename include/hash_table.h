#include "cidade.h"
#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#define TAMANHO 6000

typedef struct {
    int chave;
    Cidade cidade;
} thash;

thash tabela_hash[TAMANHO];

#endif