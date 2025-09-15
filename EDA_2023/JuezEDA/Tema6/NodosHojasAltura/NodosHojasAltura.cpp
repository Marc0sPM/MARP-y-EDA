//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
int nodos(bintree<T> const& tree){ //O(n) porque hacemos un preorder, que tiene complejidad lineal
    vector<T> nodos = tree.preorder();
    return nodos.size();
}

template <class T>
int hojas(bintree<T> const& tree) { //O(n) -> tenemos 2 llamadas recursivas de tamaño "mitad" con llamadas a funciones constantes
    if(tree.empty()) return 0;
    else if (esHoja(tree)) return 1;
    else {
        int hojasIz = hojas(tree.left());
        int hojasDr = hojas(tree.right());
        return hojasIz + hojasDr;
    }
}

template <class T>
int altura(bintree<T> const& tree) { //O(n) -> tenemos 2 llamadas recursivas de tamaño "mitad" con llamadas a funciones constantes
    if(tree.empty()) return 0;
    else {
        int alturaIz = altura(tree.left());
        int alturaDr = altura(tree.right());
        return max(alturaDr, alturaIz) + 1;
    }
}

template <class T>
bool esHoja(bintree<T> const& tree) { //O(1) -> tanto left, como right como empty son operaciones con complejidad constante
    if(tree.left().empty() && tree.right().empty()) return true;
    else return false;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
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
