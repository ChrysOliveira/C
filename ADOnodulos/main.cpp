#include "iostream"
#include "cstdlib"
using namespace std;
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
    temp =
        primeiroNO;
    while (temp != NULL)
    {
        cout << temp->pos << endl;
        temp = temp->liga;
    }
}
void destruir()
{
    cad *temp;
    temp =
        primeiroNO;
    while (temp->liga != NULL)
    {
        free(temp);
        temp = temp->liga;
    }
    free(primeiroNO);
    free(ultimoNo);
}
int main()
{
    for (int i = 0; i <= 4; i++)
        alocar();

    exibir();

    destruir();
}