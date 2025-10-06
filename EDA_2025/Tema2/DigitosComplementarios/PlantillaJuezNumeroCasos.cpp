// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

int complementario(int num) {
    if (num < 10) return 9 - num; // caso base: un solo dígito
    int izq = complementario(num / 10);
    int comp = 9 - (num % 10);
    return izq * 10 + comp;
}

// Devuelve el número complementario en orden invertido
int complementarioInvertido(int num, int invertido = 0) {
    if (num == 0) return invertido; // caso base
    int comp = 9 - (num % 10);
    return complementarioInvertido(num / 10, invertido * 10 + comp);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num; 
    std::cin >> num; 


    // escribir sol
    std::cout << complementario(num) << " " << complementarioInvertido(num)<< "\n";
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