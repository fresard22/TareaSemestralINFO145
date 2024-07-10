#include "../include/busqueda.h"
#include <chrono>
#include <iostream>

using namespace std;


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

// Función para realizar la búsqueda binaria
int buscarBinariaGP(int arreglo[], int left, int right, int elemento) {
  if (left >= right) {
    if (left>right){
      return right;
    } else {
      return left; // Elemento no encontrado
    }
  }
  int medio = (right + left) / 2;

  if (arreglo[medio] == elemento) {
    return medio; // Elemento encontrado
  } else if (elemento < arreglo[medio]) {
    return buscarBinariaGP(arreglo, left, medio - 1, elemento);
  } else {
    return buscarBinariaGP(arreglo, medio + 1, right, elemento);
  }
}

//Función para medir tiempo de la búsqueda en GapCoding
std::chrono::nanoseconds medirTiempoBusquedaBinariaGAPCODING(int arregloSample[], int tam, int elemento, int &posicion, int arregloGC[]) {
  auto inicio = std::chrono::high_resolution_clock::now();

  posicion = buscarBinariaGP(arregloSample, 0, tam - 1, elemento);
  posicion = posicion-1;
  if (posicion<0){
    posicion=0;
  }
  int suma=0;
  int i=0;
  while(suma<arregloSample[posicion]){
    suma=suma+arregloGC[i];
    i++;
  }
  posicion=posicion+1;
  while (suma<elemento){
    suma=suma+arregloGC[posicion];
    posicion++;
  }
  if (suma==elemento){
    cout << "Elemento encontrado en posicion: " << posicion << endl;
  } else {
    cout << "Elemento no encontrado" << endl;
  }
  auto fin = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

  return duracion;
}

//Función que ejecuta la búsqueda binaria y toma el tiempo de ejecución
std::chrono::nanoseconds medirTiempoBusquedaBinaria(int arreglo[], int tam, int elemento, int &posicion) {
  auto inicio = std::chrono::high_resolution_clock::now();

  posicion = buscarBinaria(arreglo, 0, tam - 1, elemento);

  auto fin = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

  return duracion;
}