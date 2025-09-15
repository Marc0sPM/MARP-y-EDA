
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
struct usuario {
    int  id, periodo, momento;
};
bool operator<(usuario const& u1, usuario const& u2) {
    return u2.momento < u1.momento || (u2.momento == u1.momento && u2.id < u1.id);

}
bool resuelveCaso() {

    int N, eventos;
    cin >> N;
    if (N == 0) return false;
   else {
       priority_queue<usuario> cola;
       for (int i = 0; i < N; ++i) { // coste O(n)
           usuario u;
           cin >> u.id >> u.periodo;
           u.momento = u.periodo;
           cola.push(u); // O(1)
       }
       cin >> eventos;
       while (eventos--) {  // coste O(n log n)
           usuario u = cola.top(); cola.pop();
           cout << u.id << "\n"; 
           u.momento += u.periodo;
           cola.push(u);
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
