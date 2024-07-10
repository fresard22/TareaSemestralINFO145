#ifndef CODIFICACIONSF_H
#define CODIFICACIONSF_H

#include <vector>
#include <string>
#include <map>
#include <utility>

struct simbolo {
    int numero;
    int frecuencias;
    simbolo(int n, int f) : numero(n), frecuencias(f) {}
};


// Función para la búsqueda binaria
std::pair<std::vector<simbolo>, std::vector<simbolo>> dividesimbolos(const std::vector<simbolo>& simbolos);

void codificacionSF(const std::vector<simbolo>& simbolos, std::string prefijo, std::map<int, std::string>& codigos);

#endif