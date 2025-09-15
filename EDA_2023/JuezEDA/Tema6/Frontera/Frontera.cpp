//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;

template <class T>
bool esHoja(bintree<T> const& tree) { //O(1) -> tanto left, como right como empty son operaciones con complejidad constante
    return (tree.left().empty() && tree.right().empty());
}

template <class T>
void frontera(bintree<T> const& tree, vector<T>& elemsFrontera){ //O(n) -> recorremos todo el árbol de arriba a abajo (dos llamadas recursivas de tamaño "mitad")
    if(tree.empty()) return;
    else if(esHoja(tree)) elemsFrontera.push_back(tree.root());
    else {
        frontera(tree.left(), elemsFrontera);
        frontera(tree.right(), elemsFrontera);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    vector<int> elemsFrontera;
    tree = leerArbol(-1);
    frontera(tree, elemsFrontera);

    for(int e : elemsFrontera) cout << e << " ";
    cout << endl;
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
