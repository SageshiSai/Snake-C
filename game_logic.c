//Contiene la logica del juego, movimiento de la serpieente, comida, colisiones, etc.

#include "game_logic.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>

void initialize_game() {
    initscr();            // Inicia la pantalla
    clear();              // Limpia la pantalla
    noecho();             // No mostrar la entrada del teclado
    cbreak();             // Desactiva el buffer de línea
    curs_set(0);          // Oculta el cursor
    timeout(100);         // Establece el tiempo de espera para getch
}

void end_game() {
    endwin();             // Finaliza la pantalla
}

#define WIDTH 30
#define HEIGHT 20


//typedef se utiliza para crear alias para tipos de datos existentes
typedef struct {
    int x, y;
} Position;
