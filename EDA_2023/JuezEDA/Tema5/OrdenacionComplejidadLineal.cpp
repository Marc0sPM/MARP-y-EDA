// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

// La solución a la pregunta del problema es que no ordena la lista, simplemente quita los elementos no
// ordenados, pero no los ordena.

// función que resuelve el problema
void resolver(std::list<int>& lista) { //O(n), recorre una vez la lista
    if(!lista.empty()) {
        auto tmp = lista.begin();
        tmp++;
        auto itAnterior = lista.begin();
        for(auto itActual = tmp; itActual != lista.end();) {
            if((*itActual) < (*itAnterior)) itActual = lista.erase(itActual);
            else {
                ++itAnterior;
                ++itActual;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num = 0;
    std::list<int> lista;
    while(num != -1) {
        std::cin >> num;
        if(num != -1) lista.push_back(num);
    }

    resolver(lista);
    // escribir sol

    if(!lista.empty()) {
        auto it = lista.begin();
        for(int i = 0; i < lista.size() - 1; ++i) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << *it << std::endl;
    }
    else std::cout << std::endl;


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