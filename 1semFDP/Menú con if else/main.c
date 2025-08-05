#include <stdio.h>
#include <stdlib.h>

int main() {

    float Saldo = 4.75f,Desicion12Dinero;//------------------------------Declarar variables
    int Tipo = 1,Desicion1, Desicion1EntrarInsertar, Desicion12Insertar, Desicion12Confirmar, Desicion13Elegir;
    char respuesta;

    void limpiarConsola() {//------------------------------Funcion que limpia la Consola
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }

    do {
        printf("\n\n\n\n-------------------------------------------------------------------------------\nDatos de mi tarjeta:\nSaldo:\n$%.2f\nTipo de Tarjeta: 1. Normal 2. 50%% 3. 100%%:\n%d\n-------------------------------------------------------------------------------\nQue quiere hacer?\n1.Subir al tren 2.Realizar una recarga 3.Modo Admin 4.Salir\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", Saldo, Tipo);
        scanf("%d", &Desicion1);//------------------------------Mostrando las Primeras Opciones

        if (Desicion1 == 1) { //-------------------------------Subir al tren
            printf("Inserte su tarjeta 1.Insertar 2.Regresar\n");
            scanf("%d", &Desicion1EntrarInsertar);

            if (Desicion1EntrarInsertar == 1) {
                if(Saldo >= 4.75f){
                    if (Tipo == 2) {
                        Saldo = Saldo - 4.75f;
                        printf("Tarjeta 50%%, Pago Realizado\nTu saldo restante es: %.2f\n", Saldo);
                    } else if (Tipo == 3) {
                        Saldo = Saldo - 4.75f;
                        printf("Tarjeta 100%%, Pago Realizado\nTu saldo restante es: %.2f\n", Saldo);
                    } else if (Tipo == 1 && Saldo >= 9.50f) {
                        Saldo = Saldo - 9.50f;
                        printf("Tarjeta Normal, Pago Realizado\nTu saldo restante es: %.2f\n", Saldo);
                    }
                    else if(Tipo == 1){
                    printf("Saldo Insuficiente\n");
                    }
                    else {
                            printf("Tarjeta Danada error dato 3 Corrupto: Tipo %d Saldo %f\n", Tipo, Saldo);
                    }
                }
                else {
                    printf("Saldo Insuficiente\n");
                }
            }
            else if (Desicion1EntrarInsertar == 2) {
                printf("\[Regresando al menu principal.. .\]\n");
            }
            else {
                printf("Dato 2 Corrupto: %d\n", Desicion1EntrarInsertar);
            }

        }
        else if (Desicion1 == 2) { //------------------------------Realizar Recarga
            printf("Inserte Su Tarjeta 1.Insertar 2.Regresar\n");
            scanf("%d", &Desicion12Insertar);

            if (Desicion12Insertar == 1) {
                printf("Tarjeta Insertada\n Inserte Dinero\n");
                scanf("%f", &Desicion12Dinero);
                printf("Desea Finalizar la recarga? 1.Si 2.Cancelar\n");
                scanf("%d", &Desicion12Confirmar);

                if (Desicion12Confirmar == 1 && Desicion12Dinero>=0) {
                    Saldo = Saldo + Desicion12Dinero;
                    printf("Recarga exitosa. Su nuevo saldo es: %.2f\n", Saldo);
                }
                else if (Desicion12Confirmar == 2) {
                    printf("Recarga cancelada.\n");
                }
                else {printf("Error de dato Desicion12Confirmar: %d Ingresado: %f.\n",Desicion12Confirmar,Desicion12Dinero);}

            }
            else if (Desicion12Insertar == 2) {
                printf("\[Regresando al menu principal.. .\]\n");
            }
            else {
                printf("Error en desicion12Insertar: %d\n", Desicion12Insertar);
            }
        }
        else if (Desicion1 == 3) { // -----------------------------Modo Admin
            printf("Elige:1.Editar Saldo 2.Editar Tipo 3.Reiniciar valores\n");
            scanf("%d", &Desicion13Elegir);
            switch (Desicion13Elegir) {
                case 1:
                    printf("Elige el saldo: ");
                    scanf("%f", &Saldo);
                    break;
                case 2:
                    printf("Elige el Tipo de Tarjeta 1.Normal 2.50%% 3.100%%: ");
                    int TipoTemp;
                    scanf("%d", &TipoTemp);
                    if(TipoTemp>=1 && TipoTemp<=3){
                        Tipo = TipoTemp;
                    }else{
                        printf("Error El dato que ingresaste no es 1 , 2 o 3 es: %d\n",TipoTemp);
                    }
                    break;
                case 3:
                    Saldo = 30.0f;
                    Tipo = 1;
                    printf("Valores reiniciados a los predeterminados.\nSaldo:%.2f Tipo:%d\n", Saldo, Tipo);
                    break;
                default:
                    printf("Error Dato no valido: %d\n", Desicion13Elegir);
                    break;
            }
        }
        else if (Desicion1 == 4) { //------------------------------Salir
            printf("\n\[Saliendo del Programa... .\]\n");
            break;
        }
        else { //--------------------------------------------------Error
            printf("\n\[Error Desicion1: %d, Saliendo del Programa.. .\]\n", Desicion1);
            break;
        }
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%cQuieres realizar otra operacion? (s/n): ",168);//------------------------------Preguntando si quieres repetir el codigo
        scanf(" %c", &respuesta);
        printf("\n########################################################################################################\n");
        limpiarConsola();
    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
