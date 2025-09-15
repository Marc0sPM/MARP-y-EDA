// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
ostream& operator<<(ostream& out, vector<char> const& v) {
    for(char c : v) out << c;
    return out;
}

void palabrasRec(vector<char>& soluc, int k, int n, int m, vector<bool>& usadas) {
    for(char c = 'a'; c < 'a' + m; ++c) {
        soluc[k] = c;
        if(!usadas[c - 'a']) {
            if(k == n-1) cout << soluc << endl;
            else {
                usadas[c - 'a'] = true;
                palabrasRec(soluc, k+1, n, m, usadas);
                usadas[c - 'a'] = false;
            }
        }
    }
}

void palabras(int n, int m) {
    vector<char> soluc(n);
    vector<bool> usadas(m, false);
    palabrasRec(soluc, 0, n, m, usadas);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;

    if (! std::cin)
        return false;

    palabras(n, m);
    cout << endl;
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