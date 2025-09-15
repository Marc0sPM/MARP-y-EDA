//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"

// función que resuelve el problema
int resolver(std::vector<Horas> trenes, Horas hora, int ini, int fin) { //O(log(n)): tenemos una llamada recursiva de tamaño mitad
    int mitad = (fin + ini) / 2, n = (fin - ini);
    if(n == 1) {
        if(trenes[mitad] < hora) return mitad + 1;
        else return mitad;
    }
    else {
        if(hora < trenes[mitad]) return resolver(trenes, hora, ini, mitad);
        else return resolver(trenes, hora, mitad, fin);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTrenes, numHoras;
    std::cin >> numTrenes >> numHoras;

    if (numTrenes == 0 && numHoras == 0)
        return false;

    std::vector<Horas> horas;
    for(int i = 0; i < numTrenes; i++) {
        Horas h;
        std::cin >> h;
        horas.push_back(h);
    }

    for(int j = 0; j < numHoras; j++) {
        try {
            Horas h;
            std::cin >> h;
            int sol = resolver(horas, h, 0, numTrenes);
            sol >= horas.size() ? std::cout << "NO" << std::endl : std::cout << horas[sol] << std::endl;
        }
        catch(std::exception& e) {
            std::cout << "ERROR" << std::endl;
        }
    }
    std::cout << "---" << std::endl;

    // escribir sol
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
