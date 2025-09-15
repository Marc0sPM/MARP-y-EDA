// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

int contarPares(std::vector<int> valores, int ini, int fin) {
    int pares = 0;
    for(int i = ini; i < fin; ++i) {
        if(valores[i] % 2 == 0) pares++;
    }
    return pares;
}

// función que resuelve el problema
bool resolver(std::vector<int> valores, int ini, int fin) { //O(n)
    int mitad = (ini + fin) / 2, elems = fin - ini;
    if(elems == 1) return true;
    else {
        int paresIzq, paresDcha;
        paresIzq = contarPares(valores, ini, mitad); //O(mitad)
        paresDcha = contarPares(valores, mitad, fin); //O(mitad)

        return (abs(paresIzq - paresDcha) <= 2)
        && resolver(valores, ini, mitad) && resolver(valores, mitad, fin); //Dos llamadas recursivas de tamaño mitad
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElems;
    std::cin >> numElems;
    if (numElems == 0)
        return false;

    std::vector<int> valores;
    int valor;
    for(int i = 0; i < numElems; ++i) {
        std::cin >> valor;
        valores.push_back(valor);
    }

    bool sol = resolver(valores, 0, numElems);

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
