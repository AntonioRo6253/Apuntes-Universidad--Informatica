@ingroup apuntes-codigos

# Matricez

# ¿Que es?

Una matriz es un arreglo rectangular bidimensional de números, símbolos u objetos matemáticos, organizados en filas (horizontales) y columnas (verticales), que se utiliza para resolver sistemas de ecuaciones lineales, almacenar y transformar datos, y en diversos campos como la informática, la física y la economía.

### 1. Inicializar una matriz con valores

```c
int matriz[3][3];

// Llenar la matriz con valores consecutivos
int valor = 1;
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        matriz[i][j] = valor++;
    }
}
```

### 2. Sumar todos los elementos de una matriz

```c
int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
int suma = 0;

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        suma += matriz[i][j];
    }
}
printf("Suma total: %d\n", suma);
```

### 3. Buscar un elemento en la matriz

```c
int matriz[2][3] = {{5, 8, 2}, {9, 4, 7}};
int objetivo = 4;
int encontrado = 0;

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        if (matriz[i][j] == objetivo) {
            printf("Encontrado en [%d][%d]\n", i, j);
            encontrado = 1;
            break;
        }
    }
    if (encontrado) break;
}
```

## 4. Buscar un elemento en la matriz

```c
#include <stdio.h>

int main() {
    int matriz[3][3] = {{5, 8, 2}, {9, 4, 7}, {1, 3, 6}};
    int objetivo = 7;
    int encontrado = 0;
    int fila, columna;

    // Buscar el elemento en la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == objetivo) {
                encontrado = 1;
                fila = i;
                columna = j;
                break;
            }
        }
        if (encontrado) break;
    }

    if (encontrado) {
        printf("El valor %d se encontró en la posición [%d][%d]\n",
               objetivo, fila, columna);
    } else {
        printf("El valor %d no se encontró en la matriz\n", objetivo);
    }

    return 0;
}
```

### 5. Matriz de caracteres (strings)

```c
char palabras[3][10] = {"Hola", "Mundo", "C"};

for (int i = 0; i < 3; i++) {
    printf("Palabra %d: %s\n", i, palabras[i]);
}
```

### 6. Modificar valores de la matriz

```c
int matriz[2][2] = {{1, 2}, {3, 4}};

// Duplicar todos los valores
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        matriz[i][j] *= 2;
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
```

# Más Ejemplos de Bucles for con Matrices Bidimensionales en C

Aquí tienes más ejemplos prácticos de cómo usar bucles `for` con matrices bidimensionales:

## 7. Inicializar matriz con valores secuenciales

```c
#include <stdio.h>

int main() {
    int matriz[3][3];
    int contador = 1;

    // Llenar la matriz con valores secuenciales
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = contador++;
        }
    }

    // Imprimir la matriz
    printf("Matriz con valores secuenciales:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 8. Suma de elementos de una matriz

```c
#include <stdio.h>

int main() {
    int matriz[2][3] = {{5, 8, 2}, {9, 4, 7}};
    int suma = 0;

    // Calcular la suma de todos los elementos
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            suma += matriz[i][j];
        }
    }

    printf("La suma de todos los elementos es: %d\n", suma);

    return 0;
}
```

## 9. Encontrar el valor máximo en una matriz

```c
#include <stdio.h>
#include <limits.h>

int main() {
    int matriz[3][4] = {{12, 5, 8, 20}, {3, 15, 7, 9}, {11, 2, 18, 6}};
    int maximo = INT_MIN;
    int fila_max, columna_max;

    // Encontrar el valor máximo y su posición
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                fila_max = i;
                columna_max = j;
            }
        }
    }

    printf("El valor máximo es %d en la posición [%d][%d]\n",
           maximo, fila_max, columna_max);

    return 0;
}
```

## 10. Transponer una matriz

```c
#include <stdio.h>

int main() {
    int original[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transpuesta[3][2];

    // Transponer la matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[j][i] = original[i][j];
        }
    }

    // Mostrar la matriz original
    printf("Matriz original:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", original[i][j]);
        }
        printf("\n");
    }

    // Mostrar la matriz transpuesta
    printf("\nMatriz transpuesta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", transpuesta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 11. Multiplicación de matrices

```c
#include <stdio.h>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {{0, 0}, {0, 0}};

    // Multiplicar matrices A x B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Mostrar el resultado
    printf("Resultado de la multiplicación A x B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 12. Matriz de caracteres (tablero de juego)

```c
#include <stdio.h>

int main() {
    char tablero[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Inicializar el tablero con algunas fichas
    tablero[0][0] = 'X';
    tablero[1][1] = 'O';
    tablero[2][2] = 'X';

    // Mostrar el tablero
    printf("Tablero de juego:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", tablero[i][j]);
        }
        printf("|\n");
        if (i < 2) printf("-------------\n");
    }

    return 0;
}
```

## 13. Promedio de cada fila

```c
#include <stdio.h>

int main() {
    float matriz[4][3] = {
        {85.5, 90.0, 78.5},
        {92.0, 88.5, 76.0},
        {79.0, 85.0, 91.5},
        {88.0, 92.5, 84.0}
    };

    // Calcular el promedio de cada fila
    printf("Promedio por fila:\n");
    for (int i = 0; i < 4; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += matriz[i][j];
        }
        float promedio = suma / 3;
        printf("Fila %d: %.2f\n", i, promedio);
    }

    return 0;
}
```

**Puntos clave:**

- Usa bucles anidados para recorrer filas y columnas
- El primer índice generalmente representa las filas
- El segundo índice generalmente representa las columnas
- Puedes usar variables diferentes para los índices (i/j, fila/columna, etc.)
- El bucle externo controla las filas y el interno las columnas
