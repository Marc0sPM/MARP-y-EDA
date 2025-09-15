// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
void resolver1(int datos, int longitud, int& ac) { //Función recursiva
    if(longitud == 0) return;
    else {
        int complementario = 0, base = 1;
        for(int i = 1; i < longitud; i++) {
            base *= 10;
        }
        complementario = 9 - datos/base;
        ac += complementario * base;
        resolver1(datos - (datos/base)*base, longitud - 1, ac);
    }
}

void resolver2(int datos, int longitud, int longitudIni, int& ac) {  //Función recursiva
    if(longitud == 0) return;
    else {
        int complementario = 0, base = 1, base2 = 1;
        for(int i = 1; i < longitud; i++) {
            base *= 10;
        }
        for(int j = longitud; j < longitudIni; j++) {
            base2 *= 10;
        }
        complementario = 9 - datos/base;
        ac += complementario * base2;
        resolver2(datos - (datos/base)*base, longitud - 1, longitudIni, ac);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int datos = 0, longitud = 0, datosTMP;
    std::cin >> datos;
    datosTMP = datos;
    do {
        longitud++;
        datosTMP /= 10;
    } while (datosTMP);

    int sol1 = 0;
    resolver1(datos, longitud, sol1);
    int sol2 = 0;
    resolver2(datos, longitud, longitud, sol2);
    // escribir sol

    std::cout << sol1 << " " << sol2 << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}