# TRABALHO FINAL - Estruturas de Dados
![Linguagem C](https://img.shields.io/badge/Linguagem-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Curso](https://img.shields.io/badge/Curso-Engenharia%20de%20Computa%C3%A7%C3%A3o-red?style=for-the-badge)
![Faculdade](https://img.shields.io/badge/Institui%C3%A7%C3%A3o-UniJorge-blue?style=for-the-badge)

> Versão 1.0 (Implementação dos trabalhos a, b e c)

## Temas Escolhidos
- **Trabalho A (Listas Simples):** Tema A2 — Controle de Estoque
- **Trabalho B (Pilhas Simples):** Tema B1 — Histórico de Navegação Web
- **Trabalho C (Filas Simples):** Tema C2 — Fila de Impressão

## Descrição dos Programas
1. **Trabalho A (Controle de Estoque):** Utiliza uma lista simples implementada via vetor de structs. Mantém os produtos ordenados automaticamente pelo código de cadastro. Permite adicionar, buscar, editar e excluir, salvando os dados em `dados_a.csv`.
2. **Trabalho B (Histórico de Navegação):** Simula os botões de voltar e avançar de um navegador usando duas pilhas (uma para histórico, outra para avanço). Implementado com vetores e controle de topo, persistindo os dados em `dados_b.csv`.
3. **Trabalho C (Fila de Impressão):** Utiliza duas estruturas: uma fila simples para impressões normais e uma fila circular para impressões prioritárias. Trabalhos prioritários são sempre processados primeiro. Os dados pendentes são salvos em `dados_c.csv`.

## Instruções de Compilação e Execução (Linux/Mac/MinGW)
Para compilar e executar cada programa via terminal, navegue até a pasta correspondente e rode os seguintes comandos:

**Trabalho A:**
`gcc trabalho_a.c -o trabalho_a`
`./trabalho_a`

**Trabalho B:**
`gcc trabalho_b.c -o trabalho_b`
`./trabalho_b`

**Trabalho C:**
`gcc trabalho_c.c -o trabalho_c`
`./trabalho_c`

## Autores

* **David Augusto (N4CH77)**
* **Luan Gabriel**
