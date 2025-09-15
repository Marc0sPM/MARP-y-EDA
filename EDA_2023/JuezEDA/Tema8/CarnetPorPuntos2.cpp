//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <list>
using namespace std;

class carnet_puntos {
private:
    using DNI = string;
    using puntos = int;
    struct Conductor {
        DNI dni;
        puntos p;
        Conductor(const DNI& d, puntos p) : dni(d), p(p) {}
    };

    vector<list<Conductor>> conductoresPorPuntos = vector<list<Conductor>>(16);
    unordered_map<DNI, list<Conductor>::iterator> conductores;

public:
    carnet_puntos() = default;

    void nuevo(const DNI& d) { //O(1)
        auto it = conductores.find(d); //O(1)
        if(it != conductores.end()) throw domain_error("Conductor duplicado"); //O(1)
        else {
            conductoresPorPuntos[15].push_front(Conductor(d, 15)); //O(1)
            conductores[d] = conductoresPorPuntos[15].begin(); //O(1)
        }
    }

    void quitar(const DNI& d, puntos p) { //O(1)
        auto it = conductores.find(d); //O(1)
        if(it == conductores.end()) throw domain_error("Conductor inexistente"); //O(1)
        else {
            int puntosAnteriores = it->second->p; //O(1)
            int puntosNuevos = puntosAnteriores - p;
            if(puntosNuevos < 0) puntosNuevos = 0; //O(1)
            if(puntosNuevos != puntosAnteriores) {
                conductoresPorPuntos[puntosNuevos].push_front(Conductor(d, puntosNuevos)); //O(1)
                it->second = conductoresPorPuntos[puntosAnteriores].erase(it->second); //O(1)
                it->second = conductoresPorPuntos[puntosNuevos].begin(); //O(1)
            }
        }
    }

    void recuperar(const DNI& d, puntos p) { //O(1)
        auto it = conductores.find(d); //O(1)
        if(it == conductores.end()) throw domain_error("Conductor inexistente"); //O(1)
        else {
            int puntosAnteriores = it->second->p; //O(1)
            int puntosNuevos = puntosAnteriores + p;
            if(puntosNuevos > 15) puntosNuevos = 15; //O(1)
            if(puntosNuevos != puntosAnteriores) {
                conductoresPorPuntos[puntosNuevos].push_front(Conductor(d, puntosNuevos)); //O(1)
                it->second = conductoresPorPuntos[puntosAnteriores].erase(it->second); //O(1)
                it->second = conductoresPorPuntos[puntosNuevos].begin(); //O(1)
            }
        }
    }

    int consultar(const DNI& d) { //O(1)
        auto it = conductores.find(d); //O(1)
        if(it == conductores.end()) throw domain_error("Conductor inexistente"); //O(1)
        else return it->second->p; //O(1)
    }

    int cuantos_con_puntos(puntos p) { //O(1)
        if(p < 0 || p > 15) throw domain_error("Puntos no validos");
        return conductoresPorPuntos[p].size(); //O(1)
    }

    list<Conductor> lista_por_puntos(puntos p) { //O(1)
        if(p < 0 || p > 15) throw domain_error("Puntos no validos");
        return conductoresPorPuntos[p];
    }

};

bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            } else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            } else if (orden == "recuperar") {
                cin >> dni >> punt;
                dgt.recuperar(dni, punt);
            } else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            } else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            } else if (orden == "lista_por_puntos") {
                cin >> punt;
                auto const& lista = dgt.lista_por_puntos(punt);
                cout << "Tienen " << punt << " puntos:";
                for (auto const& elem : lista) {
                    cout << " " << elem.dni;
                }
                cout << '\n';
            } else
                cout << "OPERACION DESCONOCIDA\n";
        } catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
