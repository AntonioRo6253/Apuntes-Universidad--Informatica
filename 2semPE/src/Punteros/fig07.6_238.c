#include <stdio.h>
int cuboPorValor(int n);
int main(void)
{
    int num = 5;
    printf("El valor original del numero es %d\n", num);
    // ? Se envia una copia ala funcion, y la funcion retorna un resultado
    printf("El cubo de %d es=%d\n", num, cuboPorValor(num));
    printf("El valor original se conserva, numero es = %d\n", num);
    return 0;
} // Fin del main

//? Funcion que calcula y devuelve el cubo de un argumento entero
int cuboPorValor(int n)
{
    return n * n * n;
}
