#include <stdio.h>

// constantes y prototipos
enum { TABLA_MIN = 1, TABLA_MAX = 12 };
static const char* const ERROR_ENTRADA =
    "Datos invalidos. Introduce tres numeros separados por espacios.\n";
static const char* const ERROR_RANGO =
    "Datos invalidos. Usa tablas entre 1 y 12 y un limite mayor a 0.\n";

static int leer_parametros(int* table_min, int* table_max, int* limit);
static int validar_parametros(int table_min, int table_max, int limit);
static void imprimir_guiones(int cantidad);
static void imprimir_tablas(int table_min, int table_max, int limit);

int main() {
  int table_min = 0;
  int table_max = 0;
  int limit = 0;

  if (leer_parametros(&table_min, &table_max, &limit) != 0) {
    return 1;
  }

  if (validar_parametros(table_min, table_max, limit) != 0) {
    return 1;
  }

  imprimir_tablas(table_min, table_max, limit);

  return 0;
}
static int leer_parametros(int* table_min, int* table_max, int* limit) {
  puts("Escribe la tabla que quieres");
  puts("<tabla1> a <tabla2> <numero de resultados>");
  if (scanf("%d %d %d", table_min, table_max, limit) != 3) {
    fputs(ERROR_ENTRADA, stderr);
    return 1;
  }
  return 0;
}

static int validar_parametros(int table_min, int table_max, int limit) {
  if (table_min < TABLA_MIN || table_max > TABLA_MAX || table_min > table_max ||
      limit < 1) {
    fputs(ERROR_RANGO, stderr);
    return 1;
  }
  return 0;
}

static void imprimir_guiones(int cantidad) {
  for (int i = 0; i < cantidad; ++i) {
    putchar('-');
  }
  putchar('\n');
}

static void imprimir_tablas(int table_min, int table_max, int limit) {
  // cada resultado ocupa tres caracteres y un espacio de separacion
  int separador = limit > 0 ? (limit * 4) - 1 : 0;
  for (int table = table_min; table <= table_max; ++table) {
    printf("Tabla %d\n", table);
    imprimir_guiones(separador);
    for (int factor = 1; factor <= limit; factor++) {
      int product = factor * table;
      printf("%3d", product);
      if (factor < limit) {
        putchar(' ');
      }
    }
    printf("\n\n");
  }
}
