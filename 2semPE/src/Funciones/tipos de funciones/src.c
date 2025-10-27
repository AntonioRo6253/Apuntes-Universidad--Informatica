#include <stdio.h>

// Disponible solo en este archivo
static int sum(int a, int b) { 
    return a + b; 
}
// disponible en todos los archivos que compilemos juntos
int calc(int a, int b) {
    return sum(a,b);
}