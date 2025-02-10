
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


class ViablePath {
public:
    ViablePath(const GrafoValorado<int>& g,int a,int umbral):visit(g.V(),false) {
        dfs(g, a, umbral);
    }

    inline bool getViablePath(int b) {
        return visit[b];
    };

private:
    vector<int>visit;


    void dfs(GrafoValorado<int> const& G, int v, int umbral) {
        visit[v] = true;
        for (auto a : G.ady(v)) {
            if (a.valor() >= umbral) {
                int w = a.otro(v);
                if (!visit[w]) {
                    dfs(G, w,umbral);
                }
            }
        }
    }
};

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, E;
    cin >> V >> E;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    GrafoValorado<int> g(V);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.ponArista(Arista<int>(a-1, b-1, c));
    }

    int consul;

    cin >> consul;

    for (int i = 0; i < consul; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        ViablePath path (g, a-1, d);
        cout << (path.getViablePath(b-1)?"SI":"NO");
        cout << "\n";
    }

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
