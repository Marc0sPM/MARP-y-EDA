//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Nodo {
    int numero;
    int profundidad;
    Nodo(int n, int prof) : numero(n), profundidad(prof) {}
};

bool esPrimo(int i) { //O(i / 2), es decir, casi lineal en el número introducido
    int tmp = i/2;
    if(i == 0 || i == 1) return false;
    for(int j = 2; j <= tmp; ++j) {
        if(i % j == 0) return false;
    }
    return true;
}

Nodo accesible(bintree<int> const& tree, int profundidad = 1){ //O(n * (k / 2)), siendo n el
    // número de nodos del árbol y k el número contenido en el nodo
    if(tree.empty() || esPrimo(tree.root())) return Nodo(-1, profundidad);
    else if(tree.root() % 7 == 0) return Nodo(tree.root(), profundidad);
    else {
        Nodo nodosIzq = accesible(tree.left(), profundidad + 1);
        Nodo nodosDcha = accesible(tree.right(), profundidad + 1);

        if(nodosIzq.numero != -1 && nodosDcha.numero != -1) {
            if((nodosIzq.profundidad <= nodosDcha.profundidad)) return nodosIzq;
            else return nodosDcha;
        }
        else if(nodosIzq.numero != -1 && nodosDcha.numero == -1) return nodosIzq;
        else return nodosDcha;


    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    Nodo n = accesible(tree);

    if(n.numero == -1) cout << "NO HAY" << endl;
    else cout << n.numero << " " << n.profundidad << endl;
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
