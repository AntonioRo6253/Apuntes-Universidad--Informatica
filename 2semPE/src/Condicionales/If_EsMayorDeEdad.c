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
  float edad;
  //-----Pedir  entrada
  printf("Teclea tu Edad: ");
  scanf("%f", &edad);

  if (edad >= 18)//---Comparamos
  {
    printf("Eres Mayor de Edad Tu edad es:%.0f", edad);//--Imprimimos
  }
   if (edad <= 18)//---Comparamos
  {
    printf("Eres Menor de Edad Tu edad es:%.0f", edad);//--Imprimimos
  }

  return 0;//--Finaliza
}
