#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/json_parser.h"
#include "../cJSON/cJSON.h"

void conversao_json(const char *filename, Hashtable *hash_table) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo JSON.\n");
        perror("fopen");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        fprintf(stderr, "Erro: Falha ao alocar memória para leitura do JSON.\n");
        fclose(file);
        return;
    }

    fread(buffer, 1, file_size, file);
    fclose(file);

    buffer[file_size] = '\0';

    cJSON *root = cJSON_Parse(buffer);
    if (!root) {
        fprintf(stderr, "Erro ao analisar o JSON.\n");
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Erro antes da posição: %ld\n", error_ptr - buffer);
        }
        free(buffer);
        return;
    }

    cJSON *cidade_obj = root;
    cJSON *cidade_item = NULL;

    cJSON_ArrayForEach(cidade_item, cidade_obj) {
        int codigo_ibge = cJSON_GetObjectItem(cidade_item, "codigo_ibge")->valueint;
        const char *nome = cJSON_GetObjectItem(cidade_item, "nome")->valuestring;
        double latitude = cJSON_GetObjectItem(cidade_item, "latitude")->valuedouble;
        double longitude = cJSON_GetObjectItem(cidade_item, "longitude")->valuedouble;
        int capital = cJSON_GetObjectItem(cidade_item, "capital")->valueint;
        int codigo_uf = cJSON_GetObjectItem(cidade_item, "codigo_uf")->valueint;
        int siafi_id = cJSON_GetObjectItem(cidade_item, "siafi_id")->valueint;
        int ddd = cJSON_GetObjectItem(cidade_item, "ddd")->valueint;
        const char *fuso_horario = cJSON_GetObjectItem(cidade_item, "fuso_horario")->valuestring;

        Cidade cidade;
        cidade.codigo_ibge = codigo_ibge;
        strcpy(cidade.nome, nome);
        cidade.latitude = latitude;
        cidade.longitude = longitude;
        cidade.capital = capital;
        cidade.codigo_uf = codigo_uf;
        cidade.siafi_id = siafi_id;
        cidade.ddd = ddd;
        strcpy(cidade.fuso_horario, fuso_horario);

        insere_cidade(hash_table, cidade);
    }

    free(buffer);
    cJSON_Delete(root);
}