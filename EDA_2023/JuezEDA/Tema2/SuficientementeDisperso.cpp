// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>



// función que resuelve el problema
bool resolver(std::vector<int> valores, int valorDispersion, int ini, int fin) { //O(n): 2 llamadas recursivas de tamaño mitad
    int mitad = (ini + fin) / 2, elems = fin - ini;
    if(elems == 1) return true;
    else {
        if(abs(valores[ini] - valores[fin - 1]) >= valorDispersion) {
            bool izq = resolver(valores, valorDispersion, ini, mitad);
            bool dcha = resolver(valores,valorDispersion, mitad, fin);
            return izq && dcha;
        }
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numTiradas, valorDispersion, valor;
    std::cin >> numTiradas; std::cin>> valorDispersion;
    if(!std::cin) {
        return false;
    }
    std::vector<int> valores;
    for(int i = 0; i < numTiradas; i++) {
        std::cin >> valor;
        valores.push_back(valor);
    }
    bool sol = resolver(valores, valorDispersion, 0, numTiradas);

    // escribir sol
    if(sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("./datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}