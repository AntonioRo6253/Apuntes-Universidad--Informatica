@ingroup apuntes-teoria

# If, else if y else — resumen

### Sintaxis básica

- if: la sintaxis general es:

  ```c
  if (condición) {
      /* sentencia(s) */
  }
  ```

  Donde "condición" es una expresión booleana o integral; en C se considera verdadera si el resultado es distinto de 0 y falsa si es 0. Desde C99 puede usarse el tipo \_Bool o el alias bool (incluyendo <stdbool.h>).

  Ejemplo usando una variable booleana:

  ```c
  bool bandera = true;
  if (bandera) {
      puts("La bandera está activa");
  }
  ```

  (en C, cualquier expresión entera distinta de 0 se trata como verdadera).

- else if y else:

  ```c
  if (cond1) {
      /* ... */
  } else if (cond2) {
      /* ... */
  } else {
      /* ... */
  }
  ```

  Nota: los paréntesis son obligatorios alrededor de la condición y las llaves {} delimitan el bloque de código.

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

## Switch — resumen

- switch: selecciona entre varias ramas según el valor de una expresión integral (int, char, enum, etc.).

### Sintaxis básica:

```c
switch (expresión_integral) {
    case constante1:
        /* sentencia(s) */
        break;
    case constante2:
        /* ... */
        break;
    default:
        /* alternativa si no coincide ningún case */
}
```

### Ejemplos:

```c
int opcion = 2;
switch (opcion) {
    case 1:
        puts("Opción 1");
        break;
    case 2:
        puts("Opción 2");
        break;
    default:
        puts("Otra opción");
}
```

- break: termina la ejecución del switch para evitar "fall-through" (caída a la siguiente etiqueta).
- Fall-through: si omites break, la ejecución continúa en el siguiente case — útil para agrupar casos:

  ```c
  switch (opcion) {
      case 1:
      case 2:
          puts("Opción 1 o 2");
          break;
      default:
          puts("Otra opción");
  }
  ```

- Notas rápidas:
  - Las etiquetas case deben ser constantes en tiempo de compilación.
  - default es opcional y se ejecuta si ningún case coincide.
  - El orden de los case no afecta la comparación (se compara el valor).
