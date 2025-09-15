
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
    int ini, fin, periodo = -1; // Por defecto tarea unica
};
bool operator <(Tarea const& a, Tarea const& b) {
    return b.ini < a.ini;
}

bool resuelveCaso() {

    int N, M, T;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> M >> T;
    priority_queue<Tarea> lista;
    
    // Tareas unicas
    for (int i = 0; i < N; i++) {
        Tarea a; 
        cin >> a.ini >> a.fin;
        lista.push(a);
    }
    //Tareas periódicas 
    for (int i = 0; i < M; i++) {
        Tarea b;
        cin >> b.ini >> b.fin >> b.periodo;
        lista.push(b);
    }

    bool conflicto = false;
    int ocupado = 0; // Tiempo hasta que se está ocupacio "top.fin" 

    while (!conflicto && !lista.empty() && lista.top().ini < T) {
        Tarea a; 
        a = lista.top(); lista.pop();
        
        conflicto = a.ini < ocupado;
        ocupado = a.fin;
        if (a.periodo != -1) {
            a.ini += a.periodo;
            a.fin += a.periodo;
            lista.push(a);
        }

    }
    
    std::cout << (conflicto ? "SI\n" : "NO\n") ;



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
