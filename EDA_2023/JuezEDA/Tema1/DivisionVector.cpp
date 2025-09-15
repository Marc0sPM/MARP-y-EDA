// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <string>


// función que resuelve el problema
bool resolver(std::array<int, 300000> a, int numElems, int pos) { //Orden de la función: O(n)
    if(pos == numElems - 1) return true;
    int maxVal = a[0], minVal = a[pos+1]; //O(1)
    for(int i = 0; i < pos + 1; i++) { //Se ejecutará este bucle p veces, es decir O(p)
        if(a[i] >= maxVal) maxVal = a[i]; //O(1)
    }
    for(int j = pos + 1; j < numElems && maxVal < minVal; j++) {
                                                //Mientras que este se ejecutará (numElems - p) veces o hasta que
                                                //encuentre un valor igual o menor que el mayor de la primera parte
                                                //del array, reduciendo mucho su tiempo de búsqueda es decir,
                                                // a mayor sea numElems, más veces se repetirá el bucle
                                                //por tanto, estamos ante otro caso de O(n)
        if(a[j] <= minVal) minVal = a[j]; //O(1)
    }

    if(maxVal >= minVal) return false; //O(1)
    else return true; //O(1)

    //Caso mejor: el array tiene 1 entrada, por lo que solo entraría 1 vez al primer bucle, pero ninguna al segundo,
    //por tanto estaríamos hablando de que solo ejecuta 1 instrucción del bucle, siendo el orden O(n)
    //Caso peor: el array está completo (tiene 300000 entradas) y la última entrada es un valor menor o igual
    //al mayor valor de la primera parte del array: O(n)
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElems, pos;
    std::cin >> numElems; std::cin >> pos;
    std::array<int, 300000> datos; //Se nos especifica en el enunciado que el mínimo es 1 y el máximo 300000
    for(int i = 0; i < numElems; i++) {std::cin >> datos[i];} //Rellenamos nuestro array con los datos que se pasen

    bool sol = resolver(datos, numElems, pos);
    // escribir sol

    if(sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

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