#ifndef __HASH_TABLE__
#define __HASH_TABLE__

typedef struct {
    int codigo_ibge;
    char nome[100];
    float latitude;
    float longitude;
    int capital;
    int codigo_uf;
    int siafi_id;
    int ddd;
    char fuso_horario[100];
} Cidade;

typedef struct {
    Cidade *cidades;
    int capacidade;
    int tamanho;
} Hashtable;

#endif