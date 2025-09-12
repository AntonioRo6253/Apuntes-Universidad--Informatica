@ingroup apuntes-teoria

# Arreglos en C

---

## Descripción

Un **arreglo** (también llamado array) es una estructura de datos que permite almacenar múltiples elementos del mismo tipo en posiciones de memoria contiguas. Los elementos se acceden mediante un índice que comienza en 0.

---

## Sintaxis Básica

```c
tipo_de_dato nombre_arreglo[tamaño];
tipo_de_dato nombre_arreglo[tamaño] = {valor1, valor2, ..., valorN};
```

### Ejemplos de declaración:

```c
int numeros[5];                    // Arreglo de 5 enteros sin inicializar
int edades[3] = {25, 30, 45};     // Arreglo inicializado
float precios[] = {10.5, 20.0, 15.75}; // Tamaño automático (3 elementos)
char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
```

---

## Arreglos Simples (Unidimensionales)

### Declaración e Inicialización

```c
// Diferentes formas de declarar e inicializar
int numeros[5];                           // Sin inicializar
int pares[4] = {2, 4, 6, 8};             // Inicialización completa
int impares[5] = {1, 3, 5};              // Inicialización parcial (resto = 0)
int fibonacci[] = {0, 1, 1, 2, 3, 5, 8}; // Tamaño automático
```

---

## Operaciones Fundamentales

### Acceso a Elementos

```c
int notas[5] = {85, 92, 78, 96, 88};

// Leer valores
printf("Primera nota: %d\n", notas[0]);  // Índice 0
printf("Última nota: %d\n", notas[4]);   // Índice 4

// Modificar valores
notas[1] = 95;  // Cambia la segunda nota de 92 a 95
```

---

## Ejemplos Prácticos

### Recorrido de Arreglos

```c
int numeros[5] = {10, 20, 30, 40, 50};
int tamaño = 5;

// Recorrer con for
for (int i = 0; i < tamaño; i++) {
    printf("Elemento %d: %d\n", i, numeros[i]);
}

// Recorrer con while
int i = 0;
while (i < tamaño) {
    printf("numeros[%d] = %d\n", i, numeros[i]);
    i++;
}
```

### Ejemplo Completo - Arreglo Simple

```c
#include <stdio.h>

int main() {
    // Declarar arreglo de temperaturas
    float temperaturas[7];  // Para 7 días de la semana
    int dias = 7;

    // Leer temperaturas
    printf("Ingrese las temperaturas de la semana:\n");
    for (int i = 0; i < dias; i++) {
        printf("Día %d: ", i + 1);
        scanf("%f", &temperaturas[i]);
    }

    // Calcular promedio
    float suma = 0;
    for (int i = 0; i < dias; i++) {
        suma += temperaturas[i];
    }
    float promedio = suma / dias;

    // Mostrar resultados
    printf("\nTemperaturas ingresadas:\n");
    for (int i = 0; i < dias; i++) {
        printf("Día %d: %.1f°C\n", i + 1, temperaturas[i]);
    }
    printf("Promedio: %.2f°C\n", promedio);

    return 0;
}
```

---

## Matrices (Arreglos Bidimensionales)

Una **matriz** es un arreglo de arreglos, que permite organizar datos en filas y columnas.

---

## Sintaxis Básica de Matrices

```c
tipo_de_dato nombre_matriz[filas][columnas];
tipo_de_dato nombre_matriz[filas][columnas] = {{fila1}, {fila2}, ...};
```

### Declaración e Inicialización

```c
// Diferentes formas de declarar matrices
int matriz[3][4];                    // 3 filas, 4 columnas sin inicializar

// Inicialización por filas
int numeros[2][3] = {
    {1, 2, 3},      // Primera fila
    {4, 5, 6}       // Segunda fila
};

// Inicialización en una línea
int tabla[2][2] = {{1, 2}, {3, 4}};

// Inicialización parcial
int datos[3][3] = {
    {1, 2},         // Resto de la fila = 0
    {4, 5, 6},
    {7}             // Resto de la fila = 0
};
```

---

## Operaciones con Matrices

### Acceso a Elementos de Matrices

```c
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Leer elemento
int elemento = matriz[1][2];  // Fila 1, Columna 2 (valor = 6)

// Modificar elemento
matriz[0][0] = 10;  // Cambia el primer elemento de 1 a 10

// Acceso con variables
int fila = 2, columna = 1;
printf("Elemento en [%d][%d]: %d\n", fila, columna, matriz[fila][columna]);
```

### Recorrido de Matrices

