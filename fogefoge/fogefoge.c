#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA mapa;
FOGEFOGE fogefoge;
int estaComBomba;

int acabou()
{
    FOGEFOGE pos;
    int encotrou = localizaFogeFoge(&mapa, &pos, HEROI);
    return !encotrou;
}

int proximoMovimentoFantasma(int xAtual, int yAtual, int *xDestino, int *yDestino)
{
    int posicoes[4][2] = {
        {xAtual, yAtual + 1},
        {xAtual + 1, yAtual},
        {xAtual, yAtual - 1},
        {xAtual - 1, yAtual}};

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int opcao = rand() % 4;

        if (podeAndar(&mapa, posicoes[opcao][0], posicoes[opcao][1], FANTASMA))
        {
            *xDestino = posicoes[opcao][0];
            *yDestino = posicoes[opcao][1];
            return 1;
        }
    }
    return 0;
}

void fantasmas()
{
    MAPA copia;

    copiaMapa(&mapa, &copia);

    for (int i = 0; i < mapa.qntLinhas; i++)
    {
        for (int j = 0; j < mapa.qntColunas; j++)
        {
            if (copia.matriz[i][j] == FANTASMA)
            {
                int xDestino, yDestino;

                int conseguiu = proximoMovimentoFantasma(i, j, &xDestino, &yDestino);

                if (conseguiu)
                {
                    atualizaPosicao(&mapa, i, j, xDestino, yDestino);
                }
            }
        }
    }
    liberaMapa(&copia);
}

void move(char comando)
{
    if (!comandoValido(comando))
    {
        return;
    }

    int x = fogefoge.posicaoX,
        y = fogefoge.posicaoY;

    switch (comando)
    {
    case CIMA:
        x--;
        break;
    case ESQUERDA:
        y--;
        break;
    case BAIXO:
        x++;
        break;
    case DIREITA:
        y++;
        break;
    }

    if (!podeAndar(&mapa, x, y, HEROI))
    {
        return;
    }

    if (ehPersonagem(&mapa, x, y, BOMBA))
    {
        printf("HERE!");
        estaComBomba = 1;
    }
    atualizaPosicao(&mapa, fogefoge.posicaoX, fogefoge.posicaoY, x, y);

    fogefoge.posicaoX = x;
    fogefoge.posicaoY = y;
}

void explodeBomba()
{
    if (!estaComBomba)
        return;
    explodeBomba2(fogefoge.posicaoX, fogefoge.posicaoY, 0, 1, 3);
    explodeBomba2(fogefoge.posicaoX, fogefoge.posicaoY, 0, -1, 3);
    explodeBomba2(fogefoge.posicaoX, fogefoge.posicaoY, 1, 0, 3);
    explodeBomba2(fogefoge.posicaoX, fogefoge.posicaoY, -1, 0, 3);

    estaComBomba = 0;
}

void explodeBomba2(int x, int y, int somax, int somay, int qnt)
{
    if (qnt == 0)
        return;

    int novox = x + somax;
    int novoy = y + somay;

    if (finalDeMapa(&mapa, novox, novoy) || ehParede(&mapa, novox, novoy))
        return;

    mapa.matriz[novox][novoy] = VAZIO;
    explodeBomba2(novox, novoy, somax, somay, qnt - 1);
}

int main(int argc, char const *argv[])
{
    leMapa(&mapa);

    localizaFogeFoge(&mapa, &fogefoge, HEROI);

    do
    {
        imprimeMapa(&mapa);
        char comando;
        scanf(" %c", &comando);
        if (comando == USABOMBA)
        {
            explodeBomba();
        }
        fantasmas();
        move(comando);

    } while (!acabou());

    liberaMapa(&mapa);
    return 0;
}
