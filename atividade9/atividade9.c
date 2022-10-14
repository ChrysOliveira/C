#include <stdlib.h>
#include <stdio.h>
#define TAMANHO_LISTA 2

typedef struct pessoa Funcionario;

struct pessoa
{
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

void aumentoSalario(Funcionario *funcionario)
{
    int opcao;

    printf("Qual funcionario deseja aumentar o salario? 1 ou 2\n");
    scanf("%d", &opcao);
    funcionario[opcao].salario *= 1.10;
}

void cadastrarPessoa(Funcionario *funcionario)
{
    int opcao;

    printf("Qual funcionario deseja cadastrar? 1 ou 2\n");
    scanf("%d", &opcao);

    printf("Digite o nome do funcionario: \n");
    scanf("%s", &funcionario[opcao].nome);

    printf("Digite a idade do funcionario: \n");
    scanf("%d", &funcionario[opcao].idade);
    gets();

    printf("Digite o sexo do funcionario: \n");
    scanf("%c", &funcionario[opcao].sexo);

    printf("Digite o salario do funcionario: \n");
    scanf("%f", &funcionario[opcao].salario);
}

void listarPessoas(Funcionario *funcionario)
{
    for (int i = 1; i <= TAMANHO_LISTA; i++)
    {
        printf("Funcionario %d\n", i);
        printf("Nome: %s\nIdade: %d\nSexo: %c\nSalario: %lf\n", funcionario[i].nome, funcionario[i].idade, funcionario[i].sexo, funcionario[i].salario);
        printf("\n\n\n");
    }
}

int main()
{
    Funcionario funcionario[TAMANHO_LISTA];

    int opcao;
    while (opcao != 9)
    {
        printf("Digite a operacao que deseja:\n");
        printf("1 - Cadastrar funcionarios\n2 - Listar Funcionarios\n3 - Aumentar salario\n");
        scanf("%d", &opcao);
        gets();

        if (opcao == 1)
        {
            cadastrarPessoa(funcionario);
        }
        else if (opcao == 2)
        {
            listarPessoas(funcionario);
        }
        else if (opcao == 3)
        {
            aumentoSalario(funcionario);
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
