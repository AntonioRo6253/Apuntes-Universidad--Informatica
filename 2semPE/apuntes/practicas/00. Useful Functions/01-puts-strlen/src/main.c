/**
 * @file main.c
 * @brief Lectura segura de una línea y cálculo de longitud sin newline.
 * @author Curso C
 * @date 2025-10-04
 */
#include <stdio.h>
#include <string.h>

/** @brief Número máximo de caracteres aceptados por la lectura. */
#define MAX_LEN 80

/**
 * @brief Elimina el newline final (si existe) reemplazándolo por terminador nulo.
 * @param s Cadena mutable.
 */
static void remove_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

/**
 * @brief Punto de entrada: lee una línea, limpia el salto e imprime longitud.
 */
int main(void) {
    char buffer[MAX_LEN + 1]; /* +1 para '\0' */

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        /* Entrada vacía / error: tratamos como cadena vacía */
        buffer[0] = '\0';
    }

    remove_newline(buffer);

    /* Imprime la cadena; puts añade '\n' */
    puts(buffer);

    /* Longitud lógica */
    printf("Longitud: %zu\n", strlen(buffer));

    return 0;
}
