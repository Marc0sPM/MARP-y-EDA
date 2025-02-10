
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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
#define MAX 10000
#define INF 1000000000

int adyacente(int v, int i) {
    switch (i) {
    case 0: return (v + 1) % MAX;
    case 1: return (v * 2) % MAX;
    case 2: return v / 3;
    }
}


int bfs(int origin, int dest) {
    if (origin == dest) return 0;
    vector<int> distancia(MAX, INF);
    distancia[origin] = 0;
    queue<int> cola; cola.push(origin);
    while (!cola.empty())
    {
        int v = cola.front(); cola.pop();
        for (int i = 0; i < 3; i++) {
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == dest) return distancia[w];
                else cola.push(w);
            }
        }
    }


}

bool resuelveCaso() {
    int origen, dest; 
    cin >> origen >> dest;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    cout << bfs(origen, dest)<<"\n";
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
