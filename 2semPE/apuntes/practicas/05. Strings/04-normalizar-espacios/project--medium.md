---
title: Normalizar espacios en una frase
topic: Strings
subtopics: [for, índices, trim, colapsar espacios, buffers, strlen]
difficulty: medium
estimated_time: 25-35 minutos
prerequisites: ["02-clasificacion-caracteres", "03-analizador-texto"]
learning_mode: project
author: Curso C
version: 1.0
last_update: 2025-10-12
---

## Resumen
Dados textos que pueden tener espacios extra al inicio, al final, y múltiples espacios intermedios, escribe un programa que los "normalice" dejando exactamente un solo espacio entre palabras y eliminando espacios sobrantes.

## Objetivos de aprendizaje
- Implementar recorrido con dos índices (lectura y escritura) usando `for` o `while`.
- Eliminar espacios iniciales y finales (trim) manualmente.
- Colapsar secuencias de espacios internos a uno solo.

## Contexto
Limpieza de entrada de usuario antes de almacenar o comparar strings.

## Enunciado (requisitos)
Escribe un programa que:
- Lea una línea con `fgets` (máx. 200 caracteres sugeridos) y elimine `\n`.
- Remueva espacios al inicio y al final.
- Reemplace cualquier cantidad de espacios consecutivos internos por un único espacio.
- Imprima exactamente: `Normalizado: <texto>` seguido de `\n`.

## Entrada
- Una línea (puede estar vacía o con solo espacios).

## Salida
- `Normalizado: <texto>` con salto de línea.

## Restricciones
- No usar funciones específicas de trimming de bibliotecas externas.
- Usar solo `for`/`while`, `strlen`, `ctype.h` opcional.
- Mantener `\0` y evitar desbordes.

## Ejemplos
Ejemplo 1
Entrada:
```
   Hola    mundo   
```
Salida:
```
Normalizado: Hola mundo
```

Ejemplo 2 (solo espacios)
Entrada:
```
     
```
Salida:
```
Normalizado: 
```

Ejemplo 3 (sin espacios extra)
Entrada:
```
C en 2025
```
Salida:
```
Normalizado: C en 2025
```

## Casos borde
- Cadena vacía.
- Un solo carácter no espacio.
- Cadena con tabs (opcional: tratarlos como no-espacios por simplicidad en esta versión).

## Pistas (progresivas)
1. Encuentra el primer índice no espacio y el último no espacio.
2. Recorre del primero al último copiando a un buffer destino.
3. Copia un solo espacio cuando detectes transición de múltiples espacios a un carácter no espacio.

## Estructura requerida
```
04-normalizar-espacios/
  project--medium.md
  src/main.c
  tests/test_input_01.txt
  tests/test_expected_01.txt
  respuestas/REFLEXION.md
```

## Rúbrica
| Criterio | Peso | Descripción |
|---|---|---|
| Corrección | 40% | Trim y colapso correctos |
| Seguridad | 15% | Sin desbordes, `\0` asegurado |
| Claridad | 15% | Algoritmo con índices legibles |
| Adherencia | 15% | Formato exacto de salida |
| Casos borde | 10% | Considerados |
| Reflexión | 5% | Respondida |

## Reflexión
1. ¿Qué variaría si consideras tabs `\t` como espacios?
2. ¿Cómo evitarías múltiples llamadas a `strlen` dentro del bucle?

## Extensiones
- Tratar cualquier `isspace` como espacio.
- Preservar mayúsculas/minúsculas y colapsar también tabs.

## Changelog
- 1.0 (2025-10-12): Versión inicial.
