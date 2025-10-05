---
title: Lectura segura y longitud de cadena
topic: Funciones de E/S y cadenas
subtopics: [puts,fgets,strlen,buffer,seguridad]
difficulty: beginner
estimated_time: 20
prerequisites: ["Repaso de variables y arrays de chars"]
learning_mode: concept
author: Autor Curso C
version: 1.0
last_update: 2025-10-04
---

## 2. Descripción General
Este ejercicio introduce la lectura segura de texto desde stdin y la impresión formateada básica usando `fgets()` y `puts()`, además de calcular la longitud real de la cadena con `strlen()`. Refuerza buenas prácticas evitando el uso de la función obsoleta `gets()`.

## 3. Objetivos de Aprendizaje
- Utilizar `fgets()` para leer una línea limitando el tamaño y evitando desbordamientos.
- Emplear `puts()` para imprimir una cadena con salto de línea automático.
- Calcular la longitud de una cadena con `strlen()` ignorando el carácter nulo.
- Remover el `\n` final opcional leído por `fgets()` antes de medir longitud.

## 4. Contexto / Escenario
Imagina que desarrollas un prototipo de consola que pide al usuario ingresar un título corto y luego muestra el texto y su longitud exacta. Es esencial evitar errores comunes de seguridad ligados a entradas sin control.

## 5. Enunciado del Problema
Implementa un programa que:
- Lea una línea de texto (máximo 80 caracteres visibles) desde stdin usando `fgets()` en un buffer de 81 (para `\0`).
- Si la cadena contiene el salto de línea final `\n`, lo reemplace por `\0`.
- Imprima la cadena exactamente como fue ingresada (sin salto de línea extra agregado manualmente) usando `puts()`.
- Calcule la longitud de la cadena resultante con `strlen()` y la muestre en el formato: `Longitud: X` finalizando con `\n`.
- No debe usar `gets()`.

## 6. Especificación de Entrada
- Fuente: stdin.
- Se leerá una línea de texto ASCII (puede contener espacios) de hasta 80 caracteres visibles.
- Si el usuario ingresa más de 80 caracteres, `fgets()` truncará el resto (se acepta este comportamiento simple para este ejercicio).
- No se validan caracteres especiales; se aceptan tal cual.

## 7. Especificación de Salida
- Primera línea: la cadena ingresada (utilizando `puts()` la cual agrega `\n`).
- Segunda línea: `Longitud: N` donde N es un entero decimal (sin espacios extras). Termina con `\n`.

Formato exacto:
```
<texto_usuario>\n
Longitud: <numero>\n
```

## 8. Restricciones y Límites
- Buffer mínimo: 81 chars.
- Prohibido usar `gets()`.
- Complejidad temporal: O(n) donde n es la longitud de la línea.
- Memoria: uso estático del arreglo (no heap).
- No modificar el prototipo de `main` estándar.

## 9. Ejemplos
```
Ejemplo 1
Input:
Hola Mundo
Output:
Hola Mundo
Longitud: 10

Ejemplo 2 (Cadena vacía solo ENTER)
Input:
\n
Output:

Longitud: 0

Ejemplo 3 (Con espacios finales)
Input:
Hola  C
Output:
Hola  C
Longitud: 7
```

## 10. Casos Límite a Considerar
- Línea vacía (solo ENTER).
- Longitud exactamente 80 caracteres.
- Cadena que no incluye `\n` porque el usuario alcanzó el límite (fgets sin newline).
- Caracteres de espacio al inicio o al final.
- Mezcla de símbolos (no se valida ni filtra).

## 11. Pistas (Opcional)
1. Verifica con `strlen()` después de eliminar el `\n`.
2. Para eliminar `\n` puedes buscarlo con un recorrido simple o usar `strcspn` (opcional, aún no estudiado). Hazlo manual para reforzar comprensión.
3. Recuerda que `puts()` añade un salto de línea automáticamente.

## 12. Estructura de Carpetas Requerida
```
01-puts-strlen/
  concept--beginner.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## 13. Requisitos de Código / Estilo
- Identificadores descriptivos en inglés o español consistente.
- Sin números mágicos: define constante `#define MAX_LEN 80`.
- Funciones cortas y claras (si separas la lógica de limpieza y longitud, mejor).
- Comentar propósito del programa al inicio.

## 14. Requisitos de Documentación
Agregar en `main.c` comentario de cabecera: propósito, autor, fecha. Documentar cualquier función auxiliar (ej. `remove_newline`).

## 15. Instrucciones de Prueba
Compilar:
```
gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
```
Ejecutar manual:
```
./main
```
Prueba automática simple:
```
./main < tests/test_input_01.txt > output.txt
Diff:
Diff tests/test_expected_01.txt output.txt
```

## 16. Rúbrica de Evaluación
| Criterio | Peso | Descripción |
|----------|------|-------------|
| Correctitud | 40% | Longitud correcta y formato exacto |
| Seguridad E/S | 15% | Uso de `fgets` y no `gets` |
| Claridad Código | 15% | Legible y modular |
| Ajuste a Especificación | 15% | Cumple formato y restricciones |
| Casos Límite | 10% | Manejo correcto de vacío y truncado |
| Reflexión | 5% | Respuestas completas |

## 17. Reflexión (respuestas/REFLEXION.md)
1. ¿Qué riesgo evita `fgets()` comparado con `gets()`?
2. ¿Por qué es necesario eliminar `\n` antes de usar `strlen()` en este contexto?
3. ¿Qué pasaría si no defines `MAX_LEN` y usas números literales?
4. ¿Qué mejorarías si se necesitara soportar líneas más largas?
5. ¿Qué prueba adicional agregarías?

## 18. Extensiones Opcionales
- Contar cuántos caracteres son espacios.
- Mostrar también la longitud original antes de quitar `\n` (si existía).
- Limitar visualmente si se truncó (imprimir aviso si no se leyó `\n`).

## 19. Errores Comunes
- Olvidar reservar espacio para `\0`.
- No eliminar el `\n` y longitud queda +1.
- Usar `gets()` (prohibido).
- Añadir salto de línea extra manual tras `puts()`.

## 20. Glosario
- Buffer: área de memoria temporal para datos.
- Truncamiento: recorte de datos que sobrepasan el tamaño permitido.

## 21. Guía de Control de Versiones
1. Añadir estructura de carpetas.
2. Implementar lectura básica.
3. Eliminar `\n` y calcular longitud.
4. Añadir pruebas.
5. Refactor y comentarios.
6. Actualizar reflexión.

## 22. Checklist de Calidad
- [ ] Usa `fgets()`
- [ ] Elimina `\n` si existe
- [ ] Usa constante `MAX_LEN`
- [ ] Salida coincide con ejemplos
- [ ] Rúbrica incluida
- [ ] Reflexión creada

## 23. Mini Author Prompt
(Ver plantilla general del curso para reutilizar.)

## 24. Ejemplo Mínimo Resumido
```
Input: Hola\n
Output:
Hola
Longitud: 4
```

## 25. Tono y Lenguaje
Instrucciones técnicas directas, español neutro.

## 26. Accesibilidad
No se depende de colores; texto plano.

## 27. Notas de Mantenimiento
Actualizar si se introducen funciones de manipulación más avanzadas.

## 28. Changelog
- 1.0 (2025-10-04): Versión inicial.
