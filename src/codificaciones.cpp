#include "../include/codificaciones.h"
#include <vector>
#include <map>
#include <string>

using namespace std;


// Función para dividir los símbolos en dos grupos
pair<vector<simbolo>, vector<simbolo>> dividesimbolos(const vector<simbolo>& simbolos) {
    int total = 0;
    for (const auto& simbolo : simbolos) {
        total += simbolo.frecuencias;
    }
    
    int mitad = total / 2;
    int suma = 0;
    size_t i;
    for (i = 0; i < simbolos.size(); ++i) {
        suma += simbolos[i].frecuencias;
        if (suma >= mitad) break;
    }
    
    return make_pair(
        vector<simbolo>(simbolos.begin(), simbolos.begin() + i + 1),
        vector<simbolo>(simbolos.begin() + i + 1, simbolos.end())
    );
}

// Función recursiva para generar los códigos Shannon-Fano
void codificacionSF(const vector<simbolo>& simbolos, string prefijo, map<int, string>& codigos) {
    if (simbolos.size() == 1) {
        codigos[simbolos[0].numero] = prefijo;
        return;
    }
    
    auto [left, right] = dividesimbolos(simbolos);
    
    codificacionSF(left, prefijo + "0", codigos);
    codificacionSF(right, prefijo + "1", codigos);
}