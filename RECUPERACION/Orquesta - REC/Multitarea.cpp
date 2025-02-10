
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

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct instrumento {
    int musicos, partituras;
};
bool operator <(instrumento const& a, instrumento const& b) {
    return (b.musicos * b.partituras < );
}

bool resuelveCaso() {

    int P, N; 
    cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    int partituras_restantes = P - N;
    priority_queue<instrumento> lista;
    // Leemos instrumentos
    for (int i = 0; i < N; ++i) {
        instrumento a;
        cin >> a.musicos;
        a.id = i;
        //Suponemos que en el inicio siempre hay al menos un partitura para cada tipo de instrumento
        a.partituras = 1;
        lista.push(a);
    }

    //Si hay partituras de sobra, 
    if (partituras_restantes > 0) {
        while (partituras_restantes--) {
            instrumento a = lista.top(); lista.pop();
            a.partituras++;
            lista.push(a);
        }
        instrumento a = lista.top();
        int final = a.musicos / a.partituras;
        int resto = a.musicos % a.partituras;
        final += resto;
        std::cout << final << "\n";
    }
    else {
        instrumento a = lista.top();
        std::cout << a.musicos << "\n";
    }
    
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
