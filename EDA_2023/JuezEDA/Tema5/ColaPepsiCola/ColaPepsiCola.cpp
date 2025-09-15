// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

// función que resuelve el problema
void resolver(queue<int>& cola, int pringao, queue<int>& colegas) {
    cola.colar(pringao, colegas);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    queue<int> cola, colegas;
    int num = -17, pringao;
    while(num != -1) {
        std::cin >> num;
        if(num != -1) cola.push(num);
    }
    std::cin >> pringao;
    num = -17;
    while(num != -1) {
        std::cin >> num;
        if(num != -1) colegas.push(num);
    }

    int n;
    for (int i = 0; i < cola.size(); ++i){
        n = cola.front();
        std::cout << n << " ";
        cola.pop();
        cola.push(n);
    }
    std::cout << std::endl;

    resolver(cola, pringao, colegas);
    while (!cola.empty()){
        std::cout << cola.front() << " ";
        cola.pop();
    }
    std::cout << std::endl;
    // escribir sol

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