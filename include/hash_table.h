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

void constroi_hash(Hashtable *hash_table, int capacidade);
int funcao_hash(int codigo_ibge, int capacidade, int tentativa);
void insere_cidade(Hashtable *hash_table, Cidade cidade);
Cidade *procura_cidade(Hashtable *hash_table, int codigo_ibge);

#endif