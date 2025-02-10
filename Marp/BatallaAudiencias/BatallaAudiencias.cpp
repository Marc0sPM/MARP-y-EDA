
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct Canal {
    int maxPrimeTime=0;
};

bool sortPair(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
}


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int mins;
    std::cin >> mins;
    int chanels;
    std::cin >> chanels;
    int updates;
    std::cin >> updates;


    if (!std::cin)  // fin de la entrada
        return false;
    IndexPQ<int,greater<int>> prime (chanels+1);
    //maxPrimeTime
    std::vector<std::pair<int,int>> canales;
    Canal aux;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < chanels; i++) {
        int au;
        std::cin >> au;
        prime.push(i+1,au);
        canales.push_back({i+1, 0});
    }


    int minute;
    int chanel;
    int audience;
    int lastMinute = 0;

    for (int i = 0; i < updates; i++) {
        std::cin >> minute;
        std::cin >> chanel;

        canales[prime.top().elem-1].second += minute - lastMinute;
        
        while (chanel != -1)
        {
            std::cin >> audience;
            prime.update(chanel, audience);
            std::cin >> chanel;
        }

        lastMinute = minute;
    }

    canales[prime.top().elem - 1].second += mins-lastMinute;

    sort(canales.begin(), canales.end(),sortPair);

    int i = 0;
    while (i<canales.size()&&canales[i].second >0)
    {
        std::cout << canales[i].first << " " << canales[i].second << std::endl;
        i++;
    }
    std::cout << "---" << std::endl;
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
