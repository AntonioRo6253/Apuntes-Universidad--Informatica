@ingroup apuntes-teoria

---

# Funciones Utiles

## Printf()
**Libreria:**
```c
#include <stdio.h>
```

Sirve para imprimir datos en consola
```c
// printf("Mi Texto");
printf("Hola Mundo");
// printf("%tipo",variable);
printf("%d",num);
// printf("Mi Variable_1 es:%tipo1  Mi Variable_2 es:%tipo2",variable1);
printf("Numero:%d Texto:%s",num,text);
```
**Resultado**
Hola Mundo!

### Marcas
Las marcas es lo que esta después de `%` su estructura es:
`{c}%[parameter][flags][width][.precision][length]type`
**Ejemplo**
```c
#include <stdio.h>

int main() {
    int cantidad = 42;
    double precio = 123.456789;
    char producto[] = "Laptop";

    // Uso completo del formato:
    // %[1$][-][10][.2][lf]
    // donde:
    // [1$] = parameter (posición)
    // [-]  = flag (alineación izquierda)
    // [10] = width (ancho mínimo)
    // [.2] = precision (2 decimales)
    // [l]  = length (long double, aunque aquí es double)
    // [f]  = type (número flotante)

    printf("Producto: %-15s Cantidad: %3d Precio: %8.2f\n", producto, cantidad, precio);

    return 0;
}
```
**Resultado**
Producto: Laptop Cantidad: 42 Precio: 123.46

### Tipos de Datos en las marcas

| Type       | Descripción                                                               |
| ---------- | ------------------------------------------------------------------------- |
| `%c`       | Imprime el carácter ASCII correspondiente                                 |
| `%d`, `%i` | Conversión decimal con signo de un entero                                 |
| `%p`       | Dirección de memoria (puntero)                                            |
| `%e`, `%E` | Conversión a coma flotante con signo en notación científica               |
| `%f`, `%F` | Conversión a coma flotante con signo, usando punto decimal                |
| `%g`, `%G` | Conversión a coma flotante, usando la notación que requiera menor espacio |
| `%o`       | Conversión octal sin signo de un entero                                   |
| `%u`       | Conversión decimal sin signo de un entero                                 |
| `%s`       | Cadena de caracteres (terminada en '\0')                                  |
| `%%`       | Imprime el símbolo %                                                      |

- [Definicion,Estructura,Flags,width,Lenght,types](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html)

---

## Scanf()
**Libreria:**
```c
#include <stdio.h>
```

Sirve para leer datos y guardarlos en una variable
```c
// printf("%tipo",variable);
scanf("%d",&num);
// scanf("%4s",array);
scanf("%4s",array);
```
- **Se parece a Printf():**
	
	  las _marcas(**%d**)_ funcionan casi igual solo que de manera mas limitada

- **Peligro con cadenas**:
	  Usar `%s` es peligroso porque no limita la cantidad de caracteres que se leen, lo que puede causar desbordamientos de búfer si el usuario escribe más caracteres de los que el array puede almacenar.
- **Especificar anchos**:
	  Para evitar desbordamientos, se debe especificar un ancho máximo en la cadena de formato, por ejemplo, `%10s` para leer un máximo de 10 caracteres.

---

---
