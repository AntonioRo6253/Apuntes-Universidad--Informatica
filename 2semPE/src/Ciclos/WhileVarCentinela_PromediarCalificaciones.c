#include <stdio.h>

//------------------------//
//     Antonio Rafael     //
//------------------------//

//**NOTA:
//? En este caso la variable centinela es calif
//? porque a pesar de las iteraciones, el valor de calif se utiliza como
//? condición para salir del ciclo.

/**
 * @brief Controla el ciclo con variable centinela para promediar calificaciones.
 */
int main() {
  float calif;        // Calificación actual
  float acum = 0.0f;  // Acumulador de calificaciones
  int count = 0;      // Contador de calificaciones

  //*---Pedir calificación por primera vez
  printf("Teclea una calificación o (-1.0 para salir): ");
  scanf("%f", &calif);

  while (calif != -1.0f) {
    //---Acumular calificaciones
    acum += calif;
    //---Sumar 1 para contar las calificaciones
    count = count + 1;
    //*---Pedir calificación cada iteracion hasta que el usuario ponga ( -1 )
    printf("Teclea una calificación o (-1.0 para salir): ");
    scanf("%f", &calif);
  }

  //*---Checa si ahi calificaciones si las ahi dar promedio
  if (count == 0) {
    printf("No se teclearon calificaciones\n");
  } else {
    printf("El promedio es: %.1f\n", acum / count);
  }
  return 0;
}
/**
 * @file WhileVarCentinela_PromediarCalificaciones.c
 * @author Antonio Rafael
 * @brief Usando Ciclo while con valor centinela
 * en C.
 * @date 01 de septiembre de 2025
 *
 * \anchor ciclo_mientras
 */
