
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

bool resuelveCaso() {

   // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
   else {
       priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> cola;
       for (int i = 0; i < n; ++i) { // coste O(n)
           int64_t k;
           cin >> k;
           cola.push(k); // O(1)
       }
       int64_t esfuerzo_min = 0;
       while (cola.size() > 1) {  // coste O(n log n)
           int64_t a, b;
           a = cola.top();
           cola.pop();  // coste O(log n)
           b = cola.top();
           cola.pop();  // coste O(log n)

           int64_t suma = a + b;
           esfuerzo_min += suma;

           cola.push(suma); // <----------- IMPORTANTE
       }
       cout << esfuerzo_min << "\n";
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
