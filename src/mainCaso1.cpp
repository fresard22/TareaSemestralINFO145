#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <fstream>
#include "../include/busqueda.h"
#include "../include/genera.h"

using namespace std;

int main() {
  //Creamos y abrimos archivo CSV para guardar estadísticas para calcular tiempo
  ofstream outFile("/home/fabrizio/Escritorio/DAA/TareaSemestral/TareaINFO-290-main-C++Modularizado/resultados/Resultados_busquedaBinaria2e16.csv");
  outFile << "Iteración,Tiempo Lineal (ns),Tiempo Normal (ns)" << endl;
  
  //Ciclo for para hacer 50 pruebas con un arreglo de tamaño TAM
  for (int i = 0; i < 50; i++){
   
    //Inicializamos el elemento a buscar como un valor random dentro del rango del arreglo
    int elementoABuscar;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, INT_MAX);
    elementoABuscar = dis(gen); 
    cout << "Elemento a buscar: " << elementoABuscar << endl;

    // Generar valores aleatorios para arreglo lineal
    int arregloNumeros[TAM];
    generarArregloLineal(arregloNumeros, TAM);

    //Realizar búsqueda binaria y obtener microsegundos arreglo lineal
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

    //Realizar búsqueda binaria y obtener tiempo arreglo normal
    int posicionNormal; 
    chrono::nanoseconds tiempoNormal = medirTiempoBusquedaBinaria(arregloNumeros, TAM, elementoABuscar, posicionNormal);

    //Mostrar resultado y tiempo de arreglo normal
    if (posicionNormal != -1) {
      cout << "Elemento encontrado en el arreglo normal en la posición " << posicionNormal << "." << endl;
    } else {
      cout << "Elemento no encontrado en el arreglo normal." << endl;
    }

    //Agregamos resultados al archivo CSV
    cout << "Tiempo de búsqueda normal: " << tiempoNormal.count() << " nanosegundos" << endl;
    outFile << i << "," << tiempoLineal.count() << "," << tiempoNormal.count() << endl;
  }
  //Cerramos archivo CSV
  outFile.close();
  return 0;
}