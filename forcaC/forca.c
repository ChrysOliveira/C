#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "forca.h"

int enforcou(int tentativa, int quantidadeDeTentativas, char letrasChutadas[26], char palavraSecreta[20])
{
    int erros = 0;

    for (int i = 0; i < tentativa; i++)
    {
        int acertou = 0;
        for (int j = 0; j < strlen(palavraSecreta); j++)
        {
            if (letrasChutadas[i] == palavraSecreta[j])
            {
                acertou = 1;
                break;
            }
        }
        if (!acertou)
        {
            erros++;
        }
    }

    return erros >= quantidadeDeTentativas;
}

void abertura()
{
    printf("********************************\n");
    printf("*        Jogo de Forca         *\n");
    printf("********************************\n");
}

int jaChutou(char letraChutada, char letrasChutadas[26])
{
    int jaChutou = 0;
    for (int i = 0; i < strlen(letrasChutadas); i++)
    {
        if (letraChutada == letrasChutadas[i])
        {
            jaChutou = 1;
            break;
        }
    }
    return jaChutou;
}

void desenhaForca(char palavraSecreta[20], char letrasChutadas[26], int tentativa)
{

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {

        int achou = jaChutou(palavraSecreta[i], letrasChutadas);

        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void chutaLetra(int *tentativa, char letrasChutadas[26])
{
    char chute;
    int achou;

    printf("Chute uma letra: \n");
    scanf(" %c", &chute);

    achou = jaChutou(chute, letrasChutadas);

    if (!achou)
    {
        letrasChutadas[(*tentativa)] = chute;
        (*tentativa)++;
    }
}

int ganhou(char palavraSecreta[20], char letrasChutadas[26])
{
    int acertou = 0;
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        for (int j = 0; j < strlen(letrasChutadas); j++)
        {
            if (letrasChutadas[j] == palavraSecreta[i])
            {
                acertou++;
                break;
            }
        }
    }
    return (acertou == strlen(palavraSecreta));
}

void escolhePalavra(char palavraSecreta[20])
{
    FILE *f = fopen("palavras.txt", "r");

    if (f == 0)
    {
        printf("Banco de dados nao disponivel!\n");
        exit(1);
    }

    int qntDePalavras;
    fscanf(f, "%d", &qntDePalavras);

    srand(time(0));

    int randomico = rand() % qntDePalavras;

    for (int i = 0; i < qntDePalavras; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

void adicionaPalavra()
{
    printf("Deseja adicionar uma nova palavra ?S ou N\n");
    char escolha;
    scanf(" %c", &escolha);

    if ('s' == tolower(escolha))
    {

        printf("Qual a nova palavra?\n");
        char novaPalavra[20];

        scanf("%s", novaPalavra);

        FILE *f = fopen("palavras.txt", "r+");

        if (f == 0)
        {
            printf("Banco de dados indisponivel!\n");
            exit(1);
        }

        int qntDePalavras;
        fscanf(f, "%d", &qntDePalavras);
        qntDePalavras++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qntDePalavras);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
    else
    {
        exit(0);
    }
}

int main()
{
    char palavraSecreta[20];
    char letrasChutadas[26];
    int quantidadeDeTentativas = 5;
    int tentativa = 0;

    escolhePalavra(palavraSecreta);

    abertura();

    do
    {
        desenhaForca(palavraSecreta, letrasChutadas, tentativa);

        chutaLetra(&tentativa, letrasChutadas);
    } while (!enforcou(tentativa, quantidadeDeTentativas, letrasChutadas, palavraSecreta) &&
             !ganhou(palavraSecreta, letrasChutadas));

    adicionaPalavra();
    return 0;
}