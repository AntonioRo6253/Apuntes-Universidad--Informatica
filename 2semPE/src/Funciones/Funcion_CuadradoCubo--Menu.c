#include <stdio.h>
//prototipos
void cuadrado(int);
int cubo(int);

//funcion principal
int main(){
	//declaracion de variables
	int num, resultado, opc;
	do{
		printf("MENU\n");
		printf("1. Elevar al cuadrado\n");
		printf("2. Elevar al cubo\n");
		printf("3. Salir\n");
		printf("Elige tu opcion: ");
		scanf("%d",&opc);
		switch( opc ){

			case 1:printf("Teclea un numero: ");
				scanf("%d",&num);
				//llamada a la funcion cuadrado
				cuadrado(num);
				break;

			case 2:printf("Teclea otro numero: ");
				scanf("%d",&num);
				//llamada a la funcion cubo
				resultado = cubo(num);
				printf("El cubo de %d es = %d\n\n",num,resultado);
				break;

			case 3:printf("Gracias por utilizar este programa\n");
				break;

			default:printf("OPCION NO VALIDA\n\n");

		}//fin switch
	}while(opc != 3);
	return 0;

}//fin main

void cuadrado(int num){
	//variable local
	int resultado;
	resultado = num*num;
	printf("El cuadrado de %d es = %d\n\n",num,resultado);
}

int cubo(int num){
	return num*num*num;
}