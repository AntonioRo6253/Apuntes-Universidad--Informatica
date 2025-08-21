/*----------------------------
  Universidad de Guadalajara
  Ingenieria en Informatica
  Programación Estructurada
  Trabajo: Selectiva Simple 2
  Codigo: [V0716]
  Autor: [Antonio Rafael]
  Fecha: [19/09/2025]
----------------------------*/
#include <stdio.h>

int main()
{
  //-----declarar variables
  float num, num2;
  //-----Pedirentrada
  printf("Teclea el numero1: ");
  scanf("%f", &num);
  //-----entrada del 2
  printf("Teclea el numero2: ");
  scanf("%f", &num2);

  if (num > num2)//---Comparamos
  {
    printf("%.0f es mayor a %.0f \n", num, num2);//--Imprimimos
  }
  if (num < num2)
  {
    printf("%.0f es menor a %.0f \n", num, num2);
  }
  if (num >= num2)
  {
    printf("%.0f es mayor o Igual a %.0f \n", num, num2);
  }
  if (num <= num2)
  {
    printf("%.0f es menor o Igual a %.0f \n", num, num2);
  }
  if (num == num2)
  {
    printf("%.0f es igual a %.0f \n", num, num2);
  }
  if (num != num2)
  {
    printf("%.0f es Diferente a %.0f \n", num, num2);
  }
  return 0;//--Finaliza
}
