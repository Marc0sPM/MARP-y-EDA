
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */



// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct info_t {
    int h;
    float max, min;
};


info_t is_AVL(const BinTree<float> &bt) {

    info_t r, l;
    // Si left esta vacio info de left 
    if (bt.left().empty()) {
        l = { 0, bt.root(), bt.root() };
    }
    else {
        l = is_AVL(bt.left());
    }
    if (bt.right().empty()) {
        r = { 0, bt.root(), bt.root() };
    }
    else {
        r = is_AVL(bt.right());
    } 
    if (r.h != -1 && l.h != -1 && abs(l.h - r.h) < 2 && l.max <= bt.root() && r.min >= bt.root()) {
        return { std::max(r.h, l.h) + 1, l.min, r.max };
    }
    return { -1, 0 ,0 };

}


bool resuelveCaso(){
    BinTree<float> mytree;
    // leer los datos de la entrada
    std::string type;
    std::getline(std::cin, type);
    if (type == "N") {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream istr(line);
        mytree = read_tree<float>(istr);
        
    }
    else if (type == "P") {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream istr(line);
        mytree = read_tree_word<float>(istr);
    }
    if (!std::cin)  // fin de la entrada
    return false;

    // resolver el caso posiblemente llamando a otras funciones
    info_t info = is_AVL(mytree);
    
    // escribir la solución
    if (info.h != -1) std::cout << "SI" << std::endl;
    else  std::cout << "NO" << std::endl;
    //std::cout << mytree << std::endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
       // ajustes para que cin extraiga directamente de un fichero
    #ifndef DOMJUDGE
       std::ifstream in("casos.txt");
       auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
       while (resuelveCaso());
    
       // para dejar todo como estaba al principio
    #ifndef DOMJUDGE
       std::cin.rdbuf(cinbuf);
    #endif
       return 0;

}
