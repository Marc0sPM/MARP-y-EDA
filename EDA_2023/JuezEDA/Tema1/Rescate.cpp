// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> alturas, int alturaVuelo) { //O(n) -> el bucle while recorre todos los
                                                                        // elementos del vector alturas solo una vez,
                                                                        //es decir, a más elementos, más tiempo tarda
    int longitud = 0, ini = 0, fin = 0, longitudTMP = 0, iniTMP = 0, finTMP = 0;
    std::vector<int> indices;

    while(fin < alturas.size()) {
        if(alturas[fin] <= alturaVuelo) {
            longitud = 0;
            fin++;
            ini = fin;
        }
        else {
            longitud++;
            if(longitud > longitudTMP) {
                iniTMP = ini;
                finTMP = fin;
                longitudTMP = longitud;
            }
            fin++;
        }
    }
    indices.push_back(iniTMP); indices.push_back(finTMP);
    return indices;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numArboles, alturaVuelo, arbol;
    std::vector<int> alturas;
    std::cin >> numArboles; std::cin >> alturaVuelo;
    for(int i = 0; i < numArboles; i++) {
        std::cin >> arbol;
        alturas.push_back(arbol);
    }

    std::vector<int> sol = resolver(alturas, alturaVuelo);
    // escribir sol
    std::cout << sol[0] << " " << sol[1] << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
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