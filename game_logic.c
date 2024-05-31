#include "game_logic.h"
#include <curses.h>
#include <stdlib.h>
#include "settings.h"
#include <time.h>

/*
Contiene la logica del juego, movimiento de la serpiente, comida, colisiones, etc.
Aparte de que se implementan las funciones y variables globales declaradas en el archivo de cabecera game_logic.h
*/

int gameRunning = 1;  
int score = 0;        

void initialize_game() {
    initscr();            // Inicializa la pantalla
    clear();              // Limpia la pantalla
    noecho();             // No mostrar la entrada del teclado
    cbreak();             // Desactiva el buffer de línea
    curs_set(0);          // Oculta el cursor
    keypad(stdscr, TRUE); // Habilita la captura de teclas especiales
    nodelay(stdscr, TRUE);// No bloquear la espera de entrada
    timeout(GAME_SPEED);  // Establece el tiempo de espera para getch


    // Inicializa el soporte de color
    if (has_colors()) {
        start_color();
        init_pair(SNAKE_COLOR, COLOR_GREEN, COLOR_BLACK);  // Color para la serpiente
        init_pair(FOOD_COLOR, COLOR_RED, COLOR_BLACK);    // Color para la comida
        init_pair(WALL_COLOR, COLOR_WHITE, COLOR_BLACK);  // Color para los muros
    }
}

void end_game() {
    endwin();            
}

void move_snake(Snake *snake) {
    // Guardar la posición de la cabeza
    Position new_head = snake->pos[0];

    // Mover la cabeza en la dirección actual
    switch (snake->dir) {
        case 0: new_head.y--; break; // Arriba
        case 1: new_head.x++; break; // Derecha
        case 2: new_head.y++; break; // Abajo
        case 3: new_head.x--; break; // Izquierda
    }

    // Mover el cuerpo de la serpiente
    for (int i = snake->length - 1; i > 0; i--) {
        snake->pos[i] = snake->pos[i - 1];
    }

    // Actualizar la posición de la cabeza
    snake->pos[0] = new_head;
}

void generate_food(Food *food, Snake *snake) {
    // Generar una posición aleatoria para la comida
    int food_x, food_y;
    bool collision;
    do {
        collision = false;
        food_x = (rand() % (WIDTH - 2)) + 1;
        food_y = (rand() % (HEIGHT - 2)) + 1;
        // Verificar si la comida se generó en el cuerpo de la serpiente
        int collision = 0;
        for (int i = 0; i < snake->length; i++) {
            if (food_x == snake->pos[i].x && food_y == snake->pos[i].y) {
                collision = true;
                break;
            }
        }
        if (!collision) {
            food->pos.x = food_x;
            food->pos.y = food_y;
        }
    } while (collision);
}

int check_collision(Snake *snake, Food *food) {
    // Verificar si la cabeza de la serpiente ha colisionado con la comida
    if (snake->pos[0].x == food->pos.x && snake->pos[0].y == food->pos.y) {
        return 1; // Colisión detectada
    }
    return 0; // No hay colisión
}

int check_self_collision(Snake *snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->pos[0].x == snake->pos[i].x && snake->pos[0].y == snake->pos[i].y) {
            return 1; // Colisión detectada
        }
    }
    return 0; // No hay colisión
}

int check_wall_collision(Snake *snake) {
    if (snake->pos[0].x < 0 || snake->pos[0].x >= WIDTH || snake->pos[0].y < 0 || snake->pos[0].y >= HEIGHT) {
        return 1; // Colisión con la pared detectada
    }
    return 0; // No hay colisión
}


//!gcc -o juego_snake main.c game_logic.c -I C:/PDCurses -L C:/PDCurses/wincon -l:pdcurses.a



