#ifndef GENERA_H
#define GENERA_H

#include <cmath>

// Tamaño del arreglo
const int TAM = pow(2,16);

// Funciones para generar arreglos
void generarArregloLineal(int vector[], int tam);
void generarArregloNormal(int vector[], int tam, double media, double desviacionEstandar);

#endif