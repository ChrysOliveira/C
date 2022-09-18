#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_
#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define USABOMBA 'b'

struct fogefoge
{
    int posicaoX;
    int posicaoY;
};

typedef struct fogefoge FOGEFOGE;

int proximoMovimentoFantasma(int xAtual, int yAtual, int *xDestino, int *yDestino);
void explodeBomba2(int x, int y, int somax, int somay, int qnt);
void explodeBomba();

#endif