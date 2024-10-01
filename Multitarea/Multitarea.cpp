
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

struct Tarea {
    int c, f, p = -1;
};
bool operator<(const Tarea& a, const Tarea& b) {
    return b.c < a.c;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, T;
    cin >> N >> M >> T;
    priority_queue<Tarea> tareas = priority_queue<Tarea>();

    if (!std::cin)  // fin de la entrada
        return false;
    
    for (int i = 0; i < N; i++) {
        Tarea a; 
        cin >> a.c >> a.f;
        tareas.push(a);
    }
    for (int i = 0; i < M; ++i) {
        Tarea a;
        cin >> a.c >> a.f >> a.p;
        tareas.push(a);
    }

   

    // resolver el caso posiblemente llamando a otras funciones
    bool conflicto = false;
    int ocupado = 0;
    while (!conflicto && !tareas.empty() && tareas.top().c < T)
    {
        Tarea primer = tareas.top(); tareas.pop();
        conflicto = primer.c < ocupado;
        ocupado = primer.f;
        if (primer.p > -1) {
            tareas.push({ primer.c + primer.p, primer.f + primer.p, primer.p});
        }
    }

    // escribir la solución
    if (!conflicto) {
        cout << "NO" << endl;
    }
    else {
        cout << "SI" << endl;
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
