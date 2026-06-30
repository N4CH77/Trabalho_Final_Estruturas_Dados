#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define ARQUIVO "dados_b.csv"

typedef struct
{
    char url[100];
    char titulo[50];
    char data_hora[20];
} Pagina;

Pagina historico[MAX], avanco[MAX];
int topo_h = -1, topo_a = -1;

void salvar_csv()
{
    FILE *f = fopen(ARQUIVO, "w");
    if (f == NULL)
        return;
    for (int i = 0; i <= topo_h; i++)
    {
        fprintf(f, "H,%s,%s,%s\n", historico[i].url, historico[i].titulo, historico[i].data_hora);
    }
    for (int i = 0; i <= topo_a; i++)
    {
        fprintf(f, "A,%s,%s,%s\n", avanco[i].url, avanco[i].titulo, avanco[i].data_hora);
    }
    fclose(f);
}

void carregar_csv()
{
    FILE *f = fopen(ARQUIVO, "r");
    if (f == NULL)
        return;
    topo_h = -1;
    topo_a = -1;
    char tipo;
    Pagina p;
    while (fscanf(f, "%c,%[^,],%[^,],%[^\n]\n", &tipo, p.url, p.titulo, p.data_hora) != EOF)
    {
        if (tipo == 'H')
            historico[++topo_h] = p;
        else if (tipo == 'A')
            avanco[++topo_a] = p;
    }
    fclose(f);
}

void visitar()
{
    if (topo_h >= MAX - 1)
    {
        printf("Historico cheio!\n");
        return;
    }
    Pagina p;
    printf("URL: ");
    scanf(" %[^\n]", p.url);
    printf("Titulo: ");
    scanf(" %[^\n]", p.titulo);
    printf("Data e Hora (dd/mm/aa hh:mm): ");
    scanf(" %[^\n]", p.data_hora);

    historico[++topo_h] = p;
    topo_a = -1;
    salvar_csv();
    printf("Pagina visitada!\n");
}

void voltar()
{
    if (topo_h < 0)
    {
        printf("Nao ha paginas para voltar!\n");
        return;
    }
    if (topo_a >= MAX - 1)
    {
        printf("Pilha de avanco cheia!\n");
        return;
    }

    avanco[++topo_a] = historico[topo_h--];
    salvar_csv();
    printf("Voce voltou uma pagina.\n");
}

void avancar()
{
    if (topo_a < 0)
    {
        printf("Nao ha paginas para avancar!\n");
        return;
    }
    if (topo_h >= MAX - 1)
    {
        printf("Historico cheio!\n");
        return;
    }

    historico[++topo_h] = avanco[topo_a--];
    salvar_csv();
    printf("Voce avancou uma pagina.\n");
}

void atual()
{
    if (topo_h < 0)
    {
        printf("Nenhuma pagina aberta.\n");
        return;
    }
    printf("\nPagina atual: %s (%s) - %s\n", historico[topo_h].titulo, historico[topo_h].url, historico[topo_h].data_hora);
}

int main()
{
    carregar_csv();
    int op;
    do
    {
        atual();
        printf("\n--- NAVEGADOR WEB ---\n");
        printf("1. Visitar Nova Pagina\n2. Voltar\n3. Avancar\n0. Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            visitar();
            break;
        case 2:
            voltar();
            break;
        case 3:
            avancar();
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