
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct GrupoM {
    int partituras;
    int personas;
};

bool operator< (const GrupoM& g1, const GrupoM& g2) {
    return (g1.personas* g2.partituras) < (g2.personas * g1.partituras);
}

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int atriles;
    cin >> atriles;
    if (!std::cin)  // fin de la entrada
        return false;
    int instrumentos;
    cin >> instrumentos;

    priority_queue<GrupoM> cola;

    float aux;
    GrupoM group;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < instrumentos; i++) {
        cin >> aux;
        group.personas = aux;
        group.partituras = 1;
        cola.push(group);
    }


    // escribir la solución
    for(int i = instrumentos; i < atriles;i++)
    {
        group = cola.top(); cola.pop();

        group.partituras++;
        cola.push(group);
    }

    group = cola.top();

    cout << (group.personas / group.partituras)+(group.personas%group.partituras>0)<<endl;

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
