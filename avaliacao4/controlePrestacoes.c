/*Faça o algoritmo que leia uma lista de nomes de devedores e suas
prestações em atraso, no máximo 5, e também a quantidade de dias em atraso
de cada prestação. Levando-se em conta a taxa de multa de 2% e a taxa de
juros mensal de 1%, calcule o valor a pagar atualizado com o valor da multa e
o valor dos juros para cada prestação atrasada. Os vetores de entrada são:
Devedor[5][30], ValPrincipal[5], QtdeDias[5], o Vetor de Saída será
ValorPagar[5]. TaxaMulta e TaxaJuros deverá ser declaradas como constantes
no início do código. Ao final exiba o vetor ValorPagar[] e também a MÉDIA
deste vetor, ou seja, a média dos valores do vetor ValorPagar[]. Criar
sub-rotinas para fazer os cálculos, processar e exibir os resultados esperados
e claro, coloque um menu para controlar as operações. Veja no próximo slide
os passos lógicos sugeridos pelo professor que irão facilitar o seu trabalho.*/

#include <stdlib.h>
#include <stdio.h>

float const taxaMulta = 0.02;
float const taxaJurosMensal = 0.01;
int const quantidadeDevedores = 5;

void defineNomeDevedores(char nomeDevedores[quantidadeDevedores][30])
{
    printf("Digite os nomes dos %d devedores: \n", quantidadeDevedores);
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        printf("Devedor %d: \n", (i + 1));
        gets(nomeDevedores[i]);
    }
}

void defineValoresPrestacoes(float valorPrestacao[quantidadeDevedores])
{
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        printf("Digite o valor da prestacao do devedor %d: \n", (i + 1));
        scanf("%f", &valorPrestacao[i]);
        gets();
    }
}

void defineQntDiasAtraso(int qntDiasAtraso[quantidadeDevedores])
{
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        printf("Digite a quantidade de dias em atraso do devedor %d: \n", (i + 1));
        scanf("%d", &qntDiasAtraso[i]);
        gets();
    }
}

float calculaAMulta(float valor)
{
    return (float)(valor * taxaMulta);
}

float calculaJuros(float valor, int qntDiasAtraso)
{
    return (float)(valor * taxaJurosMensal * qntDiasAtraso);
}

void calculaValoresAPagar(float valoresAPagar[quantidadeDevedores],
                          float valorPrestacao[quantidadeDevedores],
                          int qntDiasAtraso[quantidadeDevedores])
{
    float valorDaMulta, valorDaTaxa, soma;
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        valorDaMulta = calculaAMulta(valorPrestacao[i]);
        valorDaTaxa = calculaJuros(valorPrestacao[i], qntDiasAtraso[i]);
        soma = (valorPrestacao[i] + valorDaMulta + valorDaTaxa);
        valoresAPagar[i] = soma;
    }
}

float calculaMediaValoresAPagar(float valoresAPagar[quantidadeDevedores])
{
    float media;
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        media += valoresAPagar[i];
    }

    return (media /= quantidadeDevedores);
}

void apresentaDados(char nomeDevedores[quantidadeDevedores][30], float valoresAPagar[quantidadeDevedores], float media)
{
    printf("Aqui estao os devedores e seus respectivos valores a pagar: \n");
    for (int i = 0; i < quantidadeDevedores; i++)
    {
        printf("Devedor: %s -> R$ %.2f \n", nomeDevedores[i], valoresAPagar[i]);
    }

    printf("\n\n");
    printf("O valor medio dos pagamentos pendentes eh de: R$%.2f \n", media);
    printf("\n\n");
}

void menu(char nomeDevedores[quantidadeDevedores][30],
          float valorPrestacao[quantidadeDevedores],
          int qntDiasAtraso[quantidadeDevedores],
          float valoresAPagar[quantidadeDevedores])
{
    int opcao;
    float media;
    do
    {
        printf("Selecione a opcao que voce deseja: \n 1 - Inserir dados | 2 - Exibir valores das prestacoes | 3 - Sair\n");
        scanf("%d", &opcao);
        gets();
        switch (opcao)
        {
        case 1:
            defineNomeDevedores(nomeDevedores);
            defineValoresPrestacoes(valorPrestacao);
            defineQntDiasAtraso(qntDiasAtraso);
            calculaValoresAPagar(valoresAPagar, valorPrestacao, qntDiasAtraso);
            media = calculaMediaValoresAPagar(valoresAPagar);
            break;
        case 2:
            apresentaDados(nomeDevedores, valoresAPagar, media);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Digite um valor valido!!!\n");
            break;
        }
    } while (opcao != 3);
}

int main()
{
    char nomeDevedores[quantidadeDevedores][30];
    float valorPrestacao[quantidadeDevedores];
    int qntDiasAtraso[quantidadeDevedores];
    float valoresAPagar[quantidadeDevedores];

    menu(nomeDevedores, valorPrestacao, qntDiasAtraso, valoresAPagar);

    return 0;
}