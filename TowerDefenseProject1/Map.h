#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility> // para std::pair

// Clase que representa el mapa del juego
class Map {
public:
    Map(int width, int height); // Constructor
    ~Map(); // Destructor

    void draw() const; // Método para dibujar el mapa
    void clear(); // Método para limpiar el mapa
    char getTile(int x, int y) const; // Obtener el carácter en una posición
    void setTile(int x, int y, char tile); // Establecer un carácter en una posición
    bool isWall(int x, int y) const; // Verificar si una posición es una pared
    bool isPath(int x, int y) const; // Verificar si una posición es parte del camino
    std::pair<int, int> getStart() const; // Obtener la posición de inicio
    std::pair<int, int> getEnd() const; // Obtener la posición de fin

private:
    void initializeGrid(); // Método para inicializar la cuadrícula
    int width; // Ancho del mapa
    int height; // Altura del mapa
    std::vector<std::vector<char>> grid; // Cuadrícula del mapa
    std::pair<int, int> start; // Posición de inicio
    std::pair<int, int> end; // Posición de fin
};

#endif // MAP_H