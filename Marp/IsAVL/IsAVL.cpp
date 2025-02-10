
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "Bintree.h"
#include <string>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */
template<typename T>
bool isAVL(BinTree<T>& t,T leftMax, T rightMin,int& mH) {
    bool equilibardo;
    bool busqueda;

    if (t.empty()) {
        mH = 0;
        return true;
    }

    int hL;
    int hR;

    bool AVL = isAVL(t.left(),max(t.leftMax,t.root()),min(rightMin,t.root()),hL) && 
        isAVL(t.right(), max(t.leftMax, t.root()), min(rightMin, t.root()),hR);


    mH = max(hL, hR);

    equilibardo =abs(hL - hR) <= 1;
    busqueda = leftMax < rightMin;

    

    return AVL && equilibardo && busqueda;
}

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    char type;
    cin >> type;
    if (!std::cin)  // fin de la entrada
        return false;
    
    // resolver el caso posiblemente llamando a otras funciones
    if (type == 'N') {
        BinTree<int> a = read_tree<int>(cin);

    }
    else if (type == 'P') {
        BinTree<string> a = read_tree<string>(cin);
    }

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
