#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Variables
    int numeroSimple = 10;
    float numeroDecimal = 5.5;
    char unCaracterMinus = 'l';
    char unCaracterMayus = 'L';
    const char* unTexto = "Hola mundo";
    short int decimalCorto = 32767;
    int decimalCortoFueraDeLimite = 32768;

    // Impresiones Normales

    printf("numeroSimple: %d\n", numeroSimple);
    printf("numeroDecimal: %f\n", numeroDecimal);
    printf("CaracterMinus: %c\n", unCaracterMinus);
    printf("CaracterMayus: %c\n", unCaracterMayus);
    printf("Texto: %s\n", unTexto);
    printf("decimalCorto: %d\n", decimalCorto);
    printf("decimalCortoFueraDeLimite: %d\n", decimalCortoFueraDeLimite);

    //pruebas
    double numeroDecimalFueraDeLimite = 2147483648;
    printf("numeroDecimal fuera de limite: %f\n", numeroDecimalFueraDeLimite);
    printf("numeroSimple mas 3: %d\n", numeroSimple + 3);
    printf("numeroSimple menos 3: %d\n", numeroSimple - 3);
    printf("numeroSimple por 3: %d\n", numeroSimple * 3);
    printf("numeroSimple entre 3: %d\n", numeroSimple / 3);
    printf("numeroSimple residuo de entre 3: %d\n", numeroSimple % 3);
    printf("numeroSimple exponente 2: %d\n", numeroSimple * numeroSimple);
    return 0;
}
