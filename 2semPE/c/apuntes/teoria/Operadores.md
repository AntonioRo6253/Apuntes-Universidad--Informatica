@ingroup apuntes-teoria

# Operadores en C

---

## Descripción

Los operadores en C son símbolos especiales que permiten realizar operaciones sobre variables y valores. Se clasifican en diferentes categorías según el tipo de operación que realizan: aritméticos, de comparación, lógicos, de asignación, entre otros.

---

## Operadores Aritméticos

| Nombre         | Descripción                              | Uso      | C/C++     | Python        | JavaScript | Ejemplo  |
| -------------- | ---------------------------------------- | -------- | --------- | ------------- | ---------- | -------- |
| Suma           | Realiza la adición de dos valores        | `A + B`  | +         | +             | +          | X + Y    |
| Resta          | Realiza la sustracción de dos valores    | `A - B`  | -         | -             | -          | X - Y    |
| Multiplicación | Realiza la multiplicación de dos valores | `A * B`  | \*        | \*            | \*         | X \* Y   |
| División       | Realiza la división entre dos valores    | `A / B`  | /         | /             | /          | X / Y    |
| Módulo         | Devuelve el resto de una división        | `A % B`  | %         | %             | %          | X % Y    |
| Exponente      | Calcula la potencia de un número         | `A ** B` | No nativo | \*\*          | \*\*       | X \*\* Y |
| Cociente       | División entera (solo parte entera)      | `A // B` | No nativo | //            | No nativo  | X // Y   |
| Incremento     | Aumenta el valor en 1                    | `A++`    | ++        | No disponible | ++         | X++      |
| Decremento     | Disminuye el valor en 1                  | `A--`    | --        | No disponible | --         | X--      |

---

## Operadores de Comparación/Relacionales

| Nombre        | Descripción                                   | Uso      | C/C++ | Python | JavaScript | Ejemplo |
| ------------- | --------------------------------------------- | -------- | ----- | ------ | ---------- | ------- |
| Igual que     | Compara si dos valores son iguales            | `A == B` | ==    | ==     | ==         | X == Y  |
| Distinto de   | Compara si dos valores son diferentes         | `A != B` | !=    | !=     | !=         | X != Y  |
| Mayor que     | Compara si un valor es mayor que otro         | `A > B`  | >     | >      | >          | X > Y   |
| Menor que     | Compara si un valor es menor que otro         | `A < B`  | <     | <      | <          | X < Y   |
| Mayor o igual | Compara si un valor es mayor o igual que otro | `A >= B` | >=    | >=     | >=         | X >= Y  |
| Menor o igual | Compara si un valor es menor o igual que otro | `A <= B` | <=    | <=     | <=         | X <= Y  |

---

## Operadores Lógicos

`A` y `B` deben ser booleanos

| Nombre | Descripción                                             | Uso      | C/C++ | Python | JavaScript | Ejemplo  |
| ------ | ------------------------------------------------------- | -------- | ----- | ------ | ---------- | -------- |
| AND    | Devuelve verdadero si ambos operandos son verdaderos    | `A&&B`   | &&    | and    | &&         | X && Y   |
| OR     | Devuelve verdadero si al menos un operando es verdadero | `A\|\|B` | \|\|  | or     | \|\|       | X \|\| Y |
| NOT    | Invierte el valor lógico del operando                   | `!B`     | !     | not    | !          | !X       |

---

## Operadores de Asignación

| Nombre                       | Descripción                            | Uso     | C/C++     | Python | Java Script | Codigo (X=7)   |
| ---------------------------- | -------------------------------------- | ------- | --------- | ------ | ----------- | -------------- |
| Asignación                   | Asigna un valor a una variable         | `A=B`   | =         | =      | =           | X = 7          |
| Asignación de suma           | Suma y asigna el resultado             | `A+=B`  | +=        | +=     | +=          | X += 2 → 9     |
| Asignación de resta          | Resta y asigna el resultado            | `A-=B`  | -=        | -=     | -=          | X -= 2 → 5     |
| Asignación de multiplicación | Multiplica y asigna el resultado       | `A*=B`  | \*=       | \*=    | \*=         | X \*= 2 → 14   |
| Asignación de división       | Divide y asigna el resultado           | `A/=B`  | /=        | /=     | /=          | X /= 2 → 3.5   |
| Asignación de módulo         | Aplica módulo y asigna el resultado    | `A%=B`  | %=        | %=     | %=          | X %= 2 → 1     |
| Asignación de exponenciación | Calcula potencia y asigna el resultado | `A**=B` | No nativo | \*\*=  | \*\*=       | X \*\*= 2 → 49 |

