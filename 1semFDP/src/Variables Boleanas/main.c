
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // para usar bool

int main()
{
    //-----------------------------------------------Declarando las variables----------------------------------------------------------------
    bool boolTrue = true;
    bool boolFalse = false;
    bool combinacionesTablasDeVerdad[4][2] = {{true,true},{false,false},{true,false},{false,true}};

    //-----------------------------------------------Mostrar las tablas de verdad------------------------------------------------------------
    printf("Mostrando True : %d\n", boolTrue);
    printf("Mostrando False : %d\n", boolFalse);

    printf("\n\nMostrando Operador AND\n");

    for(int i=0; i<4; i++){
        printf("%d && %d = %d\n", combinacionesTablasDeVerdad[i][0], combinacionesTablasDeVerdad[i][1], combinacionesTablasDeVerdad[i][0] && combinacionesTablasDeVerdad[i][1]);
    };

    printf("Mostrando Operador OR\n");

    for(int i=0; i<4; i++){
        printf("%d || %d = %d\n", combinacionesTablasDeVerdad[i][0], combinacionesTablasDeVerdad[i][1], combinacionesTablasDeVerdad[i][0] || combinacionesTablasDeVerdad[i][1]);
    };

    printf("\n\nMostrando la negacion simple\n El valor original es %d y su negacion es %d\n",boolTrue,!boolTrue);
    printf("Mostrando la negacion simple\n El valor original es %d y su negacion es %d\n",boolFalse,!boolFalse);


    printf("\n\nMostrando Operador AND/NAND con negacion\n");

    for(int i=0; i<4; i++){
        printf("%d && %d = %d\n", combinacionesTablasDeVerdad[i][0], combinacionesTablasDeVerdad[i][1], !(combinacionesTablasDeVerdad[i][0] && combinacionesTablasDeVerdad[i][1]));
    };


    printf("Mostrando Operador OR/NOR con negacion\n");

    for(int i=0; i<4; i++){
        printf("%d || %d = %d\n", combinacionesTablasDeVerdad[i][0], combinacionesTablasDeVerdad[i][1], !(combinacionesTablasDeVerdad[i][0] || combinacionesTablasDeVerdad[i][1]));
    };
    return 0;
}
