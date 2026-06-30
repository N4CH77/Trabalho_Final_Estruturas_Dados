#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define ARQUIVO "dados_c.csv"

typedef struct
{
    int id;
    char arquivo[50];
    int paginas;
    char tipo;
} Trabalho;

// Fila Normal (Simples)
Trabalho fila_n[MAX];
int ini_n = 0, fim_n = 0, qtd_n = 0;

// Fila Prioritária (Circular)
Trabalho fila_p[MAX];
int ini_p = 0, fim_p = 0, qtd_p = 0;

void salvar_csv()
{
    FILE *f = fopen(ARQUIVO, "w");
    if (f == NULL)
        return;
    for (int i = 0, idx = ini_n; i < qtd_n; i++, idx = (idx + 1) % MAX)
        fprintf(f, "%d,%s,%d,%c\n", fila_n[idx].id, fila_n[idx].arquivo, fila_n[idx].paginas, fila_n[idx].tipo);
    for (int i = 0, idx = ini_p; i < qtd_p; i++, idx = (idx + 1) % MAX)
        fprintf(f, "%d,%s,%d,%c\n", fila_p[idx].id, fila_p[idx].arquivo, fila_p[idx].paginas, fila_p[idx].tipo);
    fclose(f);
}

void adicionar()
{
    Trabalho t;
    printf("ID: ");
    scanf("%d", &t.id);
    printf("Arquivo: ");
    scanf(" %[^\n]", t.arquivo);
    printf("Paginas: ");
    scanf("%d", &t.paginas);
    printf("Tipo (N-Normal, P-Prioritario): ");
    scanf(" %c", &t.tipo);

    if (t.tipo == 'P' || t.tipo == 'p')
    {
        if (qtd_p >= MAX)
        {
            printf("Fila prioritaria cheia!\n");
            return;
        }
        fila_p[fim_p] = t;
        fim_p = (fim_p + 1) % MAX;
        qtd_p++;
    }
    else
    {
        if (qtd_n >= MAX)
        {
            printf("Fila normal cheia!\n");
            return;
        }
        fila_n[fim_n] = t;
        fim_n = (fim_n + 1) % MAX;
        qtd_n++;
    }
    salvar_csv();
    printf("Trabalho enfileirado!\n");
}

void processar()
{
    Trabalho t;
    if (qtd_p > 0)
    {
        t = fila_p[ini_p];
        ini_p = (ini_p + 1) % MAX;
        qtd_p--;
        printf("Processando Prioritario: %s (%d pags)\n", t.arquivo, t.paginas);
    }
    else if (qtd_n > 0)
    {
        t = fila_n[ini_n];
        ini_n = (ini_n + 1) % MAX;
        qtd_n--;
        printf("Processando Normal: %s (%d pags)\n", t.arquivo, t.paginas);
    }
    else
    {
        printf("Nenhum trabalho na fila de impressao.\n");
        return;
    }
    salvar_csv();
}

void listar()
{
    printf("\n--- FILA PRIORITARIA ---\n");
    if (qtd_p == 0)
        printf("Vazia.\n");
    for (int i = 0, idx = ini_p; i < qtd_p; i++, idx = (idx + 1) % MAX)
        printf("ID: %d | Arq: %s | Pags: %d\n", fila_p[idx].id, fila_p[idx].arquivo, fila_p[idx].paginas);

    printf("\n--- FILA NORMAL ---\n");
    if (qtd_n == 0)
        printf("Vazia.\n");
    for (int i = 0, idx = ini_n; i < qtd_n; i++, idx = (idx + 1) % MAX)
        printf("ID: %d | Arq: %s | Pags: %d\n", fila_n[idx].id, fila_n[idx].arquivo, fila_n[idx].paginas);
}

int main()
{
    int op;
    do
    {
        printf("\n--- FILA DE IMPRESSAO ---\n");
        printf("1. Adicionar Trabalho\n2. Processar Impressao\n3. Listar Fila\n0. Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            adicionar();
            break;
        case 2:
            processar();
            break;
        case 3:
            listar();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
