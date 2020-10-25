//
// Created by andy on 23/10/20.
//

#ifndef UNTITLED_GRAFO_H
#define UNTITLED_GRAFO_H

#include <set>
#include <map>
#include <string>

class Grafo {
public:
    int agregarVertice(std::string nombre_vertice);
    int agregarArista(std::string vertice_1, std::string vertice_2);
    std::set<std::string> obtenerAdyacentes(std::string vertice);
    std::string getVerticeInicial();
    size_t getOrden();
    void imprimir();
    void setVerticeInicial(std::string nombre_vertice_inicial);

private:
    int cant_vertices;
    int cant_aristas;
    std::string vertice_inicial;
    std::map<std::string, std::set <std::string>> relaciones;
};


#endif //UNTITLED_GRAFO_H
