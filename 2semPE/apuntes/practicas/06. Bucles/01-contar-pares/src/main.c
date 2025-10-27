#include <stdio.h>

int main(void) {
    int inicio = 0;
    int fin = 0;
    int pares = 0;

    if (scanf("%d %d", &inicio, &fin) != 2) {
        fprintf(stderr, "Error: entrada invalida.\n");
        return 1;
    }

    for (int i = inicio; i <= fin; ++i) {
        if (i % 2 == 0) {
            ++pares;
        }
    }

    printf("Cantidad de pares: %d\n", pares);
    return 0;
}
