#include <stdio.h>

/**
 * @brief Clasifica una calificación numérica con condicionales anidados.
 */
int main() {
  //---Declaramos la variable
  int calif;
  //---Solicitamos la calificacion
  printf("Ingrese la calificación del estudiante: ");
  scanf("%d", &calif);  // Guardamos la calificación

  //---Checamos la calificacion
  if (calif >= 90) {
    printf("Excelente.\n");
  } else if (calif >= 80) {
    printf("Bien.\n");
  } else if (calif >= 70) {
    printf("Regular.\n");
  } else if (calif >= 60) {
    printf("Estudia Mas.\n");
  } else {
    printf("Suerte Para La Proxima.\n");
  }

  return 0;
}
/**
 * @file IfElseAnidado_PromediarCalificaciones.c
 * @author Antonio Rafael
 * @brief Comparaciones usando sentencias if, if else y else
 * en C.
 * @date 24 de agosto de 2025
 *
 * \anchor sel_doble
 */