
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

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
    Set<int> conjunto;
    int n;
    cin >> n;
   if (n == 0)
      return false;
   for (int i = 0; i < n; ++i) {
       int k;
       cin >> k;
       conjunto.insert(k);
   }
   int m;
    cin >> m;
   
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        try {
            int kesimo = conjunto.kesimo(k);
            std::cout << kesimo << std::endl;
        }
        catch (const std::exception) {
            std::cout << "??" << std::endl;
    }
   }
    cout << "---" << endl;

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
