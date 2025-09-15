//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:

    void duplica(){ //Complejidad lineal O(n)-> accedemos a cada uno de los elementos de la cola
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
        if(this->nelems == 0) {
            //No hacemos nada, no podemos
        }
        else {
            Nodo * ini = this->prim;
            while(ini != nullptr) {
                ini->sig = new Nodo(ini->elem, ini->sig);
                ini = ini->sig->sig;
                this->nelems++;
            }
            this->ult = this->ult->sig;
        }

    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    queue_plus<int> q;
    cin >> n;
    if (!cin) return false;
    while (n != 0){
        q.push(n);
        cin >> n;
    }

    // llamada a metodo
    q.duplica();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i){
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return true;
}

#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
