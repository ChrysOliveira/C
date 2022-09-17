#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct listaNumeros
{
    int *array;
    int posicaoPersistenciaNum;
    int tamanhoDoArray;
};

struct listaNomes
{
    char **matriz;
    int tamanhoDoArray;
};

typedef struct listaNumeros NUMEROS;
typedef struct listaNomes NOMES;

NUMEROS numeros;
NOMES nomes;

void digitaNumeroIndeterminado();
void digitaNomeIndeterminado();
void organizaNumCrescente();
void organizaNumDecrescente();
void organizaNomeCrescente();
void organizaNomeDecrescente();
void exibirNumeros();
void exibirNomes();
int buscaNumero();
int buscaNome();
int localizaPosicaoNumero(int valor);
int localizaPosicaoNumero(int valor);
void exibeResultadoNumero(int resultado);
void exibeResultadoNome(int resultado);
void liberaMemoria();

void menu();

void digitaNumeroIndeterminado()
{
    numeros.posicaoPersistenciaNum = 0;
    numeros.tamanhoDoArray = 0;
    numeros.array = malloc(sizeof(int) * 100);

    printf("Digite numeros aleatorios ou tecle 0 para finalizar (limite de 100 numeros): \n");
    do
    {
        scanf("%d", &numeros.array[numeros.posicaoPersistenciaNum]);
        gets();

        if (numeros.array[numeros.posicaoPersistenciaNum] != 0)
        {
            numeros.tamanhoDoArray++;
        }

        numeros.posicaoPersistenciaNum++;
    } while (numeros.array[numeros.posicaoPersistenciaNum - 1] != 0);
}

void digitaNomeIndeterminado()
{
    nomes.tamanhoDoArray = 1;
    nomes.matriz = malloc(sizeof(int *) * nomes.tamanhoDoArray);
    for (int i = 0; i < nomes.tamanhoDoArray; i++)
    {
        nomes.matriz[i] = malloc(sizeof(char) * 50);
    }

    int posicaoPersistencia = 0;

    printf("Digite nomes aleatorios ou tecle f para finalizar: \n");

    do
    {
        if (posicaoPersistencia == nomes.tamanhoDoArray)
        {
            nomes.tamanhoDoArray++;
            nomes.matriz = realloc(nomes.matriz, sizeof(int *) * nomes.tamanhoDoArray);

            for (int i = 0; i < (nomes.tamanhoDoArray - posicaoPersistencia); i++)
            {
                nomes.matriz[posicaoPersistencia + i] = malloc(sizeof(char) * 50);
            }
        }

        gets(nomes.matriz[posicaoPersistencia]);
        posicaoPersistencia++;

    } while (*nomes.matriz[posicaoPersistencia - 1] != 'f');

    if (*nomes.matriz[posicaoPersistencia - 1] == 'f')
    {
        posicaoPersistencia--;
        nomes.matriz[posicaoPersistencia] = '\0';
    }
}

void organizaNumCrescente()
{
    int aux;
    for (int i = 0; i < numeros.tamanhoDoArray - 1; i++)
    {
        for (int j = i; j < numeros.tamanhoDoArray; j++)
        {
            if (numeros.array[i] > numeros.array[j])
            {
                aux = numeros.array[i];
                numeros.array[i] = numeros.array[j];
                numeros.array[j] = aux;
            }
        }
    }
}

void organizaNomeCrescente()
{
    char aux[50];
    for (int i = 0; i < nomes.tamanhoDoArray - 2; i++)
    {
        for (int j = i; j < nomes.tamanhoDoArray - 1; j++)
        {
            if (strcmp(nomes.matriz[i], nomes.matriz[j]) > 0)
            {

                strcpy(aux, nomes.matriz[i]);
                strcpy(nomes.matriz[i], nomes.matriz[j]);
                strcpy(nomes.matriz[j], aux);
            }
        }
    }
}

