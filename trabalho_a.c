#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define ARQUIVO "dados_a.csv"

typedef struct
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto estoque[MAX];
int qtd = 0;

void salvar_csv()
{
    FILE *f = fopen(ARQUIVO, "w");
    if (f == NULL)
        return;
    for (int i = 0; i < qtd; i++)
    {
        fprintf(f, "%d,%s,%d,%.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
    fclose(f);
}

void carregar_csv()
{
    FILE *f = fopen(ARQUIVO, "r");
    if (f == NULL)
        return;
    qtd = 0;
    while (fscanf(f, "%d,%[^,],%d,%f\n", &estoque[qtd].codigo, estoque[qtd].nome, &estoque[qtd].quantidade, &estoque[qtd].preco) != EOF)
    {
        qtd++;
    }
    fclose(f);
}

int buscar_posicao(int codigo)
{
    for (int i = 0; i < qtd; i++)
    {
        if (estoque[i].codigo == codigo)
            return i;
    }
    return -1;
}

void cadastrar()
{
    if (qtd >= MAX)
    {
        printf("Erro: Estoque cheio!\n");
        return;
    }
    Produto p;
    printf("Codigo: ");
    scanf("%d", &p.codigo);
    if (buscar_posicao(p.codigo) != -1)
    {
        printf("Erro: Codigo ja existe!\n");
        return;
    }
    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Preco: ");
    scanf("%f", &p.preco);

    // Inserção ordenada
    int i = qtd - 1;
    while (i >= 0 && estoque[i].codigo > p.codigo)
    {
        estoque[i + 1] = estoque[i];
        i--;
    }
    estoque[i + 1] = p;
    qtd++;
    salvar_csv();
    printf("Produto cadastrado com sucesso!\n");
}

void listar()
{
    if (qtd == 0)
    {
        printf("Estoque vazio!\n");
        return;
    }
    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("Cod: %d | %s | Qtd: %d | R$ %.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}

void excluir()
{
    if (qtd == 0)
    {
        printf("Estoque vazio!\n");
        return;
    }
    int cod;
    printf("Codigo para excluir: ");
    scanf("%d", &cod);
    int pos = buscar_posicao(cod);
    if (pos == -1)
    {
        printf("Produto nao encontrado!\n");
        return;
    }

    for (int i = pos; i < qtd - 1; i++)
    {
        estoque[i] = estoque[i + 1];
    }
    qtd--;
    salvar_csv();
    printf("Produto excluido com sucesso!\n");
}

int main()
{
    carregar_csv();
    int op;
    do
    {
        printf("\n--- CONTROLE DE ESTOQUE ---\n");
        printf("1. Cadastrar Produto\n2. Listar Produtos\n3. Excluir Produto\n0. Sair\nEscolha: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            excluir();
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