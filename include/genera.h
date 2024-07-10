#ifndef GENERA_H
#define GENERA_H

#include <cmath>

// Tamaño del arreglo
const int TAM =pow(2,20);
const int m =log2(TAM);
const int b = TAM/m;

// Funciones para generar arreglos
void generarArregloLineal(int vector[], int tam);
void generarArregloNormal(int vector[], int tam, double media, double desviacionEstandar);
void gapEncode(int arr[], int tamaño);
void generarSample(int arreglo[], int sample[], int tamaño, int b);
long obtenerUsoMemoriaKB();
#endif