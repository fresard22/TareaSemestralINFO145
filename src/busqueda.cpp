#include "../include/busqueda.h"
#include <chrono>


// Función para realizar la búsqueda binaria
int buscarBinaria(int arreglo[], int left, int right, int elemento) {
  if (left >= right) {
    return -1; // Elemento no encontrado
  }
  int medio = (right + left) / 2;

  if (arreglo[medio] == elemento) {
    return medio; // Elemento encontrado
  } else if (elemento < arreglo[medio]) {
    return buscarBinaria(arreglo, left, medio - 1, elemento);
  } else {
    return buscarBinaria(arreglo, medio + 1, right, elemento);
  }
}

//Función que ejecuta la búsqueda binaria y toma el tiempo de ejecución
std::chrono::nanoseconds medirTiempoBusquedaBinaria(int arreglo[], int tam, int elemento, int &posicion) {
  auto inicio = std::chrono::high_resolution_clock::now();

  posicion = buscarBinaria(arreglo, 0, tam - 1, elemento);

  auto fin = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

  return duracion;
}