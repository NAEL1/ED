#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int operacion(int *v, int n, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<sup) && (!enc)) {
    med = (inf+sup)/2; 
    if (v[med]==x) 
      enc = true;
    else if (v[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();
  
  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % tam;
  
  //clock_t tini;    // Anotamos el tiempo de inicio
  //tini=clock();
  high_resolution_clock::time_point start = high_resolution_clock::now();
  // Algoritmo a evaluar
  operacion(v,tam,tam+1,0,tam-1);
  
  //clock_t tfin;    // Anotamos el tiempo de finalización
  //tfin=clock();
  high_resolution_clock::time_point end = high_resolution_clock::now();
  duration<double> tiempo = duration_cast<duration<double>>(end-start);

  // Mostramos resultados
  cout << tam << "\t" << tiempo.count() << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}
