#include <stdio.h>
//prototipos
void cuadrado(int);
int cubo(int);

//funcion principal
int main(){
	//declaracion de variables
	int num, resultado;
	printf("Teclea un numero: ");
	scanf("%d",&num);
	//llamada a la funcion cuadrado
	cuadrado(num);
	printf("Teclea otro numero: ");
	scanf("%d",&num);
	//llamada a la funcion cubo
	resultado = cubo(num);
	printf("El cubo de %d es = %d\n",num,resultado);
	return 0;

}//fin main

void cuadrado(int num){
	//variable local
	int resultado;
	resultado = num*num;
	printf("El cuadrado de %d es = %d\n",num,resultado);
}

int cubo(int num){
	return num*num*num;
}