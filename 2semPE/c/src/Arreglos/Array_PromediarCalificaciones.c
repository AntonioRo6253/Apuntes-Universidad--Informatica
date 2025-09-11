//Programa que solicita al usuario 5 edades de personas las guarda en un arreglo
//unidimensional, despues las muestra en pantalla y por ultimo imprime el promedio.
#include <stdio.h>
#define TAM 5
int main(){
    //declaracion de variables
    int edades[5], promedio, acum, i;

    //solicitar al usuario las edades
    for(i=0; i<TAM; i++){
        printf("Teclea la edad de la persona no. %d: ",i+1);
        scanf("%d",&edades[ i ]);
    }//fin for entrada

    //salto de linea
    printf("\n");

    //mostrar el contendio del arreglo
    for(i=0; i<TAM; i++)
        printf("edades[ %d ] = %d\n",i,edades[i]);

    //saldo de linea
    printf("\n");

    //sumar las edades utilizando un acumulador
    for(i=0; i<TAM; i++)
        acum = acum + edades[ i ];
    //calcular el promedio
    promedio = acum / 5;

    //mostrar el promedio
    printf("El promedio de las edades es = %d\n",promedio);

    return 0;
}//fin