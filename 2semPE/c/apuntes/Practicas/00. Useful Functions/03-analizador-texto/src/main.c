/**
 * @file main.c
 * @brief Analizador estadístico multi-línea de texto: letras, dígitos, otros y frecuencias a..z.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 255
#define ALPHABET 26

struct Stats {
    unsigned long lines;
    unsigned long chars;      /* visibles (sin newline final) */
    unsigned long letters;
    unsigned long digits;
    unsigned long others;
    unsigned long freq[ALPHABET];
};

static void init_stats(struct Stats *s) {
    memset(s, 0, sizeof(*s));
}

static void process_line(const char *line, struct Stats *s) {
    if (!line) return;
    s->lines++;
    size_t len = strlen(line);
    /* Excluir newline final si existe al final */
    if (len > 0 && line[len - 1] == '\n') {
        len--; /* no contado como caracter visible */
    }
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = (unsigned char)line[i];
        s->chars++;
        if (isalpha(c)) {
            s->letters++;
            unsigned char lower = (unsigned char)tolower(c);
            if (lower >= 'a' && lower <= 'z') {
                s->freq[lower - 'a']++;
            }
        } else if (isdigit(c)) {
            s->digits++;
        } else {
            s->others++;
        }
    }
}

static void print_report(const struct Stats *s) {
    printf("Lineas: %lu\n", s->lines);
    printf("Caracteres: %lu\n", s->chars);
    printf("Letras: %lu Digitos: %lu Otros: %lu\n", s->letters, s->digits, s->others);
    puts("Frecuencias:");
    for (int i = 0; i < ALPHABET; ++i) {
        printf("%c: %lu\n", (char)('a' + i), s->freq[i]);
    }
}

int main(void) {
    struct Stats stats;
    init_stats(&stats);

    char buffer[MAX_LINE + 1];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        process_line(buffer, &stats);
    }

    print_report(&stats);
    return 0;
}
