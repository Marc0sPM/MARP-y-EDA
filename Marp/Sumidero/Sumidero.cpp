
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;

    cin >> V>>A;
    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo d(V);
    Digrafo inv(V);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < A; i++) {
        int a, b;
        cin >> a >> b;
        //genero el grafo inverso de forma directa para ahorrar costes si no se tendria un coste O(V^2)
        d.ponArista(a, b);
        inv.ponArista(b, a);
    }
    // escribir la solución

    int i = 0;
    while (i<d.V()&&
        (d.ady(i).size()!=0 || inv.ady(i).size()!=(V-1)))
    {
        i++;
    }

    if (i == d.V()) {
        cout << "NO\n";
    }
    else {
        cout << "SI " << i << "\n";
    }

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
