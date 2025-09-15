#ifndef JUEZ_HORAS_H
#define JUEZ_HORAS_H

#include <fstream>

class Horas {
protected:
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

public:
    Horas() {

    }

    Horas(int horas, int minutos, int segundos) {
        if(horas < 0 || horas >= 24) throw std::range_error("ERROR");
        this->horas = horas;
        if(minutos < 0 || minutos >= 60) throw std::range_error("ERROR");
        this->minutos = minutos;
        if(segundos < 0 || segundos >= 60) throw std::range_error("ERROR");
        this->segundos = segundos;
    }
    bool operator<(const Horas& other) const {
        if(this->horas == other.horas) {
            if(this->minutos == other.minutos) {
                return this->segundos < other.segundos;
            }
            else return this->minutos < other.minutos;
        }
        else return this->horas < other.horas;
    }
    friend std::ostream& operator<<(std::ostream& os, const Horas& hora) {
        std::string horas = "", minutos = "", segundos = "";
        hora.horas < 10 ? horas = "0" + std::to_string(hora.horas) : horas = std::to_string(hora.horas);
        hora.minutos < 10 ? minutos = "0" + std::to_string(hora.minutos) : minutos = std::to_string(hora.minutos);
        hora.segundos < 10 ? segundos = "0" + std::to_string(hora.segundos) : segundos = std::to_string(hora.segundos);
        os << horas << ":" << minutos << ":" << segundos;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Horas& hora) {
        int horas = 0;
        int minutos = 0;
        int segundos = 0;
        char c;
        is >> horas >> c >> minutos >> c >> segundos;
        hora = Horas(horas, minutos, segundos);
        return is;
    }
};

#endif //JUEZ_HORAS_H
