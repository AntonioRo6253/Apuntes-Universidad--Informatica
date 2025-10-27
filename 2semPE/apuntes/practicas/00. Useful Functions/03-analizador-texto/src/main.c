/**
 * @file main.c
 * @brief Analizador estadístico multi-línea de texto: letras, dígitos, otros y frecuencias a..z.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** @brief Número máximo de caracteres por línea analizada. */
#define MAX_LINE 255
/** @brief Total de letras consideradas para el conteo alfabético. */
#define ALPHABET 26
/**
 * @brief Estadísticas acumuladas del análisis de texto.
 */
struct Stats {
    unsigned long lines;      /**< Cantidad de líneas procesadas. */
    unsigned long chars;      /**< Caracteres visibles (sin el salto final). */
    unsigned long letters;    /**< Letras detectadas en el flujo. */
    unsigned long digits;     /**< Dígitos detectados en el flujo. */
    unsigned long others;     /**< Caracteres no alfabéticos ni dígitos. */
    unsigned long freq[ALPHABET]; /**< Frecuencia por letra de 'a' a 'z'. */
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

/**
 * @brief Procesa la entrada estándar y muestra el reporte de estadísticas.
 */
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
