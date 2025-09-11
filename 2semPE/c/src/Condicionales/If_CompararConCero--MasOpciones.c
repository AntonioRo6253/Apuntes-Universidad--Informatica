#include <stdio.h>

int main() {
  //----- declarar variables
  float num, num2;

  //----- Pedir entrada
  printf("Teclea el numero1: ");
  scanf("%f", &num);
  //----- entrada del 2
  printf("Teclea el numero2: ");
  scanf("%f", &num2);
  //----- Comparar
  if (num > num2)  //--- Comparamos
  {
    printf("%.0f es mayor a %.0f \n", num, num2);  //-- Imprimimos
  }
  if (num < num2) {
    printf("%.0f es menor a %.0f \n", num, num2);
  }
  if (num >= num2) {
    printf("%.0f es mayor o Igual a %.0f \n", num, num2);
  }
  if (num <= num2) {
    printf("%.0f es menor o Igual a %.0f \n", num, num2);
  }
  if (num == num2) {
    printf("%.0f es igual a %.0f \n", num, num2);
  }
  if (num != num2) {
    printf("%.0f es Diferente a %.0f \n", num, num2);
  }
  return 0;
}

/**
 * @file Selectiva-Simple2.c
 * @author Antonio Rafael
 * @brief Ejemplo sencillo de comparaciones usando sentencias if en C.
 * @date 24 de agosto de 2025
 *
 * \anchor sel_simple
 * @see \ref apunte_if "Apunte IF"
 *
 */
