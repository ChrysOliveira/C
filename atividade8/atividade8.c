#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct equacaoseggrau EquacSeg;
struct equacaoseggrau
{
    double a, b, c;
};

typedef struct triHeron triHeron;

struct triHeron
{
    double a, b, c;
};

typedef struct circulo Circulo;

struct circulo
{
    double raio;
};

double calculaDelta(EquacSeg *equacseg)
{
    double delta = (pow(equacseg->b, 2) - (4 * equacseg->a * equacseg->b));
    return delta;
}

void resultadoSegGrau(double x1, double x2)
{
    printf("O resultado x' eh: %lf \n", x1);
    printf("O resultado x\" eh: %lf \n", x2);
}

void calcularEquacaoSegundoGrau(EquacSeg *equacseg)
{
    printf("Digite o valor do a b c na sequencia:\n");
    printf("a:\n");
    scanf("%lf", &equacseg->a);
    printf("b:\n");
    scanf("%lf", &equacseg->b);
    printf("c:\n");
    scanf("%lf", &equacseg->c);

    double delta = calculaDelta(equacseg);

    double x1, x2;

    x1 = ((equacseg->b * -1) + sqrt(delta)) / 2 * equacseg->a;
    x1 = ((equacseg->b * -1) - sqrt(delta)) / 2 * equacseg->a;
    system("clear");
    resultadoSegGrau(x1, x2);
}

double calculaHeron(triHeron *triHeron)
{
    double p = (triHeron->a + triHeron->b + triHeron->c) / 2;
    double heron = sqrt(p * (p - triHeron->a) * (p - triHeron->b) * (p - triHeron->c));

    return heron;
}

void calcularTrianguloHeron(triHeron *triHeron)
{
    printf("Digite o valor dos lados a b c na sequencia:\n");
    printf("a:\n");
    scanf("%lf", &triHeron->a);
    printf("b:\n");
    scanf("%lf", &triHeron->b);
    printf("c:\n");
    scanf("%lf", &triHeron->c);

    double heron = calculaHeron(triHeron);

    system("clear");
    printf("O valor do triangulo de heron eh: %lf \n", heron);
}

double calculaAreaCirculo(Circulo *circulo)
{
    double area = 3.14 * pow(circulo->raio, 2);
}

void calcularAreaCirculo(Circulo *circulo)
{
    printf("Digite o valor do raio:\n");
    scanf("%lf", &circulo->raio);

    double area = calculaAreaCirculo(circulo);

    system("clear");
    printf("O valor da area do circulo eh: %lf \n", area);
}

int main()
{
    EquacSeg segundoGrau;
    triHeron triHeron;
    Circulo circulo;

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
            calcularTrianguloHeron(&triHeron);
        }
        else if (opcao == 3)
        {
            calcularAreaCirculo(&circulo);
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
