#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fogefoge.h"
#include "mapa.h"

void copiaMapa(MAPA *mapa, MAPA *copia)
{
    copia->qntColunas = mapa->qntColunas;
    copia->qntLinhas = mapa->qntLinhas;

    alocaMapa(copia);

    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        strcpy(copia->matriz[i], mapa->matriz[i]);
    }
}

int ehParede(MAPA *mapa, int x, int y)
{
    return mapa->matriz[x][y] == PAREDE_VERTICAL || mapa->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehPersonagem(MAPA *mapa, int x, int y, char personagem)
{
    return mapa->matriz[x][y] == personagem;
}

int podeAndar(MAPA *mapa, int x, int y, char personagem)
{
    return !finalDeMapa(mapa, x, y) &&
           !ehParede(mapa, x, y) &&
           !ehPersonagem(mapa, x, y, personagem);
}

int comandoValido(char comando)
{
    return comando == CIMA || comando == ESQUERDA || comando == BAIXO || comando == DIREITA;
}

int finalDeMapa(MAPA *mapa, int posicaoX, int posicaoY)
{
    if (posicaoX >= mapa->qntLinhas || posicaoY >= mapa->qntColunas)
        return 1;

    return 0;
}

int campoVazio(MAPA *mapa, int posicaoX, int posicaoY)
{
    return mapa->matriz[posicaoX][posicaoY] == VAZIO;
}

void atualizaPosicao(MAPA *mapa, int x, int y, int proxX, int proxY)
{
    char aux = mapa->matriz[x][y];

    mapa->matriz[proxX][proxY] = aux;

    mapa->matriz[x][y] = VAZIO;
}

void alocaMapa(MAPA *mapa)
{
    mapa->matriz = malloc(sizeof(int *) * mapa->qntLinhas);

    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        mapa->matriz[i] = malloc(sizeof(char) * mapa->qntColunas + 1);
    }
}

void leMapa(MAPA *mapa)
{
    FILE *f = fopen("mapa.txt", "r");
    if (f == 0)
    {
        printf("Nao foi possivel ler o mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &mapa->qntLinhas, &mapa->qntColunas);

    alocaMapa(mapa);

    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        fscanf(f, "%s", mapa->matriz[i]);
    }

    fclose(f);
}

void liberaMapa(MAPA *mapa)
{
    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}

int localizaFogeFoge(MAPA *mapa, FOGEFOGE *fogefoge, char c)
{
    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        for (int j = 0; j < mapa->qntColunas; j++)
        {
            if (mapa->matriz[i][j] == c)
            {
                fogefoge->posicaoX = i;
                fogefoge->posicaoY = j;
                return 1;
            }
        }
    }
    return 0;
}
