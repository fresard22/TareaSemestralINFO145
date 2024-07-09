#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>
#include <limits>
#include <fstream>
#include <math.h>

using namespace std;

const int TAM = 1000000; // Tamaño de los arreglos
const int epsilon=255;

// Función para generar un arreglo con distribución lineal aleatoria
void generarArregloLineal(int vector[], int tam) {
  // Generar primer elemento aleatorio entre 1 y MAX_INT
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(1, INT_MAX);
  vector[0] = dis(gen);

  // Generar siguientes elementos aleatorios
  for (int i = 1; i < tam; ++i) {
    vector[i] = vector[i - 1] + rand() % epsilon; // Rango entre 0 y epsilon
  }
}
// Función para generar un arreglo con distribución normal aleatoria
void generarArregloNormal(int vector[], int tam, double media, double desviacionEstandar) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribucion(media, desviacionEstandar);

    for (int i = 0; i < tam; ++i) {
        double aleatorio;
        do {
            aleatorio = distribucion(gen);
        } while (aleatorio < 0 || aleatorio > (double)(INT_MAX));
        
        vector[i] = (int)(round(aleatorio));
    }
}

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

chrono::nanoseconds medirTiempoBusquedaBinaria(int arreglo[], int tam, int elemento, int &posicion) {
  auto inicio = chrono::high_resolution_clock::now();

  posicion = buscarBinaria(arreglo, 0, tam - 1, elemento);

  auto fin = chrono::high_resolution_clock::now();
  chrono::nanoseconds duracion = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);

  return duracion;
}

void gapEncode(int arr[], int tamaño) {
  if (tamaño<=1) {
  }
  int anterior = arr[0];
  for (int i = 1; i <= tamaño; i++) {
    int gap = arr[i] - anterior;
    anterior = arr[i];
    arr[i]=gap;
  }
}

int main() {
  ofstream outFile("Resultados_GapEncoded10e6.csv");
  outFile << "Iteración,Tiempo Lineal (ns),Tiempo Normal (ns)" << endl;
  for (int i = 0; i < 150; i++)
  {
    int elementoABuscar;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, INT_MAX);
    elementoABuscar = dis(gen); 
    cout << "Elemento a buscar: " << elementoABuscar << endl;

    int arregloNumeros[TAM];
    generarArregloLineal(arregloNumeros, TAM);
    /*cout << "Arreglo Lineal original: ";
    for (int i : arregloNumeros) {
      cout << i << " ";
    }
    cout << endl;*/
    gapEncode(arregloNumeros,TAM);

    /*cout << "Arreglo Gap-coded: ";
    for (int i : arregloNumeros) {
      cout << i << " ";
    }
    cout << endl;*/

    int posicionLineal;
    chrono::nanoseconds tiempoLineal = medirTiempoBusquedaBinaria(arregloNumeros, TAM, elementoABuscar, posicionLineal);

    //Mostrar resultado de búsqueda binaria y tiempo
    if (posicionLineal != -1) {
      cout << "Elemento encontrado en el arreglo lineal en la posición " << posicionLineal << "." << endl;
    } else {
      cout << "Elemento no encontrado en el arreglo lineal." << endl;
    }
    cout << "Tiempo de búsqueda lineal: " << tiempoLineal.count() << " nanosegundos" << endl;

    //Generar números arreglo normal
    generarArregloNormal(arregloNumeros, TAM, 500000, 100000);

    //Mostrar arreglo normal
    /*cout << "Arreglo normal: ";
    sort(arregloNumeros, arregloNumeros+TAM);
    for (int i = 0; i < TAM; ++i) {
      cout << arregloNumeros[i] << " ";
    }
    cout << endl;*/

    //Realizar búsqueda binaria y obtener tiempo arreglo normal
    int posicionNormal; 
    chrono::nanoseconds tiempoNormal = medirTiempoBusquedaBinaria(arregloNumeros, TAM, elementoABuscar, posicionNormal);

    //Mostrar resultado y tiempo de arreglo normal
    if (posicionNormal != -1) {
      cout << "Elemento encontrado en el arreglo normal en la posición " << posicionNormal << "." << endl;
    } else {
      cout << "Elemento no encontrado en el arreglo normal." << endl;
    }
    cout << "Tiempo de búsqueda normal: " << tiempoNormal.count() << " nanosegundos" << endl;
    outFile << i << "," << tiempoLineal.count() << "," << tiempoNormal.count() << endl;
  }
  outFile.close();
  return 0;
}