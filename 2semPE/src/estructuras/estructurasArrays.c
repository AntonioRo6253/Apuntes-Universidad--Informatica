#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief Capacidad máxima usada en los ejemplos de estructuras. */
#define MAX 100

// paso por valor
/**
 * @brief Estructura que almacena cadenas y números por valor.
 */
struct estructura_normal
{
  char texto[MAX]; /**< Texto almacenado directamente dentro de la estructura. */
  int numeros[3];  /**< Arreglo fijo de enteros. */
} main ()
{
  struct estructura_normal ejemplo;
  strcpy (ejemplo.texto, "HOLA");
  ejemplo.numeros[0] = 1;
  ejemplo.numeros[1] = 2;
  ejemplo.numeros[2] = 3;
}

// por referencia
/**
 * @brief Variante que ilustra miembros como punteros a datos externos.
 */
struct estructura_normal
{
  char *texto[MAX];   /**< Referencias a cadenas externas. */
  int *numeros[3];    /**< Referencias a arreglos de enteros existentes. */
} main ()
{
  struct estructura_normal ejemplo;
  ejemplo.texto[MAX] = "HOLA";
  int src[3] ={1,2,3};
  
  memcpy(ejemplo.numeros,src, sizeof(ejemplo.numeros));
}