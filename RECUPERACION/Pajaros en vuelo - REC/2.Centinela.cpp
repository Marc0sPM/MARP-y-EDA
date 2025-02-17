
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

	priority_queue<int> iz;  // cola de menores, aqui se guarda el pájaro centro como top() 
	priority_queue<int, std::vector<int>, std::greater<int> > der;  // cola de mayoress
		

	int inicial, N; 
	cin >> inicial >> N;
	if (N == 0 && inicial == 0) {
		return false;
	}

	der.push(inicial);

	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		int centro = der.top();
		if (a < centro && b < centro) {
			iz.push(a);
			iz.push(b);
			centro = iz.top();
			iz.pop();
			der.push(centro);
		}
		else if (a > centro && b > centro) {
			der.pop();
			der.push(a);
			der.push(b);
			iz.push(centro);
		}
		else if (a < centro && b > centro) {
			iz.push(a);
			der.push(b);
		}
		else {
			der.push(a);
			iz.push(b);
		}

		cout << centro <<  " ";
	}

	cout << std::endl;

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
