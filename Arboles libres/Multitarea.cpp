
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

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Grupo {
    int cant, id; // id ? necesaria
};
bool operator<(const Grupo& a, const Grupo& b) {
    return b.cant > a.cant || (b.cant == a.cant && b.id < a.id);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int p, n;
    cin >> p >> n;
    priority_queue<Grupo> cola;

    if (!std::cin)  // fin de la entrada
        return false;
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cola.push({ k, i });
    }

    while (cola.size() < p) {
        Grupo aux = cola.top();  cola.pop();
        int a, b;
        a = aux.cant / 2;
        b = aux.cant - a;
        // Id del grupo el mismo que se ha dividido
        cola.push({ a, aux.id }); 
        // Id del grupo el proximo valor que no esta cogido por otro grupo [0,... cola.size())
        int c = cola.size();
        cola.push({ b, c - 1});
    }

    std::cout << cola.top().cant << "\n";
   
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
