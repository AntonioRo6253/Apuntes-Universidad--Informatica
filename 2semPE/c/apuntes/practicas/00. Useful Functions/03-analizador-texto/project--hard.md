---
title: Analizador estadístico de texto multi-línea
topic: Procesamiento básico de texto
subtopics: [conteo,frecuencias,isalpha,isdigit,tolower,normalizacion]
difficulty: hard
estimated_time: 60
prerequisites: ["Clasificación de caracteres", "Arreglos y funciones" ]
learning_mode: project
author: Autor Curso C
version: 1.0
last_update: 2025-10-04
---

## 2. Descripción General
Desarrollarás un analizador que lea múltiples líneas hasta EOF y produzca estadísticas sobre el contenido: total de líneas, caracteres, letras, dígitos, otros símbolos y frecuencia de cada letra (ignorando mayúsculas/minúsculas). Reforzarás modularización y diseño limpio.

## 3. Objetivos de Aprendizaje
- Dividir un problema de análisis de texto en funciones cohesivas.
- Usar `isalpha()`, `isdigit()`, `tolower()` para conteos normalizados.
- Acumular frecuencias de letras sin importar el caso.
- Detectar líneas vacías y manejar tamaños variables con lectura segura.
- Formatear salidas tabulares de manera determinista.

## 4. Contexto / Escenario
Este módulo podría ser un primer paso de un pipeline de indexación o preprocesamiento antes de análisis más complejos (tokenización, ranking, etc.). Necesitas resultados reproducibles y claros para validación manual.

## 5. Enunciado del Problema
Implementa un programa que:
- Lea cero o más líneas desde stdin hasta EOF usando `fgets()` con buffer >= 256 (define `#define MAX_LINE 255`).
- Por cada línea leída (incluya vacías):
  - Incrementa contador de líneas.
  - Procesa cada carácter contabilizando: letras, dígitos, otros.
  - Para letras: conviértelas a minúscula y acumula frecuencia en un arreglo de 26 posiciones (`freq['a'..'z']`). Ignora cualquier carácter no ASCII alfabético.
- Lleva también un conteo total de caracteres procesados (excluye el `\n` si se elimina, pero incluye espacios y símbolos visibles).
- Al final imprime el reporte EXACTO descrito en salida.

## 6. Especificación de Entrada
- Fuente: stdin redirigido desde archivo o interacción.
- Conjunto de líneas ASCII, cada una hasta 255 caracteres visibles (el resto se ignora/trunca). EOF termina la lectura.
- No se asume número máximo de líneas (solo limitado por el flujo proporcionado).

## 7. Especificación de Salida
Imprimir exactamente:
```
Lineas: <L>\n
Caracteres: <C>\n
Letras: <A> Digitos: <D> Otros: <O>\n
Frecuencias:\n
<fila_1>\n
<fila_2>\n
...
```
Donde las filas de frecuencias listan letras en orden `a` a `z` con formato:
```
a: <fa>
b: <fb>
...
z: <fz>
```
Cada línea termina con `\n`. No imprimir texto adicional.

## 8. Restricciones y Límites
- Sin uso de memoria dinámica (`malloc`) en esta versión.
- Complejidad temporal: O(T) donde T = total de caracteres leídos.
- Prohibido `gets()`.
- Se permite múltiples pasadas por línea si justificado, pero preferible una sola.

## 9. Ejemplos
```
Ejemplo 1
Input:
Hola\n
123\n
!\n
Output:
Lineas: 3
Caracteres: 8
Letras: 4 Digitos: 3 Otros: 1
Frecuencias:
a: 1
b: 0
c: 0
d: 0
e: 0
f: 0
g: 0
h: 1
i: 0
j: 0
k: 0
l: 1
m: 0
n: 0
o: 1
p: 0
q: 0
r: 0
s: 0
t: 0
u: 0
v: 0
w: 0
x: 0
y: 0
z: 0

Ejemplo 2 (Vacío)
Input:
<EOF inmediato>
Output:
Lineas: 0
Caracteres: 0
Letras: 0 Digitos: 0 Otros: 0
Frecuencias:
a: 0
b: 0
c: 0
d: 0
e: 0
f: 0
g: 0
h: 0
i: 0
j: 0
k: 0
l: 0
m: 0
n: 0
o: 0
p: 0
q: 0
r: 0
s: 0
t: 0
u: 0
v: 0
w: 0
x: 0
y: 0
z: 0
```

