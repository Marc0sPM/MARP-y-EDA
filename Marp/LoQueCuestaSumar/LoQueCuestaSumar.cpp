
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


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int64_t a;
    cin >> a;
    if (a==0)
        return false;

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> mQueue;

    int64_t num;
    for (int64_t i = 0; i < a; i++) {
        cin >> num;
        mQueue.push(num);
    }
    int64_t val = 0;
    int64_t acum = 0;
    while (mQueue.size() > 2) {
        val = mQueue.top(); mQueue.pop();
        val += mQueue.top(); mQueue.pop();
        mQueue.push(val);
        acum += val;
    }
    if (mQueue.size() == 2) {
        acum += mQueue.top(); mQueue.pop();
        acum += mQueue.top();
    }
    // resolver el caso posiblemente llamando a otras funciones

    cout << acum << endl;

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
