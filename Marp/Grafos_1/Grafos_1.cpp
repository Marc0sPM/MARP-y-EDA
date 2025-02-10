
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

using Adj = std::vector<int>;

using AdjList = std::vector<Adj>;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // recorrido dfs del grafo si ya se ha visitado ese vetice se le añade 1 a un contador que cuenta cuantas veces se llega hasta el
 // 
 // ================================================================
 //@ <answer>

bool resuelve(int val,const AdjList& adj, std::vector<bool>& visited, std::vector<int>& ant) {
    visited[val] = true;


    for (int w : adj[val]) {

        if (!visited[w]) {
            resuelve(w, adj, visited,ant);
        }
        else {
            ant[val]++;
        }
    }
    return true;
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int V;
    int A;

    std::cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    AdjList graph(V);

    std::vector<bool> visitados(V,false);
    std::vector<int> ant2(V,0);

    ant2[0] = 1;

    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < A; i++) {
        int a;
        int b;
        std::cin >> a;
        std::cin >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    resuelve(0, graph, visitados, ant2);

    int i = 0;
    while (i< ant2.size()&& ant2[i] == 1)
    {
        i++;
    }

    // escribir la solución
    std::cout << ( i==ant2.size() ? "SI" : "NO");

    std::cout << "\n";
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
