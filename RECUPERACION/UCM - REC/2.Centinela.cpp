
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

struct usuario{
	int id, periodo, momento; 
};

bool operator <(usuario const& a, usuario const& b) {
	return b.momento < a.momento ||
		(a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {
	int N; 
	cin >> N;  if (N == 0) return false;
	priority_queue<usuario> usuarios; 
	for (int i = 0; i < N; ++i) {
		usuario a; 
		cin >> a.id >> a.periodo; 

		a.momento = a.periodo;

		usuarios.push(a);
	}
  
	int m; cin >> m; 

	for (int i = 0; i < m; ++i) {
		usuario a = usuarios.top(); usuarios.pop();

		std::cout << a.id << std::endl;
		a.momento += a.periodo; 
		usuarios.push(a);
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
