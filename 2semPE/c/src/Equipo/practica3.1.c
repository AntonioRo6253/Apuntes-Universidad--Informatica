#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 3

struct empleado
{
    int codigo;
    char nombre[40]; // nombre completo
    float salario;
};

/* prototipos */
int menu();
void solicitar_datos(struct empleado e[]);
void mostrar_datos(struct empleado e[]);
void buscar_por_codigo(struct empleado e[]);

int main()
{
    struct empleado e[MAX]; // arreglo de registros
    int opc;
    do
    {
        opc = menu();

        switch (opc)
        {
        case 1:
            solicitar_datos(e);
            break;
        case 2:
            mostrar_datos(e);
            break;
        case 3:
            buscar_por_codigo(e);
            break;
        case 0:
            printf("Gracias por utilizar este programa\n");
            break;
        default:
            printf("OPCION NO VALIDA\n");
        } // fin switch

    } while (opc != 0);
    return 0;
} // fin main

/* funcion que muestra el menu de opciones */
int menu()
{
    int opc;
    printf("MENU - EMPLEADOS\n");
    printf("1. Solicitar datos\n");
    printf("2. Mostrar datos\n");
    printf("3. Buscar por Codigo\n");
    printf("0. Salir\n");
    printf("Elige tu opcion: ");
    scanf("%d", &opc);
    return opc;
} // fin funcion menu

void solicitar_datos(struct empleado e[])
{
    int i, codigo;
    bool repetido;
    
    for (i = 0; i < MAX; i++)
    {
        printf("Introduce los datos del empleado No.%d\n", i + 1);
        
        // Solicitar código con verificación de duplicados
        do {
            repetido = false; // Reiniciar la bandera para cada nuevo código
            
            printf("Teclea el codigo ........: ");
            scanf("%d", &codigo);
            
            // Verificar si el código ya existe
            for (int j = 0; j < i; j++) // Solo verificar hasta i-1
            {
                if (codigo == e[j].codigo)
                {
                    printf("Error: Codigo repetido. Intente otro.\n");
                    repetido = true;
                    break;
                }
                
            }
        } while (repetido); // Repetir si el código está duplicado
        e[i].codigo = codigo; // Asignar el código válido
        
        // Limpiar buffer de entrada
        while (getchar() != '\n'); // Alternativa más segura a fflush(stdin)
        
        printf("Teclea el nombre completo: ");
        fgets(e[i].nombre, sizeof(e[i].nombre), stdin);
        
        // Eliminar salto de línea si existe
        size_t len = strlen(e[i].nombre);
        if (len > 0 && e[i].nombre[len-1] == '\n')
            e[i].nombre[len-1] = '\0';
        
        printf("Teclea el salario .......: ");
        scanf("%f", &e[i].salario);
        
        printf("\n");
    }
}
/* funcion que muestra los datos de los empleados */
void mostrar_datos(struct empleado e[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Datos del empleado # %d:\n", i + 1);
        printf("Codigo .........= %d\n", e[i].codigo);
        printf("Nombre completo = %s\n", e[i].nombre);
        printf("Salario ........= %.2f\n", e[i].salario);
        printf("\n");
    } // fin for
} // fin funcion mostrar

void buscar_por_codigo(struct empleado e[])
{
    int codigo;
    printf("Escribe el codigo del empleado ");
    scanf("%d", &codigo);

    for (int i = 0; i < MAX; i++)
    {
        if (codigo == e[i].codigo)
        {
            printf("Datos del empleado # %d:\n", i + 1);
            printf("Codigo .........= %d\n", e[i].codigo);
            printf("Nombre completo = %s\n", e[i].nombre);
            printf("Salario ........= %.2f\n", e[i].salario);
            printf("\n");
            break;
        }
        else
        {
            printf("UPS, no encontre tu empleado");
            break;
        }
    }
    // fin for
}
