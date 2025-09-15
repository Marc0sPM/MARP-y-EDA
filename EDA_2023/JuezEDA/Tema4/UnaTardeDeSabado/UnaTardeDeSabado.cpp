// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Pelicula.h"
#include <algorithm>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<Pelicula>& peliculas) { //O(n * log(n)), siendo n el número de películas
    std::sort(peliculas.begin(), peliculas.end());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int peliculas;
    std::cin >> peliculas;
    if (peliculas == 0)
        return false;

    std::vector<Pelicula> pelis;

    for(int i = 0; i < peliculas; ++i) {
        Pelicula tmp;
        Horas ini, duracion;
        std::string nombre;
        std::cin >> ini >> duracion;
        std::getline(std::cin, nombre);
        pelis.push_back(Pelicula(nombre, ini, duracion));
    }

    resolver(pelis);

    // escribir sol
    for(Pelicula p : pelis) std::cout << p;
    std::cout << "---" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
