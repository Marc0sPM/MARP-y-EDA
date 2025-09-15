//Alejandro Massó Martínez
//VJ30
#ifndef JUEZ_VLCLASE_H
#define JUEZ_VLCLASE_H

#include <unordered_map>
#include <map>
#include <list>

using TituloLibro = std::string;

class VentaLibros {
private:
    struct Venta {
        int ejemplares = 0;
        int ventas = 0;
        std::list<TituloLibro>::iterator pos; //apunta a una lista en ventas
        std::list<TituloLibro>* l = nullptr;
    };
    std::unordered_map<TituloLibro, Venta> libros_Ejemplares;
    std::map<int, std::list<TituloLibro>, std::greater<int>> ventas;

public:
    void nuevoLibro(TituloLibro n, int x) { //O(1)
        libros_Ejemplares[n].ejemplares += x; //operator[] tiene complejidad constante
    }

    void comprar(TituloLibro n) { //O(log(ventas))
        auto itLibro = libros_Ejemplares.find(n); //find() tiene complejidad constante
        if(itLibro == libros_Ejemplares.end()) throw std::invalid_argument("Libro no existente"); //O(1)
        if(itLibro->second.ejemplares == 0) throw std::out_of_range("No hay ejemplares"); //O(1)
        --(itLibro->second.ejemplares); //O(1)
        if(itLibro->second.l != nullptr) itLibro->second.l->erase(itLibro->second.pos);
        ++(itLibro->second.ventas); //O(1)
        //Aquí metemos cada venta en el top10
        itLibro->second.l = &ventas[itLibro->second.ventas];
        itLibro->second.l->push_front(n);
        itLibro->second.pos = itLibro->second.l->begin();
    }

    bool estaLibro(TituloLibro n) { //O(1)
        return libros_Ejemplares.count(n); //count es lineal en el orden de elementos contados, es decir, en este caso, O(1)
    }

    void elimLibro(TituloLibro n) { //O(1)
        auto itLibro = libros_Ejemplares.find(n); //find() tiene complejidad constante
        if(itLibro == libros_Ejemplares.end()) return; //O(1)
        else {
            if(itLibro->second.l != nullptr) itLibro->second.l->erase(itLibro->second.pos); //erase es lineal en el número de elementos borrados, en este caso, 1, por tanto O(1)
            libros_Ejemplares.erase(itLibro);
        }
    }

    int numEjemplares(TituloLibro n) { //O(1)
        auto itLibro = libros_Ejemplares.find(n); //find() tiene complejidad constante
        if(itLibro == libros_Ejemplares.end()) throw std::invalid_argument("Libro no existente"); //O(1)
        return itLibro->second.ejemplares; //O(1)
    }

    std::list<TituloLibro> top10() { //O(10 primeros elementos en el diccionario de ventas)
        std::list<TituloLibro> top;
        int i = 0;
        for(auto itVentas = ventas.begin(); itVentas != ventas.end() && i < 10; ++itVentas) {
            for(auto it = itVentas->second.begin(); it != itVentas->second.end() && i < 10; ++it) {
                top.push_back((*it));
                ++i;
            }
        }
        return top;
    }
};
#endif //JUEZ_VLCLASE_H
