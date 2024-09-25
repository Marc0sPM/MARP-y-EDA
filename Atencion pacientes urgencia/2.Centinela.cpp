
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
    string nombre;
    int urg, id;
};
bool operator<(const paciente& a, const paciente& b) {
    return a.urg < b.urg || (b.urg == a.urg && b.id < a.id);
}
bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) 
        return false;
   else {
        int cont_pacientes = 0;
        priority_queue<paciente> pacientes;
        for (int i = 0; i < N; ++i) { // O(N * logN)
            string op; cin >> op;
            if (op == "I") {
                paciente p;
                cont_pacientes++;
                cin >> p.nombre >> p.urg;
                p.id = cont_pacientes;
                pacientes.push(p); //O(log N)
            }
            else if (op == "A"){
                cout << pacientes.top().nombre << "\n";
                pacientes.pop(); // O(log N)
            }
        }
        cout << "---\n";
   }
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
