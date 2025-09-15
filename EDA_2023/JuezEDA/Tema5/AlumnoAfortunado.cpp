// Alejandro Massó Martínez
// VJ3O


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


// función que resuelve el problema
int resolver(std::list<int> datos, int saltos) { //O((n-1) * k), siendo n el número de elementos y k el número de saltos
    auto it = datos.begin();
    if(datos.size() == 1) return *it;
    while(datos.size() != 1) {
        for(int i = 0; i < saltos; ++i) {
            ++it;
            if(it == datos.end()) it = datos.begin();
        }
        it = datos.erase(it);
        if(it == datos.end()) it = datos.begin();
    }
    return datos.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAlumnos = 0, saltos = 0;
    std::cin >> numAlumnos >> saltos;
    if (numAlumnos == 0 && saltos == 0)
        return false;

    std::list<int> datos;
    for(int i = 1; i <= numAlumnos; ++i) {
        datos.push_back(i);
    }

    int sol = resolver(datos, saltos);

    // escribir sol
    std::cout << sol << std::endl;

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
