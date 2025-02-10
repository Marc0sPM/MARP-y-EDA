
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


struct consulta {
    int id;
    int periodo;
    int tiempo;
};

const bool operator<(const consulta& a, const consulta& b) {
    return a.tiempo>b.tiempo ||(a.tiempo == b.tiempo&&a.id >b.id);
}

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int64_t a;
    cin >> a;
    if (a == 0)
        return false;

    priority_queue<consulta> queue;
    for (int i = 0; i < a; i++) {
        int id;
        int periodo;
        cin >> id;
        cin >> periodo;
        queue.push({ id,periodo,periodo });
    }
    cin >> a;
    for (int i = 0; i < a; i++) {
        consulta aux = queue.top(); queue.pop();
        cout << aux.id << "\n";
        aux.tiempo += aux.periodo;
        queue.push(aux);
    }
    
    cout << "---" << "\n";

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
