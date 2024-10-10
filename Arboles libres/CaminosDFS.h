#pragma once
#include <vector>
#include <deque>
#include "Grafos.h"
using namespace std;
using Camino = std::deque<int>;
class  CaminosDFS {
private:
	vector<bool> visit; //visit[v] hay camino de s a v
	vector<int> ant;	//ant[v] = ultimo vertice antes de llegar a 
	int s;				//vertice origen

	/**
	*	@brief Recorrido en profuncidad mediante recursion, rellena ant y visit
	*	@param g	Grafo que se recorre
	*	@param v	Vertice que se visita
	*/
	void dfs(Grafo const& g, int v) {
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dfs(g, w);
			}
		}
	}

public:

	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
										ant(g.V()), s(s) {
		dfs(g, s);
	}

	/**
	*	Annaliza si existe camino hacia un vertice
	*	@param v Vertice del cual queremos saber si existe camino
	*	@return True si existe camino, false si no existe
	*/
	bool hayCamino(int v) const {
		return visit[v]; //Si se ha visita significa que existe algun camino
	} 
	/**
	*	@param v Vertice del cual queremos hallar el camino desde el origen
	*	@return Camino desde el origen hasta el vertice v
	*/
	Camino camino(int v) const {
		if (!hayCamino(v))
			throw std::domain_error("No existe camino");

		Camino cam;
		for (int x = v; x != s; x = ant[x]) {
			cam.push_front(x);
		}
		cam.push_front(s);
		return cam;
	}

};