---
title: Invertir una cadena (iterativo)
topic: Strings
subtopics: [for, índices, intercambio, terminador nulo]
difficulty: easy
estimated_time: 15-20 minutos
prerequisites: ["00. Useful Functions/01-puts-strlen", "02-clasificacion-caracteres"]
learning_mode: concept
author: Curso C
version: 1.0
last_update: 2025-10-12
---

## Resumen
Lee una línea y escribe su inversión (caracter por caracter), respetando espacios y puntuación. Practicarás manejo de índices con `for` y swaps básicos.

## Objetivos
- Calcular longitud con `strlen` y recorrer extremos hacia el centro con `for`.
- Intercambiar caracteres en un buffer mutable.
- Mantener el `\0` y evitar accesos fuera de rango.

## Enunciado
Implementa un programa que:
- Lea una línea con `fgets` y quite el `\n` final.
- Invierta la cadena in-place.
- Imprima: `Invertida: <cadena_invertida>` seguido de `\n`.

## Entrada
- Una línea (puede ser vacía).

## Salida
- `Invertida: <texto>` con salto de línea.

## Ejemplos
Entrada:
```
Hola
```
Salida:
```
Invertida: aloH
```

Entrada:
```
radar
```
Salida:
```
Invertida: radar
```

## Casos borde
- Cadena vacía.
- Un solo carácter.
- Longitudes pares e impares.

## Estructura requerida
```
03-invertir-cadena/
  concept--easy.md
  src/main.c
  tests/test_input_01.txt
  tests/test_expected_01.txt
  respuestas/REFLEXION.md
```

## Rúbrica
| Criterio | Peso | Descripción |
|---|---|---|
| Corrección | 40% | Invierte correctamente |
| Seguridad | 15% | Lectura segura, sin desbordes |
| Claridad | 15% | Bucle y swaps claros |
| Adherencia | 15% | Formato de salida exacto |
| Casos borde | 10% | Considerados |
| Reflexión | 5% | Respondida |

## Reflexión
1. ¿Por qué solo se itera hasta la mitad de la longitud?
2. ¿Qué cambia si en vez de in-place usas un segundo buffer?

## Extensiones
- Crear una versión que ignore espacios al invertir.
- Aceptar múltiples líneas hasta EOF.

## Changelog
- 1.0 (2025-10-12): Versión inicial.
