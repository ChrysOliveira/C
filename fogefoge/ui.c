#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhoparede[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char desenhoheroi[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

char desenhofantasma[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

void imprimeparte(char desenho[4][7], int parte)
{
    printf("%s", desenho[parte]);
}

void imprimeMapa(MAPA *mapa)
{
    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        for (int parte = 0; parte < 4; parte++)
        {
            for (int j = 0; j < mapa->qntColunas; j++)
            {
                switch (mapa->matriz[i][j])
                {
                case HEROI:
                    imprimeparte(desenhoheroi, parte);
                    break;
                case FANTASMA:
                    imprimeparte(desenhofantasma, parte);
                    break;
                case PAREDE_HORIZONTAL:
                case PAREDE_VERTICAL:
                    imprimeparte(desenhoparede, parte);
                    break;
                case BOMBA:
                    imprimeparte(desenhopilula, parte);
                    break;
                case VAZIO:
                    imprimeparte(desenhovazio, parte);
                    break;
                }
            }
        }
        printf("\n");
    }
}
