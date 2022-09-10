#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char mapa[5][10 + 1];
    FILE *f = fopen("mapa.txt", "r");
    if (f == 0)
    {
        printf("Nao foi possivel ler o mapa!\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", mapa[i]);
    }

    return 0;
}
