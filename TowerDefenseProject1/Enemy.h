#ifndef ENEMY_H
#define ENEMY_H

#include "Map.h"
#include <vector>
#include <utility> // para std::pair

// Clase que representa un enemigo
class Enemy {
public:
    Enemy(int x, int y); // Constructor
    ~Enemy(); // Destructor

    void move(Map& map); // Método para mover al enemigo
    void takeDamage(); // Método para recibir daño
    bool isDead() const; // Método para verificar si el enemigo está muerto
    void reset(); // Método para reiniciar al enemigo
    bool hasReachedEnd() const; // Método para verificar si el enemigo llegó al final
    int getX() const; // Obtener la posición x del enemigo
    int getY() const; // Obtener la posición y del enemigo

private:
    void initializePath(); // Método para inicializar la ruta
    int x; // Coordenada x del enemigo
    int y; // Coordenada y del enemigo
    int health; // Salud del enemigo
    int pathIndex; // Índice para la ruta
    bool reachedEnd; // Indicador de si llegó al final
    std::vector<std::pair<int, int>> path; // Ruta del enemigo
};

#endif // ENEMY_H
