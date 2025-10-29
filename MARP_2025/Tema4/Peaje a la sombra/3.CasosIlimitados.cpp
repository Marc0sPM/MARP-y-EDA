/*@ <authors>
 *
 * MARP86 Nombre Apellidos
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
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

using Camino = std::deque<int>; 


class  CaminoBFS {
private:
    std::vector<bool> visit;
    std::vector<int> ant; 
    std::vector<int> dist; 
    int s; 
    //bfs devuelve el vector de distancias a cada
    void bfs(Grafo const& g) {

        std::queue<int> q; 
        dist[s] = 0;  visit[s] = true;
        q.push(s); 
        while (!q.empty()) {
            int v = q.front(); q.pop(); 
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; 
                    dist[w] = dist[v] + 1;
                    visit[w] = true; 
                    q.push(w); 
                }
            }
        }
    }

public:
    CaminoBFS(Grafo const& G, int s) :
        visit(G.V(), false),
        ant(G.V()), 
        s(s),
        dist(G.V(), -1)
    {
        bfs(G); 
    }

    std::vector<int>& distancia() { return dist; }
 };
bool resuelveCaso() {

    int N, C, casaAlex, casaLucas, trabajo; 

    cin >> N >> C >> casaAlex >> casaLucas >> trabajo;

   if (!std::cin)  // fin de la entrada
      return false;

   // 
   Grafo ciudad(N);
   for (int i = 0; i < C; i++) {
       int a, b;
       cin >> a >> b;
       ciudad.ponArista(a - 1, b - 1);
   }

   CaminoBFS camA(ciudad, casaAlex - 1);
   std::vector<int> distA = camA.distancia();
   CaminoBFS camL(ciudad, casaLucas - 1);
   std::vector<int> distL = camL.distancia(); 
   CaminoBFS camT(ciudad, trabajo - 1);
   std::vector<int> distT = camT.distancia();
   int costeMin = N; 
   // cogemos la suma menor de la distancia entre todos los bfs
   for (int i = 0; i < N; i++) {
       if (distA[i] != -1 && distL[i] != -1 && distT[i] != -1) {
           costeMin = std::min(costeMin, distA[i] + distL[i] + distT[i]);
       }
   }

   std::cout << costeMin << "\n";
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
