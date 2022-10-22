// #include "iostream"
// #include "cstdlib"
#include <stdio.h>
#include <stdlib.h>

// using namespace std;
typedef struct me cad;
int cont = 0;
struct me
{
    int pos;
    cad *liga;
};
cad *ultimoNo;
cad *primeiroNO;

void alocar()
{
    cont++;
    cad *newcad = (cad *)malloc(sizeof(cad));
    if (cont == 1)
    {
        newcad->liga = NULL;
        newcad->pos = cont;
        primeiroNO = newcad;
        ultimoNo = newcad;
    }
    else
    {
        ultimoNo->liga = newcad;
        newcad->liga = NULL;
        newcad->pos = cont;
    }
    ultimoNo = newcad;
}

void exibir()
{
    cad *temp;
    temp = primeiroNO;

    while (temp != NULL)
    {
        // cout << temp->pos << endl;
        printf("%d\n", temp->pos);
        temp = temp->liga;
    }
}
void destruir()
{
    cad *temp;
    temp = primeiroNO;
    cad *aux;

    while (temp->liga != NULL)
    {
        aux = temp->liga;
        free(temp);
        temp = aux;
    }

    free(ultimoNo);
}

void buscaPosicao()
{
    int posicao;
    printf("Digite a posicao que deseja buscar: \n");
    scanf("%d", &posicao);

    cad *temp;
    temp = primeiroNO;
    int achou = 0;
    while (temp != NULL)
    {
        if (posicao == temp->pos)
        {
            achou = temp->pos;
            break;
        }
        temp = temp->liga;
    }

    if (achou == 0)
    {
        printf("A posicao nao existe na estrutura\n");
    }
    else
    {
        printf("A posicao esta na estrutura\n");
    }
}

void verificaVazio()
{

    if (primeiroNO == NULL)
    {
        printf("A estrutura esta vazia\n");
    }
    else
    {
        printf("A estrutura nao esta vazia\n");
    }
}

int main()
{
    int opcao;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1-Alocar\n");
        printf("2-Exibir\n");
        printf("3-Procurar posicao\n");
        printf("4-Verificar se esta vazia\n");
        printf("0-Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            alocar();
        }
        else if (opcao == 2)
        {
            exibir();
        }
        else if (opcao == 3)
        {
            buscaPosicao();
        }
        else if (opcao == 4)
        {
            verificaVazio();
        }
    } while (opcao != 0);

    destruir();

    return 0;
}