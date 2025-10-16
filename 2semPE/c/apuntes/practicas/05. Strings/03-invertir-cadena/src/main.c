/**
 * @file main.c
 * @brief Invierte una cadena in-place y la imprime con prefijo.
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

static void remove_newline(char *s) {
    if (!s) return;
    size_t len = strlen(s);
    if (len && s[len - 1] == '\n') s[len - 1] = '\0';
}

int main(void) {
    char s[MAX_LEN + 1];
    if (!fgets(s, sizeof(s), stdin)) s[0] = '\0';
    remove_newline(s);

    size_t n = strlen(s);
    for (size_t i = 0, j = n ? n - 1 : 0; i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    printf("Invertida: %s\n", s);
    return 0;
}
