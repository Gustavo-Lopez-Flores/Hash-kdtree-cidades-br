#include <stdio.h>
#include <stdlib.h>
#include "../include/json_parser.h"
#include "../include/hash_table.h"

int main() {
    Hashtable hash_table;
    constroi_hash(&hash_table, 5570);

    conversao_json("data/municipios.json", &hash_table);

    int codigo_ibge = 3100203; 
    Cidade *cidade = procura_cidade(&hash_table, codigo_ibge);
    if (cidade != NULL) {
        printf("Informações da cidade com código IBGE %d:\n", codigo_ibge);
        printf("Nome: %s\n", cidade->nome);
        printf("Latitude: %f\n", cidade->latitude);
        printf("Longitude: %f\n", cidade->longitude);
        printf("Capital: %d\n", cidade->capital);
        printf("Codigo_UF: %d\n", cidade->codigo_uf);
        printf("Siafi_ID: %d\n", cidade->siafi_id);
        printf("DDD: %d\n", cidade->ddd);
        printf("Fuso horário: %s\n", cidade->fuso_horario);
    } else {
        printf("Cidade com código IBGE %d não encontrada na tabela hash.\n", codigo_ibge);
    }

    free_hashtable(&hash_table);

    return 0;
}