## 10. Casos Límite a Considerar
- Entrada vacía (EOF inmediato).
- Línea exactamente de longitud máxima sin `\n`.
- Solo símbolos.
- Texto mixto con mayúsculas/minúsculas.
- Carácter no alfabético entre letras (no se cuenta como letra).

## 11. Pistas / Guía
1. Inicializa el arreglo de frecuencias en 0 al inicio.
2. Elimina el `\n` solo si está presente al final (para no contar un carácter que no se considera visible).
3. `tolower()` antes de mapear: índice = `tolower(c) - 'a'`.
4. Crea funciones: `process_line`, `print_report` para claridad.
5. Revisa cuidadosamente los cumulativos antes de imprimir.

## 12. Estructura de Carpetas Requerida
```
03-analizador-texto/
  project--hard.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## 13. Requisitos de Código / Estilo
- Definir constantes: `MAX_LINE`, `ALPHABET = 26`.
- No lógica dentro de `main` más allá de orquestación.
- Sin duplicar lógica de conteo.

## 14. Requisitos de Documentación
Documentar cada función: parámetros, efectos, precondiciones.

## 15. Instrucciones de Prueba
Compilación:
```
gcc -Wall -Wextra -std=c11 -O2 -o main src/*.c
```
Ejecución:
```
./main < tests/test_input_01.txt > output.txt
diff -u tests/test_expected_01.txt output.txt
```

## 16. Rúbrica de Evaluación
| Criterio | Peso | Descripción |
|----------|------|-------------|
| Correctitud | 35% | Estadísticas y frecuencias exactas |
| Modularidad | 15% | Funciones bien separadas |
| Eficiencia | 10% | Procesamiento lineal |
| Claridad | 10% | Código legible/documentado |
| Manejo Casos Límite | 15% | Vacío, truncado, símbolos |
| Especificación | 10% | Formato estricto salida |
| Reflexión | 5% | Profundidad de análisis |

## 17. Reflexión (respuestas/REFLEXION.md)
1. ¿Cómo validarías el conteo de caracteres con pruebas adicionales?
2. ¿Qué cambio harías para soportar Unicode básico?
3. ¿Dónde centralizaste la lógica de clasificación y por qué?
4. ¿Cómo detectarías líneas truncadas?
5. ¿Qué refactor harías si creciera a 1 millón de líneas?

## 18. Extensiones Opcionales
- Calcular la letra más frecuente y porcentaje.
- Imprimir histograma horizontal simple.
- Incluir conteo de espacios en blanco por separado.

## 19. Errores Comunes
- No reiniciar buffer antes de reutilizar (aunque no siempre necesario si se sobrescribe). 
- Contar `\n` como carácter visible.
- Acceder fuera de rango en el arreglo de frecuencias.

## 20. Glosario
- EOF: End Of File, condición de fin de entrada.
- Frecuencia: número de apariciones de un ítem.

## 21. Guía de Control de Versiones
1. Crear esqueletos de funciones.
2. Implementar lectura loop.
3. Procesar línea y acumular.
4. Imprimir reporte.
5. Validar casos básicos.
6. Refactor final.

## 22. Checklist de Calidad
- [ ] No usa `gets()`
- [ ] Frecuencias alineadas a a..z
- [ ] No cuenta `\n`
- [ ] Módulos/funciones separadas
- [ ] Formato coincide ejemplos
- [ ] Reflexión preparada

## 23. Mini Author Prompt
Ver plantilla general.

## 24. Ejemplo Mínimo Resumido
```
Input: aA\n
Output:
Lineas: 1
Caracteres: 2
Letras: 2 Digitos: 0 Otros: 0
Frecuencias:
a: 2
b: 0
... (resto 0)
```

## 25. Tono y Lenguaje
Técnico, directo.

## 26. Accesibilidad
Reporte textual simple.

## 27. Notas de Mantenimiento
Posible futura refactorización a estructura de datos dinámica.

## 28. Changelog
- 1.0 (2025-10-04): Versión inicial.
