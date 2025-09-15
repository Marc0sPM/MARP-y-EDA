//Alejandro Massó Martínez
//VJ30


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
                     vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv){ //Orden: O(n)
    int i = 0, j = 0;

    while(i < tpv.size() && j < eda.size()) {
        if(tpv[i] == eda[j]) {
            comunes.push_back(tpv[i]);
            i++;
            j++;
        }
        else if (tpv[i] > eda[j]){
            soloEda.push_back(eda[j]);
            j++;
        }
        else if(tpv[i] < eda[j]) {
            soloTpv.push_back(tpv[i]);
            i++;
        }
    }

    if(i == tpv.size()) {
        for(int h = j; h < eda.size(); h++) {
            soloEda.push_back(eda[h]);
        }
    }
    else if(j == eda.size()) {
        for(int k = i; k < tpv.size(); k++) {
            soloTpv.push_back(tpv[k]);
        }
    }

    //La complejidad del algoritmo es O(n), puesto que solo recorres una vez los vectores con números, siendo n
    //el tamaño de estos.
    //Por otra parte, si tenemos dos vectores desordenados, ordenarlos nos cuesta O(n*log(n)), mientras que recorrerlos
    //para la búsqueda es O(n). Al estar ambos en la misma función, el orden de la función es O(max[n*log(n), n]), que
    //en este caso es O(n*log(n)).

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda,tpv,comunes,soloEda,soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
