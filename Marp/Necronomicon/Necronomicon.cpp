/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <authors>
  *
  * MARP98 Ofelia Michelínez
  * MARP99 Filemón Pi
  *
  *@ </authors> */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

#include "Digrafo.h"

using Camino = deque<int>;

//O(V+A)
class CicloDirigido {
public:
    CicloDirigido(Digrafo const& g) :visit(g.V(), false), ant(g.V()), apilado(g.V(), false), hayciclo(false) {
        dfs(g, 0);
    }


    bool hayCiclo() const { return hayciclo; }
    bool finExecut() const { return finExe; }

    Camino const& ciclo() const { return _ciclo; }
private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    Camino _ciclo; // ciclo dirigido (vacío si no existe)
    bool hayciclo;
    bool finExe = false;


    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (hayciclo) {
                return;
            }
            if (!visit[w]) {
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]) {
                hayciclo = true;
                for (int x = v; x != w; x = ant[x])
                    _ciclo.push_front(x);
                _ciclo.push_front(w); _ciclo.push_front(v);
            }
        }
        apilado[v] = false;
    }
};


//O(V+A)
class BFSDirigido {
public:
    BFSDirigido(Digrafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }
    bool hayCamino(int v) const {
        return visit[v];
    }
    int distancia(int v) const {
        return dist[v];
    }
    Camino camino(int v) const {
        if (!hayCamino(v)) throw std::domain_error("No existe camino");
        Camino cam;
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
    int s;

    void bfs(Digrafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>



bool resuelveCaso() {

    int L;
    cin >> L;
    if (!cin)
        return false;

    
    Digrafo g(L+1);


    char ins;
    int num;
    char lastIns = 'A';
    if (L == 1) {
        cin >> ins;
        cout << "SIEMPRE\n";
        return true;
    }



    cin >> ins;
    lastIns = ins;

    for (int i = 1; i < g.V(); i++) {
        switch (lastIns)
        {
        case 'A':
            g.ponArista(i - 1, i);
            break;
        case 'J':
            cin >> num;
            g.ponArista(i-1, num - 1);
            break;
        case 'C':
            cin >> num;
            g.ponArista(i- 1, num - 1);
            g.ponArista(i - 1, i);
            break;
        default:
            break;
        }
        if(i != g.V()-1)
            cin >> lastIns;
    }



    CicloDirigido ciclos(g);
    BFSDirigido cam(g,0);
    

    if (ciclos.hayCiclo()&&!cam.hayCamino(g.V()-1)) {
        cout << "NUNCA\n";
    }
    else if(!ciclos.hayCiclo()&& cam.hayCamino(g.V() - 1)) {
        cout << "SIEMPRE\n";
    }
    else if (ciclos.hayCiclo() && cam.hayCamino(g.V() - 1)) {
        cout << "A VECES\n";
    }


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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
