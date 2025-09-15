// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>


// función que resuelve el problema
std::array<int, 2> resolver(std::array<int, 10000> a, int elems) { //El orden de esta función es O(n)
    std::array<int, 2> picosValles = {0,0};
    for(int i = 1; i < elems - 1; i++) { //No nos interesa analizar los extremos puesto
                                        // que no pueden ser ni picos ni valles
        //El bucle for se ejecutará exactamente (elems - 2) veces, es decir. n-2 veces. Como las instrucciones
        //dentro del bucle son del orden O(1) ya que son operaciones aritmeticológicas, el orden de la función será
        //de O(n)
        if(a[i-1] < a[i] && a[i+1] < a[i]) {picosValles[0]++;} //O(1)
        else if(a[i-1] > a[i] && a[i+1] > a[i]) {picosValles[1]++;}//O(1)
    }
    return picosValles;

    //Mejor caso: 1 elemento en nuestro array: no se entra al bucle, por tanto, O(1)
    //Peor caso: 10000 elementos en nuestro array: el bucle se recorrerá completo, por tanto se ejecutarán
    //las dos instrucciones interiores 10000 veces, es decir, O(n)
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int elems = 0;
    std::cin >> elems;
    std::array<int, 10000> datos; //Se nos especifica en el enunciado que el mínimo es 1 y el máximo 10000
    for(int i = 0; i < elems; i++) {std::cin >> datos[i];} //Rellenamos nuestro array con los datos que se pasen

    std::array<int, 2> sol = resolver(datos, elems);
    // escribir sol
    std::cout << sol[0] << " " << sol[1] << std::endl;

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