//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Caminos {
    int caminoDiametral;
    int caminoInterno;
    Caminos(int cD, int cI): caminoDiametral(cD), caminoInterno(cI) {}
};

bool esHoja(bintree<char> const& tree) { //O(1) -> tanto left, como right como empty son operaciones con complejidad constante
    if(tree.left().empty() && tree.right().empty()) return true;
    else return false;
}

Caminos resolver(bintree<char> arbol, bool primeraIt = true) { //O(n), lineal en el número de elementos del árbol
    if(arbol.empty()) return Caminos(0, 0);
    else if(esHoja(arbol)) return Caminos(1, 1);
    else {
        Caminos izq = resolver(arbol.left(), false);
        Caminos dcha = resolver(arbol.right(), false);

        if(primeraIt) {
            if(izq.caminoInterno > izq.caminoDiametral + dcha.caminoDiametral) return Caminos(izq.caminoInterno, izq.caminoInterno);
            else if(dcha.caminoInterno > izq.caminoDiametral + dcha.caminoDiametral) return Caminos(dcha.caminoInterno, dcha.caminoInterno);
            else return Caminos(izq.caminoDiametral + dcha.caminoDiametral + 1, izq.caminoInterno);
        }

       if(!arbol.left().empty() && !arbol.right().empty()) return Caminos(max(izq.caminoDiametral, dcha.caminoDiametral) + 1, izq.caminoDiametral + dcha.caminoDiametral + 1);
       else return Caminos(max(izq.caminoDiametral, dcha.caminoDiametral) + 1, max(izq.caminoDiametral, dcha.caminoDiametral) + 1);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');
    cout << resolver(tree).caminoDiametral << endl;
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
