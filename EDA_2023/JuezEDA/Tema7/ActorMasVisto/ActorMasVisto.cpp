//Alejandro Massó Martínez
//VJ30
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


using Pelicula = string;
using Actor = string;
using NumeroActores = int;
using MinutosEnPantalla = int;

struct Peliculas {
    map<Actor, MinutosEnPantalla> actores;
    int vecesEmitida;
};

using RepartosPeliculas = map<Pelicula, Peliculas>;

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas){ //O(n*m), siendo n el número de películas a analizar
                                                                 //y m el número de actores de cada película
    Pelicula p; NumeroActores n = 0;
    Actor actor;
    for (int i = 0; i < numPeliculas; ++i){
        cin >> p >> n;
        map<Actor, MinutosEnPantalla> actoresTMP;
        for (int j = 0; j < n; ++j){
            Actor a;
            MinutosEnPantalla m;
            cin >> a >> m;
            actoresTMP.insert({a, m}); //O(log(n))
        }
       peliculas.insert({p, {actoresTMP, 0}}); //O(log(n))
    }
}

//O(n), lineal, debido a que recorremos todas las emisiones de las películas
void calculoMasEmitida(RepartosPeliculas& repartos, const vector<string>& secEmisiones) {
    int numMasEmitida = 0; Pelicula masEmitida = " ";
    for (int i = 0; i < secEmisiones.size(); ++i) {
        int* emision = &repartos[secEmisiones[i]].vecesEmitida;
        (*emision)++;
        if (numMasEmitida <= *emision)
        {
            numMasEmitida = *emision;
            masEmitida = secEmisiones[i];
        }
    }
    cout << numMasEmitida << " " << masEmitida << endl;
}

void actorMasEmitido(RepartosPeliculas& repartos, vector<string> const& secEmisiones) { //O(2*n*m)
    map<Actor, MinutosEnPantalla> actoresTMP;
    MinutosEnPantalla tiempoMaxPantalla = 0;

    for (auto it = repartos.begin(); it != repartos.end(); ++it) { //O(n*m), siendo n
                                                                //el número de películas emitidas, y m el número
                                                                //de actores que aparece en cada una de ellas
        for (auto it2 = (*it).second.actores.begin(); it2 != (*it).second.actores.end(); ++it2) {
            int numVecesEmit = (*it).second.vecesEmitida;
            MinutosEnPantalla minutosActorPorPeli = (*it2).second;
            MinutosEnPantalla tiempoTotalEnPantalla = numVecesEmit * minutosActorPorPeli + actoresTMP[(*it2).first];
            if (tiempoTotalEnPantalla > tiempoMaxPantalla) tiempoMaxPantalla = tiempoTotalEnPantalla;
            actoresTMP[(*it2).first] = tiempoTotalEnPantalla;
        }
    }

    cout << tiempoMaxPantalla << " ";

    int i = 0;
    for (auto it3 = actoresTMP.begin(); it3 != actoresTMP.end(); ++it3) { //O(n), siendo n el número
                                                                //total de actores de todas las películas (n*m)
        if ((*it3).second == tiempoMaxPantalla) {
            if (i == actoresTMP.size() - 1) cout << (*it3).first << endl;
            else cout << (*it3).first << " ";
        }
        i++;
    }
}


void procesarEmisiones(RepartosPeliculas& repartos, vector<string> const& secEmisiones){
    calculoMasEmitida(repartos, secEmisiones); //O(n)
    actorMasEmitido(repartos, secEmisiones); //O(2 * n * m)
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#define DOMJUDGE
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
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