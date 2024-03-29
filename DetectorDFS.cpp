//
// Created by andy on 23/10/20.
//

#include <map>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include "DetectorDFS.h"

#define GRAFO_VALIDO 0
#define GRAFO_CICLICO 1
#define INSTRUCCIONES_SIN_USAR 2

void agregarRecorrido(std::map<std::string, std::string> &visitados,
              const std::string& vertice_actual, const std::string& adyacente);
bool detectarCiclo(std::map<std::string, std::string>& visitados, const
                    std::string& vertice_actual, const std::string& adyacente);

int DetectorDFS::recorrerGrafo(Grafo& grafo) {
    std::stack<std::string> pila;
    std::string vertice_inicial = grafo.getVerticeInicial();
    pila.push(vertice_inicial);
    std::map<std::string, std::string> visitados;
    visitados.insert(std::pair<std:: string, std::string >(vertice_inicial,""));

    while (! pila.empty()) {
        std::string vertice = pila.top();
        pila.pop();
        std::set<std::string > adyacentes = grafo.obtenerAdyacentes(vertice);
        for (auto& adyacente : adyacentes) {
            if (adyacente == vertice) {
                this-> tiene_ciclos = true;
                return 0;
            }
            if (visitados.count(adyacente) > 0) {
                if (visitados.at(adyacente) != vertice)
                    this->tiene_ciclos = detectarCiclo(visitados,
                                                       vertice, adyacente);
                if (this-> tiene_ciclos)
                    return 0;
                continue;
            }
            agregarRecorrido(visitados, vertice, adyacente);
            pila.push(adyacente);
        }
    }
    this->tiene_instrucciones_sin_visitar = visitados.size() != grafo
                                                                .getOrden();
    return 0;
}

void DetectorDFS::resetearValores() {
    this-> tiene_ciclos = false;
    this-> tiene_instrucciones_sin_visitar = false;
}

int DetectorDFS::evaluarGrafo(Grafo &grafo) {
    this-> resetearValores();
    this->recorrerGrafo(grafo);
    if (tiene_ciclos)
        return GRAFO_CICLICO;
    else if (tiene_instrucciones_sin_visitar)
        return INSTRUCCIONES_SIN_USAR;
    return GRAFO_VALIDO;
}

void agregarRecorrido(std::map<std::string, std::string> &visitados,
            const std::string& vertice_actual, const std::string& adyacente) {
    std::string cadena = vertice_actual + " - " + visitados.at(vertice_actual);
    visitados.insert(std::pair<std::string, std::string> (adyacente, cadena));
}

bool detectarCiclo(std::map<std::string, std::string>& visitados, const
                   std::string& vertice_actual, const std::string& adyacente) {
    std::string recorrido = visitados.at(vertice_actual);
    std::string cadena_1 = adyacente + " -";
    if (recorrido.find(cadena_1) != std::string::npos)
        return true;
    std::string cadena_2 = "- " +adyacente;
    if (recorrido.find(cadena_2) != std::string::npos)
        return true;
    return false;
}
