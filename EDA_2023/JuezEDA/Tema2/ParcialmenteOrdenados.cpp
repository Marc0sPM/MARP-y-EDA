//
// Created by Alex Massó Martínez on 23/9/22.
//
#include <vector>
using namespace std;

bool parcialmenteOrd(vector<int> const& v, int ini, int fin, int& min, int& max) {
    int n = fin - ini;
    if(n == 0) {
        return true;
    }
    else if(n==1) {
        min = v[ini];
        max = v[ini];
        return true;
    }
    else {
        int mitad = (ini+fin)/2;
        int maximoIzq, maximoDcha, minimoIzq, minimoDcha;
        maximoIzq = maximo(v, ini, mitad);
        maximoDcha = maximo(v, mitad, fin);
        minimoIzq = minimo(v, ini, mitad);
        minimoDcha = minimo(v, mitad, fin);
        bool ordIzq = parcialmenteOrd(v, ini, mitad, minimoIzq, maximoIzq);
        bool ordDcha = parcialmenteOrd(v, mitad, fin, minimoDcha, maximoDcha);
        min = minimo2(minimoDcha, minimoIzq);
        max = maximo2(maximoIzq, maximoDcha);
        return ordIzq && ordDcha && maximoDcha >= maximoIzq && minimoIzq <= minimoDcha;
    }
}