/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class  CaminoDFS {
private:
    std::vector<bool> visit;
    std::vector<int> ant;
    int s; // vertice origen
    std::vector<bool> colores; 
    bool bipartito = true; 

    void dfs(Grafo const& G, int v) {
        visit[v] = true; 
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                colores[w] = !colores[v];
                dfs(G, w);
            }
            else if (visit[w] && colores[v] == colores[w])
                bipartito = false; 
            
        }
    }

public:
    CaminoDFS(Grafo const& G, int s) :
        visit(G.V(), false),
        ant(G.V()), s(s),
        colores(G.V(), false)
    {
        colores[s] = true; 
        dfs(G, s); 

        for (int i = 0; i < G.V(); i++) {
            if (!visit[i]) dfs(G, i);
        }
    }

    bool esBipartito(Grafo const& G) {
        return bipartito; 
    }
};
bool resuelveCaso() {

    int V, A;
    cin >> V >> A; 

   if (!std::cin)  // fin de la entrada
      return false;

   Grafo g(V);
   for (int i = 0; i < A; i++) {
       int a, b;
       cin >> a >> b;
       g.ponArista(a, b);
   }
   // Suponiendo que los vertices siempre empiezan en 0
   CaminoDFS dfs(g, 0);

   // escribir la solución
   std::cout << (dfs.esBipartito(g) ? "SI\n" : "NO\n");

   return true;
}
//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in("casos.txt");
   if (!in.is_open())
      cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
#endif
   return 0;
}
