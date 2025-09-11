#include <stdio.h>

int main()
{
    float precios_Compus[2][4];// 2 filas y 4 columnas
    printf("----------Programa Para Guardar Los Precios De Computadoras----------\n");
    

    for (int f = 0; f < 2; f++)// f=fila, c=columna
    {
        for ( int c = 0; c < 4; c++)
        {
            printf("Teclea el precio de la compu: ");
            scanf("%f",&precios_Compus[f][c]);
        }
    }
    printf("--------------------------------------------Los precios de las compus son:\n\n");
    int ContarElementos = 1;// Creo una variable que vale 1 y la voy a ir incrementando
    for (int f = 0; f < 2; f++)
    {
        for ( int c = 0; c < 4; c++)
        {
            printf("Computadora-%d: %.2f \n",ContarElementos,precios_Compus[f][c]);
            ContarElementos++;
        }
    }

    
    return 0;
}
