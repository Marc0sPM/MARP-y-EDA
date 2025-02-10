
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "UnionFind.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int fils, cols;
    cin >> fils >> cols;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<vector<bool>> manchas(fils,vector<bool>(cols));
    char p;
    vector<pair<int, int>> pos = { {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{-1,1},{1,-1},{-1,-1} };
    ConjuntosDisjuntos ufd(fils*cols);

    int maxMancha = 0;

    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0;i < fils;i++) {
        for (int j = 0;j < cols;j++) {
            cin >> p;
            manchas[i][j] = p == '#';

            if (manchas[i][j]) {
                for (int k = 0; k < pos.size(); k++) {
                    int x = j + pos[k].second, y = i + pos[k].first;
                    if (x < cols && x >= 0 && y < fils && y >= 0 && manchas[y][x]) {//valid position
                        ufd.unir(i * cols + j, y * cols + x);
                    }
                }
                maxMancha = max(maxMancha,ufd.cardinal(i * cols + j));
            }

        }
    }

    cout << maxMancha << " ";
    

    int numEnt;
    cin >> numEnt;
    //Coste constante O(log*(N))
    for (int i = 0; i < numEnt; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        manchas[a][b] = true;

        for (int k = 0; k < pos.size(); k++) {
            int x = b + pos[k].second, y = a + pos[k].first;
            if (x < cols && x >= 0 && y < fils && y >= 0 && manchas[y][x]) {//valid position
                ufd.unir(a * cols + b, y * cols + x);
            }
        }
        maxMancha = max(maxMancha, ufd.cardinal(a * cols + b));

        cout << maxMancha << " ";
    }


    // escribir la solución
    cout << "\n";



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
