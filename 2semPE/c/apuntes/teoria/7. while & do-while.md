@ingroup apuntes-teoria

# Bucles while y do-while en C

---

## Descripción

Los bucles `while` y `do-while` son estructuras de control que permiten repetir un bloque de código mientras una condición sea verdadera. La diferencia principal es que `while` evalúa la condición antes de ejecutar el código, mientras que `do-while` la evalúa después.

---

## 1. Bucle while

---

## Sintaxis Básica

```c
while (condición) {
    // Bloque de código a ejecutar
}
```

- **Funcionamiento**: Evalúa la `condición` antes de ejecutar el bloque. Si es verdadera (`true`), ejecuta el código y repite el proceso.
- **Característica clave**: Puede que el bloque no se ejecute nunca si la condición es falsa inicialmente.

---

## Ejemplos Prácticos

### Ejemplo de while:

```c
#include <stdio.h>

int main() {
    int contador = 1;
    while (contador <= 5) {
        printf("Iteración: %d\n", contador);
        contador++; // Incrementa el contador
    }
    return 0;
}
```

**Salida**:

```
Iteración: 1
Iteración: 2
Iteración: 3
Iteración: 4
Iteración: 5
```

---

## 2. Bucle do-while

### Sintaxis básica:

```c
do {
    // Bloque de código a ejecutar
} while (condición);
```

- **Funcionamiento**: Ejecuta el bloque primero y luego evalúa la `condición`. Si es verdadera, repite el proceso.
- **Característica clave**: El bloque se ejecuta **al menos una vez**, incluso si la condición es falsa.

### Ejemplo:

```c
#include <stdio.h>

int main() {
    int numero;
    do {
        printf("Ingrese un número positivo: ");
        scanf("%d", &numero);
    } while (numero <= 0);

    printf("Número válido: %d\n", numero);
    return 0;
}
```

**Salida** (ejemplo):

```
Ingrese un número positivo: -3
Ingrese un número positivo: 0
Ingrese un número positivo: 5
Número válido: 5
```

---

## 3. Consideraciones importantes

### a) Evitar bucles infinitos:

- Asegurarse de que la condición eventualmente sea falsa.
- **Ejemplo de error**:
  ```c
  while (1) { // ¡Bucle infinito!
      printf("Esto nunca termina...\n");
  }
  ```

### b) Variables de control:

- La condición debe depender de una variable que se modifique dentro del bucle.
- **Ejemplo correcto**:
  ```c
  int i = 0;
  while (i < 10) {
      printf("%d ", i);
      i++; // Modificación de la variable
  }
  ```

### c) Diferencias clave:

| `while`                           | `do-while`                          |
| --------------------------------- | ----------------------------------- |
| Evalúa condición antes del bloque | Evalúa condición después del bloque |
| Cero o más iteraciones            | Una o más iteraciones               |

---

## 4. Ejemplo comparativo

### Mismo comportamiento con `while` y `do-while`:

```c
// Con while
int i = 1;
while (i <= 3) {
    printf("%d ", i);
    i++;
}
// Salida: 1 2 3

// Con do-while
int j = 1;
do {
    printf("%d ", j);
    j++;
} while (j <= 3);
// Salida: 1 2 3
```

### Comportamiento diferente (cuando la condición es falsa inicialmente):

```c
// Con while (no se ejecuta)
int x = 10;
while (x < 5) {
    printf("Esto no se imprime");
}

// Con do-while (se ejecuta al menos una vez)
int y = 10;
do {
    printf("Esto se imprime una vez");
} while (y < 5);
```

---

## 5. Consejos prácticos

1. Usa `while` cuando no se requiera que el bloque se ejecute al menos una vez.
2. Usa `do-while` para validar entradas de usuario o menús interactivos.
3. Siempre inicializa las variables de control antes del bucle.
4. Verifica que exista una sentencia que modifique la condición dentro del bucle.

---

**Nota**: Ambos bucles son fundamentales para controlar flujos repetitivos en C. La elección depende de si necesitas o no garantizar la primera ejecución del bloque.

---

---
