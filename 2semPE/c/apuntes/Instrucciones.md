@page instrucciones Instrucciones

# Apuntes de C — Uso con Obsidian y Doxygen

Este repositorio contiene apuntes y ejemplos en C. Aquí se explica cómo usar cómodamente los archivos con Obsidian para tomar notas y con Doxygen para generar documentación técnica.

## Requisitos

- Obsidian (https://obsidian.md) — crear/abrir la carpeta `c/Apuntes` como Vault.
  - Plugins recomendados (Community plugins):
    - code-styler
    - advanced-tables
    - dataview
    - mermaid-tools
- Visual Studio Code (opcional, para edición de código y pruebas).
- Doxygen + Graphviz (para generar documentación y diagramas).
  - En Linux (Debian/Ubuntu):
    ```bash
    sudo apt update && sudo apt install doxygen graphviz
    ```
- (Opcional) LaTeX si quieres salida PDF: texlive-full o el paquete mínimo que uses.

## Flujo de trabajo sugerido

1. Abrir vault en Obsidian

   - En Obsidian: "Open folder as vault" → seleccionar `.../2semPE/c/Apuntes`.
   - Habilitar los plugins recomendados en Settings → Community plugins.
   - Usar plantillas para encabezados de apuntes y metadatos YAML si usas Dataview.

2. Escribir y formatear código en las notas

   - Usar bloques de código con lenguaje `c` para resaltado:

     ```c
     // ejemplo
     #include <stdio.h>

     /**
      * @brief Suma dos enteros.
      * @param a primer sumando
      * @param b segundo sumando
      * @return suma de a y b
      */
     int suma(int a, int b) {
         return a + b;
     }
     ```

   - code-styler aplica formato; mermaid-tools para diagramas embebidos.

3. Indexar y listar notas con Dataview

   - Ejemplo de consulta Dataview en una nota índice:
     ```dataview
     table file.mtime as "Modificado", file.size as "Tamaño"
     from ""
     where contains(file.path, "Apuntes")
     sort file.mtime desc
     ```

4. Editar código y pruebas en VS Code
   - Abrir la carpeta del proyecto en VS Code para compilar, ejecutar pruebas y usar extensiones de C.
   - Mantener las notas en Obsidian en `apuntes/` y el código en `c/src` o la estructura que prefieras.

## Generar documentación con Doxygen

1. Verifica/edita `Doxyfile` (ya incluido en `c/.`).
   - Asegúrate de:
     - EXTRACT_ALL = YES (si quieres extraer todo)
     - HAVE_DOT = YES (para diagramas, requiere Graphviz)
     - OUTPUT_DIRECTORY = docs
     - GENERATE_LATEX = YES/NO según necesites PDF
2. Generar:
   - Desde la carpeta `c/`:
   ```bash
   doxygen Doxyfile
   ```
   - Abrir salida HTML:
     - xdg-open docs/html/index.html
3. Comentarios Doxygen en C (ejemplo):

   ```c
   /**
    * @file ejemplo.c
    * @brief Funciones de ejemplo para la materia.
    */

   /**
    * @brief Calcula el máximo de dos números enteros.
    * @param a Primer entero.
    * @param b Segundo entero.
    * @return El mayor de a y b.
    */
   int max(int a, int b) {
       return (a > b) ? a : b;
   }
   ```

## Diagramas y dependencias

- Si los diagramas no aparecen, instala Graphviz y confirma `HAVE_DOT = YES` en `Doxyfile`.
- Para diagramas Mermaid en Obsidian no se requiere Graphviz; son independientes y se renderizan dentro de Obsidian.

## Buenas prácticas

- Mantén la documentación en línea con el código: comentar funciones públicas con tags Doxygen.
- Sigue el control de versiones (git) en la carpeta `2semPE`.

## Solución de problemas rápida

- "doxygen: command not found" → instalar doxygen.
- Diagramas en blanco → instalar graphviz y regenerar.
- Archivos no indexados por Doxygen → revisar rutas y patrones en `Doxyfile` (`INPUT`, `FILE_PATTERNS`, `RECURSIVE`).
