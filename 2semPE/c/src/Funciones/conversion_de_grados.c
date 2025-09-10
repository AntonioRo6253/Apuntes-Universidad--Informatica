#include <stdlib.h>
#include <stdio.h>

//
//Robles Arambura Rafael Antonio
//El programa convierte grados Celsius a Fahrenheit y viceversa 
//usando funciones.

// TODO:---Prototipos de Funciones
/**
 * @brief Convierte grados Celsius a Fahrenheit
 *
 * Esta funcion toma un numero en Celsius, lo multiplica por 1.8
 * y lo imprime en consola.
 *
 * @param LOCAL_gradosC Cantidad de grados Celsius a convertir
 * @return void
 */
void cent_a_fahr(double);

/**
 * @brief Convierte grados Fahrenheit a Celsius
 *
 * Esta funcion toma un numero en Fahrenheit, le resta 32.0, lo divide entre 1.8
 * y retorna el resultado como decimal.
 *
 * @param LOCAL_gradosF Cantidad de grados Fahrenheit a convertir
 * @return double Cantidad de grados Celsius convertidos
 */
double fahr_a_cent(double);

int main()
{
    int GLOBAL_opc;
    double GLOBAL_gradosC, GLOBAL_gradosF;
    do
    {
        // TODO:---Menu
        printf("\n\n----------Menu Conversion De Grados----------\n");
        printf("%-4s 1. De grados C a grados F\n", " "); // El %-4s es solo para dejar espacios
        printf("%-4s 2. De grados F a grados C\n", " ");
        printf("%-4s 3. Salir\n", " ");
        printf("~~~~~~~~~~~~~~~~? Elige tu opcion: ");
        scanf("%d", &GLOBAL_opc);

        // TODO:---Seleccion de Opcion
        switch (GLOBAL_opc)
        {
        case 1:
            printf("~~~~~~~~~~~~~~~~? Teclea la cant de grados C a convertir:");
            scanf("%lf", &GLOBAL_gradosC);
            system("cls");               // limpiar la consola
            cent_a_fahr(GLOBAL_gradosC); //? LLamar a la Funcion
            break;
        case 2:
            printf("~~~~~~~~~~~~~~~~? Teclea la cant de grados F a convertir:");
            scanf("%lf", &GLOBAL_gradosF);
            system("cls");                                // limpiar la consola
            GLOBAL_gradosC = fahr_a_cent(GLOBAL_gradosF); //? LLamar a la Funcion y guardar el valor de retorno
            printf("\n------------| Grados F %.2f equivalen a: %.2f C |------------", GLOBAL_gradosF, GLOBAL_gradosC);
            break;
        case 3:
            printf("------------ Gracias por utilizar este programa ------------");
            break;

        default:
            printf("------------!! Opcion No Valida !!------------\n");
            break;
        }
    } while (GLOBAL_opc != 3);

    return 0;
}

// TODO:---Definicion de Funciones
void cent_a_fahr(double LOCAL_gradosC)
{
    double LOCAL_gradosF;
    LOCAL_gradosF = 1.8 * LOCAL_gradosC + 32.0;
    printf("------------| Grados C %.2f equivalen a: %.2f F |------------", LOCAL_gradosC, LOCAL_gradosF);
}

double fahr_a_cent(double LOCAL_gradosF)
{
    return (LOCAL_gradosF - 32.0) / 1.8;
}

/**
 * @file conversion_de_grados.c
 * @author Antonio Rafael
 * @brief  Usando funciones para conversion de grados
 * @date 01 de septiembre de 2025
 *
 * \anchor conversion_de_grados
 */