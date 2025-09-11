@ingroup apuntes-teoria

# Condicionales if, else if y else en C

---

## Descripción

Las estructuras condicionales `if`, `else if` y `else` permiten que un programa tome decisiones basadas en condiciones específicas. Estas estructuras evalúan expresiones booleanas y ejecutan diferentes bloques de código según el resultado.

---

## Sintaxis Básica

### if

La sintaxis general es:

```c
if (condición) {
    /* sentencia(s) */
}
```

Donde "condición" es una expresión booleana o integral; en C se considera verdadera si el resultado es distinto de 0 y falsa si es 0. Desde C99 puede usarse el tipo \_Bool o el alias bool (incluyendo <stdbool.h>).

### else if y else:

```c
if (cond1) {
    /* ... */
} else if (cond2) {
    /* ... */
} else {
    /* ... */
}
```

**Nota**: Los paréntesis son obligatorios alrededor de la condición y las llaves {} delimitan el bloque de código.

---

## Ejemplos Prácticos

### Ejemplo usando una variable booleana:

```c
bool bandera = true;
if (bandera) {
    puts("La bandera está activa");
}
```

(En C, cualquier expresión entera distinta de 0 se trata como verdadera).

---

## Casos de Uso Comunes

### if simple

Ejecuta un bloque cuando la condición es verdadera.

```c
int x = 5;
if (x > 0) {
    printf("x es positivo
");
}
```

### else

Bloque alternativo cuando la condición del if es falsa.

```c
if (x % 2 == 0) {
    puts("par");
} else {
    puts("impar");
}
```

### else if

Encadena varias condiciones mutuamente excluyentes.

```c
int nota = 78;
if (nota >= 90) {
    puts("A");
} else if (nota >= 80) {
    puts("B");
} else if (nota >= 70) {
    puts("C");
} else {
    puts("F");
}
```

---

## Ejemplo Completo

### Ver Documentacion

- \ref sel_simple "Selectiva-Simple2.c — vista Doxygen"
- \ref sel_doble "Selectiva-Doble-anidada-calif.c — vista Doxygen"

### Ver Codigo

![[Selectiva-Doble-anidada-calif 1.c]]

### Ejemplos

- if: ejecuta un bloque cuando la condición es verdadera.

  ```c
  int x = 5;
  if (x > 0) {
      printf("x es positivo\n");
  }
  ```

- else: bloque alternativo cuando la condición del if es falsa.

  ```c
  if (x % 2 == 0) {
      puts("par");
  } else {
      puts("impar");
  }
  ```

- else if: encadena varias condiciones mutuamente excluyentes.
  ```c
  int nota = 78;
  if (nota >= 90) {
      puts("A");
  } else if (nota >= 80) {
      puts("B");
  } else if (nota >= 70) {
      puts("C");
  } else {
      puts("F");
  }
  ```

Aquí tienes un ejemplo más completo que demuestra el uso de todas las estructuras condicionales:

```c
#include <stdio.h>

int main() {
    int edad;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    if (edad < 0) {
        printf("Edad inválida\n");
    } else if (edad < 13) {
        printf("Eres un niño\n");
    } else if (edad < 18) {
        printf("Eres un adolescente\n");
    } else if (edad < 65) {
        printf("Eres un adulto\n");
    } else {
        printf("Eres un adulto mayor\n");
    }

    return 0;
}
```

---

## Consejos y Buenas Prácticas

1. **Siempre usa llaves** `{}` incluso para una sola línea, mejora la legibilidad
2. **Ordena las condiciones** de la más específica a la más general
3. **Usa paréntesis** para clarificar expresiones complejas
4. **Evita condiciones demasiado complejas**, divide en variables auxiliares si es necesario
5. **Considera usar switch** cuando tengas muchas condiciones basadas en el mismo valor
