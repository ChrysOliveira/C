#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha pilha;

struct pilha
{
    int valor;
    pilha *ant;
    char nome[1][50];
};

int cont;
pilha *topo;

void construtor()
{
    topo = NULL;
    cont = 0;
}

int push(int valor, char nome[1][30])
{
    pilha *newpilha = (pilha *)malloc(sizeof(pilha));

    if (newpilha == NULL)
    {
        return 0;
    }

    newpilha->valor = valor;
    strcpy(newpilha->nome[1], nome[1]);
    newpilha->ant = topo;
    topo = newpilha;

    cont++;
    return 1;
}

int pop()
{
    int valor;
    pilha *temp;
    temp = topo;
    valor = topo->valor;
    topo = topo->ant;

    free(temp);

    printf("O valor %d foi removido!\n", valor);
    system("sleep 3");
    return 1;
}

void exibirPilha()
{
    pilha *temp;
    temp = topo;
    system("clear");
    while (temp != NULL)
    {
        printf("============================\n");
        printf("Valor: %d\n", temp->valor);
        printf("Nome: %s\n", temp->nome[1]);
        temp = temp->ant;
        printf("============================\n");
    }
    system("sleep 3");
}

int vazia()
{
    return topo == NULL;
}

void destruirPilha()
{
    pilha *temp;

    while (topo != NULL)
    {
        temp = topo;
        topo = topo->ant;
        free(temp);
        cont--;
    }
    free(topo);

    printf("A pilha foi destruida!\n");
    system("sleep 3");
}

int totalValores()
{
    pilha *temp;
    temp = topo;
    int cont = 0;

    while (temp != NULL)
    {
        cont += temp->valor;
        temp = temp->ant;
    }

    return cont;
}

void buscaValorExibeNome(int valor)
{
    pilha *temp;
    temp = topo;
    int achou = 0;

    while (temp != NULL)
    {
        if (temp->valor == valor)
        {
            printf("O valor %d possui o nome %s\n", valor, temp->nome[1]);
            achou = 1;
            break;
        }
        temp = temp->ant;
    }
    if (!achou)
    {
        printf("O valor %d nao esta na pilha\n", valor);
    }
}

int main()
{
    int opcao = 99;
    construtor();

    while (opcao != 0)
    {
        printf("Escolha uma opcao:\n");
        printf("1 - inserir:\n");
        printf("2 - remover:\n");
        printf("3 - exibir:\n");
        printf("4 - verificar se esta vazia:\n");
        printf("5 - destruir pilha:\n");
        printf("6 - somar valores:\n");
        printf("7 - buscar nome por valor:\n");
        printf("0 - sair:\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            system("clear");
            printf("Insira um valor:\n");
            int valor;
            scanf("%d", &valor);
            gets();
            printf("Insira um nome:\n");
            char nome[1][30];
            scanf("%s", &nome[1]);
            push(valor, nome);
            system("clear");
        }
        else if (opcao == 2)
        {
            pop();
            system("clear");
        }
        else if (opcao == 3)
        {
            system("clear");
            exibirPilha();
            system("clear");
        }
        else if (opcao == 4)
        {
            int estaVazia = vazia();
            if (estaVazia)
            {
                printf("A pilha esta vazia\n");
            }
            else
            {
                printf("A pilha nao esta vazia\n");
            }
            system("sleep 3");
            system("clear");
        }
        else if (opcao == 5)
        {
            destruirPilha();
            system("clear");
        }
        else if (opcao == 6)
        {
            int soma = totalValores();
            printf("A soma dos valores eh: %d\n", soma);
            system("sleep 3");
            system("clear");
        }
        else if (opcao == 7)
        {
            printf("Insira um valor:\n");
            int valor;
            scanf("%d", &valor);
            buscaValorExibeNome(valor);
            system("sleep 3");
            system("clear");
        }
        else if (opcao == 0)
        {
            exit(0);
        }
    }
    return 0;
}