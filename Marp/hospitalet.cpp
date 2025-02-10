
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

struct Paciente
{
    string nombre;

    int gravedad;
    int antiguedad;
};

bool operator<(const Paciente& p1,const Paciente& p2){
    return (p1.gravedad < p2.gravedad) ||
    (p1.gravedad==p2.gravedad && p1.antiguedad>p2.antiguedad);
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
    int casos;
    cin>>casos;
   if (casos == 0)
      return false;

    char a;
    Paciente p;
    priority_queue<Paciente> cola;
   // resolver el caso posiblemente llamando a otras funciones
    for(int i = 0; i < casos;i++){
        cin >>a;
        if(a == 'A'){
            cout << cola.top().nombre<<endl;cola.pop();
        }else if('I'){
            cin>>p.nombre;
            cin>>p.gravedad;
            p.antiguedad = i;
            cola.push(p);
        }
    }
   // escribir la solución
    cout<<"---"<<endl;
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
