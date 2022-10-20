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
int main()
{
    for (int i = 0; i <= 4; i++)
        alocar();

    exibir();

    destruir();

    return 0;
}