
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
//#include <...>
using namespace std;

#include "Grafos.h"  // propios o los de las estructuras de datos de clase
#include "CaminosDFS.h" 

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool esArbolLibre(Grafo const& g) {
    CaminosDFS c = CaminosDFS(g);

    return c.esAciclico(g) && c.esConexo();
}

bool resuelveCaso() {

    // leer los datos de la entrada
    Grafo g = Grafo(cin);

    if (!std::cin)  // fin de la entrada
        return false;

    if (esArbolLibre(g)) cout << "SI\n";
    else cout << "NO\n";
    
   
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
