// Alejandro Massó Martínez
// VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Tupla {
    int numeroElementos;
    std::vector<int> contenido;
    Tupla(int n) : numeroElementos(n) {
        contenido = std::vector<int>(numeroElementos - 1);
    }
};

// función que resuelve el problema
void resolver(std::vector<Tupla>& v, int altura, int k) {
    for(int i = 0; i < 3; ++i) {
        v[k].contenido.push_back(i);
        if(k != altura - 1) resolver(v, altura, k+1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura;
    std::cin >> altura;
    if (altura == 0)
        return false;

    std::vector<Tupla> soluciones(altura, Tupla(altura));

    resolver(soluciones, altura, 0);

    // escribir sol

    for(Tupla t : soluciones) {
       for(int e : t.contenido) {
           switch(e) {
               case 0:
                   std::cout << "azul";
                   break;
               case 1:
                   std::cout << "rojo";
                   break;
               case 2:
                   std::cout << "verde";
                   break;
           }
       }
        std::cout << std::endl;
    }

    std::cout << std::endl;
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
