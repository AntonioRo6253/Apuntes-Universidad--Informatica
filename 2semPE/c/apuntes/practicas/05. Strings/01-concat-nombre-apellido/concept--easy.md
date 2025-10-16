---
title: Concatenar nombre y apellido (seguro)
topic: Strings
subtopics: [strncat, strcpy, buffers, terminador nulo, bucle for]
difficulty: easy
estimated_time: 15-20 minutos
prerequisites: ["00. Useful Functions/01-puts-strlen"]
learning_mode: concept
author: Curso C
version: 1.0
last_update: 2025-10-12
---

## Resumen
Lee un nombre y un apellido en líneas separadas y construye el nombre completo en un solo string, asegurando espacio entre ambos y evitando desbordamientos de buffer. Practicarás el uso de `fgets`, limpieza de `\n`, y concatenación segura con `strncat`, además del repaso de índices con `for`.

## Objetivos de aprendizaje
- Leer strings de forma segura con `fgets` y asegurar terminación `\0`.
- Eliminar el salto de línea con una función auxiliar.
- Concatenar strings con `strncat` verificando capacidad del buffer.
- Usar `for` para validar o limpiar contenido si fuera necesario.

## Enunciado
Implementa un programa que:
- Lea dos líneas: nombre y apellido.
- Construya un string `fullName = "<nombre> <apellido>"` (con un espacio entre ambos).
- Imprima exactamente: `Nombre completo: <nombre> <apellido>` seguido de `\n`.
- Debe manejar entradas vacías: si alguno está vacío, imprime solo el otro (sin espacios extra al inicio/fin).

## Especificación de entrada
- `stdin` con dos líneas (pueden ser vacías):
  - Línea 1: nombre (puede incluir espacios, se toma la línea completa)
  - Línea 2: apellido (puede incluir espacios)
- Longitud máxima sugerida por buffer: 80 caracteres por línea (ajustable en el código).

## Especificación de salida
- Una sola línea con el formato exacto:
```
Nombre completo: <texto>
```
Donde `<texto>` es:
- Solo nombre si apellido vacío.
- Solo apellido si nombre vacío.
- "nombre apellido" si ambos presentes.

## Restricciones
- Usa `fgets` para leer.
- Asegura `\0` y evita desbordamiento usando `strncat` con límites.
- Evita funciones inseguras como `gets`.

## Ejemplos
Ejemplo 1
Entrada:
```
Ana
Lopez
```
Salida:
```
Nombre completo: Ana Lopez
```

Ejemplo 2 (apellido vacío)
Entrada:
```
Ana

```
Salida:
```
Nombre completo: Ana
```

Ejemplo 3 (nombre vacío)
Entrada:
```

Lopez
```
Salida:
```
Nombre completo: Lopez
```

## Casos borde a considerar
- Ambas líneas vacías -> salida `Nombre completo: ` seguido de `\n`.
- Espacios al final por `\n` de `fgets` (debe eliminarse).
- Nombres largos: truncamiento controlado sin desbordar.

## Estructura de carpetas requerida
```
01-concat-nombre-apellido/
  concept--easy.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## Requisitos de código/estilo
- Identificadores claros.
- Función auxiliar para quitar `\n`.
- Verificar retornos de entrada.

## Requisitos de documentación
- Encabezado de archivo y funciones con propósito y parámetros.

## Instrucciones de prueba
Compilar:
  gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
Ejecutar:
  ./main < tests/test_input_01.txt
Comparar salida con `tests/test_expected_01.txt`.

## Rúbrica
| Criterio | Peso | Descripción |
|---|---|---|
| Corrección | 40% | Formato exacto, maneja vacíos |
| Seguridad memoria | 15% | Sin desbordes, `\0` asegurado |
| Claridad | 15% | Código legible y modular |
| Adherencia a la spec | 15% | Usa `fgets`, evita `gets` |
| Casos borde | 10% | Manejo explícito |
| Reflexión | 5% | Responde en `respuestas/REFLEXION.md` |

## Preguntas de reflexión
1. ¿Dónde era más fácil olvidar el `\0` y por qué?
2. ¿Qué harías si los buffers fueran demasiado cortos para algunos nombres?
3. ¿Cómo validarías y normalizarías espacios múltiples internos?

## Extensiones
- Normalizar espacios múltiples a uno solo.
- Soportar 3 campos: nombre, apellido paterno, materno.
- Recortar espacios al inicio/fin (trim) manualmente con `for`.

## Errores comunes
- No eliminar `\n` antes de concatenar.
- No reservar espacio para el espacio intermedio y `\0`.
- Usar `strcat` sin comprobar capacidad restante.

## Changelog
- 1.0 (2025-10-12): Versión inicial.
