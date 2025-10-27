/**
 * @file main.c
 * @brief Construye "Nombre Apellido" de forma segura usando fgets y strncat.
 */
#include <stdio.h>
#include <string.h>

/** @brief Longitud máxima admitida para nombre o apellido individuales. */
#define MAX_PART 80
/** @brief Capacidad del buffer final "Nombre Apellido" incluyendo espacios. */
#define MAX_FULL (MAX_PART*2 + 2) /* nombre + espacio + apellido + nul */

static void remove_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len && s[len - 1] == '\n') s[len - 1] = '\0';
}

/**
 * @brief Lee nombre y apellido, los normaliza y construye la salida segura.
 */
int main(void) {
    char nombre[MAX_PART + 1] = {0};
    char apellido[MAX_PART + 1] = {0};
    char full[MAX_FULL + 1] = {0};

    if (!fgets(nombre, sizeof(nombre), stdin)) nombre[0] = '\0';
    if (!fgets(apellido, sizeof(apellido), stdin)) apellido[0] = '\0';

    remove_newline(nombre);
    remove_newline(apellido);

    /* Construcción segura */
    size_t cap = sizeof(full) - 1; /* espacio disponible real */
    full[0] = '\0';

    if (nombre[0] != '\0') {
        strncat(full, nombre, cap - strlen(full));
    }
    if (apellido[0] != '\0') {
        if (full[0] != '\0') {
            if (strlen(full) + 1 < cap) strncat(full, " ", cap - strlen(full) - 1);
        }
        strncat(full, apellido, cap - strlen(full));
    }

    printf("Nombre completo: %s\n", full);
    return 0;
}
