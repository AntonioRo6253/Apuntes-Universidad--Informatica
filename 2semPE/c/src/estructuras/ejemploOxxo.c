#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define MAX_COLUMNAS_BANDEJAS 2
#define MAX_FILAS_BANDEJAS 5
#define MAX_MODELO 32
#define MAX_TIPO 32

struct refrigerador
{
  const char *productos[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS];
  bool abierto;
  char tipo[MAX_TIPO];
  int puertas;
  char modelo[MAX_MODELO];
  int idRefrigerador;
};
struct oxxo
{
  struct refrigerador refrigerador1;
  struct refrigerador refrigerador2;
};

// prototipos de funciones
void llenar_refrigerador (struct refrigerador *refri, const char *productos[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS]);
void mostrar_refrigerador (struct refrigerador *refri);

int
main (void)
{
  // Crear la tienda OXXO con dos refrigeradores
  struct oxxo tienda_Av_Revolucion
      = { .refrigerador1 = { .abierto = false,
                             .puertas = 1,
                             .modelo = "XK-450",
                             .tipo = "Refrigerador pequeño",
                             .idRefrigerador = 101 },
          .refrigerador2 = {
              .abierto = false,
              .puertas = 4,
              .modelo = "JK-1500",
              .tipo = "Refrigerador grande",
              .idRefrigerador = 102,
          } };

  // Llenar el primer refrigerador
  const char *bandeja_productos1[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS]
      = { { "Leche sello rojo", "Leche marca LALA" },
          { "Yogurt griego", "Yogurt de oreo" },
          { "Jugo de naranja", "Jugo de mango" },
          { "Fanta", "Coca cola" },
          { "Niño congelado", "Nuggets" } };

  llenar_refrigerador (&tienda_Av_Revolucion.refrigerador1,
                       bandeja_productos1);

  // Llenar el segundo refrigerador

  const char *bandeja_productos2[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS]
      = { { "Cerveza Corona", "Cerveza Modelo" },
          { "Agua Ciel", "Agua Epura" },
          { "Refresco Pepsi", "Refresco 7up" },
          { "Red Bull", "Monster" },
          { "Gatorade", "Powerade" } };
  llenar_refrigerador (&tienda_Av_Revolucion.refrigerador2,
                       bandeja_productos2);

  printf ("Producto en fila 1, columna 2: %s\n",
          tienda_Av_Revolucion.refrigerador1.productos[0][1]);

  mostrar_refrigerador (&tienda_Av_Revolucion.refrigerador1);
  mostrar_refrigerador (&tienda_Av_Revolucion.refrigerador2);
  return 0;
}
void
llenar_refrigerador (
    struct refrigerador *refri,
    const char *productos[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS])
{
  for (size_t fila = 0; fila < MAX_FILAS_BANDEJAS; fila++)
    {
      for (size_t columna = 0; columna < MAX_COLUMNAS_BANDEJAS; columna++)
        {
          refri->productos[fila][columna] = productos[fila][columna];
        }
    }
}

void
mostrar_refrigerador (struct refrigerador *refri)
{
  for (size_t fila = 0; fila < MAX_FILAS_BANDEJAS; fila++)
    {
      for (size_t columna = 0; columna < MAX_COLUMNAS_BANDEJAS; columna++)
        {
          printf ("%s ", refri->productos[fila][columna]);
        }
      printf ("\n");
    }
}
