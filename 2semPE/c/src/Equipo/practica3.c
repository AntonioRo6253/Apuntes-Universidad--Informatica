#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes para tamaños de buffers
#define TAM_NOMBRES 20
#define TAM_APELLIDOS 25
#define TAM_DOMICILIO 25
#define TAM_TOTAL 100
#define TAM_CADENA 100

int menu (void); // prototipos
void solicitarDatos (char nombres[], char apellidos[], char domicilio[]);
void mostrarDatos (char nombres[], char apellidos[], char domicilio[]);
void compararDatos (char nombres[]);
char *cmpTexto (int val_comp);
void solicitarCadena (char cadena[]);
void mostrarMitadCadena (char cadena[]);
void cleanInputBuffer (void);

int
main ()
{
  char nombres[TAM_NOMBRES] = "";
  char apellidos[TAM_APELLIDOS] = "";
  char domicilio[TAM_DOMICILIO] = "";
  char cadena[TAM_CADENA] = "";
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
        case 3:
          compararDatos (nombres);
          break;
        case 4:
          solicitarCadena (cadena);
          break;
        case 5:
          mostrarMitadCadena (cadena);
          break;
        case 0:
          printf ("GRACIAS POR UTILIZAR ESTE PROGRAMA\n\n");
          break;
        default:
          printf ("OPCION NO VALIDA\n");
        }
    }
  while (opc != 0);
  return 0;
}

/**
 * @brief Mostrar menu
 *
 * Muestra el menu principal y obtiene la seleccion del usuario
 *
 * @return int Opcion seleccionada por el usuario (0, 1 o 2)
 */
int
menu ()
{
  int opc;
  printf ("MENU - CADENA DE CARACTERES\n");
  printf ("1. Solicitar datos personales\n");
  printf ("2. mostrar datos personales (concatenados)\n");
  printf ("3. comparar datos personales\n");
  printf ("4. solicitar cadena\n");
  printf ("5. mostrar la cadena (una copia parcial)\n");
  printf ("0. Salir\n");
  /* Solicitar Opcion */
  printf ("Elige una opcion:");
  scanf ("%d", &opc);
  /*Limpiar el buffer*/
  cleanInputBuffer (); // quita el enter(\n) del buffer que deja scanf
  //fflush (stdin);
  return opc;
}

/**
 * @brief Solicita y almacena los datos personales del usuario
 *
 * Solicita al usuario que ingrese sus nombres, apellidos y domicilio,
 * almacenandolos en los arreglos de caracteres proporcionados.
 *
 * @param nombres[] Arreglo donde se almacenaran los nombres
 * @param apellidos[] Arreglo donde se almacenaran los apellidos
 * @param domicilio[] Arreglo donde se almacenara el domicilio
 */
void
solicitarDatos (char nombres[], char apellidos[], char domicilio[])
{
  /* Solicitar nombres */
  printf ("Teclea tu(s) nombres(s): ");
  gets (nombres);
  /* Solicitar apellidos */
  printf ("Teclea tu(s) apellido(s): ");
  gets (apellidos);
  /* Solicitar domicilio */
  printf ("Teclea tu domicilio (calle y numero): ");
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
  // printf("Estos son tus datos Nombres:%s Apellidos:%s
  // domicilio:%s",nombres,apellidos,domicilio);

  char datosPersonalesConcatenados[TAM_TOTAL];
  datosPersonalesConcatenados[0] = '\0';

  // Concatenar
  strcat (datosPersonalesConcatenados, nombres); // dato
  strcat (datosPersonalesConcatenados, " ");     // espacio
  strcat (datosPersonalesConcatenados, apellidos);
  strcat (datosPersonalesConcatenados, " ");
  strcat (datosPersonalesConcatenados, domicilio);
  // Imprimir
  printf ("Tus datos completos (concatenados) son: \n%s\n\n", datosPersonalesConcatenados);
}

/**
 * @brief Comparar nombres
 *
 * Compara dos cadenas de caracteres y muestra si son iguales o no
 *
 * @param nombres[] Arreglo con los nombres del usuario
 * @param apellidos[] Arreglo con los apellidos del usuario
 */
void
compararDatos (char nombres[])
{
  const char nombres1[] = "Luis Angel";
  const char nombres2[] = "Luis Fernando";
  const char nombres3[] = "Luis Javier";
  // comparar
  int cmp1 = strcmp (nombres, nombres1);
  int cmp2 = strcmp (nombres, nombres2);
  int cmp3 = strcmp (nombres, nombres3);
  // mostrar resultados
  printf ("%s %s %s\n", nombres1, cmpTexto (cmp1), nombres);

  printf ("%s %s %s\n", nombres2, cmpTexto (cmp2), nombres);

  printf ("%s %s %s\n\n", nombres3, cmpTexto (cmp3), nombres);
}

/**
 * @brief comparar numero
 *
 * toma el valor de comparacion y devuelve un mensaje
 *
 * @param char cadena - mensaje de comparacion
 */
char *
cmpTexto (int val_comp)
{
  if (val_comp == 0)
    return "- Es igual -";
  else if (val_comp < 0)
    return "- es mayor que -";
  else
    return "- es menor que -";
}

/**
 * @brief Solicita una cadena de caracteres
 *
 * Solicita al usuario que ingrese una cadena de caracteres y
 * la almacena en el arreglo de caracteres proporcionado.
 *
 * @param cadena[] Arreglo donde se almacenará la cadena
 */
void
solicitarCadena (char cadena[])
{
  puts ("Introduce una cadena MAX=100: ");
  if (gets (cadena))
    cadena[strcspn (cadena, "\n")] = '\0';
}

void
mostrarMitadCadena (char cadena[])
{
  int log = strlen (cadena);
  int micha = log / 2;

  puts ("La copia parcial de la cadena (mitad) es = ");
  for (int i = 0; i < micha; i++)
    {
      printf ("%c", cadena[i]);
    }
  puts ("\n");
}

/**
 * @brief Limpiar Buffer
 *
 * Consume el caracter de nueva linea pendiente en el buffer de entrada
 * para evitar que afecte las entradas posteriores.
 */
void
cleanInputBuffer (void)
{
  int c;
  while ((c = getchar ()) != '\n' && c != EOF);
}