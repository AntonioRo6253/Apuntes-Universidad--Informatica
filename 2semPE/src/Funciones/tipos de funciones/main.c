#include <stdio.h>
/**
 * Para probar
 * gcc main.c src.c -o main
 * ./main
 */

 // Informamos que calc esta en otro archivo
extern int calc(int a, int b);

// extern int sum(int a,int b);

int main() {
  printf("10 + 20 = %d", calc(10, 20));

  // Con sum falla porque es static
  // printf("10 + 20 = %d", sum(10, 20));
  return 0;
}
