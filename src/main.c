#include <stdio.h>
#include <stdlib.h>
#include "../include/json_parser.h"
#include "../include/hash_table.h"

int main() {
    // Tarefa 1
    // Digite o seguinte comando de compilação, na raiz do projeto 
    // gcc -I./cJSON -I./include src/hash_table.c src/json_parser.c src/main.c cJSON/cJSON.c -o saida
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
    } else {
        printf("Cidade com código IBGE %d não encontrada na tabela hash.\n", codigo_ibge);
    }

    free_hashtable(&hash_table);

    return 0;
}
