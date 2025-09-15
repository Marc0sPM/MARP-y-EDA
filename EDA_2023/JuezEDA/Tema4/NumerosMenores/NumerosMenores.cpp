// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"


// función que resuelve el problema
void resolver(std::vector<int> v, int k, Set<int>& s) { //O(n * log(k))
    for(int i = 0; i < v.size(); i++) { //O(n) -> recorre todo el vector v
        if (!s.contains(v[i]) && s.size() <
                                 k) { //Si el elemento no está en el set y el tamaño del set es menor que el número de elementos pedidos
            //O(log(k), siendo k el número de elementos que hay en el vector)
            s.add(v[i]); //Añadimos el elemento //O(log(k));
        } //Orden de esta condición: k * log(k)
        else if (!s.contains(v[i]) &&
                 v[i] < s.getMax()) { //Si el elemento no está en el set y es menor que el máximo; O(log(k))
            s.removeMax(); //O(1)
            s.add(v[i]); //Sustituimos el máximo elemento por nuestro nuevo "máximo" //O(log(k))
        } //Orden de esta condición: (n-k)*log(k)
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k, dato = 0;
    Set<int> s;
    std::cin >> k;
    if (k == 0)
        return false;

    std::vector<int> v1;

    std::cin >> dato;
    while(dato != -1) {
        v1.push_back(dato);
        std::cin >> dato;
    }
    resolver(v1, k, s);


    const int* datos = s.toArray();
    for(int i = 0; i < s.size(); i++) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;

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
