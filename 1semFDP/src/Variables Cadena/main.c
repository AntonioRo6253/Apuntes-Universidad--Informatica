#include <stdio.h>
#include <stdlib.h>

char asciiMayus(char charLocal) {
    if (charLocal >= 'a' && charLocal <= 'z') {
        charLocal -= 32; // Convertir a mayuscula
    } else {
        charLocal += 32; // Convertir a minuscula
    }
    return charLocal;
}

int main() {
    char AnalizarCaracter;
    char respuesta;

    do {
        printf("Introduce tu letra: ");
        scanf(" %c", &AnalizarCaracter); // Espacio en blanco para consumir el '\n'

        int AnalizarCaracterASCII = (int)AnalizarCaracter;
        printf("Tu caracter es el siguiente: \"%c\"\nASCII: %d\nInvertido: %c\n", AnalizarCaracter, AnalizarCaracterASCII, asciiMayus(AnalizarCaracter));

        printf("¿Quieres volver a ejecutar? (s/n): ");
        scanf(" %c", &respuesta); // Espacio en blanco para consumir el '\n'

    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
