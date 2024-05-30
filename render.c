#include "render.h"

void render(Snake *snake, Food *food) {
    //este se encarga de la interfaz grafica del juego, dibuja la serpiente, la comida, etc.
    clear();  // Limpia la pantalla

    // Dibujar la comida
    mvprintw(food->pos.y, food->pos.x, "O");

    // Dibujar la serpiente
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->pos[i].y, snake->pos[i].x, "X");
    }

    // Mostrar la puntuación
    mvprintw(0, 0, "Score: %d", score);

    refresh();  // Actualiza la pantalla
}

