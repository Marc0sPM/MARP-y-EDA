
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(int suma, const vector<vector<bool>>& acumulador, int cantidadNumeros, int valorDeseado, int k, int ultimoValorSumado, int valorASumar, const vector<int>& numeros) {
    if(acumulador[])
    if(ultimoValorSumado == 0) return true;
    else {
        if(ultimoValorSumado == valorASumar) return false;
        else {
            if(suma > valorDeseado) return false;
        }
    }
}

void resolver(int& solucion, int suma, vector<vector<bool>>& acumulador, int cantidadNumeros, int valorDeseado, int k, int ultimoValorSumado, const vector<int>& numeros) {
    for(int i = 0; i < cantidadNumeros; ++i) {
        suma += numeros[i];
        if(esValida(suma, acumulador, cantidadNumeros, valorDeseado, k, ultimoValorSumado, numeros[i], numeros)) {
            if(suma == valorDeseado) solucion++;
            else {

                resolver(solucion, suma, acumulador, cantidadNumeros, valorDeseado, k + 1, numeros[i], numeros);
            }
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, valor;
    cin >> n;
    if (!cin) return false;
    cin >> valor;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int solucion = 0;

    vector<vector<bool>> acumulador(n + 1, vector<bool>(n + 1, true));
    for(int i = 0; i < n; ++i) {
        acumulador[i][i] = false; //Diagonal
    }
    resolver(solucion, 0, acumulador, n, valor, 0, 0, nums);
    // Salida
    std::cout << solucion << std::endl;
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}

