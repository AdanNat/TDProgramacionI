#include "Game.h"
#include <iostream>
#include <conio.h> // Para _getch()
#include <algorithm> // Para std::remove_if
#include <cstdlib> // Para system("cls")
#include <random>

Game::Game() : map(10, 10), lives(3), gameOver(false), turnCount(0), credits(2000) { // Inicializar turnCount
    // Inicializar enemigos
    enemies.emplace_back(0, 1); // Punto de entrada
}

Game::~Game() {}

void Game::run() {
    std::cout << "                                      <><><>BIENVENIDO A TOWER DEFENSE<><><>\n";
    std::cout << "                                            <><>MAPA SELECCIONADO<><>\n";
    std::cout << "\n";
    std::cout << "                                                0 1 2 3 4 5 6 7 8 9 (X)\n";
    std::cout << "                                              _______________________\n";
    std::cout << "                                            0 | # # # # # # # # # # |\n";
    std::cout << "                                            1 | E   #       # # # # |\n";
    std::cout << "                                            2 | #   #   #   # # # # |\n";
    std::cout << "                                            3 | #   #   #   # # # # |\n";
    std::cout << "                                            4 | #   #   #   # # # # |\n";
    std::cout << "                                            5 | #   #   #   # # # # |\n";
    std::cout << "                                            6 | #   #   #   # # # # |\n";
    std::cout << "                                            7 | #   #   #   # # # # |\n";
    std::cout << "                                            8 | #       #         S |\n";
    std::cout << "                                            9 | # # # # # # # # # # |\n";
    std::cout << "                                           (Y)-----------------------";
    std::cout << "\n";
    std::cout << "                                                 <><>LEYENDA<><>\n";
    std::cout << "                                                   E = Entrada\n";
    std::cout << "                                                   S = Salida\n";
    std::cout << "                                                   # = Muros\n";
    std::cout << "                                                   E = Enemigos\n";
    std::cout << "                                                  ' '= Camino\n";
    std::cout << "\n";
    std::cout << "                              <><><>Presiona cualquier tecla para iniciar el juego<><><>\n";
    waitForKeyPress();

    // Pedir al jugador que coloque solo una torreta al inicio
    promptForTowerPlacement();

    while (!gameOver) { // Bucle principal del juego
        update();
        render();
        checkEndCondition();

        if (!gameOver) {
            turnCount++; // Incrementar el contador de turnos

            // Preguntar al jugador si quiere colocar una torreta después de 10 turnos
            if (turnCount % 10 == 0) {
                askToPlaceTower();
            }

            std::cout << "Presiona cualquier tecla para continuar...\n";
            waitForKeyPress();
        }
    }
    std::cout << "GAME OVER\n";
}

void Game::update() {
    // Actualizar posición de los enemigos
    for (auto& enemy : enemies) {
        enemy.move(map);
        if (enemy.hasReachedEnd()) {
            lives--;
            std::cout << "Perdiste una vida! Vidas restantes: " << lives << std::endl;
            enemy.reset(); // Reiniciar enemigo en el punto de entrada
        }
    }

    // Actualizar estado de las torres
    for (auto& tower : towers) {
        tower.attack(enemies); // Pasar referencia a los enemigos
    }

    // Eliminar enemigos muertos y agregar créditos
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(), [this](Enemy& enemy) {
            if (enemy.isDead()) {
                credits += 125; // Agregar créditos al matar un enemigo
                return true;
            }
            return false;
            }), enemies.end());

    // Cada 5 turnos, generar un número aleatorio de enemigos entre 1 y 5
    if (turnCount % 5 == 0) {
        std::random_device rd; // Obtiene una semilla aleatoria del hardware
        std::mt19937 gen(rd()); // Generador de números aleatorios
        std::uniform_int_distribution<> dis(1, 5); // Distribución uniforme entre 1 y 5

        int numEnemies = dis(gen); // Generar número aleatorio de enemigos

        for (int i = 0; i < numEnemies; ++i) {
            enemies.emplace_back(0, 1); // Agregar un nuevo enemigo al vector
        }

        std::cout << numEnemies << " enemigos nuevos han aparecido.\n";
    }

    // Regenerar enemigos automáticamente si no hay enemigos
    if (enemies.empty() && !gameOver) {
        enemies.emplace_back(0, 1);
    }
}

void Game::render() {
    // Limpiar la consola antes de redibujar el mapa
    system("cls");

    // Limpiar y reinicializar el mapa
    map.clear();

    // Dibujar torres
    for (const auto& tower : towers) {
        map.setTile(tower.getX(), tower.getY(), 'T');
    }

    // Dibujar enemigos
    for (const auto& enemy : enemies) {
        map.setTile(enemy.getX(), enemy.getY(), 'E');
    }

    // Dibujar mapa
    map.draw();

    // Mostrar la cantidad de vidas
    std::cout << "Vidas restantes: " << lives << std::endl;
    std::cout << "Creditos: " << credits << std::endl;

}

void Game::placeTower(int x, int y) {
    if (map.isWall(x, y)) { // Verificar si es una pared
        if (credits >= 500) {
            towers.emplace_back(x, y);
            credits -= 500; // Restar créditos al colocar una torre
        }
        else {
            std::cout << "Dinero insuficiente\n";
        }
    }
}

void Game::waitForKeyPress() {
    _getch(); // Espera a que se presione una tecla
}

void Game::checkEndCondition() {
    if (lives <= 0) {
        gameOver = true;
    }
}

void Game::promptForTowerPlacement() {
    int x, y;
    bool validPosition = false;

    std::cout << "\n";
    std::cout << "                                                0 1 2 3 4 5 6 7 8 9 (X)\n";
    std::cout << "                                              _______________________\n";
    std::cout << "                                            0 | # # # # # # # # # # |\n";
    std::cout << "                                            1 | E   #       # # # # |\n";
    std::cout << "                                            2 | #   #   #   # # # # |\n";
    std::cout << "                                            3 | #   #   #   # # # # |\n";
    std::cout << "                                            4 | #   #   #   # # # # |\n";
    std::cout << "                                            5 | #   #   #   # # # # |\n";
    std::cout << "                                            6 | #   #   #   # # # # |\n";
    std::cout << "                                            7 | #   #   #   # # # # |\n";
    std::cout << "                                            8 | #       #         S |\n";
    std::cout << "                                            9 | # # # # # # # # # # |\n";
    std::cout << "                                           (Y)-----------------------";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Ingrese la coordenada en x para colocar una torreta: ";
    std::cin >> x;
    std::cout << "Ingrese la coordenada en y para colocar una torreta: ";
    std::cin >> y;

    while (!validPosition) {
        if (map.isWall(x, y)) {
            placeTower(x, y);
            validPosition = true;
        }
        else {
            std::cout << "No se puede colocar una torreta en esa posición. Intente nuevamente.\n";
            std::cout << "Ingrese la coordenada en x para colocar una torreta: ";
            std::cin >> x;
            std::cout << "Ingrese la coordenada en y para colocar una torreta: ";
            std::cin >> y;
        }
    }
}

void Game::askToPlaceTower() {
    char choice;
    std::cout << "¿Quieres colocar una torreta? (s/n): ";
    std::cin >> choice;

    if (choice == 's' || choice == 'S') {
        promptForTowerPlacement();
    }
}



