/*----------------------------
  Universidad de Guadalajara
  Ingenieria en Informatica
  Programación Estructurada
  Trabajo: Selectiva Simple
  Codigo: [V0716]
  Autor: [Antonio Rafael]
  Fecha: [19/09/2025]
----------------------------*/

#include <stdio.h>

int main() {
  // declarar variables
  float num;
  // entrada
  printf("Teclea un número: ");
  scanf("%f", &num);
  // Selectiva Simple
  if (num > 0) {
    printf("%f es mayor a cero \n", num);
  }
  if (num < 0) {
    printf("%f es menor a cero \n", num);
  }
  if (num == 0) {
    printf("%f es igual a cero \n", num);
  }
  return 0;
}