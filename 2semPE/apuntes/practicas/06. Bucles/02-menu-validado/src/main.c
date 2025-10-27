#include <stdio.h>

static void mostrar_menu(void) {
    printf("Seleccione una opcion:\n");
    printf("1. Consultar temperatura\n");
    printf("2. Ajustar luces\n");
    printf("3. Revisar seguridad\n");
    printf("4. Salir\n");
}

int main(void) {
    int opcion = 0;
    int lectura = 0;

    do {
        mostrar_menu();
        lectura = scanf("%d", &opcion);
        if (lectura != 1) {
            perror("Entrada Invalida");
            //fprintf(stderr, "Entrada invalida\n");
            return 1;
        }

        switch (opcion) {
            case 1:
                printf("Consultando temperatura...\n");
                break;
            case 2:
                printf("Ajustando luces...\n");
                break;
            case 3:
                printf("Revisando seguridad...\n");
                break;
            case 4:
                printf("Saliendo del sistema.\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
