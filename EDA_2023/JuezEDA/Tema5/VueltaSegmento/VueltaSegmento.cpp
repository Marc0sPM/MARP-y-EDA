//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;


void invertirSegmento(list<int>& l, int pos, int longitud) { //En total, cada bucle recorre una parte de la lista llegando
                                                            //hasta pos+longitud (2 veces), por tanto es O(pos+ 2 *longitud),
                                                            //que es prácticamente O(n), por tanto, lineal
   list<int>::iterator itINI = l.begin();

   for(int i = 1; i < pos; i++) ++itINI; //movemos un iterador al primer elemento de nuestro segmento
    list<int>::iterator itFIN = itINI;
   for(int k = 0; k < longitud; k++) ++itFIN; //Movemos el otro al siguiente del último elemento de nuestro segmento
   for(int j = 0; j < longitud; j++) {
       l.insert(itFIN, *itINI);
       --itFIN;
       itINI = l.erase(itINI);
   }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, pos, longitud, elem;
    list<int> l;
    cin >> n;
    if (!std::cin) return false;
    cin >> pos >> longitud;

    // Leo la lista
    for (int i=0; i < n; ++i) { cin >> elem; l.push_back(elem); }

    // Llamada a la funcion pedida
    invertirSegmento(l,pos,longitud);

    // Muestro la lista
    for (int& e : l) cout << e << " ";
    cout << endl;

    return true;
}

#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}