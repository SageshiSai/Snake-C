#include "game_logic.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>

/*
Contiene la logica del juego, movimiento de la serpieente, comida, colisiones, etc.
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
    timeout(100);         // Establece el tiempo de espera para getch
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

void generate_food(Food *food) {
    // Generar una posición aleatoria para la comida
    food->pos.x = rand() % WIDTH;
    food->pos.y = rand() % HEIGHT;
}

int check_collision(Snake *snake, Food *food) {
    // Verificar si la cabeza de la serpiente ha colisionado con la comida
    if (snake->pos[0].x == food->pos.x && snake->pos[0].y == food->pos.y) {
        return 1; // Colisión detectada
    }
    return 0; // No hay colisión
}

//gcc -o juego_snake main.c game_logic.c -I C:/PDCurses -L C:/PDCurses/wincon -l:pdcurses.a



