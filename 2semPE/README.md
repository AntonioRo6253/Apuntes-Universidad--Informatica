@mainpage

# 📘 Ciclo 2023A (V0716)

Este repositorio contiene ejercicios y proyectos desarrollados durante el curso de Programación Estructurada, siguiendo el libro **"Programación en C, C++, Java y UML" de Luis Joyanes Aguilar, 2ª edición**. El material está orientado a reforzar los conceptos fundamentales de la programación estructurada y modular.

## 🧠 Conocimientos clave abordados

A lo largo del curso, se trabajarán los siguientes temas esenciales:

- **C1. Concepto de abstracción y modularidad**
- **C2. Funciones y procedimientos**
- **C3. Paso de parámetros por valor**
- **C4. Paso de parámetros por referencia**
- **C5. Datos de tipo estructurado:** arreglos unidimensionales, bidimensionales, N-dimensionales, registros
- **C6. Datos estructurados: Vectores**
- **C7. Datos estructurados: Matrices**
- **C8. Datos estructurados: Registros**
- **C9. Apuntadores**
- **C10. Manejo de memoria dinámica**
- **C11. Recursividad**
- **C12. Manejo de caracteres y cadenas de caracteres**
- **C13. Estructuras de control**

---

> **Nota:** Configura tu editor como prederminado para abrir archivos **.c y .tsx**

## 🚀 Cómo usar este proyecto en Code::Blocks

si usas este ide no podrias editar la version mobile de este proyecto

1. **Instala Code::Blocks**  
   Descarga e instala desde [https://www.codeblocks.org/downloads/](https://www.codeblocks.org/downloads/).

2. **Importa el proyecto**

   - Abre Code::Blocks.
   - Ve a `File > Open...` y selecciona el archivo `.cbp` del proyecto (si existe) o abre los archivos `.c` directamente.

3. **Compila y ejecuta**
   - Haz clic en el botón "Build and Run" (F9) para compilar y ejecutar el código.

---

## ⚡ Cómo usar este proyecto en Visual Studio Code

1. **Instala VSCode**  
   Descarga desde [https://code.visualstudio.com/](https://code.visualstudio.com/).

2. **Instala extensiones recomendadas**

   - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
   - [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) (opcional)

3. **Configura el compilador**

   - Instala [gcc](https://www.mingw-w64.org/) (Windows) o usa `gcc`/`clang` en Linux/Mac.
   - Verifica la instalación ejecutando `gcc --version` en la terminal.

4. **Compila y ejecuta**
   - Abre la carpeta del proyecto en VSCode.
   - Compila desde la terminal con:
     ```sh
     gcc archivo.c -o programa
     ./programa
     ```
   - O usa "Run Code" si tienes Code Runner.

---

## 📑 Notas

- Este repositorio es de uso académico y personal.
- Se recomienda consultar el libro de Luis Joyanes Aguilar para profundizar en los temas.
- Para dudas técnicas, revisa la documentación oficial de C y los foros de programación.

---

---

# Primeros Pasos Usando La Documentacion

Este repositorio contiene apuntes y ejemplos en C. Aquí se explica cómo usar cómodamente los archivos con Obsidian para tomar notas y con Doxygen para generar documentación técnica.

---

## Requisitos

- Obsidian (https://obsidian.md) — crear/abrir la carpeta `c/apuntes` como Vault.
  - Plugins recomendados (Community plugins):
    - code-styler
    - advanced-tables
    - mermaid-tools
- Visual Studio Code/codeblocks (opcional, para edición de código y pruebas).
- Doxygen + Graphviz (para generar documentación y diagramas).
  - En Linux (Debian/Ubuntu):
    ```bash
    sudo apt update && sudo apt install doxygen graphviz
    ```
- (Opcional) LaTeX si quieres salida PDF: texlive-full o el paquete mínimo que uses.

## Flujo de trabajo sugerido

1. Abrir vault en Obsidian

   - En Obsidian: "Open folder as vault" → seleccionar `.../2semPE/c/apuntes`.
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

3. Editar código y pruebas en VS Code
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
   - Abrir salida HTML con el plugin [live-Server](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer):
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
- Sigue el control de versiones (git) en la carpeta `Trabajos-Universidad-codigo-UDG`.

## Solución de problemas rápida

- "doxygen: command not found" → instalar doxygen.
- Diagramas en blanco → instalar graphviz y regenerar.
- Archivos no indexados por Doxygen → revisar rutas y patrones en `Doxyfile` (`INPUT`, `FILE_PATTERNS`, `RECURSIVE`).
