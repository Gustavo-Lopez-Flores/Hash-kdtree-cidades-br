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

## Estrutura do Repositório

- **`include/`**: Diretório para arquivos de cabeçalho (headers).

- **`src/`**: Diretório para arquivos de código-fonte (source).

- **`test/`**: Diretório para arquivos de teste.
  
- **`data/`**: Diretório para dados necessários ao programa.

## Contribuição

Sinta-se à vontade para contribuir com melhorias, correções ou novas funcionalidades para este projeto. Caso tenha dúvidas ou sugestões, abra uma issue para discussão.

---

**Nota:** Este projeto foi desenvolvido como parte de um trabalho acadêmico na disciplina de Estrutura de Dados. As funcionalidades foram implementadas com base em conceitos de estruturas de dados e algoritmos estudados em sala de aula.
