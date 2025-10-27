---
title: Contar vocales en una línea
topic: Strings
subtopics: [strlen, tolower, for, conteos]
difficulty: easy
estimated_time: 15-20 minutos
prerequisites: ["00. Useful Functions/01-puts-strlen"]
learning_mode: guided
author: Curso C
version: 1.0
last_update: 2025-10-12
---

## Resumen
Lee una línea de texto y cuenta cuántas vocales contiene (a, e, i, o, u) sin distinguir mayúsculas/minúsculas. Practicarás índices con `for`, `strlen`, y normalización con `tolower`.

## Objetivos de aprendizaje
- Recorrer un string con `for` y conocer sus límites con `strlen`.
- Normalizar caracteres con `tolower`.
- Implementar un contador simple y claro.

## Enunciado
Implementa un programa que:
- Lea una línea desde `stdin` con `fgets` (máx. 200 caracteres sugerido).
- Imprima: `Vocales: N` seguido de `\n`, donde `N` es el total de vocales `a,e,i,o,u` presentes.

## Entrada
- Una sola línea de texto (puede estar vacía).

## Salida
- Una línea: `Vocales: <entero>` con salto de línea.

## Restricciones
- Usa `fgets` y elimina el `\n` final si existe.
- Recorre con `for` desde 0 hasta `strlen(cadena)`.
- No cuentes caracteres acentuados (á, é, í, ó, ú) en esta versión básica.

## Ejemplos
Ejemplo 1
Entrada:
```
Hola Mundo
```
Salida:
```
Vocales: 4
```

Ejemplo 2 (vacío)
Entrada:
```

```
Salida:
```
Vocales: 0
```

## Casos borde
- Cadena vacía.
- Solo consonantes y espacios.
- Todo en mayúsculas.

## Pistas (pasos guiados)
1. Lee con `fgets` y quita el `\n`.
2. Inicializa un contador a 0.
3. Recorre con `for (i = 0; i < strlen(s); i++)`.
4. Convierte `s[i]` a minúscula con `tolower` y compara contra `a,e,i,o,u`.

## Estructura requerida
```
02-contar-vocales/
  guided--easy.md
  src/main.c
  tests/test_input_01.txt
  tests/test_expected_01.txt
  respuestas/REFLEXION.md
```

## Rúbrica
| Criterio | Peso | Descripción |
|---|---|---|
| Corrección | 40% | Cuenta vocales correctamente |
| Seguridad | 15% | Lectura segura y `\0` |
| Claridad | 15% | Bucle claro y documentado |
| Adherencia | 15% | Formato exacto de salida |
| Casos borde | 10% | Manejo explícito |
| Reflexión | 5% | Completada |

## Reflexión
1. ¿Cómo cambiaría si agregas vocales acentuadas?
2. ¿Qué impacto tiene llamar `strlen` en cada iteración?

## Extensiones
- Soportar vocales acentuadas y diéresis.
- Ignorar dígitos y contar solo letras.

## Changelog
- 1.0 (2025-10-12): Versión inicial.
