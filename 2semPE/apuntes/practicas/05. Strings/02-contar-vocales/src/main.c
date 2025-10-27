/**
 * @file main.c
 * @brief Cuenta vocales a,e,i,o,u (no acentuadas), insensible a mayúsculas.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** @brief Límite de caracteres para analizar vocales. */
#define MAX_LEN 200

static void remove_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len && s[len - 1] == '\n') s[len - 1] = '\0';
}

static int es_vocal(char c) {
    c = (char)tolower((unsigned char)c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

/**
 * @brief Calcula la cantidad de vocales presentes en la entrada estándar.
 */
int main(void) {
    char s[MAX_LEN + 1];
    if (!fgets(s, sizeof(s), stdin)) {
        s[0] = '\0';
    }
    remove_newline(s);

    int count = 0;
    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) {
        if (es_vocal(s[i])) count++;
    }

    printf("Vocales: %d\n", count);
    return 0;
}
