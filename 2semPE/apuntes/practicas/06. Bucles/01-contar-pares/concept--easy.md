---
title: Contador de numeros pares en un rango
topic: Bucles
subtopics: [for, operadores comparativos, modularidad]
difficulty: easy
estimated_time: 20
prerequisites: [../00. Useful Functions/01-puts-strlen]
learning_mode: concept
author: Antonio Rodriguez
version: 1.0
last_update: 2025-10-22
---

## Panorama general
El ejercicio permite practicar el uso del bucle `for` para recorrer secuencias numericas y contar elementos que cumplen una condicion. Servira para reforzar el control de iteraciones finitas y el uso de operadores modulares en un contexto sencillo.

## Objetivos de aprendizaje
- Identificar la estructura general de un bucle `for` en C.
- Aplicar condiciones mediante el operador modulo para reconocer numeros pares.
- Implementar contadores que se actualizan de forma controlada dentro del ciclo.

## Contexto
Imagina que debes elaborar un reporte rapido de cuantos numeros pares existen dentro de un rango proporcionado por un sistema de monitoreo. Necesitas un ciclo que recorra todos los valores y registre los que cumplen la regla de paridad.

## Enunciado del problema
Debes escribir un programa en C que:
- Lea dos enteros `inicio` y `fin` tales que `inicio <= fin`.
- Use un bucle `for` para iterar desde `inicio` hasta `fin`, ambos inclusive.
- Cuente cuantas cifras del rango son pares.
- Imprima la cantidad total en la forma `Cantidad de pares: X` con salto de linea final.

## Especificacion de entrada
- Entrada desde `stdin`.
- Dos enteros con signo `inicio` y `fin` en una sola linea separados por un espacio.
- Rango valido: `-10000 <= inicio <= fin <= 10000`.

## Especificacion de salida
- Una linea con el texto `Cantidad de pares: X`, donde `X` es el numero de valores pares encontrados.
- La linea debe terminar con un salto de linea.

## Restricciones
- Complejidad temporal O(n) respecto al tamano del rango.
- Sin memoria dinamica.
- No modificar el orden de lectura de datos.
- No usar funciones de biblioteca adicionales distintas de `stdio.h`.

## Ejemplos
```
Ejemplo 1
Entrada:
1 10
Salida:
Cantidad de pares: 5

Ejemplo 2
Entrada:
-4 3
Salida:
Cantidad de pares: 4

Ejemplo 3 (Borde: rango unitario par)
Entrada:
6 6
Salida:
Cantidad de pares: 1
```

## Casos borde a considerar
- Rango donde `inicio` y `fin` son iguales.
- Rango que incluye negativos y positivos.
- Rango compuesto solo por impares (resultado 0).
- Rango amplio que cruza cero.

## Guia paso a paso
1. Identifica las variables de control: indice `i` para el ciclo y contador de pares.
2. Estructura el bucle `for` iniciando en `inicio`, condicion `i <= fin` y actualizacion `i++`.
3. Dentro del ciclo, usa `if (i % 2 == 0)` para actualizar el contador.
4. Al terminar el ciclo, imprime el resultado con el formato requerido.

## Estructura de carpetas requerida
```
01-contar-pares/
  concept--easy.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## Requisitos de codigo
- `main.c` debe contener toda la logica en funciones pequenas; si agregas funciones auxiliares, declara prototipos al inicio.
- Emplea nombres descriptivos (`contadorPares`, `inicio`, `fin`).
- Valida el resultado de `scanf`; si falla, muestra un mensaje de error y termina con `return 1`.

## Requisitos de documentacion
- Encabezado de archivo con proposito, autor y fecha.
- Comentario breve por funcion con proposito, parametros y retorno.

## Instrucciones de prueba
```
Compilacion:
  gcc -Wall -Wextra -std=c17 -O0 -o main src/main.c
Ejecucion manual:
  ./main < tests/test_input_01.txt
Verificacion rapida:
  diff -u tests/test_expected_01.txt output.txt (si rediriges la salida a un archivo)
```

## Rubrica de evaluacion
| Criterio | Peso | Descripcion |
|----------|------|-------------|
| Correccion | 40% | El conteo coincide con los casos proporcionados y adicionales |
| Seguridad de memoria | 15% | Sin accesos invalidos ni uso de memoria dinamica |
| Claridad de codigo | 15% | Nombres claros, estructura simple, comentarios minimos |
| Adherencia a la especificacion | 15% | Formato de salida y restricciones respetadas |
| Casos borde | 10% | Prueba e identifica resultados especiales |
| Reflexion | 5% | Respuestas completas en `respuestas/REFLEXION.md` |

## Preguntas de reflexion
1. Que estrategia usaste para garantizar que el contador se actualizara solo en numeros pares?
2. Que caso borde te obligo a revisar la logica de tu bucle?
3. Como documentaste el proposito de tu codigo?
4. Que mejoraras si tuvieras que admitir rangos mucho mas grandes?
5. Que concepto necesitas repasar para sentirte mas seguro con bucles `for`?

## Extensiones sugeridas
- Mostrar la lista completa de numeros pares antes del total.
- Permitir que el usuario elija si desea contar pares o impares.
- Adaptar el programa para contar multiplos de un valor configurable.

## Errores comunes
- Olvidar inicializar el contador en cero.
- Usar `i < fin` en lugar de `i <= fin` y omitir el ultimo valor.
- No validar el resultado de `scanf`.

## Glosario
- **Numero par**: entero divisible entre 2 sin residuo.
- **Bucle for**: estructura de control que permite iteraciones con inicializacion, condicion y actualizacion.

## Guia de control de versiones
1. Crea la carpeta del ejercicio y agrega archivos base.
2. Implementa la lectura de datos.
3. Agrega el contador y la logica del bucle.
4. Prueba con los casos proporcionados y registra resultados.
5. Documenta y limpia el codigo antes del commit final.

## Lista de calidad
- [ ] Compila sin advertencias con `-Wall -Wextra`.
- [ ] Salida exactamente igual a lo especificado.
- [ ] Comentarios y encabezados segun lo requerido.
- [ ] Casos borde probados y anotados.

## Changelog
- 1.0 (2025-10-22): Publicacion inicial.
