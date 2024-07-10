#include "../include/genera.h"
#include <random>
#include <climits>

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
    vector[i] = vector[i - 1] + dis(gen)%epsilon; // Rango entre 0 y epsilon
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

void generarSample(int arreglo[], int sample[], int tamaño, int b){

  for (int i = 0; i < m; ++i) {
    // Añadir al sample el elemento de índice 2*i (elementos pares)
    sample[i]=arreglo[b*i];
  }
}
