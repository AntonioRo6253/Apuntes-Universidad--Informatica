@ingroup apuntes-teoria
## Aritméticos
| Nombre         | Descripción                              | Uso      | C/C++     | Python        | JavaScript | Ejemplo |
| -------------- | ---------------------------------------- | -------- | --------- | ------------- | ---------- | ------- |
| Suma           | Realiza la adición de dos valores        | `A + B`  | +         | +             | +          | X + Y   |
| Resta          | Realiza la sustracción de dos valores    | `A - B`  | -         | -             | -          | X - Y   |
| Multiplicación | Realiza la multiplicación de dos valores | `A * B`  | *         | *             | *          | X * Y   |
| División       | Realiza la división entre dos valores    | `A / B`  | /         | /             | /          | X / Y   |
| Módulo         | Devuelve el resto de una división        | `A % B`  | %         | %             | %          | X % Y   |
| Exponente      | Calcula la potencia de un número         | `A ** B` | No nativo | **            | **         | X ** Y  |
| Cociente       | División entera (solo parte entera)      | `A // B` | No nativo | //            | No nativo  | X // Y  |
| Incremento     | Aumenta el valor en 1                    | `A++`    | ++        | No disponible | ++         | X++     |
| Decremento     | Disminuye el valor en 1                  | `A--`    | --        | No disponible | --         | X--     |

## Comparación/Relacionales
| Nombre        | Descripción                                   | Uso        | C/C++ | Python | JavaScript | Ejemplo |
| ------------- | --------------------------------------------- | ---------- | ----- | ------ | ---------- | ------- |
| Igual que     | Compara si dos valores son iguales            | `A == B`   | ==    | ==     | ==         | X == Y  |
| Distinto de   | Compara si dos valores son diferentes         | `A != B`   | !=    | !=     | !=         | X != Y  |
| Mayor que     | Compara si un valor es mayor que otro         | `A > B`    | >     | >      | >          | X > Y   |
| Menor que     | Compara si un valor es menor que otro         | `A < B`    | <     | <      | <          | X < Y   |
| Mayor o igual | Compara si un valor es mayor o igual que otro | `A >= B`   | >=    | >=     | >=         | X >= Y  |
| Menor o igual | Compara si un valor es menor o igual que otro | `A <= B`   | <=    | <=     | <=         | X <= Y  |

## Lógicos
`A` y `B` deben ser booleanos

| Nombre | Descripción                                             | Uso      | C/C++ | Python | JavaScript | Ejemplo  |
| ------ | ------------------------------------------------------- | -------- | ----- | ------ | ---------- | -------- |
| AND    | Devuelve verdadero si ambos operandos son verdaderos    | `A&&B`   | &&    | and    | &&         | X && Y   |
| OR     | Devuelve verdadero si al menos un operando es verdadero | `A\|\|B` | \|\|  | or     | \|\|       | X \|\| Y |
| NOT    | Invierte el valor lógico del operando                   | `!B`     | !     | not    | !          | !X       |

## Asignación
| Nombre                       | Descripción                            | Uso     | C/C++     | Python | Java  Script | Codigo (X=7) |
| ---------------------------- | -------------------------------------- | ------- | --------- | ------ | ------------ | ------------ |
| Asignación                   | Asigna un valor a una variable         | `A=B`   | =         | =      | =            | X = 7        |
| Asignación de suma           | Suma y asigna el resultado             | `A+=B`  | +=        | +=     | +=           | X += 2 → 9   |
| Asignación de resta          | Resta y asigna el resultado            | `A-=B`  | -=        | -=     | -=           | X -= 2 → 5   |
| Asignación de multiplicación | Multiplica y asigna el resultado       | `A*=B`  | *=        | *=     | *=           | X *= 2 → 14  |
| Asignación de división       | Divide y asigna el resultado           | `A/=B`  | /=        | /=     | /=           | X /= 2 → 3.5 |
| Asignación de módulo         | Aplica módulo y asigna el resultado    | `A%=B`  | %=        | %=     | %=           | X %= 2 → 1   |
| Asignación de exponenciación | Calcula potencia y asigna el resultado | `A**=B` | No nativo | **=    | **=          | X **= 2 → 49 |

## Bits
| Operador | Uso      | Ejemplo                | Descripción              |
| -------- | -------- | ---------------------- | ------------------------ |
| &        | `a & b`  | flags = mask & value;  | AND a nivel de bits      |
| \|       | `a \| b` | flags = mask \| value; | OR a nivel de bits       |
| ^        | `a ^ b`  | flags = mask ^ value;  | XOR a nivel de bits      |
| ~        | `~a`     | flags = ~mask;         | NOT a nivel de bits      |
| <<       | `a << b` | value = num << 2;      | Desplazamiento izquierda |
| >>       | `a >> b` | value = num >> 2;      | Desplazamiento derecha   |

## Otros

| Categoría    | Operador | Uso            | Ejemplo                | Descripción          |
| ------------ | -------- | -------------- | ---------------------- | -------------------- |
| **Ternario** | ? :      | `cond ? a : b` | max = (a > b) ? a : b; | Operador condicional |
| **Otros**    | sizeof() | `sizeof(tipo)` | size = sizeof(int);    | Tamaño en bytes      |
|              | &        | `&variable`    | ptr = &var;            | Dirección de         |
|              | *        | `*ptr`         | valor = *ptr;          | Indirección          |

## Operadores Bit a Bit (Parcial)
*Incluyen operaciones de desplazamiento y operaciones lógicas a nivel de bits*
- Desplazamiento a la izquierda
- Desplazamiento a la derecha  
- AND bit a bit
- OR bit a bit
- XOR bit a bit

## Bibliografía
- `WEB`_Óscar Ramírez Jiménez(2024)”Operadores de python” Consultado el 2/02/2025. Disponible en https://ellibrodepython.com/operadores-python
- `WEB`_Mozilla(2024)”Expresiones y operadores JavaScript”Consultado el 2/02/2025. Disponible en https://developer.mozilla.org/es/docs/Web/JavaScript/Guide/Expressions_and_operators
- `WEB`_LearnMicrosoft(05/03/2024)”Operadores de asignación”Consultado el 2/02/2025. Disponible en https://learn.microsoft.com/es-es/cpp/cpp/assignment-operators?view=msvc-170