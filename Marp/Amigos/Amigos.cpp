// Amigos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"
//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */



class MaximaComponenteConexa {
public:
    MaximaComponenteConexa(Grafo const& g) :visit(g.V(), false), maxim(0){
        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) {
                int tam = dfs(g,v);
                maxim = max(tam, maxim);
            }
        }
    }
    int maximo() const { return maxim; }
private:
    int dfs(Grafo const& g,int v){
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                tam += dfs(g,w);
            }
        }
        return tam;
    }
    std::vector<bool> visit;
    int maxim;
};


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {
    int numPersonas;
    int relaciones;

    std::cin >> numPersonas;
    std::cin >> relaciones;


    Grafo g(numPersonas);
    // leer los datos de la entrada
    int a, b;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < relaciones;i++) {
        std::cin >> a;
        std::cin >> b;
        g.ponArista(a-1, b-1);
    }
    MaximaComponenteConexa maxi(g);

    
    // escribir la solución
    std::cout << maxi.maximo() << std::endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);;
#endif
    return 0;
}

