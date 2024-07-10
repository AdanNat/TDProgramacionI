#include "Tower.h"

Tower::Tower(int x, int y) : x(x), y(y), turnCounter(0) {} // Constructor con inicializaci�n

Tower::~Tower() {}

void Tower::attack(std::vector<Enemy>& enemies) {
    turnCounter++; // Incrementar contador de turnos
    if (turnCounter == 4) { // Cada 4 turnos
        for (auto& enemy : enemies) {
            int ex = enemy.getX();
            int ey = enemy.getY();
            // Verificar si el enemigo est� en el rango de ataque
            if (ex >= x - 1 && ex <= x + 1 && ey >= y - 1 && ey <= y + 1) {
                enemy.takeDamage(); // Infligir da�o al enemigo
            }
        }
        turnCounter = 0; // Reiniciar contador despu�s de atacar
    }
}

int Tower::getX() const {
    return x; // Devolver coordenada x
}

int Tower::getY() const {
    return y; // Devolver coordenada y
}
