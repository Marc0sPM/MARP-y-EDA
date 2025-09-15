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
    void cuela(const T& a, const T& b){ //O(n): recorremos toda la cola una sola vez,
        // (o en su defecto, hasta que hemos encontrado los dos números) y hacemos las operaciones sobre ellos,
        //por tanto, lineal en el número de elementos de la cola
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
        Nodo* A = this->prim;
        Nodo* posteriorA = A->sig;
        Nodo* anteriorB = nullptr;
        Nodo* B = this->prim;
        Nodo* posteriorB = B->sig;

        bool encontradoA = false, encontradoB = false;
        //Búsqueda de a y b
        for(int i = 0; i < this->nelems && (!encontradoA || !encontradoB); ++i) {
            if(A->elem != a && !encontradoA) {
                if(posteriorA != nullptr) {
                    A = posteriorA;
                    posteriorA = posteriorA->sig;
                }
            }
            else if(!encontradoA) encontradoA = true;

            if((B->elem != b && !encontradoB) || (B->elem == b && !encontradoA) || B == A) {
                anteriorB = B;
                if(posteriorB != nullptr) {
                    B = posteriorB;
                    posteriorB = posteriorB->sig;
                }
            }
            else encontradoB = true;
        }

        if(encontradoA && encontradoB) {
            if(B != A->sig) {
                //Cambio los alrededores de B
                anteriorB->sig = posteriorB;
                if(posteriorB == nullptr) this->ult = anteriorB;
                A->sig = B;
                B->sig = posteriorA;
            }
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1){
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a,b);

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

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
