//contienen funciones que no necesariamente son de la logica del juego, pero que son necesarias para su funcionamiento
#include "utils.h"
#include "settings.h"

void generate_walls() {
    // Dibujar los muros
    attron(COLOR_PAIR(WALL_COLOR));
    // Dibujar la pared superior e inferior
    for (int x = 0; x < WIDTH; x++) {
        mvprintw(0, x, "-");
        mvprintw(HEIGHT-1, x, "-");
    }
    // Dibujar las paredes izquierda y derecha
    for (int y = 1; y < HEIGHT-1; y++) {
        mvprintw(y, 0, "|");
        mvprintw(y, WIDTH-1, "|");
    }
    attroff(COLOR_PAIR(WALL_COLOR));
}