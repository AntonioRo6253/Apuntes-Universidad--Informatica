---
title: Generador de tabla de multiplicar con formato
topic: Bucles
subtopics: [for anidado, formato de salida, aritmetica]
difficulty: medium
estimated_time: 40
prerequisites: [../06. Bucles/01-contar-pares]
learning_mode: project
author: Antonio Rodriguez
version: 1.0
last_update: 2025-10-22
---

## Panorama general
Construiras una herramienta de consola que genere tablas de multiplicar alineadas, usando bucles `for` anidados. Practicaras el control de ciclos dobles y la preparacion de salidas tabulares.

## Objetivos de aprendizaje
- Dominar la configuracion de bucles `for` anidados con indices independientes.
- Formatear salidas numericas con anchuras constantes usando `printf`.
- Implementar validaciones previas para asegurar limites correctos.

## Contexto
Un profesor desea imprimir tablas de multiplicar personalizadas para sus estudiantes. Necesita especificar hasta que numero se generaran las multiplicaciones y que subconjunto de filas mostrar.

## Enunciado del problema
Desarrolla un programa en C que:
- Lea tres enteros `tabla_min`, `tabla_max` y `limite`.
- Valide que `1 <= tabla_min <= tabla_max <= 12` y que `1 <= limite <= 20`.
- Para cada tabla desde `tabla_min` hasta `tabla_max`, genere una fila con las multiplicaciones `tabla x 1` hasta `tabla x limite`.
- Formatee cada numero usando tres espacios de anchura (`%3d`).
- Imprima una linea separadora compuesta por guiones entre cada tabla.
- Salte una linea en blanco al finalizar cada tabla.
- Si la validacion falla, imprima `Datos invalidos` y termine con codigo de salida `1`.

## Especificacion de entrada
- Entrada desde `stdin`.
- Una linea con tres enteros separados por espacio: `tabla_min tabla_max limite`.
- Rango permitido: `1 <= tabla_min <= tabla_max <= 12`, `1 <= limite <= 20`.

## Especificacion de salida
- Para cada tabla `t`:
  - Linea de encabezado: `Tabla t`.
  - Linea de guiones del mismo ancho que la fila de datos (usa `-` repetido).
  - Linea con los productos formateados, separados por un espacio.
  - Linea en blanco.
- Si los datos son invalidos, solo imprime `Datos invalidos` con salto de linea.

## Restricciones
- Complejidad O(n * m) respecto al numero de tablas y limite.
- Usa exclusivamente bucles `for` para recorrer filas y columnas.
- No emplees arreglos; imprime cada resultado directamente.
- Evita funciones de librerias adicionales a `stdio.h`.

## Ejemplos
```
Ejemplo 1
Entrada:
2 3 4
Salida:
Tabla 2
---------------
  2   4   6   8

Tabla 3
Tabla 3
---------------
  3   6   9  12

Ejemplo 2
Entrada:
5 5 6
Salida:
Tabla 5
-----------------------
  5  10  15  20  25  30

Ejemplo 3 (Datos invalidos)
Entrada:
0 4 5
Salida:
Datos invalidos
```

## Casos borde a considerar
- `tabla_min` igual a `tabla_max`.
- `limite` al valor maximo (20) para revisar el ancho de guiones.
- Valor de `tabla_min` o `tabla_max` fuera de rango.
- Orden incorrecto (min mayor que max).

## Guia paso a paso
1. Lee los tres valores y valida las condiciones solicitadas.
2. Determina el ancho de la linea separadora: `(limite * 4)` guiones cubren el espacio (`%3d` + un espacio).
3. Usa un `for` externo para iterar las tablas.
4. Dentro, imprime el encabezado y la linea de guiones.
5. Emplea un `for` interno para generar cada producto con `printf("%3d ", resultado)`.
6. Tras el ciclo interno, imprime dos saltos de linea.

## Estructura de carpetas requerida
```
03-tabla-multiplicar/
  project--medium.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## Requisitos de codigo
- Crea funciones auxiliares si es necesario (ej. para imprimir la linea de guiones).
- Valida la entrada antes de iniciar cualquier bucle.
- Usa constantes simbolicas para el maximo de tablas y limite.

## Requisitos de documentacion
- Encabezado con proposito, autor y fecha en `main.c`.
- Comentarios Doxygen para funciones auxiliares.

## Instrucciones de prueba
```
Compilacion:
  gcc -Wall -Wextra -std=c17 -O0 -o tablas src/main.c
Ejecucion:
  ./tablas < tests/test_input_01.txt
Verificacion:
  diff -u tests/test_expected_01.txt output.txt
```

## Rubrica de evaluacion
| Criterio | Peso | Descripcion |
|----------|------|-------------|
| Correccion | 40% | Resultados numericos y formato alineado |
| Seguridad de memoria | 15% | Sin accesos fuera de rango ni variables sin inicializar |
| Claridad de codigo | 15% | Uso adecuado de funciones y nombres descriptivos |
| Adherencia a la especificacion | 15% | Validaciones y formato exacto |
| Casos borde | 10% | Consideracion explicita de limites y errores |
| Reflexion | 5% | Preguntas respondidas en `respuestas/REFLEXION.md` |

## Preguntas de reflexion
1. ¿Como definiste el numero de guiones de cada separador?
2. ¿Que decision tomaste para evitar arreglos temporales?
3. ¿Que parte del formato fue mas dificil de alinear?
4. ¿Que pruebas adicionales agregarias para tablar limites grandes?
5. ¿Que concepto deberias repasar sobre bucles anidados?

## Extensiones sugeridas
- Agrega una columna al inicio con el factor (1..limite).
- Permite elegir si se imprime en filas o columnas intercambiadas.
- Exporta la salida a un archivo de texto.

## Errores comunes
- Olvidar validar que `tabla_min <= tabla_max`.
- No dejar un espacio despues de cada numero y romper la alineacion.
- Reutilizar una variable de control en ambos bucles por accidente.

## Glosario
- **Bucle anidado**: bucle que se ejecuta dentro de otro bucle, permitiendo recorrer estructuras bidimensionales.
- **Ancho fijo**: numero constante de caracteres que ocupa un campo en la impresion formateada.

## Guia de control de versiones
1. Crear archivos y escribir validaciones de entrada.
2. Implementar el ciclo externo y mostrador de encabezado.
3. Agregar el ciclo interno y formateo de productos.
4. Integrar la linea separadora y los saltos de linea.
5. Probar, revisar formato y documentar.

## Lista de calidad
- [ ] Validaciones cubren todos los casos fuera de rango.
- [ ] Salida coincide con los ejemplos (incluye separadores y espacios).
- [ ] Compila sin advertencias con `-Wall -Wextra`.
- [ ] Codigo comentado y organizado.

## Changelog
- 1.0 (2025-10-22): Publicacion inicial.
