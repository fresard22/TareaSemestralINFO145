#include <iostream>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include <limits>
#include <fstream>
#include "../include/busqueda.h"
#include "../include/genera.h"

using namespace std;



int main() {
  ofstream outFile("/home/fabrizio/Escritorio/DAA/TareaSemestral/TareaINFO-290-main-C++Modularizado/resultados/Resultados_GapEncoded10e6.csv");
  outFile << "Iteración,Tiempo Lineal (ns),Tiempo Normal (ns)" << endl;
  for (int i = 0; i < 150; i++)
  {
    int elementoABuscar=7;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, INT_MAX);
    elementoABuscar = dis(gen);
    cout << "Elemento a buscar: " << elementoABuscar << endl;

    int arregloNumeros[TAM];
    generarArregloLineal(arregloNumeros, TAM);
    int sample[m];
    /*cout << "Arreglo Lineal original: ";
    for (int i : arregloNumeros) {
      cout << i << " ";
    }
    cout << endl;*/
    generarSample(arregloNumeros, sample, m,b);
    gapEncode(arregloNumeros,TAM);

    /*cout << "Arreglo GC : ";
    for (int i : arregloNumeros) {
      cout << i << " ";
    }
    cout << endl;

    cout << "Arreglo sample: ";
    for (int i : sample) {
      cout << i << " ";
    }
    cout << endl;*/

    int posicionLineal;
    chrono::nanoseconds tiempoLineal = medirTiempoBusquedaBinariaGAPCODING(sample, m, elementoABuscar, posicionLineal, arregloNumeros);

    //Mostrar resultado de búsqueda binaria y tiempo
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
    chrono::nanoseconds tiempoNormal = medirTiempoBusquedaBinariaGAPCODING(sample, m, elementoABuscar, posicionNormal, arregloNumeros);

    //Mostrar resultado y tiempo de arreglo normal
    cout << "Tiempo de búsqueda normal: " << tiempoNormal.count() << " nanosegundos" << endl;
    outFile << i << "," << tiempoLineal.count() << "," << tiempoNormal.count() << endl;
  }
  outFile.close();
  return 0;
}