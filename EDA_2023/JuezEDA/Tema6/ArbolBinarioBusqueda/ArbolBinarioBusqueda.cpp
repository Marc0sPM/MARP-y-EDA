//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "bintree_eda.h"
using namespace std;


template <class T>
bool arbolBinarioBusqueda(bintree<T> const& tree, int min, int max){ //O(n) -> recorremos todo el árbol de arriba a abajo
    if(tree.empty()) return true;
    else {
        if(tree.root() <= min || tree.root() >= max) return false;
        return arbolBinarioBusqueda(tree.left(), min, tree.root()) && arbolBinarioBusqueda(tree.right(), tree.root(), max);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int max = INT_MAX;
    arbolBinarioBusqueda(tree, 0, max) ? cout << "SI" << endl : cout << "NO" << endl;
}


#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
