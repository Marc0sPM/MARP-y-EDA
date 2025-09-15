// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValido(const std::vector<std::vector<bool>>& tablero, int fila, int columna, int N) {
    for(int i = 0; i < fila; ++i) {
       if(tablero[i][columna]) return false;
    }

    for(int i = 0; i < columna; ++i) {
        if(tablero[fila][i]) return false;
    }

    for(int j = fila, l = columna; j >= 0 && l >= 0; --j, --l) {
        if(tablero[j][l]) return false;
    }

    for(int j = fila, l = columna; j >= 0 && l < N; --j, ++l) {
        if(tablero[j][l]) return false;
    }

    return true;
}

// función que resuelve el problema
void resolver(int& soluciones, std::vector<std::vector<bool>>& tablero, int N, int k) {
    for(int i = 0; i < N; ++i) {
        if(esValido(tablero, k, i, N)) {
            if(k == N - 1) soluciones++;
            tablero[k][i] = true;
            resolver(soluciones, tablero, N, k+1);
            tablero[k][i] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    std::cin >> N;
    std::vector<std::vector<bool>> soluc(N, std::vector<bool>(N, false));
    int soluciones = 0;
    resolver(soluciones, soluc, N, 0);
    std::cout << soluciones << std::endl;
    // escribir sol
}

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
    system("PAUSE");
#endif

    return 0;
}