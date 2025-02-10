
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

//#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

class SerpientesEscaleras {
public:
    SerpientesEscaleras(int N, int K,const unordered_map<int,int>& lad):distancia(N*N,-1),visitados(N* N, false),mLad(lad){
        tiradas = bfs(N * N,K);
    }

    int minTiradas() { return tiradas; }

private:
    const unordered_map<int, int>& mLad;
    int tiradas;
    vector<bool>visitados;
    vector<int> distancia;


    int adyacente(int v,int i) {
        if (mLad.count(v + i)) {
            return mLad.at(v + i);
        }
        return v + i;
    }


    int bfs(int N2,int K) {
        distancia[0] = 0;
        queue<int> cola; cola.push(0);
        while (!cola.empty())
        {
            int v = cola.front(); cola.pop();
            for (int i = 1; i <= K && v+1>0; i++) {

                int w = adyacente(v, i);
                
                if (distancia[w] == -1) {
                    distancia[w] = distancia[v] + 1;
                    if (w == N2-1) return distancia[w];
                    else cola.push(w);
                }
            }
        }
        return distancia[N2-1];
    }
};



 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, S, E;
    
    cin >> N >> K >> S >> E;

    if (N==K&& K==S&&S==E&&E==0)
        return false;
    
    unordered_map<int, int> escaleras;

    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < S + E; i++) {
        int a, b;
        cin >> a >> b;
        escaleras[a-1]= b-1;
    }
    
    SerpientesEscaleras ser(N,K,escaleras);

    cout<<ser.minTiradas()<<"\n";
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
