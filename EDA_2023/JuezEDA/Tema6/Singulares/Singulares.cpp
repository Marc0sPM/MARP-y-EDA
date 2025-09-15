//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


template <class T>
int singulares(bintree<T> const& tree, int acumulador, int& numNodosSingulares){ //O(n), recorremos todo el árbol en busca de nodos singulares
    if(!tree.empty()) {
        int sumaIzq, sumaDcha;
        sumaIzq = singulares(tree.left(), acumulador + tree.root(), numNodosSingulares);
        sumaDcha = singulares(tree.right(), acumulador + tree.root(), numNodosSingulares);
        if(acumulador == sumaIzq + sumaDcha) numNodosSingulares++;
        return sumaIzq + sumaDcha + tree.root();
    }
    else return 0;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int numNodosSingulares = 0;
    singulares(tree, 0, numNodosSingulares);
    cout << numNodosSingulares << endl;
}


#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
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
