#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Tower.h"
#include "Enemy.h"
#include "Map.h"

// La clase Game encapsula la l�gica principal del juego Tower Defense.
class Game {
public:
    Game(); // Constructor de la clase Game
    ~Game(); // Destructor de la clase Game
    void run(); // M�todo que contiene el bucle principal del juego

private:
    void update(); // M�todo para actualizar el estado del juego en cada turno
    void render(); // M�todo para dibujar el estado actual del juego en la consola
    void placeTower(int x, int y); // M�todo para colocar una torreta en una posici�n espec�fica
    void waitForKeyPress(); // M�todo para esperar a que el jugador presione una tecla
    void checkEndCondition(); // M�todo para verificar si se cumple alguna condici�n de fin del juego
    void promptForTowerPlacement(); // M�todo para solicitar al jugador que coloque una torreta
    void askToPlaceTower(); // M�todo para preguntar al jugador si desea colocar una torreta despu�s de cierto n�mero de turnos

    std::vector<Tower> towers; // Vector que almacena todas las torretas colocadas en el juego
    std::vector<Enemy> enemies; // Vector que almacena todos los enemigos en el juego
    Map map; // Objeto que representa el mapa del juego
    int lives; // Variable que almacena el n�mero de vidas del jugador
    bool gameOver; // Variable que indica si el juego ha terminado
    int turnCount; // Nueva variable para contar los turnos
    int credits;   // Nueva variable para los cr�ditos
};

#endif // GAME_H
