
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct paciente {
    int id, urgencia;
    std::string nombre; 
};
bool operator<(paciente const& a, paciente const& b) {
    return a.urgencia < b.urgencia || 
        (a.urgencia == b.urgencia && b.id < a.id); 

}
bool resuelveCaso() {
    int N; 
    std::cin >> N;
    if (N == 0) return false; 

    std::priority_queue<paciente> cola; 
    int counter = 0; ;

    for (int i = 0; i < N; i++) {
        char tipo; 
        cin >> tipo; 
        if (tipo == 'I') {
            paciente p;
            p.id = counter;
            counter++;
            cin >> p.nombre >> p.urgencia;
            cola.push(p);
        }
        else if (tipo == 'A') {
            paciente p = cola.top(); cola.pop();
            cout << p.nombre + "\n";
        }
        else {
            std::cerr << "Error al leer el tipo de accion\n";
            continue; 
        }
    }
    std::cout << "---\n"; 
    
   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
#endif
   return 0;
}
