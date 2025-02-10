
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Header.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

class Noticias {
public:
    Noticias(Grafo& g):vist(g.V()),userComponentIndexes(g.V()) {
        int iter =0;
        for (int i = 0; i < g.V();i++) {
            if (!vist[i]) {
                componentValues.push_back(dfs(g, i, iter));
                iter++;
            }
        }
    }

    void resolve() {
        for (int ind : userComponentIndexes) {
            std::cout << componentValues[ind] << " ";
        }
        std::cout << "\n";
    }
private:
    std::vector<bool> vist;
    int dfs(Grafo& g, int v,int itNum) {
        vist[v] = true;
        int tam = 1;
        userComponentIndexes[v] = itNum;
        for (auto w : g.ady(v)) {
            if (!vist[w]) {
                vist[w] = true;
                tam += dfs(g, w,itNum);
                userComponentIndexes[w] = itNum;
            }
        }
        return tam;
    }
    std::vector<int>userComponentIndexes;
    std::vector<int>componentValues;
};

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int usuarios;
    int grupos;
    std::cin >> usuarios;
    std::cin >> grupos;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(usuarios);
    
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < grupos; i++) {
        int numEnGrupo;
        std::cin >> numEnGrupo;
        if (numEnGrupo > 0) {
            int val1,val2;
            std::cin >> val1;
            for (int j = 1; j < numEnGrupo; j++) {
                std::cin >> val2;
                g.ponArista(val1 - 1, val2 - 1);
                val1 = val2;
            }
        }
    }
    Noticias noti(g);


    // escribir la solución
    noti.resolve();

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
