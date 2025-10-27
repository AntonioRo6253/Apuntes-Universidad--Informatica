@ingroup apuntes-teoria

# Sentencia switch en C

---

## Descripción

La sentencia `switch` es una estructura de control que permite seleccionar una entre múltiples alternativas, basándose en el valor de una **expresión de control (selector)**. Es ideal cuando las decisiones dependen de valores discretos (ej: menús, categorías, opciones).

---

## Sintaxis Básica

```c
switch (selector) {
    case etiqueta1:
        sentencias1;
        break;
    case etiqueta2:
        sentencias2;
        break;
    default:
        sentencias_default; // Opcional
}
```

---

## Reglas y Consideraciones

1. El **selector** debe ser de tipo `int` o `char` (no `float`, `double` o strings).
2. Las **etiquetas** deben ser constantes únicas (ej: `case 5:`, `case 'A':`).
3. El `default` es opcional, pero recomendado para manejar valores inesperados.
4. La sentencia `break` termina la ejecución del `switch`. Sin ella, se ejecutarán todos los casos siguientes (**fall-through**).

---

## Ejemplos Prácticos

### Ejemplo 1: Selección Simple

```c
switch (opcion) {
    case 0:
        puts("Cero!");
        break;
    case 1:
        puts("Uno!");
        break;
    default:
        puts("Fuera de rango");
}
```

---

## Ejemplo 2: Múltiples Etiquetas (Fall-Through Controlado)

```c
switch (nota) {
    case 'A':
    case 'B':
    case 'C':
        puts("Aprobado");
        break;
    case 'D':
    case 'F':
        puts("Reprobado");
        break;
    default:
        puts("Nota inválida");
}
```

---

## Comparación if-else vs. switch

| Característica      | `if-else`                         | `switch`                         |
| ------------------- | --------------------------------- | -------------------------------- |
| Tipo de condiciones | Expresiones booleanas (ej: `>=5`) | Valores discretos (ej: `5`)      |
| Legibilidad         | Mejor para rangos                 | Ideal para opciones fijas        |
| Eficiencia          | Puede ser menos eficiente         | Optimizado para múltiples casos  |
| Uso de `break`      | No aplica                         | Crítico para evitar fall-through |

---

**Precaución: Omisión de `break`**  
Si se omite `break`, el programa ejecutará **todos los casos siguientes** hasta encontrar un `break` o el final del `switch`. Esto puede causar comportamientos inesperados. Ejemplo:

```c
switch (tipo_vehiculo) {
    case 1:
        printf("Turismo\n");
        // Sin break: ¡Ejecutará el siguiente caso!
    case 2:
        printf("Autobús\n");
        break;
}
// Si tipo_vehiculo es 1, imprimirá "Turismo" y "Autobús".
```

---

### Evaluación en Cortocircuito

En expresiones lógicas con `&&` y `||`, C evalúa solo hasta donde sea necesario. Ejemplo:

```c
if (a != 0 && b / a > 2) {
    // Si a es 0, evita la división (evita error)
}
```

**Explicación**:

- En `&&`: Si el primer operando es falso, el segundo no se evalúa.
- En `||`: Si el primer operando es verdadero, el segundo no se evalúa.

---

**Usos Prácticos**

1. **Menús Interactivos**:
   ```c
   switch (opcion_menu) {
       case 1: abrir_archivo(); break;
       case 2: guardar_archivo(); break;
       default: printf("Opción no válida\n");
   }
   ```
2. **Autenticación de Usuarios**:
   ```c
   switch (nivel_acceso) {
       case 1: printf("Administrador\n"); break;
       case 2: printf("Usuario\n"); break;
       default: printf("Invitado\n");
   }
   ```

Aquí tienes un ejemplo completo que demuestra el uso del switch:

```c
#include <stdio.h>

int main() {
    char escala;
    float temperatura;

    printf("Ingrese la escala de temperatura (C/F): ");
    scanf(" %c", &escala);

    printf("Ingrese la temperatura: ");
    scanf("%f", &temperatura);

    switch (escala) {
        case 'C':
        case 'c':
            printf("%.2f°C = %.2f°F\n", temperatura, (temperatura * 9/5) + 32);
            break;
        case 'F':
        case 'f':
            printf("%.2f°F = %.2f°C\n", temperatura, (temperatura - 32) * 5/9);
            break;
        default:
            printf("Escala no soportada. Use C o F.\n");
    }

    return 0;
}
```

---

## Consejos y Buenas Prácticas

1. **Siempre incluye `break`** a menos que específicamente quieras fall-through
2. **Usa `default`** para manejar casos inesperados
3. **Agrupa casos similares** usando fall-through controlado
4. **Prefiere switch sobre múltiples if-else** cuando compares el mismo valor
5. **Considera usar enums** para hacer el código más legible

El `switch` es una herramienta poderosa para decisiones basadas en valores discretos. Su correcto uso depende de elegir el tipo correcto para el selector, incluir `break` donde sea necesario y manejar casos inesperados con `default`.
