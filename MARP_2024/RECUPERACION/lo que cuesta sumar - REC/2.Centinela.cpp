
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

	// Leer entrada 
	int N; 
	cin >> N; 
	if (N == 0) return false;
	priority_queue<int, vector<int>, greater<int> > numeros; 
	// Leemos los numeros a sumar
	int esfuerzo = 0; 
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n; 
		numeros.push(n);
	}

	while (numeros.size() > 1) {
		int a = numeros.top();  numeros.pop();
		int b = numeros.top();  numeros.pop();
		int sum = a + b; 

		esfuerzo += sum;

		numeros.push(sum);
	}

	std::cout << esfuerzo << std::endl; 
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
