//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) { //O(log(n)): o bien devuelve el valor o bien hace una de las dos llamadas recursivas
    int mitad = (ini + fin) / 2, anterior = mitad - 1, posterior = mitad + 1;

        if(posterior < fin && sec[mitad] > sec[posterior]) {
            return minimo(sec, mitad, fin);
        }
        else if (anterior >= ini && sec[mitad] > sec[anterior]) {
            return minimo(sec, ini, mitad);
        }
        else return sec[mitad];

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << minimo(sec,0,n) << endl;
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
    //system("PAUSE");
#endif

    return 0;
}