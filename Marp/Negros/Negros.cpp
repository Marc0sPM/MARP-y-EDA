
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


using Mapa = std::vector<std::string>;

class Manchas {
public:
    Manchas(Mapa const& M):F(M.size()),C(M[0].size()),visit(F,vector<bool>(C,false)),num(0),maxim(0){
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!visit[i][j] && M[i][j] == '#') {
                    ++num;
                    int nuevotam = dfs(M, i, j);
                    maxim = max(maxim, nuevotam);
                }
            }
        }
    }

    int maxMan() { return maxim; }
    int numMan() { return num; }
private:
    const std::vector<std::pair<int, int>> dirs = { {1,0},{-1,0},{0,1},{0,-1} };
    int dfs(const Mapa& M,int fil, int col) {
        visit[fil][col] = true;
        int tam = 1;
        for (auto d : dirs) {
            int ni = fil + d.first, nj = col + d.second;
            if (correcta(ni, nj) &&M[ni][nj]=='#' && !visit[ni][nj]) {
                tam += dfs(M, ni, nj);
            }
        }
        return tam;
    }
    int F, C;
    std::vector<std::vector<bool>> visit;
    int num;
    int maxim;
    bool correcta(int i, int j)const {
        return 0 <= i && i < F && 0 <= j && j < C;
    }
};


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int fils;
    int cols;
    std::cin >> fils >> cols;
    if (!std::cin)  // fin de la entrada
        return false;

    Mapa m(fils);
    for (string& s : m) {
        cin >> s;
    }

    Manchas manch(m);
    // resolver el caso posiblemente llamando a otras funciones
    cout << manch.numMan() << " " << manch.maxMan() << "\n";

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
