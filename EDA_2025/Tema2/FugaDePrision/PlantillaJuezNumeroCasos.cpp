// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



char buscarFugado(const std::vector<char>& v, int ini, int fin, char prim, char ult) {
    int n = fin - ini; 
    if (n == 0) {
        return prim; 
    }
    if (n == 1) {
        if (v[ini] == prim) return ult; 
        else return prim; 
    }

    int mid = (ini + fin) / 2; 


    char esperado = prim + (mid - ini);

    if (v[mid] != esperado) { // Si no coincide con la posicion -> avanzamos por la izq
        return buscarFugado(v, ini, mid, prim, v[mid] - 1);
    }
    else {
        // Avanzamos a la derecha
        return buscarFugado(v, mid + 1, fin, v[mid] + 1, ult);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ult; 
    std::cin >> prim >> ult; 

    int n = ult - prim ; 

    std::vector<char> v(n); 
    for (int i = 0; i < n; i++) std::cin >> v[i]; 

    // escribir sol
    std::cout << buscarFugado(v, 0, v.size(), prim, ult)  << "\n";
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
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