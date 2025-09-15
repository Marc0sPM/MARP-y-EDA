
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

	int ini, parejas;
	cin >> ini >> parejas;
	if (ini == 0 && parejas == 0)
		return false;
	// Cola de minimos
	priority_queue<int, std::vector<int>, std::greater<int>> derecha;
	// Cola de maximos
	priority_queue<int> izquierda;

	izquierda.push(ini);

	for (int i = 0; i < parejas; ++i) {
		int uno, dos, medio;
		medio = izquierda.top();
		cin >> uno >> dos;
		if (uno < medio && dos < medio) {
			izquierda.pop();
			derecha.push(medio);
			izquierda.push(uno);
			izquierda.push(dos);
		}
		else if (uno > medio && dos > medio) {
			derecha.push(uno);
			derecha.push(dos);
			medio = derecha.top();
			derecha.pop();
			izquierda.push(medio);
		}
		else if (uno < medio && dos > medio) {
			izquierda.push(uno);
			derecha.push(dos);
		}
		else {
			izquierda.push(dos);
			derecha.push(uno);
		}
		std::cout << izquierda.top() << " ";

	}
	std::cout << "\n"; 
	// El de la mitad siempre va a estar en la cola de la izquierda
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
