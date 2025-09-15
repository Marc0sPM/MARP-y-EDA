#ifndef JUEZ_PELICULA_H
#define JUEZ_PELICULA_H

#include "Horas.h"

class Pelicula {
private:
    std::string nombre;
    Horas inicio;
    Horas duracion;

public:
    Pelicula() {}

    Pelicula(std::string nombre, Horas inicio, Horas duracion) : nombre(nombre), inicio(inicio), duracion(duracion) {}

    Horas horaFinalizacion() const {
        return inicio + duracion;
    }

    bool operator<(const Pelicula& p) const {
        if(this->horaFinalizacion() == p.horaFinalizacion()) return this->nombre < p.nombre;
        return this->horaFinalizacion() < p.horaFinalizacion();
    }

    friend std::ostream& operator<<(std::ostream& os, const Pelicula& peli) {
        return os << peli.horaFinalizacion() << peli.nombre << std::endl;
    }
};


#endif //JUEZ_PELICULA_H
