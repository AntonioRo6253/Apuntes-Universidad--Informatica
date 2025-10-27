#include <stdio.h>

#define MAX_CONSUMO 10000

int main(void) {
    long total = 0;
    int dias = 0;
    int maximo = 0;
    int consumo = 0;
    int lectura = 0;

    printf("Ingrese consumos diarios en kWh (valor negativo para terminar).\n");

    do {
        lectura = scanf("%d", &consumo);
        if (lectura != 1) {
            fprintf(stderr, "Entrada invalida\n");
            return 1;
        }

        if (consumo < 0) {
            break;
        }

        if (consumo > MAX_CONSUMO) {
            printf("Dato fuera de rango\n");
            continue;
        }

        total += consumo;
        if (dias == 0 || consumo > maximo) {
            maximo = consumo;
        }
        ++dias;
    } while (1);

    if (dias == 0) {
        printf("Sin datos para reportar\n");
        return 0;
    }

    double promedio = (double)total / dias;

    printf("Dias registrados: %d\n", dias);
    printf("Consumo total: %ld kWh\n", total);
    printf("Promedio diario: %.2f kWh\n", promedio);
    printf("Maximo diario: %d kWh\n", maximo);

    return 0;
}
