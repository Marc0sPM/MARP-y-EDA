// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

void maxMinMitad(std::vector<int> valores, int ini, int fin, int& max, int& min) {
    max = -100;
    min = INT_MAX;
    for(int i = ini; i < fin; ++i) { //O(fin - ini), es decir, O(n)
        if(valores[i] > max) max = valores[i];
        if(valores[i] < min) min = valores[i];
    }
}

// función que resuelve el problema
bool resolver(std::vector<int> valores, int ini, int fin) { //O(n)
    int mitad = (ini + fin) / 2, elems = fin - ini;
    if(elems == 1) return true;
    else {
        int minIzq, maxIzq, minDcha, maxDcha;
        maxMinMitad(valores, ini, mitad, maxIzq, minIzq); //O(n/2)
        maxMinMitad(valores, mitad, fin, maxDcha, minDcha); //O(n/2)

        return (minIzq <= minDcha) && (maxDcha >= maxIzq) &&
        resolver(valores, ini, mitad) && resolver(valores, mitad, fin); //Dos llamadas recursivas de tamaño mitad
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int primNumero;
    std::cin >> primNumero;

    if (primNumero == 0)
        return false;

    std::vector<int> valores;
    while(primNumero != 0) {
        valores.push_back(primNumero);
        std::cin >> primNumero;
    }

    bool sol = resolver(valores, 0, valores.size());

    // escribir sol
    sol ? std::cout << "SI" << std::endl : std::cout << "NO" << std::endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
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
