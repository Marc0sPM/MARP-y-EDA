// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>

// función que resuelve el problema
std::string resolver(std::string mensaje) {
    std::deque<char> xprimaprima, tmp, xprima;
    for(int i = 0; i < mensaje.size(); ++i) xprimaprima.push_back(mensaje[i]);

    tmp.push_back(xprimaprima.front());
    xprimaprima.pop_front();
    auto itMitadDerecha = tmp.begin();
    tmp.push_front(xprimaprima.front());
    xprimaprima.pop_front();
    while(!xprimaprima.empty()) {
        tmp.push_back(xprimaprima.front());
        xprimaprima.pop_front();
        if(!xprimaprima.empty()) {
            tmp.push_front(xprimaprima.front());
            xprimaprima.pop_front();
        }
    }
    bool reverso = false;
    while(!tmp.empty()) {
        if(&(tmp.front()) == &(*itMitadDerecha)) reverso = true;
        if(!reverso) {
            xprima.push_back(tmp.front());
            tmp.pop_front();
        }
        else {
            xprima.push_front(tmp.back());
            tmp.pop_back();
        }
    }
    std::string x;
    int consonantesSeguidas = 0;
    while(!xprima.empty()) {
        if(xprima.front() == 'A' || xprima.front() == 'a' || xprima.front() == 'E' ||
            xprima.front() == 'e' || xprima.front() == 'I' || xprima.front() == 'i' ||
            xprima.front() == 'O' || xprima.front() == 'o' || xprima.front() == 'U' ||
            xprima.front() == 'u') {
            if(consonantesSeguidas > 1) {
                consonantesSeguidas = 0;

            }
            x.push_back(xprima.front());
            xprima.pop_front();
        }
        else {
            consonantesSeguidas++;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    std::string s;
    std::getline(std::cin, s);

    if (! std::cin)
        return false;

    resolver(s);

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}