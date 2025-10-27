/*
 * VLA_demo.c
 * Demonstrates Variable Length Arrays (VLAs) introduced in C99.
 * Reads an integer n, creates a VLA `char str[n]`, prints sizeof, then
 * reads a string into it (with bounds checking) and shows limitations.
 *
 * Limitations shown in comments:
 *  - VLAs exist only in the scope where they are declared
 *  - VLAs cannot be resized after creation
 *  - VLAs consume stack memory (may overflow for large n)
 *
 * Compile: gcc -std=c99 -Wall -Wextra -pedantic VLA_demo.c -o VLA_demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    printf("Introduce el tamaño n para el VLA (por ejemplo 16): ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Entrada no válida\n");
        return 1;
    }

    if (n <= 0) {
        fprintf(stderr, "n debe ser mayor que cero\n");
        return 1;
    }

    /* Declaración de VLA - válido a partir de C99 */
    char str[n];

    printf("sizeof(str) = %zu bytes\n", sizeof(str));
    printf("Puedes escribir hasta %d caracteres (menos 1 para el NUL)\n", n-1);

    /* Consumir el salto de línea dejado por scanf antes de fgets */
    int c = getchar();
    if (c != '\n' && c != EOF) { /* limpiar hasta fin de línea */
        while ((c = getchar()) != '\n' && c != EOF) ;
    }

    printf("Introduce una cadena: ");
    if (fgets(str, n, stdin) == NULL) {
        fprintf(stderr, "Error leyendo la cadena\n");
        return 1;
    }

    /* Eliminar posible '\n' al final de la cadena */
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] = '\0';

    printf("Has introducido: '%s' (longitud %zu)\n", str, strlen(str));

    /* Mostrar limitaciones en tiempo de ejecución */
    printf("\nNotas sobre VLAs:\n");
    printf(" - El arreglo \"str\" solo existe en este ámbito (no se puede devolver)\n");
    printf(" - No puedes redimensionarlo (no hay realloc para VLAs)\n");
    printf(" - Su tamaño viene de la pila: pedir valores muy grandes puede fallar\n");

    /* Ejemplo de alcance: crear una función interna demuestra que no es accesible fuera */
    {
        /* Nuevo ámbito */
        int m = 4;
        char tmp[m]; /* VLA en otro ámbito */
        (void)tmp; /* evitar warning */
        printf("(Ejemplo) VLA tmp de tamaño %d existe solo en este bloque\n", m);
    }

    return 0;
}
