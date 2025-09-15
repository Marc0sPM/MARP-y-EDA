//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using TablaRefs = map<string, set<int>>;

void referencias(int numLineas, TablaRefs& refs){ //O(log(n)), siendo n el número de palabras a procesar
    // (ignoraremos la transformación de cada palabra a minúsculas, que sería O(k),
    // siendo k el número de letras de esta)
    string palabra;
    char c;
    for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
        cin.get(c);
        while (c != '\n'){
            cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
            cin >> palabra;
            string palabraMinuscula(palabra.length(), ' ');
            if(palabraMinuscula.length() > 2) {
                transform(palabra.begin(), palabra.end(), palabraMinuscula.begin(), ::tolower); //O(n), siendo n la cantidad de letras en la palabra
                refs[palabraMinuscula].insert(numLinea); //O(log(n)), siendo n el número de elementos en el árbol
            }
            cin.get(c);
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    char c;
    cin >> n;
    cin.get(c); // Me salto el \n de detrás del N
    if (n == 0)
        return false;

    TablaRefs refs;
    referencias(n,refs);

    // escribir sol
    for(auto it = refs.begin(); it != refs.end(); ++it) {
        cout << it->first;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            cout << " " << *it2;
        }
        cout << endl;
    }
    cout << "---\n";
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
#endif

    return 0;
}