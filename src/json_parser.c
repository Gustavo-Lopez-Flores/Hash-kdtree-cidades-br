
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cJSON/cJSON.h"
#include "../include/hash_table.h"

#define define MAX_CIDADES 5570 // numero de cidades no json

void conversao_json(const char *filename, Cidade *cidades) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo JSON.\n");
        exit(1);
    }

    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    cJSON *root = cJSON_Parse(buffer);
    if (!root) {
        fprintf(stderr, "Erro ao analisar o JSON.\n");
        exit(1);
    }

    cJSON *municipios = cJSON_GetObjectItem(root, "municipios");
    int index = 0;

    cJSON *cidade;
    cJSON_ArrayForEach(cidade, municipios) {
        cidades[index].codigo_ibge = cJSON_GetObjectItem(cidade, "codigo_ibge")->valueint;
        strcpy(cidades[index].nome, cJSON_GetObjectItem(cidade, "nome")->valuestring);
        cidades[index].latitude = cJSON_GetObjectItem(cidade, "latitude")->valuedouble;
        cidades[index].longitude = cJSON_GetObjectItem(cidade, "longitude")->valuedouble;
        cidades[index].capital = cJSON_GetObjectItem(cidade, "capital")->valueint;
        cidades[index].codigo_uf = cJSON_GetObjectItem(cidade, "codigo_uf")->valueint;
        cidades[index].siafi_id = cJSON_GetObjectItem(cidade, "siafi_id")->valueint;
        cidades[index].ddd = cJSON_GetObjectItem(cidade, "ddd")->valueint;
        strcpy(cidades[index].fuso_horario, cJSON_GetObjectItem(cidade, "fuso_horario")->valuestring);

        index++;
    }

    cJSON_Delete(root);
}