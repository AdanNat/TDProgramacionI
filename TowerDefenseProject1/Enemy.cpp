#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y) : x(x), y(y), health(2), pathIndex(0), reachedEnd(false) {
    initializePath(); // Inicializar ruta del enemigo
}

Enemy::~Enemy() {}

void Enemy::initializePath() {
    // Definir la ruta predefinida desde 'E' hasta 'S'
    path = {
        {0, 1}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8},
        {2, 8}, {3, 8}, {3, 7}, {3, 6}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {3, 1}, {4, 1}, {5, 1},
        {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8},
        {6, 8}, {7, 8}, {8, 8}, {9, 8}
    };
}

void Enemy::move(Map& map) {
    // Mover enemigo a lo largo de la ruta
    if (pathIndex < path.size()) {
        x = path[pathIndex].first;
        y = path[pathIndex].second;
        pathIndex++;
        if (x == 9 && y == 8) {
            reachedEnd = true; // Indicar que el enemigo llegó al final
        }
    }
    std::cout << "Enemy moves to (" << x << ", " << y << ").\n"; // Mostrar movimiento del enemigo
}

void Enemy::takeDamage() {
    health--; // Reducir salud del enemigo
}

bool Enemy::isDead() const {
    return health <= 0; // Verificar si la salud es 0 o menor
}

void Enemy::reset() {
    x = path[0].first;
    y = path[0].second;
    pathIndex = 0; // Reiniciar posición y ruta
    reachedEnd = false;
    health = 3; // Reiniciar salud
}

bool Enemy::hasReachedEnd() const {
    return reachedEnd; // Verificar si llegó al final
}

int Enemy::getX() const {
    return x; // Devolver coordenada x
}

int Enemy::getY() const {
    return y; // Devolver coordenada y
}

