---
title: Registro de consumo energetico con do-while sentinela
topic: Bucles
subtopics: [do-while, acumuladores, valores centinela]
difficulty: medium
estimated_time: 45
prerequisites: [../06. Bucles/02-menu-validado]
learning_mode: guided
author: Antonio Rodriguez
version: 1.0
last_update: 2025-10-22
---

## Panorama general
Implementaras un ciclo `do-while` que recopila consumos energeticos diarios hasta que el usuario ingresa un valor centinela negativo. Practicaras el uso de acumuladores, validaciones y calculo de promedios en una interaccion repetitiva.

## Objetivos de aprendizaje
- Diseñar un flujo repetitivo basado en un valor centinela.
- Controlar acumuladores y contadores para calcular estadisticos basicos.
- Validar entradas y responder con mensajes adecuados al usuario.

## Contexto
Una empresa monitorea el consumo energetico de sus oficinas y debe capturar los kilovatios hora (kWh) diarios hasta que se ingrese un valor negativo para terminar el registro. Se requiere reportar el total, el promedio y el dia con mayor consumo.

## Enunciado del problema
Construye un programa en C que:
- Muestre instrucciones iniciales para el usuario.
- Utilice un bucle `do-while` para leer valores de consumo (enteros no negativos) dia por dia.
- Termine la captura cuando se ingrese un valor negativo.
- Ignore valores superiores a 10000, mostrando "Dato fuera de rango" y repitiendo la iteracion del dia actual.
- Lleve la cuenta del total acumulado, la cantidad de dias validos y el valor maximo registrado.
- Al finalizar, si se capturaron datos validos, imprima:
  - `Dias registrados: X`
  - `Consumo total: Y kWh`
  - `Promedio diario: Z.ZZ kWh`
  - `Maximo diario: W kWh`
- Si no se capturo ningun dia valido, muestre `Sin datos para reportar`.

## Especificacion de entrada
- Entrada desde `stdin`.
- Un valor entero por linea.
- Valores permitidos: `0 <= consumo <= 10000`; el valor negativo termina el ciclo.

## Especificacion de salida
- Mensaje inicial: `Ingrese consumos diarios en kWh (valor negativo para terminar).`
- Para cada valor fuera de rango (>10000): `Dato fuera de rango`.
- Al finalizar con datos validos, muestra las cuatro lineas de reporte, cada una con salto de linea.
- El promedio debe mostrarse con dos decimales usando `printf("%.2f", promedio)`.

## Restricciones
- Usa un unico bucle `do-while` para la captura principal.
- No utilices arreglos ni listas; todo se calcula durante la lectura.
- Las variables deben inicializarse antes del bucle.

## Ejemplos
```
Ejemplo 1
Entrada:
120
95
-1
Salida:
Ingrese consumos diarios en kWh (valor negativo para terminar).
Dias registrados: 2
Consumo total: 215 kWh
Promedio diario: 107.50 kWh
Maximo diario: 120 kWh

Ejemplo 2
Entrada:
15000
300
-5
Salida:
Ingrese consumos diarios en kWh (valor negativo para terminar).
Dato fuera de rango
Dato fuera de rango

Ejemplo 3
Entrada:
0
0
-1
Salida:
Ingrese consumos diarios en kWh (valor negativo para terminar).
Dias registrados: 2
Consumo total: 0 kWh
Promedio diario: 0.00 kWh
Maximo diario: 0 kWh
```

## Casos borde a considerar
- Primer valor negativo (sin datos validos).
- Valores cero repetidos.
- Valores mayores a 10000 (descartados con mensaje).
- Secuencia larga de entradas antes del centinela.

## Guia paso a paso
1. Inicializa acumuladores (`total`, `contador`, `maximo`).
2. Muestra el mensaje inicial fuera del bucle.
3. Dentro del `do`, lee el consumo y verifica si es negativo para salir.
4. Si es mayor que 10000, imprime el mensaje de error y usa `continue` para repetir la lectura.
5. Actualiza acumuladores y maximo cuando el dato sea valido.
6. Despues del bucle, decide si existen datos y calcula el promedio (`(double)total / contador`).
7. Formatea el reporte final segun lo indicado.

## Estructura de carpetas requerida
```
04-registro-consumo/
  guided--medium.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## Requisitos de codigo
- Usa constantes simbolicas para limites (`MAX_CONSUMO` si lo consideras util).
- Implementa funciones auxiliares solo si clarifican la logica.
- Controla el valor devuelto por `scanf`; ante error imprime `Entrada invalida` y termina.

## Requisitos de documentacion
- Encabezado en `main.c` con proposito, autor y fecha.
- Comentarios en funciones (si existen) siguiendo estilo breve tipo Doxygen.

## Instrucciones de prueba
```
Compilacion:
  gcc -Wall -Wextra -std=c17 -O0 -o consumo src/main.c
Ejecucion:
  ./consumo < tests/test_input_01.txt
Comparacion:
  diff -u tests/test_expected_01.txt output.txt
```

## Rubrica de evaluacion
| Criterio | Peso | Descripcion |
|----------|------|-------------|
| Correccion | 40% | Reportes correctos y manejo del centinela |
| Seguridad de memoria | 15% | Entradas validadas, sin uso de memoria dinamica |
| Claridad de codigo | 15% | Variables descriptivas y flujo legible |
| Adherencia a la especificacion | 15% | Mensajes exactos y formato de promedio |
| Casos borde | 10% | Manejo adecuado de valores negativos y fuera de rango |
| Reflexion | 5% | Respuestas entregadas |

## Preguntas de reflexion
1. ¿Como aseguraste que el bucle se ejecutara al menos una vez?
2. ¿Que estrategia seguiste para ignorar los datos fuera de rango?
3. ¿Como definiste y usaste el valor centinela?
4. ¿Que mejorarias para evitar errores del usuario?
5. ¿Que concepto de acumuladores necesitas repasar?

## Extensiones sugeridas
- Agrega el calculo del consumo minimo y la cantidad de dias por encima de cierto umbral.
- Permite registrar tambien comentarios de texto asociados a cada dia (implica usar arreglos).
- Guarda el reporte en un archivo de salida especificado por el usuario.

## Errores comunes
- Olvidar reiniciar la lectura tras un dato fuera de rango.
- Dividir entre cero al calcular el promedio cuando no hay datos.
- Actualizar el maximo antes de validar el dato.

## Glosario
- **Valor centinela**: valor especial que indica el final de una secuencia de entradas.
- **Acumulador**: variable que se incrementa gradualmente para guardar sumas o conteos.

## Guia de control de versiones
1. Configura archivos base y variables iniciales.
2. Implementa el bucle `do-while` con lectura y centinela.
3. Agrega validaciones y mensaje "Dato fuera de rango".
4. Calcula y muestra el reporte final.
5. Documenta, prueba y realiza commit.

## Lista de calidad
- [ ] Mensajes coinciden exactamente con lo indicado.
- [ ] El promedio se imprime con dos decimales.
- [ ] Se manejan correctamente datos fuera de rango y centinela.
- [ ] Compila sin advertencias con `-Wall -Wextra`.

## Changelog
- 1.0 (2025-10-22): Version inicial.
