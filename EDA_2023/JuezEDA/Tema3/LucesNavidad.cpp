//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<int>& soluc, int numBombillas, int numTipoBombillas, int k, int consumoTotal, int consumoMax, const vector<int>& totalesPorColor) {
    if(consumoTotal > consumoMax) return false;
    else {
        for(int i = 0; i < numTipoBombillas; ++i) {
            int restoBombillas = (k + 1) - totalesPorColor[i];
            if(totalesPorColor[i] > restoBombillas + 1) return false;
        }
        if(numBombillas >= 3) {
            for(int l = 1; l < numBombillas - 1; ++l) {
                if((soluc[l - 1] == soluc[l] && soluc[l] != -1) && (soluc[l] == soluc[l + 1] && soluc[l] != -1)) return false;
            }
        }

        return true;
    }
}

void resolver(int& solucion, vector<int>& soluc, int numBombillas, int numTipoBombillas, int k, int consumoTotal, int consumoMax, vector<int> consumoIndividual, vector<int>& totalesPorColor) {
    for(int i = 0; i < numTipoBombillas; ++i) {
        soluc[k] = i;
        consumoTotal += consumoIndividual[i];
        ++totalesPorColor[i];
        if(esValida(soluc, numBombillas, numTipoBombillas, k, consumoTotal, consumoMax, totalesPorColor)){
            if(k == numBombillas - 1) solucion++;
            else resolver(solucion, soluc, numBombillas, numTipoBombillas, k + 1, consumoTotal, consumoMax, consumoIndividual, totalesPorColor);
        }

        consumoTotal -= consumoIndividual[i];
        --totalesPorColor[i];
        soluc[k] = -1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m, consumoMax;
    int combinaciones = 0;
    cin >> n;
    if (n == 0) return false;
    cin >> m >> consumoMax;
    vector<int> consumosPorColor(m);
    for (int& e : consumosPorColor) cin >> e;
    vector<int> soluc(n, -1);
    int k = 0;
    vector<int> totalesPorColor(m,0);
    int solucion = 0;
    resolver(solucion, soluc, n, m, 0, 0, consumoMax, consumosPorColor, totalesPorColor);
    // Salida
    std::cout << solucion << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}