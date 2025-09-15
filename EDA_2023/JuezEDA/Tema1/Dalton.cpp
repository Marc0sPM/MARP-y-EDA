// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

// función que resuelve el problema
std::string resolver(std::array<int, 100000> a, int numCasos) { //El orden de esta función es O(n)
    bool dalton = true; //O(1): asignaciones siempre tienen coste O(1)
    int i = 0, TMP = 0; //O(1), O(1): asignaciones siempre tienen coste O(1)

    if(a[i] < a[i+1]) { //O(1)
        TMP = a[i];
        i++;
        while(i < numCasos && dalton) { //Nuestro while sería el sumatorio desde 0 hasta (numCasos - 1) del
                                        // coste de las instrucciones en su interior, por tanto, de 1,
                                        // que en total nos va a dar un orden de O(numCasos), es decir:
                                        //O(n).
            if(a[i] <= TMP) dalton = false; //O(1): al tratarse de un if-else con instrucciones básicas,
                                            // su coste es del orden de O(1)
            else TMP = a[i]; //O(1)
            i++; //O(1): instrucción básica
        }
    }
    else { //Esta parte es igual que el if anterior pero comprueba si el orden es estrictamente decreciente
        TMP = a[i];
        i++;
        while(i < numCasos && dalton) {
            if(a[i] >= TMP) dalton = false;
            else TMP = a[i];
            i++;
        }
    }

    if(dalton) return "DALTON";
    else return "DESCONOCIDOS";

    //Nuestro caso mejor es que solo tengamos 2 elementos, o más elementos con la condición de que el segundo
    // sea menor o igual al primero, por tanto, el bucle solo se ejecutaría dos veces, dándonos un orden de O(2) == O(1)
    //Nuestro caso peor es que los n elementos estén en orden, dando un orden de O(n), ya que tendría que ejecutar
    //el bucle tantas veces como elementos haya.
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numCasos = 0; //Número de casos de la entrada
    std::cin >> numCasos;

    if (numCasos == 0) //Si es 0, salimos del método y acabaría el problema
        return false;

    std::array<int, 100000> datos; //Se nos especifica en el enunciado que el mínimo es 2 y el máximo 100000
    for(int i = 0; i < numCasos; i++) {std::cin >> datos[i];} //Rellenamos nuestro array con los datos que se pasen

    std::string sol = resolver(datos, numCasos); //Mandamos el array junto con el número de elementos del array

    // escribir sol
    std::cout << sol << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("trenes.txt");
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
