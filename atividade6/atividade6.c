#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAMANHO_LISTA 10

struct pessoa
{
    char nome[50];
    int idade;
};

typedef struct pessoa Pessoa;

Pessoa pessoa[TAMANHO_LISTA];

void menu();
void digitaPessoas();
void exibeTabela();
void ordenaIdadeSelection();
void ordenaIdadeInsert();
int selPosMinNome(int i);
void ordenaNomeSelection();
void ordenaNomeInsert();
int buscaBinIdade(int x);
void apresentaBuscaBinIdade();
void apresentaBuscaBinNome();

void digitaPessoas()
{

    printf("Cadastre as pessoas:\n");
    for (int i = 0; i < TAMANHO_LISTA; i++)
    {
        printf("Nome:\n");
        gets(pessoa[i].nome);
        printf("Idade:\n");
        scanf("%d", &pessoa[i].idade);
        gets();
    }
}

void exibeTabela()
{
    printf("Lista:\n");
    for (int i = 0; i < TAMANHO_LISTA; i++)
    {
        printf("Nome: %s   Idade: %d\n", pessoa[i].nome, pessoa[i].idade);
    }
    printf("\n");
}

int selPosMinIdade(int i)
{
    int j, k;
    k = i;
    for (int j = i + 1; j < TAMANHO_LISTA; j++)
    {
        if (pessoa[k].idade > pessoa[j].idade)
            k = j;
    }
    return k;
}

int selPosMinNome(int i)
{
    int j, k;
    k = i;
    for (int j = i + 1; j < TAMANHO_LISTA; j++)
    {
        if (strcmp(pessoa[k].nome, pessoa[j].nome))
            k = j;
    }
    return k;
}

void ordenaIdadeSelection()
{
    Pessoa y, x;
    int k, i;

    for (i = 0; i < TAMANHO_LISTA - 1; i++)
    {
        k = selPosMinIdade(i);
        y = pessoa[i];
        pessoa[i] = pessoa[k];
        pessoa[k] = y;
    }
}

void ordenaNomeSelection()
{
    Pessoa y, x;
    int k, i;

    for (i = 0; i < TAMANHO_LISTA - 1; i++)
    {
        k = selPosMinNome(i);
        y = pessoa[i];
        pessoa[i] = pessoa[k];
        pessoa[k] = y;
    }
}

void ordenaIdadeInsert()
{
    int i, j;
    Pessoa key;

    for (i = 1; i < TAMANHO_LISTA; i++)
    {
        key = pessoa[i];
        j = i - 1;

        while (j >= 0 && pessoa[j].idade > key.idade)
        {
            pessoa[j + 1] = pessoa[j];
            j = j - 1;
        }
        pessoa[j + 1] = key;
    }
}

void ordenaNomeInsert()
{
    int i, j;
    Pessoa key;

    for (i = 1; i < TAMANHO_LISTA; i++)
    {
        key = pessoa[i];
        j = i - 1;

        while (j >= 0 && strcmp(pessoa[j].nome, key.nome) == 1)
        {
            pessoa[j + 1] = pessoa[j];
            j = j - 1;
        }
        pessoa[j + 1] = key;
    }
}

int buscaBinIdade(int x)
{
    int e = 0, d = TAMANHO_LISTA, m;

    for (int i = 0; i < TAMANHO_LISTA; i++)
    {
        m = (e + d) / 2;

        if (x == pessoa[m].idade)
            return m;
        else
        {
            if (x > pessoa[m].idade)
                e = m;
            else if (m == 1)
            {
                d = 0;
            }
            else
            {
                d = m;
            }
        }
    }
    return -1;
}

int buscaBinNome(char nome[50])
{
    int e = 0, d = TAMANHO_LISTA, m;

    for (int i = 0; i < TAMANHO_LISTA; i++)
    {
        m = (e + d) / 2;

        if (strcmp(nome, pessoa[m].nome) == 0)
            return m;
        else
        {
            if (strcmp(nome, pessoa[m].nome) == 1)
                e = m;
            else if (m == 1)
            {
                d = 0;
            }
            else
            {
                d = m;
            }
        }
    }
    return -1;
}

void apresentaBuscaBinIdade()
{
    ordenaIdadeInsert();

    printf("Digite a idade que deseja buscar: \n");
    int idadeDesejada;
    scanf("%d", &idadeDesejada);
    int posicao = buscaBinIdade(idadeDesejada);
    if (posicao != -1)
    {
        printf("A idade %d esta cadastrada em sistema na posicao %d e pertence a pessoa %s\n", pessoa[posicao].idade, posicao, pessoa[posicao].nome);
    }
    else
    {
        printf("A idade buscada nao esta na nossa relacao de pessoas\n");
    }
}

void apresentaBuscaBinNome()
{
    ordenaNomeInsert();

    printf("Digite o nome que deseja buscar: \n");
    char nomeDesejado[50];
    scanf("%s", &nomeDesejado);
    int posicao = buscaBinNome(nomeDesejado);
    if (posicao != -1)
    {
        printf("O nome %s esta cadastrada em sistema na posicao %d e tem idade %d\n", pessoa[posicao].nome, posicao, pessoa[posicao].idade);
    }
    else
    {
        printf("O nome buscado nao esta na nossa relacao de pessoas\n");
    }
}

void menu()

{
    printf("=-= Selecione uma opcao =-=\n");
    int opcao;
    system("clear");
    do
    {
        printf("1 - Ler nome e idade\n2 - Exibir tabela\n3 - Classificar idade (Selection Sort)\n4 - Classificar idade (Insertion Sort)\n5 - Classificar nome(Selection Sort)\n6 - Classificar nome(Insertion Sort)\n7 - Busca idade (busca binaria) -\n8 - Busca nome (busca binaria)\n9 - Sair\n");
        scanf("%d", &opcao);
        gets();

        switch (opcao)
        {
        case 9:
            exit(1);
            break;
        case 1:
            system("clear");
            digitaPessoas();
            system("clear");
            break;
        case 2:
            system("clear");
            exibeTabela();
            break;
        case 3:
            ordenaIdadeSelection();
            system("clear");
            break;
        case 4:
            ordenaIdadeInsert();
            system("clear");
            break;
        case 5:
            ordenaNomeSelection();
            system("clear");
            break;
        case 6:
            ordenaNomeInsert();
            system("clear");
            break;
        case 7:
            system("clear");
            apresentaBuscaBinIdade();
            break;
        case 8:
            system("clear");
            apresentaBuscaBinNome();
            break;
        default:
            printf("Digite um valor valido!\n");
            break;
        }
    } while (opcao != 0);
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
