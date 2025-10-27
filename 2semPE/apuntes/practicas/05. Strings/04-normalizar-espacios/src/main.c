/**
 * @file main.c
 * @brief Normaliza espacios: trim y colapsa múltiples espacios a uno.
 */
#include <stdio.h>
#include <string.h>

/** @brief Tamaño máximo de la línea a normalizar. */
#define MAX_LEN 200

static void remove_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len && s[len - 1] == '\n') s[len - 1] = '\0';
}

/**
 * @brief Ajusta espacios en la cadena de entrada y emite la versión limpia.
 */
int main(void) {
    char in[MAX_LEN + 1];
    char out[MAX_LEN + 1];
    if (!fgets(in, sizeof(in), stdin)) in[0] = '\0';
    remove_newline(in);

    size_t n = strlen(in);
    size_t start = 0;
    while (start < n && in[start] == ' ') start++;
    size_t end = n;
    while (end > start && in[end - 1] == ' ') end--;

    size_t w = 0;
    int prev_space = 0;
    for (size_t r = start; r < end; r++) {
        char c = in[r];
        if (c == ' ') {
            prev_space = 1; /* aplazamos espacio */
        } else {
            if (prev_space && w < sizeof(out) - 1) {
                out[w++] = ' ';
            }
            prev_space = 0;
            if (w < sizeof(out) - 1) out[w++] = c;
        }
    }
    out[w] = '\0';

    printf("Normalizado: %s\n", out);
    return 0;
}
