//Alejandro Massó Martínez
//VJ30

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
using namespace std;


bool anagramas(const string& cad1, const string& cad2) { //Orden de la función: O(n)
    bool anagrama = true;
    if(cad1.length() != cad2.length()) return false; //Una comprobación por si acaso
    array<int, 26> letras; //Creamos un array por cada número de letras del alfabeto español menos la ñ
    for(int i = 0; i < 26; i++) {letras[i] = 0;} //Y lo inicializamos a 0: O(26) = O(1), no crece nunca dependiendo
                                                 //de las palabras, siempre es constante

    for(int j = 0; j < cad1.length(); j++) { //O(n), a mayor sea la palabra más veces se ejecutará el bucle
        int letraArray = cad1[j] - 97; //97 es el unicode de 'a'
        letras[letraArray]++;
    }
    for(int k = 0; k < cad2.length(); k++) { //O(n), a mayor sea la palabra más veces se ejecutará el bucle
        int letraArray = cad2[k] - 97; //97 es el unicode de 'a'
        letras[letraArray]--;
    }
    for(int l = 0; l < 26 && anagrama; l++) { //O(26) == O(1)
        if(letras[l] != 0) anagrama = false; //O(1)
    }
    return anagrama;

    //Caso mejor: son las mismas palabras de una leta, por ejemplo "a": tendríamos que nuestros bucles for
    //de búsqueda en el array se ejecutarían solo 1 vez, por tanto nos limitan los bucles que inicializan y
    //comprueban el array letras, siendo entonces O(26)
    //Caso peor: un anagrama con la palabra más larga del español: "electroencefalografista", con 23 letras: O(n)
    //Al no tratarse de recorrer un bucle dentro de otro, sino de dos bucles independientes, nuestra complejidad
    //va a estar por debajo de O(n*n), y es más, estará en O(n), siendo n el número de letras que tengan nuestras
    //palabras
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1,word2) ? "SI" : "NO") << endl;
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