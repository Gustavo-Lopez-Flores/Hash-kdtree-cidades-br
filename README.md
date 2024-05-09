# Cidades Brasileiras - Consulta e Vizinhança

Este repositório contém uma implementação em C para consulta e análise de cidades brasileiras, utilizando tabelas hash e k-d trees para realizar operações como consulta por código IBGE, busca de cidades vizinhas mais próximas e combinação dessas funcionalidades.

## Tarefas Implementadas

1. **Consulta por Código IBGE**
   - **Objetivo:** Dado o código IBGE de uma cidade, retorne todas as informações desta cidade.
   - **Descrição:** Implementação de uma tabela hash com tratamento de colisões utilizando hash duplo para armazenar todas as cidades brasileiras disponíveis no [JSON de municípios brasileiros](https://github.com/kelvins/municipios-brasileiros/blob/main/json/municipios.json). Ao consultar um código IBGE, o código retornará todas as informações relacionadas a essa cidade presente no banco de dados.

2. **Cidades Vizinhas Mais Próximas**
   - **Objetivo:** Dado o código IBGE de uma cidade, retornar os códigos IBGE das N cidades vizinhas mais próximas, onde N é um parâmetro definido pelo usuário.
   - **Descrição:** Utilização de uma k-d tree implementada como uma árvore binária de busca (ABB) para realizar a busca por vizinhança. A k-d tree será construída com base nas coordenadas de latitude e longitude das cidades. A busca por vizinhança alternará entre latitude e longitude para identificar as cidades mais próximas.

3. **Consulta Combinada por Nome de Cidade**
   - **Objetivo:** Dado o nome de uma cidade, retornar todas as informações das N cidades vizinhas mais próximas.
   - **Descrição:** Implementação de outra tabela hash que permite pesquisar o código IBGE com base no nome da cidade. Uma vez obtido o código IBGE, o sistema utilizará a funcionalidade da Tarefa 2 para retornar os vizinhos mais próximos e a funcionalidade da Tarefa 1 para obter informações detalhadas sobre essas cidades. Em casos de cidades com nomes idênticos, será apresentada uma lista de opções para que o usuário escolha a cidade desejada.

## Como Utilizar

1. **Compilação e Execução:**
   - Compile o código usando um compilador C compatível com o seu sistema operacional.
   - Execute o programa resultante, fornecendo os inputs necessários para realizar consultas ou operações de busca conforme descrito nas tarefas acima.

2. **Requisitos:**
   - Certifique-se de ter instalado um compilador C adequado e as bibliotecas necessárias para manipulação de JSON e estruturas de dados como tabelas hash e k-d trees.

## Estrutura do Repositório

- **`src/`**: Contém os arquivos fonte da implementação, incluindo módulos para manipulação de tabelas hash, k-d trees e funcionalidades relacionadas.
  
- **`data/`**: Armazena o arquivo `municipios.json` com as informações das cidades brasileiras.

- **`docs/`**: Documentação adicional sobre o funcionamento do código, algoritmos utilizados e instruções de uso.

- **`requirements.txt`**: Lista de dependências necessárias para executar o código.

## Contribuição

Sinta-se à vontade para contribuir com melhorias, correções ou novas funcionalidades para este projeto. Caso tenha dúvidas ou sugestões, abra uma issue para discussão.

---

**Nota:** Este projeto foi desenvolvido como parte de um trabalho acadêmico. As funcionalidades foram implementadas com base em conceitos de estruturas de dados e algoritmos estudados em sala de aula.
