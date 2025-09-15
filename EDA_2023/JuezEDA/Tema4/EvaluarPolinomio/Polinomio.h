#ifndef JUEZ_POLINOMIO_H
#define JUEZ_POLINOMIO_H

#include <vector>
#include <cmath>
#include <algorithm>

class Polinomio {
protected:
    struct Monomio {
        int coeficiente;
        int exponente;

        Monomio(int coeficiente, int exponente) {
            this->coeficiente = coeficiente;
            this->exponente = exponente;
        }

        Monomio operator+(const Monomio& m) const{
            return Monomio(this->coeficiente + m.coeficiente, this->exponente);
        }

        bool operator<(const Monomio& m) const {
            return this->exponente < m.exponente;
        }
    };


    std::vector<Monomio> polinomio;
    int nElems = 0;

    bool tieneExponente(int exponente, int ini, int fin, int& pos) const{
        int mitad = (ini + fin) / 2, n = fin - ini;

        if(fin == 0) return false;
        if(n == 1) {
            pos = mitad;
            return exponente == polinomio[mitad].exponente;
        }
        if(exponente < polinomio[mitad].exponente) {
            return tieneExponente(exponente, ini, mitad, pos);
        }
        else return tieneExponente(exponente, mitad, fin, pos);
    }

    void sustituyeElemento(int indice, Monomio m, int fin) {
        if(indice != fin) {
            Monomio tmp = polinomio[indice];
            polinomio[indice] = m;
            sustituyeElemento(indice + 1, tmp, fin);
        }
        else polinomio.push_back(m);
    }

public:
    Polinomio() {}

    void addMonomio(int coeficiente, int exponente) {
        int pos = 0;
        if(coeficiente == 0) return;
        else {
            Monomio m(coeficiente, exponente);
            if(!tieneExponente(m.exponente, 0, nElems, pos)) {
                    polinomio.push_back(m);
                    nElems++;
            }
            else polinomio[pos] = polinomio[pos] + m;
        }
    }

    int evaluar(int x) const {
        int total = 0;
        for(int i = 0; i < nElems; i++) {
            total += (pow(x, polinomio[i].exponente) * polinomio[i].coeficiente);
        }
        return total;
    }
};

#endif //JUEZ_POLINOMIO_H
