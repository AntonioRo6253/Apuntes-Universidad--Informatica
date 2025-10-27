// Figura 7.20: fig07_20.c pag. 255, 256
// Uso de las notaciones de subindices y de apuntadores con arreglos
#include <stdio.h>

void compara(int n1, int n2); // prototipo

int main()
{
    int b[] = {10, 20, 30, 40};                  //? tamaño 4
    printf("Direccion del arreglo b = %p\n", b); //? no es necesario el & para el arreglo

    int *ptrB = b;
    printf("Direccion que guarda ptrB = %p\n", ptrB); //?%p es para imprimir la direccion

    int i;              // contador
    int desplazamiento; // contador

    // muestra el arreglo b con la notacion de subindices
    printf("\nArreglo b impreso con:\nNotacion de subindices de arreglos\n");
    /*
     * Notacion subindices
     */
    for (i = 0; i < 4; i++)
        printf("b[ %d ] = %d\n", i, b[i]);

    // muestra el arreglo b mediante el uso del nombre del arreglo y notacion
    // apuntador/desplazamiento
    printf("\nNotacion apuntador/desplazamiento donde\n"
           "el apuntador es el nombre del arreglo\n");
    /*
     *TODO: indice y desplazamiento son lo mismo
     * el nombre de la notacion es apuntador desplasamiento
     */
    for (desplazamiento = 0; desplazamiento < 4; desplazamiento++)
        printf("*(b + %d) = %d\n", desplazamiento, *(b + desplazamiento));

    // muestra el arreglo b mediante el uso del ptrB y notacion de subindices de arreglos
    printf("\nNotacion subindices de arreglos\n");

    for (i = 0; i < 4; i++)
        printf("ptrB[ %d ] = %d\n", i, ptrB[i]);

    // muestra el arreglo b mediante el uso de ptrB y notacion de
    // apuntador/desplazamiento
    printf("\nNotacion apuntador desplazamiento\n");

    for (desplazamiento = 0; desplazamiento < 4; desplazamiento++)
        printf("*(ptrB + %d) = %d\n", desplazamiento, *(ptrB + desplazamiento));

    printf("\n");
    // llamada a la funcion compara
    compara(b[0], b[3]);
    return 0;

} // fin main
  // funcion que compara el primer y ultimo elemento del arreglo para ver si son iguales o diferentes 52 void
compara(int n1, int n2)
{
    if (n1 == n2)
        54 printf("SON IGUALES\n");
    else
        56 printf("SON DIFERENTES\n");
}