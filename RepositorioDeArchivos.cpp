//
// Created by andy on 29/10/20.
//


#include <string>
#include "RepositorioDeArchivos.h"

void RepositorioDeArchivos::guardarArchivo(const std::string& nombre) {
    this-> nombres_de_archivos.push(nombre);
}

std::string RepositorioDeArchivos::getProximoArchivo() {
    m.lock();
    std::string nombre_archivo;
    if (this->nombres_de_archivos.empty()) {
        nombre_archivo = "";
    } else {
        nombre_archivo = this-> nombres_de_archivos.front();
        this->nombres_de_archivos.pop();
    }
    m.unlock();
    return nombre_archivo;
}

bool RepositorioDeArchivos::tieneArchivosSinProcesar() {
    return !this->nombres_de_archivos.empty();
}

