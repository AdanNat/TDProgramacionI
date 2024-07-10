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

    void move(Map& map); // M�todo para mover al enemigo
    void takeDamage(); // M�todo para recibir da�o
    bool isDead() const; // M�todo para verificar si el enemigo est� muerto
    void reset(); // M�todo para reiniciar al enemigo
    bool hasReachedEnd() const; // M�todo para verificar si el enemigo lleg� al final
    int getX() const; // Obtener la posici�n x del enemigo
    int getY() const; // Obtener la posici�n y del enemigo

private:
    void initializePath(); // M�todo para inicializar la ruta
    int x; // Coordenada x del enemigo
    int y; // Coordenada y del enemigo
    int health; // Salud del enemigo
    int pathIndex; // �ndice para la ruta
    bool reachedEnd; // Indicador de si lleg� al final
    std::vector<std::pair<int, int>> path; // Ruta del enemigo
};

#endif // ENEMY_H
