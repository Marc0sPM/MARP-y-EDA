//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Nodo {
    int caudalAcumulado;
    int tramosNavegables;
    Nodo( int c, int t) : caudalAcumulado(c), tramosNavegables(t) {}
};

bool esHoja(bintree<int> const& tree) { //O(1) -> tanto left, como right como empty son operaciones con complejidad constante
    if(tree.left().empty() && tree.right().empty()) return true;
    else return false;
}

Nodo resolver(const bintree<int>& arbol, bool primeraIt = true) { //O(n), recorremos una sola vez el árbol, siendo n el número de elementos que este contenga
    if(arbol.empty()) return Nodo(0, 0);
    else if(esHoja(arbol)) return Nodo(1, 0);
    else {
        Nodo izq = resolver(arbol.left(), false);
        Nodo dcha = resolver(arbol.right(), false);

        if(izq.caudalAcumulado + dcha.caudalAcumulado - arbol.root() < 0) return Nodo(0, izq.tramosNavegables + dcha.tramosNavegables);
        else {
            Nodo tmp(izq.caudalAcumulado + dcha.caudalAcumulado - arbol.root(), izq.tramosNavegables + dcha.tramosNavegables);
            if(!primeraIt && tmp.caudalAcumulado >= 3) tmp.tramosNavegables += 1;
            return tmp;
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);

    cout << resolver(tree).tramosNavegables << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
