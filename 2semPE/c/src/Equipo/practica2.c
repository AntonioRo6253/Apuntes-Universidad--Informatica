#include <ctype.h>
#include <stdio.h>
#include <string.h>

// #include <windows.h> //setConsoleCP

// TODO: Definir macros
#define MAX 500

// TODO: Prototipos
int printfMenu (void);
void cleanInputBuffer (void);
void getString (char *string);
void showString (const char *string);
int totalLetterString (const char *string);
int totalDigitString (const char *string);
void showStringMayus (const char *string);
void showStringMinus (const char *string);

int
main ()
{
  /**  TODO: Configurar consola en UTF-8
  SetConsoleOutputCP (CP_UTF8); // salida UTF-8
  SetConsoleCP (CP_UTF8);       // entrada UTF-8
                                //? Si no funciona
                                // system("chcp 65001 > nul");
                                */
  // TODO: Variables
  int option_menu = 0;
  char string[MAX] = "";

  // TODO: Menu
  do
    {
      option_menu = printfMenu ();

      switch (option_menu)
        {
        case 1:
          getString (string);
          break;
        case 2:
          showString (string);
          break;
        case 3:
          {
            int totalLetter = totalLetterString (string);
            printf ("El total de letras que tiene tu cadena de texto es: %d\n",
                    totalLetter);
          }
          break;
        case 4:
          printf ("El total de digitos que tiene tu cadena de texto es: %d\n",
                  totalDigitString (string));
          break;
        case 5:
          showStringMayus (string);
          break;
        case 6:
          showStringMinus (string);
          break;
        case 0:
          puts ("Gracias por usar este programa");
          break;
        default:
          puts ("Opcion no valida\n");
          break;
        }
    }
  while (option_menu != 0);

  return 0;
}

int
printfMenu (void)
{
  puts ("MENU - CADENAS DE CARACTERES\n"
        "1. Solicitar la cadena de caracteres\n"
        "2. Mostrar la cadena original \n"
        "3. Total de letras\n"
        "4. Total de digitos\n"
        "5. Mostrar la cadena en MAYUSCULAS\n"
        "6. Mostrar la cadena en minúsculas\n"
        "0. Salir\n"
        "Elige tu opción:");
  int option_menu = 0;
  scanf ("%d", &option_menu);
  cleanInputBuffer ();
  return option_menu;
}

void
cleanInputBuffer (void)
{
  int ch;
  while ((ch = getchar ()) != '\n' && ch != EOF);
}

void
getString (char *string)
{
  puts ("Escribe tu texto: ");
  fgets (string, MAX, stdin);
}
void
showString (const char *string)
{
  printf ("Esta es tu cadena de caracteres/texto: %s\n", string);
}

int
totalLetterString (const char *string)
{
  puts ("Haz ejecutado la funcion total de letras");
  return 5;
}

int
totalDigitString (const char *string)
{
  puts ("Haz ejecutado la funcion total de digitos");
  return 5;
}

void
showStringMayus (const char *string)
{
  puts ("Haz ejecutado la funcion ver en mayusculas");
}

void
showStringMinus (const char *string)
{
  puts ("Haz ejecutado la funcion ver en minusculas");
}
