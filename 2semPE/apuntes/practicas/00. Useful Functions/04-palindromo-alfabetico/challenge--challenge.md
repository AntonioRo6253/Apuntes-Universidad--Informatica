---
title: Verificador de palíndromo alfabético robusto
topic: Manipulación y filtrado de caracteres
subtopics: [isalpha,tolower,normalizacion,punteros]
difficulty: challenge
estimated_time: 75
prerequisites: ["Frecuencias de letras", "Clasificación de caracteres"]
learning_mode: challenge
author: Autor Curso C
version: 1.0
last_update: 2025-10-04
---

## 2. Descripción General
Reto para construir un verificador de palíndromos que ignore todos los caracteres no alfabéticos y no distinga entre mayúsculas y minúsculas. Reforzarás normalización, recorrido dual y validación exhaustiva de entradas.

## 3. Objetivos de Aprendizaje
- Normalizar una cadena filtrando solo letras con `isalpha()`.
- Aplicar `tolower()` para comparar sin distinción de caso.
- Implementar verificación de palíndromo usando punteros o índices convergentes.
- Manejar espacios, símbolos y entrada vacía correctamente.

## 4. Contexto / Escenario
Necesitas una función modelo para un motor de búsqueda que identifique términos palindrómicos ignorando puntuación y variantes de capitalización. Este módulo debe ser fiable y fácil de extender.

## 5. Enunciado del Problema
Implementa un programa que:
- Lea una línea desde stdin (máximo 200 caracteres visibles) con `fgets()`.
- Elimine `\n` final si existe.
- Construya una cadena filtrada que contenga solo letras (a-z, A-Z) convertidas todas a minúsculas.
- Determine si la cadena filtrada es palíndromo.
- Imprima exactamente:
  - `SI` si es palíndromo (cadena filtrada de longitud > 0 y palíndroma)
  - `NO` en caso contrario.

## 6. Especificación de Entrada
- Fuente: stdin.
- Una sola línea ASCII (puede contener espacios, dígitos, símbolos) hasta 200 caracteres.
- Si supera 200 visibles se trunca (simple, sin manejo especial adicional).

## 7. Especificación de Salida
- Única línea: `SI` o `NO` seguida de `\n`.

## 8. Restricciones y Límites
- `#define MAX_LEN 200` (buffer de lectura >= 201).
- No usar memoria dinámica.
- Complejidad O(n) sobre longitud filtrada.
- Prohibido `gets()`.
- No usar recursión.

## 9. Ejemplos
```
Ejemplo 1
Input:
Anita lava la tina
Output:
SI

Ejemplo 2 (Con símbolos)
Input:
A!b@b#a
Output:
SI

Ejemplo 3 (No palíndromo)
Input:
Hola Mundo
Output:
NO

Ejemplo 4 (Solo símbolos)
Input:
***
Output:
NO
```

## 10. Casos Límite a Considerar
- Solo símbolos (filtrado resulta longitud 0).
- Un solo carácter alfabético.
- Longitud máxima (200) sin `\n`.
- Mixto letras con acentos (los acentos no se contemplan: se ignorarán al no ser isalpha si el entorno no es locale extendido).

## 11. Pistas (Opcional, último recurso)
1. Construye la versión filtrada y normalizada primero.
2. Usa dos índices: inicio y fin; avanza hasta que se crucen.
3. Si algún par no coincide => `NO` inmediato.
4. Vacío o longitud 0 filtrada => `NO`.

## 12. Estructura de Carpetas Requerida
```
04-palindromo-alfabetico/
  challenge--challenge.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## 13. Requisitos de Código / Estilo
- Función sugerida: `int es_palindromo(const char *normalizada);`
- Separar lógica: lectura, normalización, verificación.
- Variables claras y sin abreviaturas crípticas.

## 14. Requisitos de Documentación
- Documentar función de normalización y verificación.
- Comentar decisiones clave (e.g., criterio para vacío).

## 15. Instrucciones de Prueba
Compilación:
```
gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
```
Ejecución ejemplo:
```
./main < tests/test_input_01.txt
```
Comparación:
```
diff -u tests/test_expected_01.txt output.txt
```

## 16. Rúbrica de Evaluación
| Criterio | Peso | Descripción |
|----------|------|-------------|
| Correctitud | 40% | Detección exacta palíndromo |
| Normalización | 15% | Filtrado/tolower correcto |
| Eficiencia | 10% | Una sola pasada de comparación |
| Claridad | 10% | Código modular y documentado |
| Casos Límite | 15% | Maneja vacío, símbolos, extremos |
| Reflexión | 10% | Análisis crítico respuestas |

## 17. Reflexión (respuestas/REFLEXION.md)
1. ¿Por qué se descarta la cadena vacía como palíndromo aquí?
2. ¿Cómo soportarías letras con acentos?
3. ¿Podrías evitar crear un buffer adicional? ¿Pros/Contras?
4. ¿Qué prueba adicional agregarías?
5. ¿Cómo extenderlo a múltiples líneas?

## 18. Extensiones Opcionales
- Aceptar múltiples líneas y reportar cuántas son palíndromos.
- Ignorar números pero contarlos en un estadístico aparte.
- Implementar versión in-place sin segundo buffer.

## 19. Errores Comunes
- Olvidar terminar la cadena normalizada con `\0`.
- Considerar símbolos como parte de la validación.
- Aceptar cadena vacía como palíndromo sin criterio explícito.

## 20. Glosario
- Palíndromo: secuencia que se lee igual de izquierda a derecha y viceversa.
- Normalización: proceso de convertir entrada a formato estándar.

## 21. Guía de Control de Versiones
1. Crear esqueletos.
2. Implementar normalización.
3. Implementar verificación doble índice.
4. Probar casos representativos.
5. Refactor comentarios.
6. Añadir reflexión.

## 22. Checklist de Calidad
- [ ] No usa `gets()`
- [ ] Filtra solo letras
- [ ] Usa `tolower()` correctamente
- [ ] Rechaza vacío
- [ ] Formato salida exacto
- [ ] Reflexión lista

## 23. Mini Author Prompt
Ver plantilla global.

## 24. Ejemplo Mínimo Resumido
```
Input: Aa\n
Output:
SI
```

## 25. Tono y Lenguaje
Técnico y conciso.

## 26. Accesibilidad
Salida clara sin dependencias visuales.

## 27. Notas de Mantenimiento
Posible internacionalización futura.

## 28. Changelog
- 1.0 (2025-10-04): Versión inicial.
