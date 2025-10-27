#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'true' y 'false'
#include <ncurses.h> // Para acceder al teclado

int main()
{
//-------------------------------------------Ejemplo de Tablas De verdad Sensillo------------------------------------------------------
/*
    bool a = true;
    bool b = false;

    printf("a vale: %d\nb vale: %d\n", a, b); // Imprimir las variables Deberia Imprimir a: 1 y b: 0
    // Conjunción [AND] a ∧ b
    printf("a ∧ b: %d\n", a && b); // Debería imprimir 0 (falso)

    // Disyunción [OR] (a ∨ b)
    printf("a ∨ b: %d\n", a || b);  // Debería imprimir 1 (verdadero)

    // Negación [NOT] (¬a, ¬b)
    printf("¬a: %d\n", !a);     // Debería imprimir 0 (falso)
    printf("¬b: %d\n", !b);     // Debería imprimir 1 (verdadero)

    // Implicación (a -> b)
    printf("a -> b: %d\n", !a || b); // Debería imprimir 0 (falso)

    // Bicondicional (a <-> b)
    printf("a <-> b: %d\n", (a && b) || (!a && !b)); // Debería imprimir 0 (falso)

    // Disyunción exclusiva [XOR] (a ⊻ b)
    printf("a ⊻ b: %d\n", a ^ b); // Debería imprimir 1 (verdadero)*/


//-------------------------------------------Programa final de tablas de verdad--------------------------------------------------------


    bool a, b, continuar;
    int opcion_a, opcion_b, opcion_continuar;
    int ch;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    do {
        bool opcion_a = 0;
        bool opcion_b = 0;
        bool opcion_continuar = 0;

        // Selección de 'a'
        mvprintw(0, 0, "Selecciona el valor de a:");
        while (1) {
            mvprintw(1, 0, "%s", opcion_a == 0 ? "[*] Falso [ ] Verdadero" : "[ ] Falso [*] Verdadero");
            ch = getch();
            if (ch == KEY_LEFT || ch == KEY_RIGHT) {
                opcion_a = !opcion_a;
            } else if (ch == 10) {
                a = opcion_a;
                break;
            }
        }

        // Selección de 'b'
        mvprintw(3, 0, "Selecciona el valor de b:");
        while (1) {
            mvprintw(4, 0, "%s", opcion_b == 0 ? "[*] Falso [ ] Verdadero" : "[ ] Falso [*] Verdadero");
            ch = getch();
            if (ch == KEY_LEFT || ch == KEY_RIGHT) {
                opcion_b = !opcion_b;
            } else if (ch == 10) {
                b = opcion_b;
                break;
            }
        }

        // Operaciones lógicas con salida en texto
        mvprintw(6, 0, "a Conjuncion b: %s", (a && b) ? "Verdadero    " : "Falso    ");
        mvprintw(7, 0, "a Disyuncion b: %s", (a || b) ? "Verdadero    " : "Falso    ");
        mvprintw(8, 0, "NOT a: %s ", (!a) ? "Verdadero    " : "Falso    ");
        mvprintw(9, 0, "NOT b: %s ", (!b) ? "Verdadero    " : "Falso    ");
        mvprintw(10, 0, "a -> b: %s", (!a || b) ? "Verdadero" : "Falso");
        mvprintw(11, 0, "a <-> b: %s", ((a && b) || (!a && !b)) ? "Verdadero    " : "Falso    ");
        mvprintw(12, 0, "a Disyuncion Exclusiva b: %s", (a ^ b) ? "Verdadero    " : "Falso    ");

        // Selección de continuar
        mvprintw(14, 0, "¿Deseas ingresar otros valores?");
        while (1) {
            mvprintw(15, 0, "%s", opcion_continuar == 0 ? "[*] Si [ ] No" : "[ ] Si [*] No");
            ch = getch();
            if (ch == KEY_LEFT || ch == KEY_RIGHT) {
                opcion_continuar = !opcion_continuar;
            } else if (ch == 10) {
                continuar = !opcion_continuar;
                break;
            }
        }

    } while (continuar);
    endwin();
    return 0;
}
