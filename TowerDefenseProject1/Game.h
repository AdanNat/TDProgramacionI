#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Tower.h"
#include "Enemy.h"
#include "Map.h"

// La clase Game encapsula la lógica principal del juego Tower Defense.
class Game {
public:
    Game(); // Constructor de la clase Game
    ~Game(); // Destructor de la clase Game
    void run(); // Método que contiene el bucle principal del juego

private:
    void update(); // Método para actualizar el estado del juego en cada turno
    void render(); // Método para dibujar el estado actual del juego en la consola
    void placeTower(int x, int y); // Método para colocar una torreta en una posición específica
    void waitForKeyPress(); // Método para esperar a que el jugador presione una tecla
    void checkEndCondition(); // Método para verificar si se cumple alguna condición de fin del juego
    void promptForTowerPlacement(); // Método para solicitar al jugador que coloque una torreta
    void askToPlaceTower(); // Método para preguntar al jugador si desea colocar una torreta después de cierto número de turnos

    std::vector<Tower> towers; // Vector que almacena todas las torretas colocadas en el juego
    std::vector<Enemy> enemies; // Vector que almacena todos los enemigos en el juego
    Map map; // Objeto que representa el mapa del juego
    int lives; // Variable que almacena el número de vidas del jugador
    bool gameOver; // Variable que indica si el juego ha terminado
    int turnCount; // Nueva variable para contar los turnos
    int credits;   // Nueva variable para los créditos
};

#endif // GAME_H
