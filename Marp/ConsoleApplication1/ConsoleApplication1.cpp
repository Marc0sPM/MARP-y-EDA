
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "BinTreeAVL.h"
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

void resuelve(Set<int>& set,int k) {

}


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    Set<int> set;
    // leer los datos de la entrada

    //if (!std::cin)  // fin de la entrada
    //    return false;

    // resolver el caso posiblemente llamando a otras funciones
    int elems;

    cin >> elems;
    int value;
    if (elems == 0) {
        return false;
    }

    for (int i = 0;i < elems;i++) {
        cin >> value;
        set.insert(value);
    }

    cin >> elems;
    for (int i = 0;i < elems;i++) {
        cin >> value;

        try {
            cout << set.kesimo(value)<<endl;
        }
        catch(exception& e){
            cout << "??" << endl;
        }
    }
    cout << "---"<<endl;
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