void organizaNomeDecrescente()
{
    char aux[50];
    for (int i = 0; i < nomes.tamanhoDoArray - 2; i++)
    {
        for (int j = i; j < nomes.tamanhoDoArray - 1; j++)
        {
            if (strcmp(nomes.matriz[i], nomes.matriz[j]) < 0)
            {

                strcpy(aux, nomes.matriz[i]);
                strcpy(nomes.matriz[i], nomes.matriz[j]);
                strcpy(nomes.matriz[j], aux);
            }
        }
    }
}

void organizaNumDecrescente()
{
    int aux;
    for (int i = 0; i < numeros.tamanhoDoArray - 1; i++)
    {
        for (int j = i; j < numeros.tamanhoDoArray; j++)
        {
            if (numeros.array[i] < numeros.array[j])
            {
                aux = numeros.array[i];
                numeros.array[i] = numeros.array[j];
                numeros.array[j] = aux;
            }
        }
    }
}

void exibirNumeros()
{
    printf("Lista de numeros:\n");
    for (int i = 0; i < numeros.tamanhoDoArray; i++)
    {
        printf("%d - ", numeros.array[i]);
    }
    printf("\n");
}

void exibirNomes()
{
    printf("Lista de nomes:\n");
    for (int i = 0; i < nomes.tamanhoDoArray - 1; i++)
    {
        printf("%s - ", nomes.matriz[i]);
    }
    printf("\n");
}

int buscaNumero()
{
    printf("Digite o numero que deseja buscar:\n");
    int numeroDesejado = 0;
    scanf("%d", &numeroDesejado);

    for (int i = 0; i < numeros.tamanhoDoArray; i++)
    {
        if (numeros.array[i] == numeroDesejado)
            numeroDesejado = numeros.array[i];
    }

    return numeroDesejado;
}

int buscaNome()
{
    printf("Digite o nome que deseja buscar:\n");
    char nomeDesejado[50];
    scanf("%s", &nomeDesejado);

    int encontrou = 0;

    for (int i = 0; i < nomes.tamanhoDoArray - 1; i++)
    {
        if (strcmp(nomes.matriz[i], nomeDesejado) == 0)
        {
            encontrou = i;
            break;
        }
    }

    return encontrou;
}

int localizaPosicaoNumero(int valor)
{
    int numeroDaPosicao;
    for (int i = 0; i < numeros.tamanhoDoArray; i++)
    {
        if (numeros.array[i] == valor)
        {
            numeroDaPosicao = i;
            break;
        }
    }
    return numeroDaPosicao;
}

void exibeResultadoNumero(int resultado)
{
    if (resultado)
    {
        printf("O numero esta na lista na posicao:%d", localizaPosicaoNumero(resultado));
    }
}

void exibeResultadoNome(int resultado)
{
    printf("O nome esta na lista na posicao:%d\n", resultado);
}

void liberaMemoria()
{
    free(numeros.array);
    for (int i = 0; i < nomes.tamanhoDoArray; i++)
    {
        free(nomes.matriz[i]);
    }
    free(nomes.matriz);
}

void menu()
{
    printf("=-= Selecione uma opcao =-=\n");
    int opcao;
    do
    {
        printf("1 - Inserir numeros e nomes;\n2 - Ordernar dados em ordem crescente\n3 - Ordernar dados em ordem decrescente\n4 - Exibir listas\n5 - Buscar numero\n6 - Buscar nome\n0 - Sair\n");
        scanf("%d", &opcao);
        gets();

        switch (opcao)
        {
        case 0:

            exit(1);
            break;
        case 1:

            digitaNumeroIndeterminado();
            digitaNomeIndeterminado();
            break;
        case 2:

            organizaNumCrescente();
            printf("Tamanho array de nomes: %d", nomes.tamanhoDoArray);
            organizaNomeCrescente();
            break;
        case 3:

            organizaNumDecrescente();
            organizaNomeDecrescente();
            break;
        case 4:

            exibirNumeros();
            exibirNomes();
            break;
        case 5:

            int achouNumero = buscaNumero();
            int posicao = localizaPosicaoNumero(achouNumero);
            exibeResultadoNumero(posicao);
            break;
        case 6:

            int achouNome = buscaNome();
            exibeResultadoNome(achouNome);
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
    liberaMemoria();
    return 0;
}
