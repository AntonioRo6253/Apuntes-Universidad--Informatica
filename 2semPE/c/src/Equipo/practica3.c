#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para tamaños de buffers
#define TAM_NOMBRES 20
#define TAM_APELLIDOS 25
#define TAM_DOMICILIO 25
#define TAM_TOTAL 100

int menu (void); // prototipos
void solicitarDatos (char nombres[], char apellidos[], char domicilio[]);
void mostrarDatos (char nombres[], char apellidos[], char domicilio[]);
void cleanInputBuffer(void);

int
main ()
{
  char nombres[TAM_NOMBRES] = ""; 
  char apellidos[TAM_APELLIDOS] = "";
  char domicilio[TAM_DOMICILIO] = "";
  int opc;
  do
    {
      opc = menu ();
      switch (opc)
        {
        case 1:
          solicitarDatos (nombres, apellidos, domicilio);
          break;
        case 2:
          mostrarDatos (nombres, apellidos, domicilio);
          break;
        case 0:
          printf ("Gracias por utilizar este programa\n\n");
          break;
        default:
          printf ("Opcion no valida\n");
        }
    }
  while (opc != 0);
  return 0;
}

/**
 * @brief Mostrar menu
 *
 * Muestra el menu principal y obtiene la selección del usuario
 *
 * @return int Opcion seleccionada por el usuario (0, 1 o 2)
 */
int
menu ()
{
  int opc;
  printf ("MENU - Cadena de caracteres\n");
  printf ("1. Solicitar datos personales\n");
  printf ("2 mostrar datos\n");
  printf ("0. Salir\n");
  /* Solicitar Opcion */
  printf ("Elige una opcion:");
  scanf ("%d", &opc);
  cleanInputBuffer ();// quita el enter(\n) del buffer que deja scanf
  //fflush (stdin);
  return opc;
}

/**
 * @brief Solicita y almacena los datos personales del usuario
 *
 * Solicita al usuario que ingrese sus nombres, apellidos y domicilio,
 * almacenándolos en los arreglos de caracteres proporcionados.
 *
 * @param nombres[] Arreglo donde se almacenarán los nombres
 * @param apellidos[] Arreglo donde se almacenarán los apellidos
 * @param domicilio[] Arreglo donde se almacenará el domicilio
 */
void
solicitarDatos (char nombres[], char apellidos[], char domicilio[])
{
  //?  Alternativa Segura de gets
  //? if (fgets(nombres, TAM_NOMBRES, stdin))
  //? nombres[strcspn(nombres, "\n")] = '\0';

  /* Solicitar nombres */
  printf ("Teclea tus (s) nombres: ");
  gets (nombres);
  /* Solicitar apellidos */
  printf ("Teclea tus apellidos: ");
  gets (apellidos);
  /* Solicitar domicilio */
  printf ("Teclea tu domicilio: ");
  gets (domicilio);
}
/**
 * @brief Mostrar datos del usuario
 *
 * Concatena y muestra los datos personales en un formato legible.
 *
 * @param nombres[] Arreglo con los nombres del usuario
 * @param apellidos[] Arreglo con los apellidos del usuario
 * @param domicilio[] Arreglo con el domicilio del usuario
 */
void
mostrarDatos (char nombres[], char apellidos[], char domicilio[])
{
  /* Concatenacion corta */
  // printf("Estos son tus datos Nombres:%s Apellidos:%s domicilio:%s",nombres,apellidos,domicilio);

  char datosPersonalesConcatenados[TAM_TOTAL];
  datosPersonalesConcatenados[0] = '\0';

  // Concatenar
  strcat (datosPersonalesConcatenados, nombres); // dato
  strcat (datosPersonalesConcatenados, " ");     // espacio
  strcat (datosPersonalesConcatenados, apellidos);
  strcat (datosPersonalesConcatenados, " ");
  strcat (datosPersonalesConcatenados, domicilio);
  // Imprimir
  puts (datosPersonalesConcatenados);
}

/**
 * @brief Limpiar Buffer
 *
 * Consume el carácter pendiente salto de línea(\n) que haya
 * quedado tras usar funciones como scanf evitando que interfieran con las
 * lecturas posteriores de texto.
 */
void
cleanInputBuffer (void)
{
  int ch;
  while ((ch = getchar ()) != '\n' && ch != EOF);
}