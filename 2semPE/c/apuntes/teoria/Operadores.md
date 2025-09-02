@ingroup apuntes-teoria
# Tabla Mejorada de Operadores en C

**Operadores en el Lenguaje C**

| Categoría                 | Operador   | Uso            | Ejemplo                  | Descripción                 |
| ------------------------- | ---------- | -------------- | ------------------------ | --------------------------- |
| **Aritméticos**           | `+`        | `a + b`        | `resultado = 5 + 3;`     | Suma                        |
|                           | `-`        | `a - b`        | `resultado = 5 - 3;`     | Resta                       |
|                           | `*`        | `a * b`        | `resultado = 5 * 3;`     | Multiplicación              |
|                           | `/`        | `a / b`        | `resultado = 5 / 3;`     | División                    |
|                           | `%`        | `a % b`        | `resultado = 5 % 3;`     | Módulo (resto)              |
| **Incremento/Decremento** | `++`       | `variable++`   | `i++;`                   | Incremento postfijo         |
|                           | `++`       | `++variable`   | `++i;`                   | Incremento prefijo          |
|                           | `--`       | `variable--`   | `j--;`                   | Decremento postfijo         |
|                           | `--`       | `--variable`   | `--j;`                   | Decremento prefijo          |
| **Asignación**            | `=`        | `a = b`        | `x = 5;`                 | Asignación básica           |
|                           | `+=`       | `a += b`       | `x += 3;`                | Suma y asignación           |
|                           | `-=`       | `a -= b`       | `x -= 3;`                | Resta y asignación          |
|                           | `*=`       | `a *= b`       | `x *= 3;`                | Multiplicación y asignación |
|                           | `/=`       | `a /= b`       | `x /= 3;`                | División y asignación       |
|                           | `%=`       | `a %= b`       | `x %= 3;`                | Módulo y asignación         |
| **Lógicos**               | `&&`       | `a && b`       | `if (a && b)`            | AND lógico                  |
|                           | `\|\|`     | `a \|\| b`     | `if (a \|\| b)`          | OR lógico                   |
|                           | `!`        | `!a`           | `if (!a)`                | NOT lógico                  |
| **Comparación**           | ` == `     | `a == b`       | `if (a == b)`            | Igual a                     |
|                           | `!=`       | `a != b`       | `if (a != b)`            | Diferente de                |
|                           | `>`        | `a > b`        | `if (a > b)`             | Mayor que                   |
|                           | `<`        | `a < b`        | `if (a < b)`             | Menor que                   |
|                           | `>=`       | `a >= b`       | `if (a >= b)`            | Mayor o igual que           |
|                           | `<=`       | `a <= b`       | `if (a <= b)`            | Menor o igual que           |
| **Bits**                  | `&`        | `a & b`        | `flags = mask & value;`  | AND a nivel de bits         |
|                           | `\|`       | `a \| b`       | `flags = mask \| value;` | OR a nivel de bits          |
|                           | `^`        | `a ^ b`        | `flags = mask ^ value;`  | XOR a nivel de bits         |
|                           | `~`        | `~a`           | `flags = ~mask;`         | NOT a nivel de bits         |
|                           | `<<`       | `a << b`       | `value = num << 2;`      | Desplazamiento izquierda    |
|                           | `>>`       | `a >> b`       | `value = num >> 2;`      | Desplazamiento derecha      |
| **Ternario**              | `? :`      | `cond ? a : b` | `max = (a > b) ? a : b;` | Operador condicional        |
| **Otros**                 | `sizeof()` | `sizeof(tipo)` | `size = sizeof(int);`    | Tamaño en bytes             |
|                           | `&`        | `&variable`    | `ptr = &var;`            | Dirección de                |
|                           | `*`        | `*ptr`         | `valor = *ptr;`          | Indirección                 |

**Notas importantes:**
- C **no tiene** un operador de exponenciación nativo (`**` como en otros lenguajes)
- Para operaciones de potenciación, se utiliza la función `pow()` de la biblioteca `math.h`
- El operador de módulo `%` solo funciona con tipos enteros
- Los operadores de bits trabajan a nivel de bits individuales

Esta tabla ampliada incluye los operadores más comunes del lenguaje C, organizados por categorías para mejor referencia.