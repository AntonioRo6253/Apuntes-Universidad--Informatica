#include <stdio.h>



int main()
{
    int edades[3][5];

    for (int f = 0; f < 3; f++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("Ingresa la edad del estudiante %d del grupo %d: ", c + 1, f + 1);
            scanf("%d", &edades[f][c]);
        }
    }

    printf("\nEdades ingresadas:\n");
    for (int f = 0; f < 3; f++)
    {
        printf("Fila %d: ", f + 1);
        for (int c = 0; c < 5; c++)
        {
            printf("%d ", edades[f][c]);
        }
        printf("\n");
    }

    return 0;
}