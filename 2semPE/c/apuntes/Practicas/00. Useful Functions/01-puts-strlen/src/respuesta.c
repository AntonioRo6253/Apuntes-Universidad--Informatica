#include <stdio.h>
#include <string.h>

#define MAX_LEN 81



int main()
{
    char respuesta[MAX_LEN]= {0};
    fgets(respuesta,MAX_LEN, stdin);
    printf("%c",respuesta);
    return 0;
}
