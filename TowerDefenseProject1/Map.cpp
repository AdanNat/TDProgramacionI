#include "Map.h"
#include <iostream>
#include <windows.h> // Para obtener el tama�o de la consola

Map::Map(int width, int height) : width(width), height(height) {
    initializeGrid(); // Inicializar la cuadr�cula del mapa
}

Map::~Map() {}

void Map::initializeGrid() {
    // Definir el dise�o del mapa
    grid = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'E', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', 'S'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Encontrar puntos de entrada y salida
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == 'E') {
                start = { x, y }; // Posici�n de inicio
            }
            if (grid[y][x] == 'S') {
                end = { x, y }; // Posici�n de fin
            }
        }
    }
}

void Map::clear() {
    initializeGrid(); // Reinicializar la cuadr�cula
}

void Map::draw() const {
    // Obtener el tama�o de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    else {
        consoleWidth = 80; // Valor por defecto si no se puede obtener el tama�o
    }

    int mapWidth = width * 2; // Ancho del mapa en caracteres (incluye espacios)
    int paddingLeft = (consoleWidth - mapWidth) / 2;

    // Dibujar el mapa en la consola
    for (const auto& row : grid) {
        for (int i = 0; i < paddingLeft; ++i) {
            std::cout << ' ';
        }
        for (char tile : row) {
            std::cout << tile << ' ';
        }
        std::cout << std::endl;
    }
}

char Map::getTile(int x, int y) const {
    return grid[y][x]; // Obtener el car�cter en la posici�n (x, y)
}

void Map::setTile(int x, int y, char tile) {
    grid[y][x] = tile; // Establecer un car�cter en la posici�n (x, y)
}

bool Map::isWall(int x, int y) const {
    return grid[y][x] == '#'; // Verificar si la posici�n es una pared
}

bool Map::isPath(int x, int y) const {
    return grid[y][x] == ' ' || grid[y][x] == 'E' || grid[y][x] == 'S'; // Verificar si la posici�n es parte del camino
}

std::pair<int, int> Map::getStart() const {
    return start; // Obtener la posici�n de inicio
}

std::pair<int, int> Map::getEnd() const {
    return end; // Obtener la posici�n de fin
}
