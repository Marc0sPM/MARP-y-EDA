// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>

// función que resuelve el problema
/**
*   La complejidad del algoritmo es lineal respecto a la longitud de cada palabra, tomemos los valores n y m,
*   y lineal a la constante 26, cantidad de letras del abecedario.
* 
*   Resultando en O(n + m + 26) --> O(n + m)  
*/
 bool resolver(std::string a, std::string b) {
     if (a.size() != b.size()) return false; 

     std::array<int, 26> freq = { 0 };

     // Recorremos la primera palabra, y vamos sumando la frecuencia de caracteres
     for (char c : a) {
         freq[c - 'a']++;
     }
     // Restamos la frecuencia
     for (char c : b) {
         freq[c - 'a']--;
     }

     // Si todos los elementos en freq son 0 significa que se han recorrido los mismo caracteres
     for (int e : freq) {
         if (e != 0) return false;
     }

     return true; 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string a, b; 
    std::cin >> a >> b; 

    std::cout << (resolver(a, b) ? "SI\n" : "NO\n"); 
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