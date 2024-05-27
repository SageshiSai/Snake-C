#include "game_logic.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>

//?aqui se incializa la ventana de la interfaz grafica y  el que inicia el juego

int main() {
    Snake snake = {{{5, 5}}, 1, 1}; // Inicializar la serpiente
    Food food;
    generate_food(&food);           // Generar la primera comida

    initialize_game();              // Inicializar el juego

    while (gameRunning) {
        clear();                    // Limpiar la pantalla

        // Dibujar la comida
        mvprintw(food.pos.y, food.pos.x, "O");

        // Dibujar la serpiente
        for (int i = 0; i < snake.length; i++) {
            mvprintw(snake.pos[i].y, snake.pos[i].x, "X");
        }

        // Mover la serpiente
        move_snake(&snake);

        // Verificar colisiones
        if (check_collision(&snake, &food)) {
            score++;
            snake.length++;
            generate_food(&food);
        }

        // Esperar y leer la entrada del usuario
        int ch = getch();
        switch (ch) {
            case KEY_UP:    snake.dir = 0; break;
            case KEY_RIGHT: snake.dir = 1; break;
            case KEY_DOWN:  snake.dir = 2; break;
            case KEY_LEFT:  snake.dir = 3; break;
            case 'q':       gameRunning = 0; break;
        }

        refresh(); // Refrescar la pantalla
    }

    end_game(); // Finalizar el juego
    return 0;
}


