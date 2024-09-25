
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
struct caja {
    int id;
    int t = 0;
};
bool operator<(const caja& a, const caja& b) {
    return b.t < a.t || (b.t == a.t && b.id < a.id);
}

bool resuelveCaso() {

    int N, C;
    cin >> N >> C;
    if (N == 0 && C == 0) 
        return false;
   else {
        vector<int> cola;
        for (int i = 0; i < C; ++i){  // O(C)
            int c;
            cin >> c;
            cola.push_back(c);
        }
        priority_queue<caja> cajas; // O(N log N)
        for (int i = 0; i < N; ++i) {
            caja c;
            c.id = i + 1;
            cajas.push(c);
        }
        while (C > 0){  // O(C log N) --> no se hace eliminando elementos del vector puesto que el coste es O(C) y da timelimit
            auto aux = cajas.top(); cajas.pop();
            aux.t += cola[cola.size() - C]; //O(1)
            cajas.push(aux); //O(log N)
            C--;
        }
        cout << cajas.top().id << "\n";
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
