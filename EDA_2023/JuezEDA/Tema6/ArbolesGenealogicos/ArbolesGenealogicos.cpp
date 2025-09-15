// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <math.h>

bool padre(const bintree<int>& arbol) { //O(1)
    if(arbol.left().empty()) return true;
    else {
        if(arbol.right().empty()) return arbol.root() - arbol.left().root() >= 18;
        else return arbol.root() - arbol.left().root() >= 18 && arbol.root() - arbol.right().root() >= 18;
    }
}

bool hijos(const bintree<int>& arbol) { //O(1)
    if(arbol.left().empty()) return true;
    else {
        if(arbol.right().empty()) return true;
        else return arbol.left().root() - arbol.right().root() >= 2;
    }
}

struct Familia {
    bool cumple;
    int generaciones;
    Familia(bool cumple, int gen) : cumple(cumple), generaciones(gen) {}
};

// función que resuelve el problema
Familia resolver(const bintree<int>& arbol, int genTMP = 0) { //O(n), siendo n el número de integrantes de la familia
    if(arbol.empty()) return Familia(true, genTMP);
    else if(arbol.left().empty() && !arbol.right().empty() || !padre(arbol) || !hijos(arbol)) return Familia(false, genTMP);
    else {
        Familia parteIzq = resolver(arbol.left(), genTMP + 1);
        Familia parteDcha = resolver(arbol.right(), genTMP + 1);

        return Familia(parteIzq.cumple && parteDcha.cumple, std::max(parteIzq.generaciones, parteDcha.generaciones));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol;

    arbol = leerArbol(-1);

    Familia sol = resolver(arbol);
    // escribir sol

   sol.cumple ? std::cout << "SI " << sol.generaciones << std::endl : std::cout << "NO" << std::endl;

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