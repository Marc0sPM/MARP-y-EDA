//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"
using namespace std;


template <class T>
void minimo(bintree<T> const& tree, T& elemMinimo){ //O(n) -> recorremos todo el árbol de arriba a abajo (dos llamadas recursivas de tamaño "mitad")
    if(tree.empty()) return;
    else {
        if(tree.root() < elemMinimo) elemMinimo = tree.root();
        minimo(tree.left(), elemMinimo);
        minimo(tree.right(), elemMinimo);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    cin >> tipo;

    if (! std::cin)
        return false;

    if(tipo == 'N') {
        bintree<int> numTree;
        int intMinimo;
        numTree = leerArbol(-1);
        intMinimo = numTree.root();
        minimo(numTree, intMinimo);
        cout << intMinimo << endl;
    }
    else if (tipo == 'P') {
        bintree<string> stringTree;
        string stringMinimo;
        string vacio = "#";
        stringTree = leerArbol(vacio);
        stringMinimo = stringTree.root();
        minimo(stringTree, stringMinimo);
        cout << stringMinimo << endl;
    }

    // escribir sol
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
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
