// Marcos Perez Martinez
// EDA-GDV58


#include <iostream>
#include <iomanip>
#include <fstream>

#include "list_eda.h"

using namespace std;

/* === EXPLICACION === 
    Primero de todo realizamos comprobaciones para ver si el metodo se puede ejecutar o no. 
    Por ejemplo, si la longitud (lon) <= 0 no avanzamos nada, por lo que se sale del metodo; o si k > pos
    , significa que estamos intentando adelantar mas alla del principio. 
    
    Luego, asignamos recorriendo los pos nodos de manera constante desde el primer nodo (this->fantasma->sig) hasta
    el nodo que coincide con pos. Asi tenemos una complejidad en tiempo de O(pos). 
    Además, asignamos el ultimo nodo del segmento de la misma forma que el primero, pero
    recorriendo desde el nodo pos hasta pos + lon, teniendo asi una complejidad de O(lon). 

    A continuacion se separa el segmento de la lista. Se busca la posicion destino, 
    teniendo asi un recorrido de (pos - k) elementos -> O(pos - k) e insertamos el segmento en esa posicion.

    Como pos y lon siempre < n (numero de elementos de la lista), el caso peor seria mover el ultimo elemento
    hasta la primera posicion, haciendo que la complejidad de la funcion sea O(n). 

*/

// función que resuelve el problema
void resolver(list<char>& datos, int pos, int lon, int k) {

    datos.adelantaPosiciones(pos, lon, k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int n, pos, lon, k;
    char auxC;
    std::cin >> n >> pos >> lon >> k;
    list<char> datos;
    for (int i = 0; i < n; ++i) {
        std::cin >> auxC;
        datos.push_back(auxC);
    }


    resolver(datos, pos, lon, k);

    for (auto it = datos.begin(); it != datos.end(); ++it) {
        std::cout << *it << " ";
    }
    std:: cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}