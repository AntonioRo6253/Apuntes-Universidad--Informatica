#include <stdio.h>

int main(){
    int cant_califs,count=1;
    float calif, promedio, acum=0.0;
    printf("Cuantas calificaciones vamos a promediar?:");
    scanf("%d", &cant_califs);
    while(count <= cant_califs){
        printf("Teclea la calificación: ");
        scanf("%f", &calif);
        acum = acum + calif;
        count = count + 1;
    }
    promedio = acum / cant_califs;
    printf("El promedio es = %.1f\n", promedio);
    return 0;
}
