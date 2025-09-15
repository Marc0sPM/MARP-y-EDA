// Nombre del alumno Marcos Perez
// Usuario del Juez EDA-GDV58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool isDalton(const std::vector<int>& vec,int ini, int fin, bool creciente) { // Complejidad O(logN)
    if (fin - ini <= 1) return true; //Caso base, no se puede dividir mas el vector

    int mid = (ini + fin) / 2; 

    bool izq = isDalton(vec, ini, mid, creciente); 
    bool der = isDalton(vec, mid, fin, creciente); 

    bool ordenado; 
    if (creciente) ordenado = vec[mid - 1] < vec[mid]; 
    else ordenado = vec[mid - 1] > vec[mid]; 
    return izq && der && ordenado; 
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N; 
    std::cin >> N; 
    if (N == 0)
        return false;

    std::vector<int> vec; 

    for (int i = 0; i < N; i++) {
        int temp; 
        std::cin >> temp;
        vec.push_back(temp); 
    }

    bool creciente = vec[0] < vec[1]; 
    bool sol = isDalton(vec, 0 , vec.size(), creciente);
    
    // escribir sol
    if (sol) std::cout << "DALTON\n";
    else std::cout << "DESCONOCIDOS\n"; 
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
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
