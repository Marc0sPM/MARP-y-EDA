//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int ini, int fin) { //O(log(n)), se mete en una sola rama de la recursión
    int mitad = (ini + fin) / 2, n = fin - ini, dif = mitad - ini;
    
    if(n == 1) return v[mitad];
    else {
        if(v[ini] + dif == v[mitad]) return resolver(v, mitad, fin);
        else return resolver(v, ini, mitad);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    for (int& e : v1) cin >> e;
    int sol = resolver(v1, 0, v1.size());
    cout << sol << endl;
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
