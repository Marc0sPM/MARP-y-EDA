//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

//Calculamos el menor precio de los productos que nos quedan por comprar
int menorPrecio(const vector<vector<int>>& precios, int producto, int supermercados) {
    int menorPrecio = INT_MAX;
    for(int i = 0; i < supermercados; ++i) {
        if(precios[i][producto] < menorPrecio) {
            menorPrecio = precios[i][producto];
        }
    }
    return menorPrecio;
}

// Hacemos una estimación del menor precio que podemos pagar por los artículos que nos queden en los supermercados que podamos
int estimacionGasto(const vector<vector<int>>& precios, int productoActual, int supermercados, int productos) {
    int gasto = 0;
    for(int i = productoActual + 1; i < productos; ++i) {
        gasto += menorPrecio(precios, i, supermercados);
    }
    return gasto;
}

// función que resuelve el problema:
//p es el producto actual, n es el número de productos, m el número de supermercados
void resolver(const vector<vector<int>>& precios, vector<int>& comprasPorSupermercado, int p, int n, int m, int gasto, int& mejorGasto){
        for(int i = 0; i < m; ++i) {
            if(comprasPorSupermercado[i] < 3) {
                gasto += precios[i][p];
                ++comprasPorSupermercado[i];
                if(p == n - 1) {
                    if(gasto < mejorGasto) mejorGasto = gasto;
                }
                else {
                    if(gasto + estimacionGasto(precios, p, m, n) < mejorGasto) {
                        //SOLUCIÓN PROMETEDORA
                        ++p;
                        resolver(precios, comprasPorSupermercado, p, n, m, gasto, mejorGasto);
                        --p;
                    }
                }
                gasto -= precios[i][p];
                --comprasPorSupermercado[i];
            }
        }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    int mejorGasto = INT_MAX;
    cin >> m >> n;
    vector<vector<int>> precios(m,vector<int>(n));
    vector<int> comprasPorSupermercado(m , 0);
    // Lectura de datos
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> precios[i][j];
        }
    }
    resolver(precios, comprasPorSupermercado ,0, n ,m, 0, mejorGasto);
    cout << mejorGasto << endl;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
