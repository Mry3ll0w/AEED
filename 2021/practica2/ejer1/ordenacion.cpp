#include <algorithm>  //std:swap, std::min_element
using namespace std; 
static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

// Ordenaci�n por intercambio directo del rango [p, f).

void ordenacion_intercambio(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i)
    burbujea(i, f);
}

// Desciende el m�nimo del rango [i, j) 
// hasta la posici�n i.
static void burbujea(int* i, int* j)
{
  for (int* k = j - 1; k != i; --k) {
    if (*k < *(k - 1))
      swap(*k, *(k - 1));
  }
}

// Ordenaci�n por selecci�n directa del rango [p, f).

void ordenacion_seleccion(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i) {
    int* p = min_element(i, f); // pos. m�n. del rango [i, f)
    swap(*i, *p);
  }
} 

// Ordenaci�n por inserci�n directa del rango [p, f).

void ordenacion_insercion(int* p, int* f)
{
  for (int* i = p + 1; i != f; ++i)
    inserta(p, i);
}

// Inserci�n ordenada de *j en el rango ordenado [i, j - 1]
static void inserta(int* i, int* j)
{
  int x = *j;
  while (j != i && x < *(j - 1)) {
    *j = *(j - 1);
    --j;
  }
  *j = x;
}

