#include <stdio.h>
#include <stdlib.h>

int main() {
    char respuesta;
    int eleccionP1;
    do {
        printf("¿Quieres escribir tu calificación o elegir una opción rápida?\n1. Manual 2. Rápida: ");
        scanf("%d", &eleccionP1);

        if (eleccionP1 == 1) {
        float calificacion;

        printf("Dame tu calificación: ");
        scanf("%f", &calificacion);

        if (calificacion < 0 || calificacion > 100) {
                printf("Error, tu número: %.0f, no es una calificación válida.\n", calificacion);
            } else if (calificacion >= 97 && calificacion <= 100) {
                printf("Tu calificación es: %.0f, así que tienes una A+\n", calificacion);
            } else if (calificacion >= 93 && calificacion <= 96) {
                printf("Tu calificación es: %.0f, así que tienes una A\n", calificacion);
            } else if (calificacion >= 90 && calificacion <= 92) {
                printf("Tu calificación es: %.0f, así que tienes una A-\n", calificacion);
            } else if (calificacion >= 87 && calificacion <= 89) {
                printf("Tu calificación es: %.0f, así que tienes una B+\n", calificacion);
            } else if (calificacion >= 83 && calificacion <= 86) {
                printf("Tu calificación es: %.0f, así que tienes una B\n", calificacion);
            } else if (calificacion >= 80 && calificacion <= 82) {
                printf("Tu calificación es: %.0f, así que tienes una B-\n", calificacion);
            } else if (calificacion >= 77 && calificacion <= 79) {
                printf("Tu calificación es: %.0f, así que tienes una C+\n", calificacion);
            } else if (calificacion >= 73 && calificacion <= 76) {
                printf("Tu calificación es: %.0f, así que tienes una C\n", calificacion);
            } else if (calificacion >= 70 && calificacion <= 72) {
                printf("Tu calificación es: %.0f, así que tienes una C-\n", calificacion);
            } else if (calificacion >= 60 && calificacion <= 69) {
                printf("Tu calificación es: %.0f, así que tienes una D\n", calificacion);
            } else {
                printf("Tu calificación es: %.0f, así que tienes una F\n", calificacion);
            }
        }
        else if (eleccionP1 == 2) {
            int respuestaRapida;
            char arrayCalificaciones[12][2][12] = {
            {"A+", "97-100"},
            {"A", "93-96"},
            {"A-", "90-92"},
            {"B+", "87-89"},
            {"B", "83-86"},
            {"B-", "80-82"},
            {"C+", "77-79"},
            {"C", "73-76"},
            {"C-", "70-72"},
            {"D+", "67-69"},
            {"D", "65-66"},
            {"F", "Menos de 65"}
            };
            printf("Estas son las opciones:\n");
            for (int i = 0; i < 12; i++) {
                printf("%d.(%s)\n", i + 1, arrayCalificaciones[i][1]);
            }
            printf("Elige una opción: ");
            scanf("%d", &respuestaRapida);

            if (respuestaRapida >= 1 && respuestaRapida <= 12) {
                printf("Tu calificación es una: %s\n", arrayCalificaciones[respuestaRapida-1][0]);
            } else {
                printf("Opción no válida.\n");
            }
        }
        else {
            printf("Opción no válida.\n");
        }


        printf("¿Quieres calcular otra calificación? (s/n): ");
        scanf(" %c", &respuesta); // Se agrega un espacio antes de %c para consumir el salto de línea anterior
    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
