//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

using Diccionario = map<string, int>;

void compararDiccionarios(const Diccionario& antiguo, const Diccionario& nuevo) { //O(n): recorremos los 2 diccionarios hasta el final en el mismo bucle
    auto itAnt = antiguo.begin();
    auto itNue = nuevo.begin();
    vector<string> anadidas, eliminadas, modificadas;

    bool sinCambios = true;
    for(; itAnt != antiguo.end() && itNue != nuevo.end(); ) {
        if(antiguo.empty()) {
            sinCambios = false;
            anadidas.push_back(itNue->first);
            ++itNue;
        }
        else if(nuevo.empty()) {
            sinCambios = false;
            eliminadas.push_back(itAnt->first);
            ++itAnt;
        }
        else {
            if(itAnt->first == itNue->first) {
                if(itAnt->second != itNue->second) {
                    sinCambios = false;
                    modificadas.push_back(itAnt->first);
                }
                ++itAnt;
                ++itNue;
            }
            else if(itAnt->first < itNue->first) {
                sinCambios = false;
                eliminadas.push_back(itAnt->first);
                ++itAnt;
            }
            else if(itAnt->first > itNue->first) {
                sinCambios = false;
                anadidas.push_back(itNue->first);
                ++itNue;
            }
        }

    }

    if(itAnt == antiguo.end() && itNue != nuevo.end()) {
        sinCambios = false;
        while(itNue != nuevo.end()) {
            anadidas.push_back(itNue->first);
            ++itNue;
        }
    }
    else if(itNue == nuevo.end() && itAnt != antiguo.end()) {
        sinCambios = false;
        while(itAnt != antiguo.end()) {
            eliminadas.push_back(itAnt->first);
            ++itAnt;
        }
    }


    //No lo cuento en la complejidad por ser la salida en consola
    if(sinCambios) cout << "Sin cambios" << endl;
    else {
        if(anadidas.size() != 0) {
            cout << "+";
            for(auto it = anadidas.begin(); it != anadidas.end(); ++it) cout << " " << *it;
            cout << endl;
        }
        if(eliminadas.size() != 0) {
            cout << "-";
            for(auto it = eliminadas.begin(); it != eliminadas.end(); ++it) cout << " " << *it;
            cout << endl;
        }
        if(modificadas.size() != 0) {
            cout << "*";
            for(auto it = modificadas.begin(); it != modificadas.end(); ++it) cout << " " << *it;
            cout << endl;
        }
    }
    cout << "---" << endl;
}

void leerDiccionario(Diccionario& diccionario){
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n'){
        cin.unget();
        cin >> clave >> valor;
        string claveMinuscula(clave.length(), ' ');
        transform(clave.begin(), clave.end(), claveMinuscula.begin(), ::tolower);
        diccionario.insert({claveMinuscula, valor});
        cin.get(c);
    }
}

void resuelveCaso(){
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);
    compararDiccionarios(antiguo, nuevo);
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
