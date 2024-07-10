#include <iostream>
#include <algorithm>
#include <random>
#include <limits.h>
#include "../include/codificaciones.h"
#include "../include/genera.h"
#include "../include/busqueda.h"
using namespace std;

int main() {

    // Arreglo de números ordenados de forma creciente, con repeticiones
    //vector<int> numeros = generarArregloLineal()
    int arregloNumeros[TAM];
    generarArregloLineal(arregloNumeros, TAM);

    // Contar frecuencias manteniendo el orden
    vector<simbolo> simbolos;
    for (int num : arregloNumeros ) {
        auto it = find_if(simbolos.begin(), simbolos.end(),
                          [num](const simbolo& s) { return s.numero == num; });
        if (it == simbolos.end()) {
            simbolos.emplace_back(num, 1);
        } else {
            it->frecuencias++;
        }
    }
    
    map<int, string> codigos;
    codificacionSF(simbolos, "", codigos);
    
    // Imprimir los códigos
    for (const auto& simbolo : simbolos) {
        cout << simbolo.numero << " (frecuencias: " << simbolo.frecuencias << "): " 
             << codigos[simbolo.numero] << endl;
    }

    string encodedArray[TAM];
    for (int i = 0; i < TAM; ++i) {
        encodedArray[i] = codigos[arregloNumeros[i]];
    }
    
    cout << "\nArreglo codificado Shannon-Fano:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << encodedArray[i] << " ";
    }
    std::cout << std::endl;

    int elementoABuscar;
    long memoriaKB = obtenerUsoMemoriaKB();
    cout << "Uso de memoria (KB): " << memoriaKB << endl;

    return 0;
}