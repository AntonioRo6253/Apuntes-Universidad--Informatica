#include <stdlib.h>
#include <stdio.h>

// TODO:---Variables globales
int GLOBAL_ArregloIncompleto = 0;
int GLOBAL_ElementosValidos = 0;

// TODO:---Prototipos
double PromedioDeElementos(double LOCAL_Arreglo[], int LOCAL_ElementosValidos);
void LlenarArreglo(double LOCAL_Arreglo[]);
void MostrarArreglo(double LOCAL_Arreglo[], int LOCAL_ElementosValidos);

int main()
{
    int LOCAL_opc;
    double LOCAL_Arreglo[10];

    do
    {
        // TODO:---Menu
        printf("\n\n----------Menu De Arreglo Unidimensional----------\n");
        printf("%-4s 1. Llenar Arreglo\n", " ");
        printf("%-4s 2. Mostrar Arreglo\n", " ");
        printf("%-4s 3. Mostrar El Promedio De Elementos\n", " ");
        printf("%-4s 4. Salir\n", " ");
        printf("~~~~~~~~~~~~~~~~? Elige tu opcion: ");
        scanf("%d", &LOCAL_opc);

        // TODO:---Seleccion de Opcion
        switch (LOCAL_opc)
        {
        case 1:
            LlenarArreglo(LOCAL_Arreglo); // Primer parametro es el arreglo, segundo es el tamaño
            break;
        case 2:
            MostrarArreglo(LOCAL_Arreglo, GLOBAL_ElementosValidos); // Primer parametro es el arreglo, segundo es la cantidad de elementos validos
            break;
        case 3:
            if (GLOBAL_ElementosValidos > 0)
                printf("Promedio de Estaturas: %.2f\n", PromedioDeElementos(LOCAL_Arreglo, GLOBAL_ElementosValidos)); // Primer parametro es el arreglo, segundo es la cantidad de elementos validos
            else
                printf("No hay datos suficientes para calcular el promedio.\n");
            break;
        case 4:
            printf("------------ Gracias por utilizar este programa ------------");
            break;
        default:
            printf("------------!! Opcion No Valida !!------------\n");
            break;
        }
    } while (LOCAL_opc != 4);

    return 0;
}

// TODO:---Definicion de Funciones
void LlenarArreglo(double LOCAL_Arreglo[])
{
    GLOBAL_ArregloIncompleto = 0;
    GLOBAL_ElementosValidos = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("~~~~~~~~~~~~~~~~? -1.0 para Salir o Ingrese la estatura %d: ", i + 1);
        scanf("%lf", &LOCAL_Arreglo[i]);
        if (LOCAL_Arreglo[i] == -1.0)
        {
            GLOBAL_ArregloIncompleto = 1;
            break;
        }
        GLOBAL_ElementosValidos++;
    }
}

void MostrarArreglo(double LOCAL_Arreglo[], int LOCAL_ElementosValidos)
{
    if (LOCAL_ElementosValidos == 0)
    {
        printf("No hay estaturas para mostrar.\n");
        return;
    }
    printf("Estaturas ingresadas:\n");
    for (int i = 0; i < LOCAL_ElementosValidos; i++)// Recorremos solo los elementos validos
    {
        printf("Estatura %d: %.2f\n", i + 1, LOCAL_Arreglo[i]);
    }
    if (LOCAL_ElementosValidos < 10)
        printf("Arreglo incompleto, solo se ingresaron %d estaturas.\n", LOCAL_ElementosValidos);
}

double PromedioDeElementos(double LOCAL_Arreglo[], int LOCAL_ElementosValidos)
{
    double LOCAL_suma = 0.0;
    for (int i = 0; i < LOCAL_ElementosValidos; i++)
    {
        LOCAL_suma += LOCAL_Arreglo[i];// Sumar solo los elementos validos
    }
    return (LOCAL_ElementosValidos > 0) ? (LOCAL_suma / LOCAL_ElementosValidos) : 0.0; // Evitar division por cero
}