---

## Operadores de Bits

| Operador | Uso      | Ejemplo                | Descripción              |
| -------- | -------- | ---------------------- | ------------------------ |
| &        | `a & b`  | flags = mask & value;  | AND a nivel de bits      |
| \|       | `a \| b` | flags = mask \| value; | OR a nivel de bits       |
| ^        | `a ^ b`  | flags = mask ^ value;  | XOR a nivel de bits      |
| ~        | `~a`     | flags = ~mask;         | NOT a nivel de bits      |
| <<       | `a << b` | value = num << 2;      | Desplazamiento izquierda |
| >>       | `a >> b` | value = num >> 2;      | Desplazamiento derecha   |

---

## Otros Operadores

| Categoría    | Operador | Uso            | Ejemplo                | Descripción          |
| ------------ | -------- | -------------- | ---------------------- | -------------------- |
| **Ternario** | ? :      | `cond ? a : b` | max = (a > b) ? a : b; | Operador condicional |
| **Otros**    | sizeof() | `sizeof(tipo)` | size = sizeof(int);    | Tamaño en bytes      |

---

## Ejemplos Prácticos

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    int resultado;

    // Operadores aritméticos
    printf("Suma: %d + %d = %d\n", a, b, a + b);
    printf("Resta: %d - %d = %d\n", a, b, a - b);
    printf("Multiplicación: %d * %d = %d\n", a, b, a * b);
    printf("División: %d / %d = %d\n", a, b, a / b);
    printf("Módulo: %d %% %d = %d\n", a, b, a % b);

    // Operadores de comparación
    printf("\nComparaciones:\n");
    printf("%d == %d: %s\n", a, b, (a == b) ? "verdadero" : "falso");
    printf("%d > %d: %s\n", a, b, (a > b) ? "verdadero" : "falso");

    // Operadores lógicos
    printf("\nOperadores lógicos:\n");
    printf("(a > 5) && (b < 5): %s\n", ((a > 5) && (b < 5)) ? "verdadero" : "falso");
    printf("(a < 5) || (b < 5): %s\n", ((a < 5) || (b < 5)) ? "verdadero" : "falso");

    // Operador ternario
    resultado = (a > b) ? a : b;
    printf("\nEl mayor entre %d y %d es: %d\n", a, b, resultado);

    return 0;
}
```

---

## Consejos y Buenas Prácticas

1. **Usa paréntesis** para clarificar la precedencia de operadores
2. **Prefiere `++i` sobre `i++`** en bucles para mejor rendimiento
3. **Ten cuidado con la división** entre enteros (resultado truncado)
4. **Usa operadores de asignación compuesta** (+=, -=, etc.) para código más limpio
5. **Conoce la precedencia** de operadores para evitar errores lógicos
   | | & | `&variable` | ptr = &var; | Dirección de |
   | | * | `*ptr` | valor = \*ptr; | Indirección |

## Operadores Bit a Bit (Parcial)

_Incluyen operaciones de desplazamiento y operaciones lógicas a nivel de bits_

- Desplazamiento a la izquierda
- Desplazamiento a la derecha
- AND bit a bit
- OR bit a bit
- XOR bit a bit

## Bibliografía

- `WEB`\_Óscar Ramírez Jiménez(2024)”Operadores de python” Consultado el 2/02/2025. Disponible en https://ellibrodepython.com/operadores-python
- `WEB`\_Mozilla(2024)”Expresiones y operadores JavaScript”Consultado el 2/02/2025. Disponible en https://developer.mozilla.org/es/docs/Web/JavaScript/Guide/Expressions_and_operators
- `WEB`\_LearnMicrosoft(05/03/2024)”Operadores de asignación”Consultado el 2/02/2025. Disponible en https://learn.microsoft.com/es-es/cpp/cpp/assignment-operators?view=msvc-170
