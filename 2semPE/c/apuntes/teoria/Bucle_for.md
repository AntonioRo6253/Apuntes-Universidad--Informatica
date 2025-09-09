@ingroup apuntes-teoria

---

# Sintaxis Básica

```c
for (inicialización; condición; actualización) {
    // Código a repetir
}
```

- **Inicialización**: Se ejecuta una vez al inicio. Suele declarar/inicializar la variable de control (ej: `int i = 0`).
- **Condición**: Se evalúa antes de cada iteración. Si es verdadera (`true`), el bucle continúa.
- **Actualización**: Se ejecuta al final de cada iteración (ej: incrementar/decrementar la variable).

---

## Consideraciones Importantes

1. **Variables de control**:

   - La variable de control puede declararse dentro del bucle (en C99 o superior):
     ```c
     for (int i = 0; i < 5; i++) { ... }
     ```
   - En C antiguo, debe declararse fuera:
     ```c
     int i;
     for (i = 0; i < 5; i++) { ... }
     ```

2. **Expresiones opcionales**:

   - Cualquier parte del `for` puede omitirse, pero los `;` deben permanecer:
     ```c
     int i = 0;
     for (; i < 5; i++) { ... } // Sin inicialización
     for (;;) { ... }           // Bucle infinito (requiere `break` para salir)
     ```

3. **Alcance de la variable**:

   - Si se declara dentro del `for`, solo existe dentro del bucle.

4. **Anidamiento**:
   - Los bucles `for` pueden anidarse para trabajar con estructuras multidimensionales.

---

### Ejemplos Prácticos

#### 1. Contar del 0 al 4:

```c
#include <stdio.h>
int main() {
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    // Output: 0 1 2 3 4
    return 0;
}
```

#### 2. Sumar números del 1 al 10:

```c
#include <stdio.h>
int main() {
    int suma = 0;
    for (int i = 1; i <= 10; i++) {
        suma += i;
    }
    printf("Suma: %d", suma); // Output: Suma: 55
    return 0;
}
```

#### 3. Recorrer un array:

```c
#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    // Output: 10 20 30
    return 0;
}
```

#### 4. Decrementar (contar regresivamente):

```c
for (int i = 5; i > 0; i--) {
    printf("%d ", i);
}
// Output: 5 4 3 2 1
```

#### 5. Múltiples variables en el bucle:

```c
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d, j=%d\n", i, j);
}
/* Output:
   i=0, j=10
   i=1, j=9
   ... (hasta i=4, j=6) */
```

---

#### Errores Comunes

- **Condiciones infinitas**:
  ```c
  for (int i = 0; i >= 0; i++) { ... } // Nunca termina (i siempre >= 0).
  ```
- **Actualización incorrecta**:
  ```c
  for (int i = 0; i < 5; i--) { ... } // i decrece, nunca alcanza i < 5.
  ```

---

#### Consejos

- Usa variables con nombres significativos (ej: `contador` en lugar de `i` si mejora la legibilidad).
- Evita modificar la variable de control dentro del cuerpo del bucle (puede causar comportamientos inesperados).

Este bucle es ideal cuando se conoce el número de iteraciones de antemano. ¡Practica con variaciones para dominarlo!

---
---

