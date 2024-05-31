#include "render.h"

void render_game(Snake *snake, Food *food) {
    clear();

    // Dibujar los muros
    attron(COLOR_PAIR(3));
    for (int x = 0; x < WIDTH; x++) {
        mvprintw(0, x, "-");
        mvprintw(HEIGHT-1, x, "-");
    }
    for (int y = 0; y < HEIGHT; y++) {
        mvprintw(y, 0, "|");
        mvprintw(y, WIDTH-1, "|");
    }
    attroff(COLOR_PAIR(3));

    // Dibujar la serpiente
    attron(COLOR_PAIR(1));
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->pos[i].y, snake->pos[i].x, "O");
    }
    attroff(COLOR_PAIR(1));

    // Dibujar la comida
    attron(COLOR_PAIR(2));
    mvprintw(food->pos.y, food->pos.x, "X");
    attroff(COLOR_PAIR(2));

     // Dibujar la puntuación
    mvprintw(HEIGHT, 0, "Score: %d", score);

    refresh();
}

