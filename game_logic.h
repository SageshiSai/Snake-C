#ifndef GAME_LOGIC_H   
#define GAME_LOGIC_H

/*
En este archivo se declaran las constantes, estructuras, variables globales y funciones
*/

// Definir estructura Position
typedef struct {
    int x, y;
} Position;

// Definir estructura Snake
typedef struct {
    Position pos[100]; // La serpiente puede tener hasta 100 segmentos
    int length;        // Longitud actual de la serpiente
    int dir;           // Dirección de la serpiente (0: arriba, 1: derecha, 2: abajo, 3: izquierda)
} Snake;

// Definir estructura Food
typedef struct {
    Position pos;      // Posición de la comida
} Food;

// Declarar variables globales para el estado del juego y la puntuación
extern int gameRunning;  // 1 si el juego está en curso, 0 si ha terminado
extern int score;        // Puntuación del jugador

// Declarar funciones
void initialize_game();
void end_game();
void move_snake(Snake *snake);
void generate_food(Food *food, Snake *snake);
int check_collision(Snake *snake, Food *food);
int check_self_collision(Snake *snake);
int check_wall_collision(Snake *snake);

#endif /* GAME_LOGIC_H */