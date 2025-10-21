#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// paso por valor
struct estructura_normal
{
  char texto[MAX]; // Solo con los strings se debe pasar asi el tamaño
  int numeros[3];
} main ()
{
  struct estructura_normal ejemplo;
  strcpy (ejemplo.texto, "HOLA");
  ejemplo.numeros[0] = 1;
  ejemplo.numeros[1] = 2;
  ejemplo.numeros[2] = 3;
}

// por referencia
struct estructura_normal
{
  char *texto[MAX];
  int *numeros[3];
} main ()
{
  struct estructura_normal ejemplo;
  ejemplo.texto[MAX] = "HOLA";
  int src[3] ={1,2,3};
  
  memcpy(ejemplo.numeros,src, sizeof(ejemplo.numeros));
}