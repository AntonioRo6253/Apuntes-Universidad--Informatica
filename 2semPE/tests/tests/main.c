/*----------INTEGRANTES----------*/
// Nande Cuenca Luis Antonio
// Perez Santamaria Andre
// Reyes Hernandez Cinthia Ximena
// Robles Arambula Antonio Rafael
/*-------------V0716-------------*/

#include <stdio.h>
#include <string.h>
#include <windows.h> // libreria para SetConsole

#define MAX 5 // maximo de empleados para arreglo empleados

typedef struct{
 int dia;
 char mes[10];
 int year;
} fecha;

struct empleado
{
    int codigo;
    char nombre[40]; // nombre completo
    float salario;
    fecha nacimiento; // structura anida
};

/* prototipos */
int menu();
int verificar_codigo_existe(const struct empleado e[], int len, int codigo);
void solicitar_datos(struct empleado e[]);
void mostrar_datos(struct empleado e[]);
void buscar_empleado(struct empleado e[]);

int main()
{
    /* Configuración simplificada para ver los acentos en la terminal */
    SetConsoleOutputCP(CP_UTF8); // salida UTF-8
    SetConsoleCP(CP_UTF8);       // entrada UTF-8

    /* arreglo de registros 'e[]' de 5 empleados */
    struct empleado e[1] = {0};

    /* Logica del menu*/
    int opc = 0;
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
            buscar_empleado(e);
            break;
        case 0:
            printf("\nGracias por utilizar este programa.\n");
            break;
        default:
            printf("\nOPCION NO VALIDA.\n");
            break;
        }

    } while (opc != 0);

    return 0;
}

/* funcion que muestra el menu de opciones */
int menu()
{
    int opc = 0;
    printf("\nMENU - EMPLEADOS\n");
    printf("1. Solicitar datos\n");
    printf("2. Mostrar datos\n");
    printf("3. Buscar empleado por codigo\n");
    printf("0. Salir\n");
    printf("Elige tu opcion: ");
    scanf("%d", &opc);
    getchar();
    return opc;
}

/* funcion que solicita los datos de los empleados */
void solicitar_datos(struct empleado e[])
{
    int i;
    for (i = 0; i < MAX; i++) // Recorre el arreglo de empleados | e[i] empleado en la posicion actual 'i'
    {
        int buffer = 0;
        printf("\nIntroduce los datos del empleado No.%d\n", i + 1);

        printf("Teclea el codigo ........: ");
        scanf("%d", &buffer);
        while (verificar_codigo_existe(e, i, buffer)) // Verificar si el código ya existe
        {
            printf("El codigo %d ya existe. Por favor, ingresa un codigo diferente: ", buffer);
            scanf("%d", &buffer);
        }
        e[i].codigo = buffer; // solo asigna el codigo si es unico
        getchar();

        printf("Teclea el nombre completo: ");
        fgets(e[i].nombre, sizeof(e[i].nombre), stdin);
        e[i].nombre[strcspn(e[i].nombre, "\n")] = '\0'; // Elimina el salto de linea '\n'

        printf("Teclea el salario .......: ");
        scanf("%f", &e[i].salario);
        getchar();

        printf("Teclea la fecha de nacimiento \n");
        printf("Dia .......: ");
        scanf("%d",&e[i].nacimiento.dia);
        getchar();
        printf("Mes .......: ");
        fgets(&e[i].nacimiento.mes,sizeof(e[i].nacimiento.mes),stdin);
        e[i].nacimiento.mes[strcspn(e[i].nacimiento.mes, "\n")] = '\0'; // Elimina el salto de linea '\n'
        printf("Año .......: ");
        scanf("%d",&e[i].nacimiento.year);
        getchar();

    }
}

int verificar_codigo_existe(const struct empleado e[], int len, int codigo)
{
    for (int i = 0; i < len; i++) // Recorre los empleados ya ingresados
    {
        if (e[i].codigo == codigo) // Si el codigo ya existe
            return 1;
    }
    return 0; // No existe el codigo
}

/* funcion que muestra los datos de los empleados */
void mostrar_datos(struct empleado e[])
{
    if (e[0].codigo != 0) // solo mostrar datos si ahi datos ingresados
    {
        int i;
        printf("\n=== DATOS DE LOS EMPLEADOS ===\n");
        for (i = 0; i < MAX; i++) // Recorre el arreglo de empleados | e[i] empleado en la posicion actual 'i'
        {
            printf("\nEmpleado #%d:\n", i + 1);
            printf("Codigo .........= %d\n", e[i].codigo);
            printf("Nombre completo = %s\n", e[i].nombre);
            printf("Salario ........= %.2f\n", e[i].salario);
            printf(
                   "Fecha de nacimiento\n Dia ........= %d\n mes ........= %s\n año ........= %d\n", e[i].nacimiento.dia,e[i].nacimiento.mes,e[i].nacimiento.year
                   );
        }
    }
    else
    {
        printf("\nNo hay datos de empleados para mostrar. Por favor, ingresa los datos primero.\n");
    }
}

/* funcion que busca un empleado por su codigo */
void buscar_empleado(struct empleado e[])
{
    int codigo_buscar = 0, encontrado = 0, i;

    printf("\nTeclea el codigo del empleado que deseas buscar: ");
    scanf("%d", &codigo_buscar);

    for (i = 0; i < MAX; i++) // Recorre el arreglo de empleados | e[i] empleado en la posicion actual 'i'
    {
        if (e[i].codigo == codigo_buscar) // Si el codigo de la posicion actual coincide con el codigo buscado
        {
            printf("\nEmpleado encontrado:\n");
            printf("Codigo .........= %d\n", e[i].codigo);
            printf("Nombre completo = %s\n", e[i].nombre);
            printf("Salario ........= %.2f\n", e[i].salario);
            encontrado = 1; // indica que se encontro el empleado
            break;
        }
    }

    if (!encontrado) // Si no se encontro ningun empleado con el codigo buscado
    {
        printf("\nNo se encontró ningún empleado con el código %d\n", codigo_buscar);
    }
}
