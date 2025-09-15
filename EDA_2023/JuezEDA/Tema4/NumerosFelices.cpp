// Alejandro Massó Martínez
// VJ30

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>

std::vector<int> descomponer(int n) { //Lineal en la cantidad de dígitos del número n, por tanto O(log(n) + 1)
    std::vector<int> descomposicion;
    std::string num = std::to_string(n);
    for(char c : num) {
        int tmp = c - '0';
        descomposicion.push_back(tmp);
    }
    return descomposicion;
}

bool esFeliz(int n, std::set<int>& s, std::vector<int>& pasos) { //O(log(x)), siendo x MAX(DigitosNumero, NumeroPasos)
    if(n == 1) { //O(1)
        pasos.push_back(n); //O(1)
        return true; //O(1)
    }

    std::vector<int> descomp = descomponer(n); //O(log(n) + 1)

    auto it = s.find(n); //O(log(s.size())), logarítmico en el número de descomposiciones
    if(it == s.end()) { //O(1)
        s.insert(n); //O(log(s.size())), logarítmico en el número de descomposiciones
        pasos.push_back(n); //O(1)
    }
    else {
        pasos.push_back(n); //O(1)
        return false; //O(1)
    }

    int suma = 0;
    for(int e : descomp) suma += e * e; //O(log(n) + 1): hacemos la suma tantas veces como dígitos tenga el número, que son log(n) + 1, siendo n el número

    return esFeliz(suma, s, pasos);
}

// función que resuelve el problema
bool resolver(int dato, std::vector<int>& pasos) { //O(log(x))
    std::set<int> s;
    return esFeliz(dato, s, pasos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::vector<int> pasos;
    std::cin >> num;
    if (! std::cin)
        return false;

    bool sol = resolver(num,pasos);

    // escribir sol
    for(int e : pasos) std::cout << e << " ";

    sol ? std::cout << 1 << std::endl : std::cout << 0 << std::endl;
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