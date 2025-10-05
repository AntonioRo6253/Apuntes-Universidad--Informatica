/**
 * @file main.c
 * @brief Verifica si una línea es palíndromo alfabético (ignora no letras, case-insensitive).
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

static size_t normalizar(const char *src, char *dest) {
    size_t j = 0;
    for (size_t i = 0; src[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)src[i];
        if (isalpha(c)) {
            dest[j++] = (char)tolower(c);
        }
    }
    dest[j] = '\0';
    return j;
}

static int es_palindromo(const char *s, size_t len) {
    if (len == 0) return 0; /* criterio: vacío NO */
    size_t i = 0, k = len ? len - 1 : 0;
    while (i < k) {
        if (s[i] != s[k]) return 0;
        ++i; --k;
    }
    return 1;
}

int main(void) {
    char buffer[MAX_LEN + 1];
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        buffer[0] = '\0';
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';

    char filtrada[MAX_LEN + 1];
    size_t f_len = normalizar(buffer, filtrada);

    int ok = es_palindromo(filtrada, f_len);
    puts(ok ? "SI" : "NO");
    return 0;
}
