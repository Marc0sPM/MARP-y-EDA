// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"



// función que resuelve el problema
int resolver(const Polinomio& datos, int x) {
    return datos.evaluar(x);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int coeficiente = 1, exponente = 1, numCasos, caso;
    Polinomio datos;

    while(coeficiente != 0 || exponente != 0) {
        std::cin >> coeficiente >> exponente;
        if(coeficiente != 0 || exponente != 0) datos.addMonomio(coeficiente, exponente);

        if (! std::cin)
            return false;
    }

    std::cin >> numCasos;
    std::vector<int> casos;
    for(int i = 0; i < numCasos; i++) {
        std::cin >> caso;
        casos.push_back(caso);
    }

    // escribir sol

    for(int j = 0; j < numCasos; j++) {
        int sol = resolver(datos, casos[j]);
        std::cout << sol << " ";
    }
    std::cout << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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