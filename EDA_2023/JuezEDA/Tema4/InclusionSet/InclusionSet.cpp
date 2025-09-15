// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"



// función que resuelve el problema
bool resolver(const Set<int>& s1, const Set<int>& s2 ) {
    return s1 <= s2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elemsSet1, elemsSet2, elem;
    Set<int> s1, s2;

    std::cin >> elemsSet1;
    for(int i = 0; i < elemsSet1; ++i) {
        std::cin >> elem;
        s1.add(elem);
    }

    std::cin >> elemsSet2;
    for(int j = 0; j < elemsSet2; ++j) {
        std::cin >> elem;
        s2.add(elem);
    }

    if (! std::cin)
        return false;


    bool sol = resolver(s1, s2);

    // escribir sol

    sol ? std::cout << "1" << std::endl : std::cout << "0" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}