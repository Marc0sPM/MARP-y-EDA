//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) { //O(log(n)), se mete en una sola rama de la recursión
    int mitad = (ini + fin) / 2, n = fin - ini;

    if(n == 0) return ini;
    else {
        if(v1[mitad] < v2[mitad]) return resolver(v1, v2, ini, mitad);
        else return resolver(v1, v2, mitad + 1, fin);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size() - 1);
    cout << v1[sol] << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    ifstream in("input2.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
