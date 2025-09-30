#include <stdio.h>

int main()
{
    int a;
    int *ptrA;

    a = 7;
    ptrA = &a;

    printf("La direccion de a es %p\n",
           "El valor de ptrA es %p\n", &a, ptrA);
           printf("La direccion de a es %p\n",
           "El valor de ptrA es %p\n", a, ptrA);
    printf("\n\nMuestra de que * y & son complementos" //! No se suele usar
           "uno del otro\n&*ptrA = %p"
           "\n*&ptrA = %p\n", &*ptrA, *&ptrA);

    return 0;
}
