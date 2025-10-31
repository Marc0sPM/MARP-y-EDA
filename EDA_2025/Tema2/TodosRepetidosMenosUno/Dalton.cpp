
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) return ini; 

    int mid = (ini + fin) / 2; 
    if (v[mid] == v[mid - 1]) {
        if (mid % 2 == 0) return resolver(v, ini, mid - 2);
        return resolver(v, mid + 1, fin);
    }
    else if (v[mid] == v[mid + 1]) {
        if (mid % 2 == 0) return resolver(v, mid + 2, fin);
        return resolver(v, ini, mid - 1);
    }
    else return mid; 
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Llamada a la función resolver
    int sol = resolver(v, 0, v.size() - 1); 

    // Mostrar el resultado
    cout << sol << "\n"; 
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}