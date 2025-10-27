#include <stdio.h>

void mostrarMenu() {
  printf(
      "\n1. Consultar temperatura \n"
      "2. Ajustar luces\n"
      "3. Revisar seguridad\n"
      "4. Salir\n"
      "Elige una opcion: ");
}

int main() {
  int option;

  do {
    mostrarMenu();
    if (scanf("%d", &option) != 1) {
      fprintf(stderr, "Dato Invalido\n");// stderr es la salida para errores
      return 1;  // las funciones deben retornar 0 si completaron correctamente
                 // o cualquier numero si hubo un error
    }
    char ch;
    while (((ch = getchar()) != '\n') &&
           ch != EOF);  // Limpiar buffer quitar \n que deja enter
    switch (option) {
      case 1:
        printf("Revisando la temperatura");
        break;
      case 2:
        printf("Revisando las luces");
        break;
      case 3:
        printf("Revisando seguridad");
        break;
      case 4:
        printf("Cerrando programa.. .");
        break;
      default:
        printf("Error opcion no valida");
        break;
    }
  } while (option != 4);
  return 0;
}
