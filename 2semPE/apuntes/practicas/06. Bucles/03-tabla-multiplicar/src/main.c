#include <stdio.h>

#define TABLA_MIN 1
#define TABLA_MAX 12
#define LIMITE_MAX 20

static void imprimir_guiones(int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        putchar('-');
    }
    putchar('\n');
}

int main(void) {
    int tabla_min = 0;
    int tabla_max = 0;
    int limite = 0;

    if (scanf("%d %d %d", &tabla_min, &tabla_max, &limite) != 3) {
        fprintf(stderr, "Datos invalidos\n");
        return 1;
    }

    if (tabla_min < TABLA_MIN || tabla_max > TABLA_MAX || tabla_min > tabla_max || limite < 1 || limite > LIMITE_MAX) {
        printf("Datos invalidos\n");
        return 1;
    }

    int separador = (limite * 4) - 1;

    for (int tabla = tabla_min; tabla <= tabla_max; ++tabla) {
        printf("Tabla %d\n", tabla);
        imprimir_guiones(separador);
        for (int factor = 1; factor <= limite; ++factor) {
            int producto = tabla * factor;
            printf("%3d", producto);
            if (factor < limite) {
                putchar(' ');
            }
        }
        printf("\n\n");
    }

    return 0;
}
