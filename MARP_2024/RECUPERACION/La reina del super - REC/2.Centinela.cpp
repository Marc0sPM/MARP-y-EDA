
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
	int id, tiempo; 
};
bool operator <(caja const& a, caja const& b) {
	return b.tiempo < a.tiempo ||
		b.tiempo == a.tiempo && b.id < a.id;
}

bool resuelveCaso() {
	int N, C; 
	cin >> N >> C; 
	if (N == 0 && C == 0) return false;

	priority_queue<caja> cajas; 

	for (int i = 0; i < N; ++i) {
		caja a; a.id = i + 1; 
		a.tiempo = 0; 
		cajas.push(a);
	}
	for (int i = 0; i < C; ++i) {
		int cliente; cin >> cliente; 
		caja c = cajas.top(); cajas.pop();
		c.tiempo += cliente;
		cajas.push(c);
	}
	cout << cajas.top().id << endl;

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
