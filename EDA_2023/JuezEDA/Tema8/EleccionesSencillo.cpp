//Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

using estado = string;
using partido = string;

class ConteoVotos {
private:
    struct Estado {
        estado e;
        int compromisarios;
        unordered_map<partido, int>::iterator ganador = partidos.end();
        unordered_map<partido, int> partidos;
        Estado(estado e, int c) : e(e), compromisarios(c) {}
    };


    unordered_map<estado, Estado> estados;
    map<partido,int> compromisariosPorPartido;


public:

    void nuevo_estado(const estado &nombre, int num_compromisarios) { //O(1)
        auto it = estados.find(nombre); //O(1)
        if(it != estados.end()) throw domain_error("Estado ya existente");
        else estados.insert({nombre, Estado(nombre, num_compromisarios)}); //O(1)
    }

    void sumar_votos(const estado &e, const partido &p, int num_votos) { //O(log(n)), siendo n el número de partidos
        auto it = estados.find(e); //O(1)
        if(it == estados.end()) throw domain_error("Estado no encontrado");
        else { //Si el estado existe...
            //Buscamos si el partido ya ha sido registrado en ese estado
            auto itPartido = it->second.partidos.find(p); //O(1)
            auto finalPartidos = it->second.partidos.end(); //O(1)
            if(itPartido == it->second.partidos.end()) {
                it->second.partidos[p] = num_votos; //O(1)
                itPartido = it->second.partidos.find(p); //O(1)
            }
            else itPartido->second += num_votos; //O(1)
            //Registrar el ganador
            if(it->second.ganador == finalPartidos) {
                it->second.ganador = itPartido; //O(1)
                auto itCompromisarios = compromisariosPorPartido.find(p); //O(log(n))
                if(itCompromisarios == compromisariosPorPartido.end()) compromisariosPorPartido.insert({p,it->second.compromisarios}); //O(log(n))
                else itCompromisarios->second += it->second.compromisarios; //O(1)
            }
            else {
                if(itPartido->second > it->second.ganador->second) {
                    auto itCompromisarios = compromisariosPorPartido.find(p); //O(log(n))
                    if(itCompromisarios == compromisariosPorPartido.end()) compromisariosPorPartido.insert({p,it->second.compromisarios}); //O(log(n))
                    else itCompromisarios->second += it->second.compromisarios; //O(1)

                    compromisariosPorPartido[it->second.ganador->first] -= it->second.compromisarios; //O(log(n))
                    it->second.ganador = itPartido; //O(1)
                }
            }
        }
    }

    partido ganador_en(const estado &e) const { //O(1)
        auto it = estados.find(e); //O(1)
        if(it == estados.end()) throw domain_error("Estado no encontrado");
        else return it->second.ganador->first; //O(1)
    }

    vector<pair<partido,int>> resultados() const { //O(n), siendo n el número de partidos
        vector<pair<partido, int>> res;
        for(auto it = compromisariosPorPartido.begin(); it != compromisariosPorPartido.end(); ++it) {
            if(it->second > 0) res.push_back({it->first, it->second});
        }
        return res;
    }

};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                estado e;
                int num_compromisarios;
                cin >> e >> num_compromisarios;
                elecciones.nuevo_estado(e, num_compromisarios);
            } else if (comando == "sumar_votos") {
                estado e;
                partido p;
                int num_votos;
                cin >> e >> p >> num_votos;
                elecciones.sumar_votos(e, p, num_votos);
            } else if (comando == "ganador_en") {
                estado e;
                cin >> e;
                partido ganador  = elecciones.ganador_en(e);
                cout << "Ganador en " << e << ": " << ganador << "\n";
            } else if (comando == "resultados") {
                for (const auto &par : elecciones.resultados()) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
        } catch (std::exception &e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
