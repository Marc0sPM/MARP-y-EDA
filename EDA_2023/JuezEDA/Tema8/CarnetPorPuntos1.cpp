//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

class carnet_puntos {
private:
    using DNI = string;
    using puntos = int;
    unordered_map<DNI, puntos> conductor;
    vector<puntos> conductoresPorPuntos = vector<puntos>(16, 0);

public:
    carnet_puntos() = default;

    void nuevo(DNI d) { //O(1)
        auto it = conductor.find(d); //O(1)
        if(it != conductor.end()) throw domain_error("Conductor duplicado"); //O(1)
        else {
            conductor[d] = 15; //O(1)
            ++conductoresPorPuntos[15];
        }
    }

    void quitar(DNI d, puntos p) { //O(1)
        auto it = conductor.find(d); //O(1)
        if(it == conductor.end()) throw domain_error("Conductor inexistente"); //O(1)
        else {
            --conductoresPorPuntos[it->second];
            it->second -= p; //O(1)
            if(it->second < 0) it->second = 0; //O(1)
            ++conductoresPorPuntos[it->second];
        }
    }

    int consultar(DNI d) { //O(1)
        auto it = conductor.find(d); //O(1)
        if(it == conductor.end()) throw domain_error("Conductor inexistente"); //O(1)
        else return it->second;
    }

    int cuantos_con_puntos(puntos p) { //O(1)
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
            } else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            } else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
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
