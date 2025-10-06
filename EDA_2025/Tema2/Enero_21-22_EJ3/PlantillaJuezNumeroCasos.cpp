// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



int ultimoConsecutivo(const std::vector<int>& v, int ini, int fin) {

    // Un elemento es consecutivo si su valor v[x] = v[0] + x
    // EJ: v = 1, 2, 3, 4, 5

    // v[4](5) = v[0](1) + 4


    // Caso base: solo un elemento
    if (ini == fin) {
        // Si ese elemento es consecutivo se devuelve
        if (v[ini] == v[0] + (ini - 0)) {
            return v[ini];
        }
        else {
            // SI la secuencia no sigue, el ulitmo elemento consecutivp es el anterior
            return v[ini - 1];
        }
    }

    int mid = (ini + fin) / 2;

    // Si mid es consecutivo, seguimos por la derecha
    if (v[mid] == v[0] + (mid - 0)) {
        return ultimoConsecutivo(v, mid + 1, fin);
    }
    // Si no es consecutivo, comprobamos por la izquierda
    else {
        return ultimoConsecutivo(v, ini, mid);
    }

    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    std::cin >> n; 

    std::vector<int> v(n); 
    for (int i = 0; i < n; i++) std::cin >> v[i]; 

    // escribir sol
    std::cout << ultimoConsecutivo(v, 0, v.size() -1 )  << "\n";
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