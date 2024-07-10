#ifndef TOWER_H
#define TOWER_H

#include <vector>
#include "Enemy.h"

// Clase que representa una torre
class Tower {
public:
    Tower(int x, int y); // Constructor
    ~Tower(); // Destructor

    void attack(std::vector<Enemy>& enemies); // Método para atacar enemigos
    int getX() const; // Obtener la posición x de la torre
    int getY() const; // Obtener la posición y de la torre

private:
    int x; // Coordenada x de la torre
    int y; // Coordenada y de la torre
    int turnCounter; // Contador de turnos
};

#endif // TOWER_H
