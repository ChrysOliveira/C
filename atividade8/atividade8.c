#include <stdlib.h>
#include <stdio.h>

typedef struct equacaoseggrau EquacSeg;
struct equacaoseggrau
{
    int a, b, c;
};

void calcularEquacaoSegundoGrau();

void calcularEquacaoSegundoGrau()
{
}

int main()
{
    EquacSeg segundoGrau;

    int opcao;
    while (opcao != 9)
    {
        printf("Digite a operacao que deseja:\n");
        printf("1 - Calcular equacao de segundo grau\n2 - Calcular triangulo heron\n3 - Calcular area de circulo\n");
        scanf("%d", &opcao);
        gets();

        if (opcao == 1)
        {
            calcularEquacaoSegundoGrau();
        }
        else if (opcao == 2)
        {
            calcularTrianguloHeron();
        }
        else if (opcao == 3)
        {
            calcularAreaCirculo();
        }
        else if (opcao == 0)
        {
            exit(0);
        }
        else
        {
            printf("!!!!!!!!!!digite um valor valido!!!!!!!!!!\n");
        }
    }
    return 0;
}
