#include <stdbool.h>
#include <stdio.h>
#define MAX 100 // Límite general disponible (no se usa en este ejemplo, pero se mantiene para futuras extensiones)

int main() {
  int countExample = 0, INICIO = 0, FIN = 0, pairs = 0; // Variables principales para controlar el flujo y contabilizar pares

  while (true) { // Bucle principal que se repite hasta recibir la señal de salida
    //? INPUT
    countExample++; // Incrementa el número de ejemplo mostrado al usuario
    printf("Ejemplo %d\nEntrada(numero numero | SALIR -1 -1):\n",countExample);
    int status = scanf("%d %d", &INICIO, &FIN); // Lee dos enteros y guarda el resultado del escaneo
    if (INICIO == -1 && FIN == -1) { // Condición de salida explícita (-1 -1)
      break;
    } else if (status == 2) { // Valida que se hayan leído correctamente dos números
      if (INICIO > FIN) { // Intercambia los valores si el usuario los ingresó invertidos
        int temp = INICIO;
        INICIO = FIN;
        FIN = temp;
      }
      pairs = 0; // Reinicia el contador de números pares hallados en el rango
      for (int i = INICIO; i <= FIN; i++) { // Recorre el rango inclusive
        if (i % 2 == 0) { // Verifica si el número actual es par
          printf("%d ", i); // Muestra el número par
          pairs++; // Incrementa el conteo de pares encontrados
        }
      }
      if (pairs == 0) { // Caso en que no se encontró ningún número par
        printf("No hay pares en el rango.\n");
      } else {
        printf("\n"); // Salto de línea tras listar los pares
      }
      printf("Cantidad de pares: %d\n", pairs); // Muestra la cantidad total de pares hallados
    } else {
      printf("Dato erroneo, vuelve a intentarlo\n"); // Informa sobre una entrada inválida
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF) { // Limpia el búfer de entrada antes de reintentar
      }
      continue; // Vuelve al inicio del bucle para solicitar un nuevo conjunto de datos
    }
  }

  return 0; // Fin del programa con código de salida exitoso
}
