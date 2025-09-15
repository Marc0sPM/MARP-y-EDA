// Alejandro Massó Martínez
// VJ30

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <unordered_map>
#include <map>
using namespace std;

using medico = string;
using paciente = string;

struct fecha {
    int dia;
    int hora;
    int minuto;
    fecha(int d, int h, int m) : dia(d), hora(h), minuto(m) {}
    bool operator<(const fecha& other) const {
        if(this->dia != other.dia) return this->dia < other.dia;
        else {
            if(this->hora != other.hora) return this->hora < other.hora;
            else {
                return this->minuto < other.minuto;
            }
        }
    }

    friend ostream& operator<<(ostream& os, fecha f) {
        string hora = to_string(f.hora), minuto = to_string(f.minuto);
        if(f.hora < 10) hora = "0" + to_string(f.hora);
        if(f.minuto < 10) minuto = "0" + to_string(f.minuto);
        return os << hora << ":" << minuto;
    }
};

class Consultorio {
private:
    unordered_map<medico, map<fecha, paciente>*> medicos;
public:
    void nuevoMedico(medico m) { //O(1)
        auto it = medicos.find(m); //O(1)
        if(it != medicos.end()) return; //O(1)
        else medicos[m] = new map<fecha, paciente>; //O(1)
    }

    void pideConsulta(paciente p, medico m, fecha f) { //O(log(n)), siendo n el número de fechas
        auto it = medicos.find(m); //O(1)
        if(it == medicos.end()) throw invalid_argument("Medico no existente"); //O(1)
        else {
            auto it2 = it->second->find(f); //O(log(num fechas));
            if(it2 != it->second->end()) throw invalid_argument("Fecha ocupada");
            else it->second->operator[](f) = p; //O(log(num fechas))
        }
    }

    paciente siguientePaciente(medico m) { //O(1)
        auto it = medicos.find(m); //O(1)
        if(it == medicos.end()) throw invalid_argument("Medico no existente");
        else {
            if(it->second->size() == 0) throw invalid_argument("No hay pacientes");
            else {
                return it->second->begin()->second; //O(1)
            }
        }
    }

    void atiendeConsulta(medico m) { //O(1)
        auto it = medicos.find(m); //O(1)
        if(it == medicos.end()) throw invalid_argument("Medico no existente");
        else {
            if(it->second->size() == 0) throw invalid_argument("No hay pacientes");
            else {
                it->second->erase(it->second->begin()); //O(1)
            }
        }
    }

    map<fecha, paciente> listaPacientes(medico m, fecha f) { //O(n log(n)), siendo n el número de pacientes
        auto it = medicos.find(m); //O(1)
        if(it == medicos.end()) throw invalid_argument("Medico no existente");
        else {
            map<fecha, paciente> tmp;
            auto it2 = it->second->begin();
            while(it2 != it->second->end()) {
                if(it2->first.dia == f.dia) tmp[fecha(0, it2->first.hora, it2->first.minuto)] = it2->second;
                ++it2;
            }
            return tmp;
        }
    }


};

int casos = 0;
bool resuelve() {

    int N;
    cin >> N;
    if (!cin) return false;

    string inst; medico med; paciente pac; int d, h, m; char c;
    Consultorio con;

    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                con.nuevoMedico(med);
            } else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> c >> m;
                con.pideConsulta(pac, med, fecha(d,h,m));
            } else if (inst == "siguientePaciente") {
                cin >> med;
                pac = con.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << '\n';
                cout << pac << '\n';
            } else if (inst == "atiendeConsulta") {
                cin >> med;
                con.atiendeConsulta(med);
            } else if (inst == "listaPacientes") {
                cin >> med >> d;
                auto vec = con.listaPacientes(med, fecha(d,0,0));
                cout << "Doctor " << med << " dia " << d << '\n';
                for (auto p : vec) {
                    cout << p.second << ' ' << p.first << '\n';
                }
            } else
                assert(false);
        } catch (invalid_argument e) { cout << e.what() << '\n'; }
    }
    cout << "---\n";

    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelve());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
