#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"
#include "render.h"
#include "utils.h"
#include "settings.h"

int main() {
    Snake snake = {{{15, 10}}, 1, 1};  // Inicializa la serpiente en el centro
    Food food;
    srand(time(NULL));                 // Inicializa la semilla para la generación de comida
    initialize_game();                 // Inicializa el entorno del juego
    generate_food(&food, &snake);               // Genera la primera comida
    generate_walls();             

    while (gameRunning) {
        // Capturar la entrada del teclado
        int ch = getch();
        mvprintw(0, 0, "Tecla presionada: %d", ch); // Mostrar la tecla presionada para depuración

        switch (ch) {
    case 'w':
    case 'W':
        mvprintw(1, 0, "Arriba    ");
        if (snake.dir != 2) snake.dir = 0;
        break;
    case 'd':
    case 'D':
        mvprintw(1, 0, "Derecha   ");
        if (snake.dir != 3) snake.dir = 1;
        break;
    case 's':
    case 'S':
        mvprintw(1, 0, "Abajo     ");
        if (snake.dir != 0) snake.dir = 2;
        break;
    case 'a':
    case 'A':
        mvprintw(1, 0, "Izquierda ");
        if (snake.dir != 1) snake.dir = 3;
        break;
    case 'q':  // Permitir al usuario salir presionando 'q'
        gameRunning = 0;
        break;
    default:
        mvprintw(1, 0, "Otra tecla");
}

        move_snake(&snake);  // Mover la serpiente

        // Verificar colisiones
        if (check_self_collision(&snake) || check_wall_collision(&snake)) {
            gameRunning = 0;
        }

        // Verificar si la serpiente ha comido la comida
        if (check_collision(&snake, &food)) {
            snake.length++;
            score++;
            generate_food(&food, &snake);
        }

        // Renderizar la pantalla
        clear();
        render_game(&snake, &food);
        refresh();

        // Añadir un pequeño retraso
        napms(100);
    }

    end_game();  // Finalizar el juego
    return 0;
}
