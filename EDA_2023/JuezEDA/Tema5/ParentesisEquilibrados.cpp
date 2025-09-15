// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

// función que resuelve el problema
bool resolver(std::string frase) { //O(n), siendo n el número de caracteres de la frase
    std::stack<char> aperturas;
    for (int i = 0; i < frase.length(); i++) { //El bucle itera tantas veces como caracteres tenga la frase
        if (frase[i] == '(' || frase[i] == '[' || frase[i] == '{') aperturas.push(frase[i]);
        else {
            switch (frase[i]) { //O(1): empty, top y pop son constantes
                case ')':
                    if(!aperturas.empty() && aperturas.top() == '(') aperturas.pop();
                    else return false;
                break;
                case ']':
                    if(!aperturas.empty() && aperturas.top() == '[') aperturas.pop();
                    else return false;
                break;
                case '}':
                    if(!aperturas.empty() && aperturas.top() == '{') aperturas.pop();
                    else return false;
                break;
            }
        }
    }
    if(aperturas.size() != 0) return false; //O(1)
    else return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string frase;
    std::getline(std::cin, frase);

    if (! std::cin)
        return false;

    bool sol = resolver(frase);

    // escribir sol

    sol ? std::cout << "SI" << std::endl : std::cout << "NO" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
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