```c
int matriz[3][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};

int filas = 3, columnas = 4;

// Recorrido con bucles anidados
printf("Matriz completa:\n");
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        printf("%3d ", matriz[i][j]);
    }
    printf("\n");  // Nueva línea al final de cada fila
}
```

---

## Ejemplo Completo

### Ejemplo Completo - Matriz

```c
#include <stdio.h>

int main() {
    // Matriz para almacenar calificaciones de estudiantes
    float calificaciones[3][4];  // 3 estudiantes, 4 materias
    int estudiantes = 3, materias = 4;

    // Leer calificaciones
    printf("Ingrese las calificaciones:\n");
    for (int i = 0; i < estudiantes; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < materias; j++) {
            printf("  Materia %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }

    // Mostrar matriz de calificaciones
    printf("\nCalificaciones:\n");
    printf("        Materia1  Materia2  Materia3  Materia4  Promedio\n");

    for (int i = 0; i < estudiantes; i++) {
        printf("Est %d:  ", i + 1);
        float suma = 0;

        // Mostrar calificaciones del estudiante
        for (int j = 0; j < materias; j++) {
            printf("%8.1f  ", calificaciones[i][j]);
            suma += calificaciones[i][j];
        }

        // Calcular y mostrar promedio
        float promedio = suma / materias;
        printf("%8.2f\n", promedio);
    }

    return 0;
}
```

## Arreglos de Caracteres (Cadenas)

Los arreglos de caracteres se usan para manejar cadenas de texto:

```c
// Diferentes formas de declarar cadenas
char nombre[20];                    // Cadena sin inicializar
char saludo[] = "Hola Mundo";      // Tamaño automático
char mensaje[50] = "Bienvenido";   // Inicialización parcial
char letras[] = {'H', 'o', 'l', 'a', '\0'}; // Inicialización carácter por carácter
```

## Operaciones Comunes con Arreglos

### Buscar un Elemento

```c
int buscar(int arreglo[], int tamaño, int valor) {
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == valor) {
            return i;  // Retorna el índice donde se encontró
        }
    }
    return -1;  // No se encontró
}
```

### Encontrar el Mayor y Menor

```c
void mayorMenor(int arreglo[], int tamaño, int *mayor, int *menor) {
    *mayor = *menor = arreglo[0];

    for (int i = 1; i < tamaño; i++) {
        if (arreglo[i] > *mayor) *mayor = arreglo[i];
        if (arreglo[i] < *menor) *menor = arreglo[i];
    }
}
```

### Suma de Elementos

```c
int sumarArreglo(int arreglo[], int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += arreglo[i];
    }
    return suma;
}
```

## Limitaciones y Consideraciones

1. **Tamaño fijo**: El tamaño debe conocerse en tiempo de compilación
2. **Índices válidos**: Solo de 0 a (tamaño-1)
3. **Sin verificación de límites**: C no verifica automáticamente los límites
4. **Paso por referencia**: Los arreglos se pasan por referencia a funciones

## Ejemplo Integrador

```c
#include <stdio.h>

#define MAX_ESTUDIANTES 5
#define MAX_MATERIAS 3

int main() {
    // Matriz de calificaciones
    float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
    char nombres[MAX_ESTUDIANTES][50];

    printf("=== SISTEMA DE CALIFICACIONES ===\n\n");

    // Capturar datos
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        scanf("%s", nombres[i]);

        printf("Calificaciones de %s:\n", nombres[i]);
        for (int j = 0; j < MAX_MATERIAS; j++) {
            printf("  Materia %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
        printf("\n");
    }

    // Mostrar reporte
    printf("\n=== REPORTE DE CALIFICACIONES ===\n");
    printf("%-15s %8s %8s %8s %10s\n", "NOMBRE", "MAT1", "MAT2", "MAT3", "PROMEDIO");
    printf("------------------------------------------------\n");

    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        printf("%-15s ", nombres[i]);

        float suma = 0;
        for (int j = 0; j < MAX_MATERIAS; j++) {
            printf("%8.1f ", notas[i][j]);
            suma += notas[i][j];
        }

        float promedio = suma / MAX_MATERIAS;
        printf("%10.2f\n", promedio);
    }

    return 0;
}
```

---

## Consejos y Buenas Prácticas

1. **Siempre verifica los límites** del arreglo para evitar errores
2. **Inicializa los arreglos** antes de usarlos
3. **Usa constantes** para definir tamaños de arreglos
4. **Ten cuidado con los índices** (recuerda que empiezan en 0)
5. **Para cadenas**, siempre incluye el carácter nulo '\0'
