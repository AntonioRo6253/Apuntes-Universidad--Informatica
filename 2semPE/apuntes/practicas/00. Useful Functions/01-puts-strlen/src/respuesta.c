#include <stdio.h>
#include <string.h>

#define MAX_LENGHT 81

static void
remove_newline (char *string)
{
  if (!string)
    return;

  size_t lenghtString = strlen (string); // usamos strlen no llena el string
                                         // con un '\n' a diferencia de sizeof
  if (lenghtString > 0 && string[lenghtString - 1] == '\n')
    string[lenghtString - 1] = '\0';
}

static void
printfCaraters (char *buffer)
{
  for (int i = 0; i <= strlen (buffer); i++)
    {
      printf ("Caracter: %c, Valor: %d\n", buffer[i], buffer[i]);
    }
}

int
main ()
{
  char buffer[MAX_LENGHT];

  if (!fgets (buffer, sizeof (buffer), 
  stdin)) // Si fgets esta vacio definimos el buffer como vacio
    {
      buffer[0] = '\0';
    }
  remove_newline (buffer);

  /* Log de consola*/
  puts (buffer);
  printf ("Longitud: %zu\n", strlen (buffer));
  printfCaraters (buffer);

  return 0;
}
