/**
 * @file main.c
 * @brief Clasifica caracteres y genera versiones en minúscula y mayúscula.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 120

static void build_cases(const char *src, char *lower, char *upper, int *letters, int *digits, int *others) {
    *letters = *digits = *others = 0;
    for (size_t i = 0; src[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)src[i];
        if (isalpha(c)) {
            (*letters)++;
            lower[i] = (char)tolower(c);
            upper[i] = (char)toupper(c);
        } else if (isdigit(c)) {
            (*digits)++;
            lower[i] = upper[i] = (char)c; /* dígitos sin cambio */
        } else {
            (*others)++;
            lower[i] = upper[i] = (char)c; /* otros sin cambio */
        }
    }
}

int main(void) {
    char original[MAX_LEN + 1];
    if (!fgets(original, sizeof(original), stdin)) {
        original[0] = '\0';
    }
    size_t len = strlen(original);
    if (len > 0 && original[len - 1] == '\n') {
        original[len - 1] = '\0';
        len--; /* longitud lógica */
    }

    char lower[MAX_LEN + 1];
    char upper[MAX_LEN + 1];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    int letters, digits, others;
    build_cases(original, lower, upper, &letters, &digits, &others);
    /* Asegurar terminadores */
    lower[len] = '\0';
    upper[len] = '\0';

    printf("Original: %s\n", original);
    printf("Minuscula: %s\n", lower);
    printf("Mayuscula: %s\n", upper);
    printf("Letras: %d Digitos: %d Otros: %d\n", letters, digits, others);

    return 0;
}
