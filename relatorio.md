# RELATÓRIO TÉCNICO - Trabalho Final de Estruturas de Dados

## 1. Introdução
Este relatório apresenta os detalhes técnicos e as decisões de projeto adotadas no desenvolvimento dos três sistemas que compõem o Trabalho Final da disciplina de Estruturas de Dados. Conforme os requisitos atualizados, todas as estruturas foram implementadas de forma estática utilizando **vetores de structs** e variáveis de controle, sem o uso de alocação dinâmica de memória.

**Autores:** David Augusto (N4CH77) e Luan Gabriel  

---

## 2. Trabalho A: Controle de Estoque (Lista Simples)
### Estrutura e Lógica Utilizada
O sistema de controle de estoque foi desenvolvido utilizando uma **Lista Sequencial Ordenada**. A estrutura armazena os dados em um vetor fixo de structs (`Produto estoque[MAX]`), acompanhado por uma variável inteira `qtd` que monitoriza o número de registos ativos.

### Diferenciais da Implementação
* **Ordenação Automática:** Para cumprir a exigência de manter a lista ordenada pelo código do produto, a função de inserção realiza uma busca da posição correta de trás para frente. Caso o código inserido seja menor que os existentes, o programa desloca os elementos para a direita para abrir espaço, garantindo a ordenação em tempo de inserção.
* **Remoção de Elementos:** Na exclusão, após localizar o índice do produto, todos os elementos subsequentes são deslocados uma posição para a esquerda para evitar buracos na estrutura do vetor.

---

## 3. Trabalho B: Histórico de Navegação Web (Pilhas Simples)
### Estrutura e Lógica Utilizada
A simulação dos botões de voltar e avançar de um navegador de internet exige o comportamento **LIFO (Last-In, First-Out)**. Para isso, o programa gerencia **duas Pilhas Sequenciais** independentes baseadas em vetores (`historico[MAX]` e `avanco[MAX]`), controladas por variáveis de controle de topo (`topo_h` e `topo_a`), inicializadas em `-1`.

### Fluxo de Operações
* **Nova Visita:** O site é empilhado na estrutura de histórico (`topo_h++`) e a pilha de avanço é imediatamente limpa (`topo_a = -1`), impedindo navegações inconsistentes.
* **Voltar e Avançar:** A operação de voltar desempilha o elemento corrente do histórico e o empilha na estrutura de avanço. A operação de avançar faz o caminho inverso, respeitando estritamente os limites de pilha vazia e pilha cheia.

---

## 4. Trabalho C: Fila de Impressão (Filas Simples e Circular)
### Estrutura e Lógica Utilizada
O gerenciador de impressões adota o comportamento **FIFO (First-In, First-Out)** e trabalha com dois fluxos distintos de prioridade:
1. **Fila Normal:** Implementada como uma Fila Sequencial Simples.
2. **Fila Prioritária:** Implementada como uma **Fila Circular**, utilizando variáveis de controlo para `inicio`, `fim` e `quantidade`.

### Mecanismo de Priorização e Circularidade
* A fila circular utiliza o operador matemático de resto da divisão (`% MAX`) para reaproveitar os índices do vetor. Quando o ponteiro de fim atinge o limite físico do vetor, ele retorna para a posição zero (caso haja espaço), otimizando o uso da memória.
* A regra de negócio garante que nenhum trabalho da fila normal será processado enquanto houver qualquer documento pendente na fila prioritária circular.

---

## 5. Persistência de Dados (Arquivos CSV)
A persistência foi integrada nativamente em todos os módulos através da biblioteca padrão `<stdio.h>`.
* **Leitura:** O programa abre os ficheiros em modo de leitura (`"r"`) e consome os dados utilizando a função `fscanf` com máscaras de formatação que ignoram as vírgulas delimitadoras (`%[^,]`).
* **Escrita:** Sempre que ocorre uma alteração na estrutura (inserção, processamento ou remoção), o arquivo correspondente é sobrescrito no modo `"w"`, garantindo que os dados em disco reflitam exatamente o estado atual da memória volátil.

---

## 6. Conclusão e Dificuldades Encontradas
O desenvolvimento do projeto foi fundamental para consolidar os conceitos teóricos de estruturas de dados lineares e indexação de matrizes/vetores. 

A principal dificuldade encontrada pelo grupo residiu no controlo preciso dos índices de `inicio` e `fim` da **Fila Circular** no Trabalho C, de forma a evitar o atropelamento de dados e falsos alertas de estrutura cheia ou vazia. O desafio foi superado com a aplicação correta da aritmética modular e testes de mesa detalhados.
