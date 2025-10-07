---
title: Clasificador y normalizador de caracteres
topic: Manejo de caracteres (ctype.h)
subtopics: [isdigit,isalpha,tolower,toupper,conteo]
difficulty: medium
estimated_time: 35
prerequisites: ["Lectura segura de cadenas", "Uso básico de arrays"]
learning_mode: guided
author: Autor Curso C
version: 1.0
last_update: 2025-10-04
---

## 2. Descripción General
Este ejercicio profundiza en el análisis de cada carácter de una cadena utilizando funciones de la librería `<ctype.h>` para clasificar y transformar. Practicarás distinguir dígitos, letras y otros símbolos, y generar versiones normalizadas de la entrada.

## 3. Objetivos de Aprendizaje
- Aplicar `isalpha()` e `isdigit()` para clasificar caracteres.
- Transformar letras a minúsculas y mayúsculas con `tolower()` y `toupper()`.
- Contabilizar categorías (letras, dígitos, otros) de forma robusta.
- Construir cadenas derivadas normalizadas sin modificar el buffer original.

## 4. Contexto / Escenario
Se requiere un módulo para limpiar y reportar características básicas de un texto antes de procesarlo en un sistema mayor (e.g., tokenización, validación de formularios o análisis simple).

## 5. Enunciado del Problema
Implementa un programa que:
- Lea una línea desde stdin (máximo 120 caracteres visibles) con `fgets()` en un buffer de 121.
- Elimine `\n` final si existe.
- Recorra cada carácter y:
  - Cuente cuántos son letras (isalpha), cuántos dígitos (isdigit), y cuántos son otros caracteres.
  - Genere dos nuevas cadenas: una versión totalmente en minúsculas (solo letras afectadas) y otra totalmente en mayúsculas.
- Imprima en el formato exacto descrito en la sección de salida.

## 6. Especificación de Entrada
- Fuente: stdin.
- Línea ASCII arbitraria, hasta 120 caracteres.
- No se valida UTF-8 extendido (asumir ASCII simple).

## 7. Especificación de Salida
Debe imprimirse exactamente:
```
Original: <cadena_original>
Minuscula: <cadena_minusculas>
Mayuscula: <cadena_mayusculas>
Letras: <L> Digitos: <D> Otros: <O>\n
```
Cada etiqueta inicia con mayúscula tal como se muestra. Fin de línea al final de cada renglón.

## 8. Restricciones y Límites
- Complejidad O(n).
- Prohibido usar `gets()`.
- No modificar el buffer original al construir las variantes (usar arrays separados).
- Evitar funciones no vistas aún (no usar `strtok`, etc.).

## 9. Ejemplos
```
Ejemplo 1
Input:
Hola123!
Output:
Original: Hola123!
Minuscula: hola123!
Mayuscula: HOLA123!
Letras: 4 Digitos: 3 Otros: 1

Ejemplo 2 (Solo símbolos)
Input:
***
Output:
Original: ***
Minuscula: ***
Mayuscula: ***
Letras: 0 Digitos: 0 Otros: 3

Ejemplo 3 (Vacío)
Input:
\n
Output:
Original: 
Minuscula: 
Mayuscula: 
Letras: 0 Digitos: 0 Otros: 0
```

## 10. Casos Límite a Considerar
- Cadena vacía.
- Longitud 120 sin `\n` (truncado).
- Mezcla intensa de letras/dígitos/símbolos.
- Solo dígitos.
- Solo espacios (espacios cuentan como otros).

## 11. Pistas Guiadas
1. Crea tres contadores inicializados a 0.
2. Al iterar: primero verifica `isalpha`, luego `isdigit`, de lo contrario incrementa "otros".
3. Para construir minúsculas y mayúsculas, copia carácter a carácter aplicando `tolower` / `toupper` solo si es letra.
4. Asegura terminar las dos cadenas nuevas con `\0`.

## 12. Estructura de Carpetas Requerida
```
02-clasificacion-caracteres/
  guided--medium.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## 13. Requisitos de Código / Estilo
- Usar `#define MAX_LEN 120`.
- Función auxiliar recomendada: `void build_cases(const char *src, char *lower, char *upper);`
- No repetir lógica de clasificación: haz una sola pasada si es posible.

## 14. Requisitos de Documentación
- Documentar función auxiliar con Doxygen.
- Comentario de archivo con propósito general.

## 15. Instrucciones de Prueba
Compilar:
```
gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
```
Prueba:
```
./main < tests/test_input_01.txt > output.txt
diff -u tests/test_expected_01.txt output.txt
```

## 16. Rúbrica de Evaluación
| Criterio | Peso | Descripción |
|----------|------|-------------|
| Correctitud | 40% | Conteos y transformaciones exactas |
| Eficiencia | 10% | Una sola pasada principal |
| Claridad | 15% | Código legible y modular |
| Especificación | 15% | Formato estricto |
| Casos Límite | 10% | Manejo de vacío y truncado |
| Reflexión | 10% | Profundidad en respuestas |

## 17. Reflexión (respuestas/REFLEXION.md)
1. ¿Por qué conviene una sola pasada para clasificar y construir?
2. ¿Qué limitaciones tendría con caracteres no ASCII?
3. ¿Qué cambio harías para ignorar espacios en los conteos?
4. ¿Qué caso te causó más dudas?
5. ¿Cómo detectarías truncamiento?

## 18. Extensiones Opcionales
- Detectar si la cadena es alfanumérica pura.
- Contar vocales y consonantes por separado.
- Normalizar espacios múltiples a uno.

## 19. Errores Comunes
- Olvidar finalizar las cadenas derivadas con `\0`.
- Intercambiar los conteos de dígitos/letras.
- Doble recorrido innecesario (no penaliza severo pero reduce eficiencia).

## 20. Glosario
- Alfanumérico: compuesto solo por letras y dígitos.
- Normalización: proceso de convertir datos a una forma estándar.

## 21. Guía de Control de Versiones
1. Crear estructura y prototipo.
2. Implementar lectura + eliminación de `\n`.
3. Añadir clasificación y transformaciones.
4. Probar casos básicos.
5. Refactor y comentar.
6. Agregar reflexión.

## 22. Checklist de Calidad
- [ ] Usa `fgets()`
- [ ] Una sola pasada (ideal)
- [ ] Cadenas minúscula y mayúscula correctas
- [ ] Conteos correctos
- [ ] Formato coincide
- [ ] Reflexión creada

## 23. Mini Author Prompt
Consultar plantilla global.

## 24. Ejemplo Mínimo Resumido
```
Input: A9\n
Output:
Original: A9
Minuscula: a9
Mayuscula: A9
Letras: 1 Digitos: 1 Otros: 0
```

## 25. Tono y Lenguaje
Técnico claro.

## 26. Accesibilidad
Solo texto; salida estructurada.

## 27. Notas de Mantenimiento
Ampliar si se introduce soporte UTF-8.

## 28. Changelog
- 1.0 (2025-10-04): Versión inicial.
