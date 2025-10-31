// Marcos Pérez Martínez
// EDA-GDV 58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int recursion(const std::vector<int>& salarios, int buscado, int ini, int fin) {
    if (ini > fin) return -1; 
    int mid = (ini + fin) / 2; 
    // O(1) -> accesos al vector
    int incremento = salarios[mid] - salarios[mid - 1]; 

    // Al ir descartando la mitad del vector en cada iteración, 
    // queda una complejidad logiritmica de O(log n)
    if (incremento == buscado) return mid;
    else if (incremento < buscado)
        return recursion(salarios, buscado, mid + 1, fin);
    else
        return recursion(salarios, buscado, ini, mid - 1); 

    //Complejidad final: O(log n) + O(1) --> O(log n) ; 
}


int resolver(int buscado, const std::vector<int>& salarios) {
    int n = salarios.size(); 

    if (buscado == 0) return 0; // En el año 0, no hay incremento -> incremento = 0
    if (n < 2) return -1; // si no hay incrementos, return -1

    return recursion(salarios, buscado, 1, n - 1); 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int buscado, n; 
    std::cin >> buscado >> n; 
    std::vector<int> salarios(n); 
    for (int i = 0; i < n; i++)
        std::cin >> salarios[i]; 
    
    int sol = resolver(buscado, salarios);
    // escribir sol
    std::cout << sol << "\n"; 
    
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