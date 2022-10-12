#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct equacaoseggrau EquacSeg;
struct equacaoseggrau
{
    int a, b, c;
};

double calculaDelta(EquacSeg *equacseg)
{
    double delta = pow((equacseg->b * -1), 2) - (4 * equacseg->a * equacseg->b);
    return delta;
}

void calcularEquacaoSegundoGrau(EquacSeg *equacseg)
{
    printf("Digite o valor do a b c na sequencia:\n");
    printf("a:\n");
    scanf("%d", &equacseg->a);
    printf("b:\n");
    scanf("%d", &equacseg->b);
    printf("c:\n");
    scanf("%d", &equacseg->c);

    double delta = calculaDelta(equacseg);

    // parei aqui fazendo a segundo grau
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
            calcularEquacaoSegundoGrau(&segundoGrau);
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
