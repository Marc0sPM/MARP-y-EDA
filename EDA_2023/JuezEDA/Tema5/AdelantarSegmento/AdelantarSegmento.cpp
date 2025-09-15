// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"


// función que resuelve el problema
void resolver(list<char>& datos, int pos, int lon, int k) {
    datos.adelantarSegmento(pos, lon , k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int elems, pos, lon, k;
    char c;
    std::cin >> elems >> pos >> lon >> k;
    list<char> lista;

    for(int i = 0; i < elems; ++i) {
        std::cin >> c;
        lista.push_back(c);
    }

    resolver(lista, pos, lon, k);
    // escribir sol

    list<char>::iterator it = lista.begin();
    while(it != lista.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}