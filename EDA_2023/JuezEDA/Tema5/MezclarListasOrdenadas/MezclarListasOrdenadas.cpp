// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template<class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void mezclaOrdenada(queue_plus<T>& lista2) { //O(n): recorremos las 2 listas (1 en el mejor de los casos), por tanto, n = (lista1.size() + lista2.size())
        if(!this->empty()) {
            Nodo* itLista1 = this->prim;
            Nodo* itLista2 = lista2.prim;
            Nodo* anterior = nullptr;
            while(!lista2.empty() && itLista1 != nullptr) {
                if(itLista1->elem < itLista2->elem) {
                    anterior = itLista1;
                    itLista1 = itLista1->sig;
                }
                else {
                    if(anterior != nullptr) {
                        anterior->sig = itLista2;
                        anterior = anterior->sig;
                    }
                    else {
                        this->prim = itLista2;
                        anterior = this->prim;
                    }
                    itLista2 = itLista2->sig;
                    anterior->sig = itLista1;
                    lista2.nelems--;
                    this->nelems++;
                }
            }
            if(!lista2.empty()) {
                anterior->sig = itLista2;
                this->ult = lista2.ult;
                while(lista2.nelems != 0) {
                    this->nelems++;
                    lista2.nelems--;
                }
            }
            lista2.ult = nullptr;
            lista2.prim = nullptr;
        }
        else {
            this->prim = lista2.prim;
            this->ult = lista2.ult;
            lista2.prim = nullptr;
            lista2.ult = nullptr;
            this->nelems = lista2.nelems;
            lista2.nelems = 0;
        }

    }

    void imprimir() {
        for(int i = 0; i < this->size(); ++i) {
            T elem = this->front();
            std::cout << elem << " ";
            this->pop();
            this->push(elem);
        }
        std::cout << std::endl;
    }
};


// función que resuelve el problema
void resolver(queue_plus<int>& cola1, queue_plus<int>& cola2) {
    cola1.mezclaOrdenada(cola2);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero = -17;
    queue_plus<int> cola1, cola2;
    while(numero != 0) {
        std::cin >> numero;
        if(numero != 0) cola1.push(numero);
    }

    numero = -19;
    while(numero != 0) {
        std::cin >> numero;
        if(numero != 0) cola2.push(numero);
    }

    resolver(cola1, cola2);

    cola1.imprimir();
    // escribir sol

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