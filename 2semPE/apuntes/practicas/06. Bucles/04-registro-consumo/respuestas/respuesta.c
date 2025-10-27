#include <stdbool.h>
#include <stdio.h>

static void imprimirRegistro(int total, int maximo, int contador);

#define MAX_CONSUMO 10000

int main() {
  //? Acumuladores
  int total = 0, contador = 0, maximo = 0, consumo = 0;
  //? mensaje inicial
  printf("Ingrese consumos diarios en kWh (valor negativo para terminar).\n");
  do {
    //? Solicitar entrada
    if (scanf("%d", &consumo) != 1) {
      printf("Entrada no valida");
      return 1;
    }
    //? Validar entrada
    if (consumo < 0) break;

    if (!(0 <= consumo <= MAX_CONSUMO)) {
      printf("Dato fuera de rango\n Vuelva a escribir su consumo\n");
      continue;
    }

    if (consumo > maximo) maximo = consumo;
    //? Guardar datos
    total += consumo;
    contador++;

  } while (true);
  //? Imprimir Registro
  contador > 0 ? imprimirRegistro(total, maximo, contador)
               : printf("Sin datos para reportar\n");

  return 0;
} 
static void imprimirRegistro(int total, int maximo, int contador) {
  printf(
      "Dias registrados: %d\n"
      "Consumo total: %d kWh\n"
      "Promedio diario: %.2f kWh\n"
      "Maximo diario: %d kWh\n",
      contador, total, (float)total / contador, maximo);
}
