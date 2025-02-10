
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <list>
#include <set>
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

class KevinBacon {
public:
    KevinBacon(Grafo&g,int beiconInd):visit(g.V(),false),dist(g.V(),-1){
        if(beiconInd!=0)
            bfs(g,beiconInd);
    }

    int beicon(int ind) {
       return dist[ind];
    }


private:
    std::vector<bool> visit;
    std::vector<int> dist;//all to -1
    void bfs(Grafo& g,int v) {
        visit[v]=true;
        dist[v] = 0;
        queue<int> q;
        q.push(v);
        while (!q.empty())
        {
            int w = q.front(); q.pop();
            for (int n : g.ady(w)) {
                if (!visit[n]) {
                    visit[n] = true;
                    dist[n] = dist[w] + 1;
                    q.push(n);
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int numPelis;
    cin >> numPelis;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    std::unordered_map<std::string, std::list<std::string>> listaPelis;
    std::set<std::string> nombres;
    std::unordered_map<std::string, int> nombreIndice;

    for (int i = 0; i < numPelis; i++) {
        std::string peli;
        cin >> peli;
        int actores;
        cin >> actores;
        for (int j = 0; j < actores; j++) {
            std::string actor;
            cin >> actor;
            listaPelis[peli].push_back(actor);
            nombres.insert(actor);
        }
    }
    
    int iter = 0;
    for (auto a : nombres) {
        nombreIndice[a] = listaPelis.size() + iter;
        iter++;
    }

    Grafo g(listaPelis.size()+nombres.size());


    int pel = 0;
    for (auto lista : listaPelis) {
        for (auto actor : lista.second){
            g.ponArista(pel, nombreIndice[actor]);
        }
        pel++;
    }

    
    KevinBacon kevin(g,nombreIndice["KevinBacon"]);

    int numQueryActors;
    cin >> numQueryActors;
    std::string name;
    for (int i = 0;i < numQueryActors;i++) {
        std::cin >> name;
        int aux = kevin.beicon(nombreIndice[name]);
        if(aux == -1)
            std::cout << name << " " << "INF"<<"\n";
        else
            std::cout << name << " " << aux/2<<"\n";
    }
    std::cout << "---\n";
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
