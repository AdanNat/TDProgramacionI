#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility> // para std::pair

// Clase que representa el mapa del juego
class Map {
public:
    Map(int width, int height); // Constructor
    ~Map(); // Destructor

    void draw() const; // M�todo para dibujar el mapa
    void clear(); // M�todo para limpiar el mapa
    char getTile(int x, int y) const; // Obtener el car�cter en una posici�n
    void setTile(int x, int y, char tile); // Establecer un car�cter en una posici�n
    bool isWall(int x, int y) const; // Verificar si una posici�n es una pared
    bool isPath(int x, int y) const; // Verificar si una posici�n es parte del camino
    std::pair<int, int> getStart() const; // Obtener la posici�n de inicio
    std::pair<int, int> getEnd() const; // Obtener la posici�n de fin

private:
    void initializeGrid(); // M�todo para inicializar la cuadr�cula
    int width; // Ancho del mapa
    int height; // Altura del mapa
    std::vector<std::vector<char>> grid; // Cuadr�cula del mapa
    std::pair<int, int> start; // Posici�n de inicio
    std::pair<int, int> end; // Posici�n de fin
};

#endif // MAP_H