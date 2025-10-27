#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/** @brief Columnas por bandeja en el refrigerador de ejemplo. */
#define MAX_COLUMNAS_BANDEJAS 2
/** @brief Filas por bandeja en el refrigerador de ejemplo. */
#define MAX_FILAS_BANDEJAS 5
/** @brief Tamaño máximo reservado para la cadena del modelo. */
#define MAX_MODELO 32
/** @brief Tamaño máximo reservado para la descripción del tipo. */
#define MAX_TIPO 32

/**
 * @brief Representa un refrigerador con bandejas y metadatos.
 */
struct refrigerador
{
  const char *productos[MAX_FILAS_BANDEJAS][MAX_COLUMNAS_BANDEJAS]; /**< Referencias a los productos por posición. */
  bool abierto;                                                    /**< Indica si la puerta está abierta. */
  char tipo[MAX_TIPO];                                             /**< Tipo o categoría del refrigerador. */
  int puertas;                                                     /**< Cantidad de puertas físicas. */
  char modelo[MAX_MODELO];                                         /**< Identificador del modelo comercial. */
  int idRefrigerador;                                              /**< Clave única para inventario. */
};
/**
 * @brief Modela la tienda con dos refrigeradores controlados.
 */
struct oxxo
{
  struct refrigerador refrigerador1; /**< Primer refrigerador expuesto. */
  struct refrigerador refrigerador2; /**< Segundo refrigerador expuesto. */
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
