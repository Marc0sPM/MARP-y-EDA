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

	CaminosDFS(Grafo const& g, int s = 0) : visit(g.V(), false),
										ant(g.V()), s(s) {
			dfs(g, s);
	}

	/**
	*	Analiza si existe camino hacia un vertice
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

	/**
	*	Comprueba si el grafo es aciclico o no
	*	@return True en caso de que el grafo sea aciclico, false en caso contrario
	*/
	//bool esAciclico(Grafo const& g) {	// coste O(V + A)

	//	for (int v = 0; v < visit.size(); ++v) {
	//		if (visit[v]) {
	//			// Recorremos los adyacentes del v�rtice actual
	//			for (int w : g.ady(v)) {
	//				// Si se encuentra uun vertice ya visitado que no es el predecesor de v existe un ciclo
	//				if (visit[w] && ant[v] != w) {
	//					return false; // Encontramos un ciclo
	//				}
	//			}
	//		}
	//	}
	//	return true;
	//}
	/**
	*	@return True en caso de que todos los vertices se hayan visitado, false si hay alguno que no
	*/
	bool esConexo() const {
		for (int i = 0; i < visit.size(); ++i) {
			if (!visit[i]) return false;
		}
		return true;
	}

	bool dfsCiclo(int v, int parent, Grafo const& g, vector<bool>& visited) {
		visited[v] = true;

		for (int w : g.ady(v)) {
			if (!visited[w]) {
				if (dfsCiclo(w, v, g, visited))
					return true;
			}
			else if (w != parent) {
				return true; 
			}
		}
		return false;
	}

	bool esAciclico(Grafo const& g) {
		vector<bool> visited(g.V(), false);
		while(true){}
		for (int v = 0; v < g.V(); ++v) {
			if (!visited[v]) {
				if (dfsCiclo(v, -1, g, visited))
					return false; 
			}
		}
		return true;
	}
};