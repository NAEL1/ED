# Practica1


## Ejercicio1:
El siguiente código realiza la ordenación mediante el algoritmo de la burbuja:

```c++ 
1 void ordenar(int *v, int n) {
2	for (int i=0; i<n-1; i++)
3		for (int j=0; j<n-i-1; j++)
4			if (v[j]>v[j+1]) {
5				int aux = v[j];
6				v[j] = v[j+1];
7				v[j+1] = aux;
8			}
9  }
``` 
Calcule la eficiencia teórica de este algoritmo:
`
linea 2: 4 OE de las cuales 1 se ejecuta 1 vez( int i=0)
linea 3: 4 OE de las cuales 1 se ejecuta 1 vez( int j=0)
linea 4: 3 OE
linea 5: 3 OE
linea 6: 3 OE
linea 7: 2 OE
`

![pr1-1](https://github.com/NAEL1/ED/blob/master/practica1/pr1-1.png)