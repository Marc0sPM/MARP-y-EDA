//
//  list_eda.h
//
//  Implementación del TAD lista heredando de colas dobles
//  y con iteradores (constantes y no constantes)
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef list_eda_h
#define list_eda_h

#include <stdexcept>
#include <cassert>

#include "deque_eda.h"

template <class T>
class list : public deque<T> {
protected:
   using Nodo = typename deque<T>::Nodo;

   template <class Apuntado>
   class Iterador {
      // puntero al nodo actual del recorrido
      Nodo * act;
      // puntero al nodo fantasma (para saber cuándo estamos fuera)
      Nodo * fan;
   public:
      
      Iterador() : act(nullptr), fan(nullptr) {}
      
      // para acceder al elemento apuntado
      Apuntado & operator*() const {
         if (act == fan) throw std::out_of_range("fuera de la lista");
         return act->elem;
      }
      
      // para acceder a un método del elemento apuntado
      // it->metodo() en vez de (*it).metodo()
      Apuntado * operator->() const {
         return &(operator*());
      }
      
      Iterador & operator++() { // ++ prefijo (recomendado)
         if (act == fan) throw std::out_of_range("fuera de la lista");
         act = act->sig;
         return *this;
      }
      
      Iterador operator++(int) { // ++ postfijo
         Iterador ret(*this);
         operator++();
         return ret;
      }
      
      bool operator==(Iterador const& that) const {
         return act == that.act && fan == that.fan;
      }
      
      bool operator!=(Iterador const& that) const {
         return !(*this == that);
      }
      
   private:
      // para que list pueda construir objetos del tipo iterador
      friend class list;
      
      // constructora privada
      Iterador(Nodo * ac, Nodo * fa) : act(ac), fan(fa) {}
   };
   
public:
   /*
    Iteradores que permiten recorrer la lista pero no cambiar sus elementos.
    */
   using const_iterator = Iterador<T const>;
   
   // devuelven un iterador constante al principio de la lista
   const_iterator cbegin() const {
      return const_iterator(this->fantasma->sig, this->fantasma);
   }
   const_iterator begin() const {
      return cbegin();
   }
   
   // devuelven un iterador constante al final del recorrido y fuera de este
   const_iterator cend() const {
      return const_iterator(this->fantasma, this->fantasma);
   }
   const_iterator end() const {
      return cend();
   }
   
   /*
    Iteradores que permiten recorrer la lista y cambiar sus elementos.
    */
   using iterator = Iterador<T>;
   
   // devuelve un iterador al principio de la lista
   iterator begin() {
      return iterator(this->fantasma->sig, this->fantasma);
   }
   
   // devuelve un iterador al final del recorrido y fuera de este
   iterator end() {
      return iterator(this->fantasma, this->fantasma);
   }
   
   // inserta un elemento delante del apuntado por el iterador it
   // (it puede estar apuntado detrás del último)
   // devuelve un iterador al nuevo elemento
   iterator insert(iterator const& it, T const& elem) {
      assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
      Nodo * nuevo = this->inserta_elem(elem, it.act->ant, it.act);
      return iterator(nuevo, this->fantasma);
   }
   
   // elimina el elemento apuntado por el iterador (debe haber uno)
   // devuelve un iterador al siguiente elemento al borrado
   iterator erase(iterator const& it) {
      assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
      if (it.act == this->fantasma)
         throw std::out_of_range("fuera de la lista");
      iterator next(it.act->sig, this->fantasma);
      this->borra_elem(it.act);
      return next;
   }

    void adelantarSegmento(int pos, int lon, int k) { //O(n): solo recorremos una vez la lista
        if(this->nelems == 0 || lon == 0 || k == 0 || pos == 0 || pos < k || pos >= this->nelems) return;
        else {
            Nodo* nodoIterador = this->fantasma->sig;
            Nodo* anterior;
            Nodo* posterior;
            Nodo* primero;
            Nodo* ultimo;
            if(pos - (k + 1) == -1) {
                anterior = this->fantasma;
                posterior = this->fantasma->sig;
            }
            for(int i = 0; i < this->nelems; ++i) {
                if(i == pos - (k + 1)) {
                    anterior = nodoIterador;
                    posterior = anterior->sig;
                }
                if(i == pos) primero = nodoIterador;

                if(pos + lon > this->nelems) ultimo = this->fantasma->ant;
                else if(i == (pos + lon) - 1) ultimo = nodoIterador;

                nodoIterador = nodoIterador->sig;
            }

            primero->ant->sig = ultimo->sig;
            anterior->sig = primero;
            primero->ant = anterior;
            ultimo->sig = posterior;
            posterior->ant = ultimo;
        }
    }

};

#endif // list_eda_h
