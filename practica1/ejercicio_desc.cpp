#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;

/*void ordenar(int *v, int n) { // funcion de ordenacion burbuja
  for (int i=0; i<n-1; i++)
    for (int j=0; j<n-i-1; j++)
      if (v[j]>v[j+1]) {
      int aux = v[j];
      v[j] = v[j+1];
      v[j+1] = aux;
    }
}
*/
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
  /*for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % tam;
  ordenar(v,tam); // ordenamos el vector
 */
  high_resolution_clock::time_point start = high_resolution_clock::now();
  for(int i=0;i<1000 ; i++)
    operacion(v,tam,tam+1,0,tam-1); // Algoritmo a evaluar
  high_resolution_clock::time_point end = high_resolution_clock::now();
  duration<double> tiempo = duration_cast<duration<double>>(end-start)/1000.0;

  // Mostramos resultados
  cout << tam << "\t" << tiempo.count() << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}
