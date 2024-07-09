#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <chrono>

// Función para la búsqueda binaria
int buscarBinaria(int arreglo[], int left, int right, int elemento);

// Función para medir el tiempo de búsqueda binaria
std::chrono::nanoseconds medirTiempoBusquedaBinaria(int arreglo[], int tam, int elemento, int &posicion);

#endif