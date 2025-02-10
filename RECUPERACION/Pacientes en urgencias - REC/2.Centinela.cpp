
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
	std::string name; 
	int urgencia;
	int espera; 
};
bool operator <(paciente const& a, paciente const& b) {
	return b.urgencia > a.urgencia || (b.urgencia == a.urgencia && b.espera < a.espera); 
}

bool resuelveCaso() {
	int N;
	cin >> N; 
	if (N == 0) return 0;

	// Cola de mayores, en vez de menores
	priority_queue < paciente > lista;
	int i = 0;
	while (N--) {
		char a; cin >> a;
		if (a == 'I') {
			paciente p; 
			cin >> p.name >> p.urgencia;
			p.espera = i;
			lista.push(p);
			++i;
		}
		else if (a == 'A') { // Atendemos al paciente
			paciente p = lista.top(); lista.pop();
			cout << p.name << "\n";
		}
	}
	cout << "---\n";

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
