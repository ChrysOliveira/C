#ifndef _MAPA_H_
#define _MAPA_H_
#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define BOMBA 'P'
#include "fogefoge.h"

struct mapa
{
    char **matriz;
    int qntLinhas;
    int qntColunas;
};

typedef struct mapa MAPA;

void liberaMapa(MAPA *mapa);
void leMapa(MAPA *mapa);
void alocaMapa(MAPA *mapa);
int localizaFogeFoge(MAPA *mapa, FOGEFOGE *fogefoge, char c);
int comandoValido(char comando);
int finalDeMapa(MAPA *mapa, int posicaoX, int posicaoY);
int campoVazio(MAPA *mapa, int posicaoX, int posicaoY);
void atualizaPosicao(MAPA *mapa, int x, int y, int proxX, int proxY);
void fantasmas();
void copiaMapa(MAPA *mapa, MAPA *copia);
int podeAndar(MAPA *mapa, int x, int y, char personagem);
int ehPersonagem(MAPA *mapa, int x, int y, char personagem);
int ehParede(MAPA *mapa, int x, int y);
#endif