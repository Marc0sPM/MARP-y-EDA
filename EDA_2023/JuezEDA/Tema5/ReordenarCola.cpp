// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <deque>

// función que resuelve el problema
void resolver(std::queue<int>& datos) { //O(2n), lineal en n, siendo n el número de elementos en la cola
    std::deque<int> tmp;

    tmp.push_back(datos.front()); //O(1)
    datos.pop(); //O(1)

    auto max = tmp.begin(), min = tmp.begin(); //O(1)

    while(!datos.empty()) { //n iteraciones
        if(datos.front() >= *max) {
            tmp.push_back(datos.front()); //O(1)
            max = tmp.end();
            --max;
        }
        else if(datos.front() <= *min) {
            tmp.push_front(datos.front()); //O(1)
            min = tmp.begin();
        }
        datos.pop(); //O(1)
    }
    while(!tmp.empty()) { //n iteraciones
        datos.push(tmp.front()); //O(1)
        tmp.pop_front(); //O(1)
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elems, num;
    std::cin >> elems;
    if (elems == 0)
        return false;
    std::queue<int> datos;

    for(int i = 0; i < elems; i++) {
        std::cin >> num;
        datos.push(num);
    }

    resolver(datos);

    // escribir sol

    for(int i = 0; i < elems - 1; ++i) {
        std::cout << datos.front() << " ";
        datos.pop();
    }
    std::cout << datos.front() << std::endl;
    datos.pop();

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
