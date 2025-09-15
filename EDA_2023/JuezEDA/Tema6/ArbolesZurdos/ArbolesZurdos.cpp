//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Nodo {
    int numHijos;
    bool cumpleCondiciones;
    Nodo(int h, bool c) : numHijos(h), cumpleCondiciones(c) {}
};

Nodo zurdo(const bintree<char>& arbol) { //O(n), siendo n el número de elementos del árbol, ya que solo lo recorremos una vez
    if(arbol.empty()) return Nodo(0, true);
    else if((arbol.left().empty() && arbol.right().empty())) return Nodo(1, true);
    else {
        Nodo izq = zurdo(arbol.left());
        if(izq.cumpleCondiciones) {
            Nodo dcha = zurdo(arbol.right());
            if(dcha.cumpleCondiciones) {
                if(izq.numHijos <= dcha.numHijos) return Nodo(0, false);
                else return Nodo(izq.numHijos + dcha.numHijos + 1, true);
            }
            else return Nodo(0, false);
        }
        else return Nodo(0, false);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');

    zurdo(tree).cumpleCondiciones ? cout << "SI" << endl : cout << "NO" << endl;

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
