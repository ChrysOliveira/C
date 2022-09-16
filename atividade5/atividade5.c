#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *numeros;
char **nomes;

void digitaNumeroIndeterminado();
void digitaNomeIndeterminado();

void digitaNumeroIndeterminado()
{
    int tamanhoDoArray = 2;
    int posicaoPersistencia = 0;
    numeros = malloc(sizeof(int) * tamanhoDoArray);

    printf("Digite numeros aleatorios ou tecle 0 para finalizar: \n");
    do
    {
        scanf("%d", &numeros[posicaoPersistencia]);
        printf("Salvou: %d\n", numeros[posicaoPersistencia]);
        gets();
        posicaoPersistencia++;

        if (posicaoPersistencia == sizeof(numeros) && numeros[posicaoPersistencia - 1] != 0)
        {
            printf("+1 %d\n", sizeof(numeros));
            int tamanhoAtual = sizeof(numeros);
            realloc(numeros, (tamanhoAtual++) * sizeof *numeros);
            printf("+2 %d\n", sizeof(numeros));
        }

    } while (numeros[posicaoPersistencia - 1] != 0);

    if (numeros[posicaoPersistencia - 1] == 0)
    {
        posicaoPersistencia--;
        numeros[posicaoPersistencia] = '\0';
    }
}

void digitaNomeIndeterminado()
{
    int tamanhoDoArray = 1;
    nomes = malloc(sizeof(int *) * tamanhoDoArray);
    for (int i = 0; i < tamanhoDoArray; i++)
    {
        nomes[i] = malloc(sizeof(char) * 50);
    }

    int posicaoPersistencia = 0;

    printf("Digite nomes aleatorios ou tecle f para finalizar: \n");

    do
    {
        if (posicaoPersistencia == tamanhoDoArray)
        {
            tamanhoDoArray++;
            nomes = realloc(nomes, sizeof(int *) * tamanhoDoArray);

            for (int i = 0; i < (tamanhoDoArray - posicaoPersistencia); i++)
            {
                nomes[posicaoPersistencia + i] = malloc(sizeof(char) * 50);
            }
        }

        gets(nomes[posicaoPersistencia]);
        posicaoPersistencia++;

    } while (*nomes[posicaoPersistencia - 1] != 'f');

    if (*nomes[posicaoPersistencia - 1] == 'f')
    {
        posicaoPersistencia--;
        nomes[posicaoPersistencia] = '\0';
    }

    for (int i = 0; i < posicaoPersistencia; i++)
    {
        printf("%s", nomes[i]);
    }
}

int main(int argc, char const *argv[])
{
    digitaNumeroIndeterminado();
    printf("na main\n");
    for (int i = 0; i < sizeof(numeros); i++)
    {
        printf("%d\n", numeros[i]);
    }
    printf("\n");

    digitaNomeIndeterminado();
    free(numeros);
    return 0;
}
