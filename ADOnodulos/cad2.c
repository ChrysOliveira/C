
#include <stdio.h>
#include <stdlib.h>

typedef struct me cad2;
int cont = 0;
struct me
{
    int pos;
    char nome[1][30];
    cad2 *liga;
};
cad2 *ultimoNo;
cad2 *primeiroNO;
void alocar()
{
    cont++;
    cad2 *newcad2 = (cad2 *)malloc(sizeof(cad2));
    if (cont == 1)
    {
        newcad2->liga = NULL;
        newcad2->pos = cont;
        primeiroNO = newcad2;
        ultimoNo = newcad2;
    }
    else
    {
        ultimoNo->liga = newcad2;
        newcad2->liga = NULL;
        newcad2->pos = cont;
    }
    ultimoNo = newcad2;
}

void exibir()
{
    cad2 *temp;
    temp = primeiroNO;

    while (temp != NULL)
    {
        printf("%d\n", temp->pos);
        temp = temp->liga;
    }
}
void destruir()
{
    cad2 *temp;
    temp = primeiroNO;
    cad2 *aux;

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

    cad2 *temp;
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
    for (int i = 0; i <= 4; i++)
        alocar();

    int opcao;
    do
    {
        printf("Escolha uma opcao:\n");
        printf("1-Exibir\n");
        printf("2-Procurar posicao\n");
        printf("3-Verificar se esta vazia\n");
        printf("0-Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            exibir();
        }
        else if (opcao == 2)
        {
            buscaPosicao();
        }
        else if (opcao == 3)
        {
            verificaVazio();
        }
    } while (opcao != 0);

    destruir();

    return 0;
}