---
title: Menu simple con validacion do-while
topic: Bucles
subtopics: [do-while, validacion de entrada, menus]
difficulty: easy
estimated_time: 25
prerequisites: [../05. Strings/01-concat-nombre-apellido]
learning_mode: guided
author: Antonio Rodriguez
version: 1.0
last_update: 2025-10-22
---

## Panorama general
El ejercicio refuerza la construccion de menus interactivos que deben repetirse al menos una vez. La estructura `do-while` permite validar la seleccion del usuario y solamente finalizar cuando se elige la opcion de salida.

## Objetivos de aprendizaje
- Reconocer cuando un `do-while` es mas conveniente que un `while`.
- Implementar validaciones basicas de opciones de menu.
- Diseñar flujos interactivos con mensajes claros al usuario.

## Contexto
Estan desarrollando un prototipo de interfaz de consola para un panel de control. El menu debe aparecer siempre y repetirse mientras el usuario no pida salir, mostrando mensajes acordes a cada opcion.

## Enunciado del problema
Crea un programa en C que:
- Muestre un menu con cuatro opciones numeradas del 1 al 4.
- Pregunte la opcion al usuario y la valide dentro de un bucle `do-while`.
- Imprima una respuesta especifica dependiendo de la opcion:
  - `1`: "Consultando temperatura..."
  - `2`: "Ajustando luces..."
  - `3`: "Revisando seguridad..."
  - `4`: "Saliendo del sistema."
- El menu se repite hasta que se ingrese `4`.
- Si se proporciona un numero diferente de 1 a 4, muestra "Opcion invalida" y repite.

## Especificacion de entrada
- Entrada desde `stdin`.
- Una opcion por linea; solo se esperan enteros.
- Rango esperado: 1 a 4, pero pueden ingresar valores fuera de ese rango.

## Especificacion de salida
- Antes de cada lectura imprime el menu completo con las cuatro opciones numeradas.
- Despues de leer, muestra exactamente un mensaje de accion o de error.
- Al salir, imprime el mensaje de salida y termina con salto de linea.

## Restricciones
- Utiliza un unico bucle `do-while` para repetir el menu.
- No uses `goto`.
- No almacenes mas de la ultima opcion leida.
- Todo el texto debe coincidir exactamente (incluyendo mayusculas, minusculas y signos).

## Ejemplos
```
Ejemplo 1
Entrada:
1
4
Salida:
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Consultando temperatura...
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Saliendo del sistema.

Ejemplo 2
Entrada:
9
3
2
4
Salida:
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Opcion invalida
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Revisando seguridad...
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Ajustando luces...
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Saliendo del sistema.

Ejemplo 3 (Entrada repetida)
Entrada:
2
2
4
Salida:
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Ajustando luces...
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Ajustando luces...
Seleccione una opcion:
1. Consultar temperatura
2. Ajustar luces
3. Revisar seguridad
4. Salir
Saliendo del sistema.
```

## Casos borde a considerar
- Opcion fuera del rango (debe mostrar "Opcion invalida").
- Repeticion de la misma opcion antes de salir.
- Entrada inmediata de `4`.

## Guia paso a paso
1. Diseña una funcion auxiliar que muestre el menu antes de leer.
2. Dentro del `do`, imprime el menu y lee la opcion con `scanf`.
3. Usa `switch` o `if` para decidir el mensaje.
4. Controla la repeticion con la condicion del `while (opcion != 4)`.
5. Muestra "Opcion invalida" cuando la opcion no este en el rango 1-4.

## Estructura de carpetas requerida
```
02-menu-validado/
  guided--easy.md
  src/
    main.c
  tests/
    test_input_01.txt
    test_expected_01.txt
  respuestas/
    REFLEXION.md
```

## Requisitos de codigo
- Implementa funciones auxiliares si el cuerpo de `main` crece demasiado.
- Controla el valor devuelto por `scanf`; si es distinto de 1, imprime "Entrada invalida" y termina.
- Evita duplicar cadenas literales (usa funciones o constantes para centralizar).

## Requisitos de documentacion
- Encabezado de archivo con proposito, autor y fecha.
- Comentarios antes de cada funcion explicando que hace, parametros y retorno.

## Instrucciones de prueba
```
Compilacion:
  gcc -Wall -Wextra -std=c17 -O0 -o menu src/main.c
Ejecucion:
  ./menu < tests/test_input_01.txt
Comparacion:
  diff -u tests/test_expected_01.txt output.txt
```

## Rubrica de evaluacion
| Criterio | Peso | Descripcion |
|----------|------|-------------|
| Correccion | 40% | Mensajes exactos y flujo de repeticion correcto |
| Seguridad de memoria | 15% | Sin lecturas invalidas ni desbordes |
| Claridad de codigo | 15% | Menu modular y funciones claras |
| Adherencia a la especificacion | 15% | Formato textual y uso de `do-while` |
| Casos borde | 10% | Validacion de opciones fuera de rango |
| Reflexion | 5% | Respuestas completas |

## Preguntas de reflexion
1. ¿Por que elegiste `do-while` en lugar de otro bucle?
2. ¿Como evitaste repetir codigo al mostrar mensajes?
3. ¿Que cambio harias para admitir mas opciones?
4. ¿Que pruebas adicionales realizarias?
5. ¿Que concepto de manejo de entrada necesitas reforzar?

## Extensiones sugeridas
- Agrega mas opciones con acciones simuladas.
- Implementa un contador de usos por opcion y muestralo al salir.
- Permite limpiar el buffer cuando se ingresa texto en lugar de numeros.

## Errores comunes
- Olvidar mostrar el menu antes de leer la opcion.
- No validar el resultado de `scanf`.
- Colocar la condicion `while` incorrecta y provocar un bucle infinito.

## Glosario
- **Menu interactivo**: interfaz de texto que presenta opciones para que el usuario elija una accion.
- **do-while**: bucle que siempre ejecuta el cuerpo al menos una vez antes de evaluar la condicion.

## Guia de control de versiones
1. Configura la estructura de carpetas y crea archivos vacios.
2. Implementa la presentacion del menu y la lectura basica.
3. Agrega el cuerpo de decision para cada opcion.
4. Añade la validacion para opciones invalidas.
5. Documenta, prueba y realiza el commit.

## Lista de calidad
- [ ] Compila sin advertencias.
- [ ] Los mensajes se muestran exactamente como en la especificacion.
- [ ] El programa finaliza solo al seleccionar 4.
- [ ] Casos fuera de rango probados.

## Changelog
- 1.0 (2025-10-22): Version inicial.
