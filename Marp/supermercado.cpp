
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct caja
{
    int num;

    int momento;
    /* data */
};

bool operator<(const caja& c1,const caja& c2){
    return (c1.momento > c2.momento)||(c1.momento==c2.momento && c1.num > c2.num);
}

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
   int cajas;
   int clientes;
   cin>>cajas;
   cin>>clientes;


    std::priority_queue<caja>queue;

   if (cajas==clientes&& cajas==0)
      return false;

    caja c;
   // resolver el caso posiblemente llamando a otras funciones
    for(int i= 0; i< cajas;i++){
        c.num = i+1;
        c.momento = 0;
        queue.push(c);
    }

    caja aux;
   // escribir la solución
    for(int i = 0; i< clientes;i++){
        int time;
        aux = queue.top();queue.pop();
        cin >> time;
        aux.momento += time;
        queue.push(aux);
    }    
    std::cout << queue.top().num<<endl;
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
