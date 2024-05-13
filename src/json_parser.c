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

    int num_objects = cJSON_GetArraySize(root);
    for (int i = 0; i < num_objects; i++) {
        cJSON *obj = cJSON_GetArrayItem(root, i);

        int codigo_ibge = cJSON_GetObjectItem(obj, "codigo_ibge")->valueint;
        const char *nome = cJSON_GetObjectItem(obj, "nome")->valuestring;
        double latitude = cJSON_GetObjectItem(obj, "latitude")->valuedouble;
        double longitude = cJSON_GetObjectItem(obj, "longitude")->valuedouble;

        Cidade cidade;
        cidade.codigo_ibge = codigo_ibge;
        strcpy(cidade.nome, nome);
        cidade.latitude = latitude;
        cidade.longitude = longitude;

        insere_cidade(hash_table, cidade);
    }

    free(buffer);
    cJSON_Delete(root);
}