#include <iostream>
#include "cronometro.h"
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std; // Avoid using std:: ....
void EsquemaAdaptativoDirecto();
void EsquemaAdaptativoIndirecto();
int main()
{
    EsquemaAdaptativoIndirecto();
    return 0;
}

// Funcion para realizar pruebas de caja negra

/**
 * Enunciado tipico:
 * Analice empiricamente los algoritmos del primer ejercicio en el caso promedio, use las permutaciones aleatorias
 * de un vector de enteros que contenga los n primeros numeros naturales, donde n variará desde 1000 hasta 20000
 * en incrementos de 1000, empleando un esquema adaptativo de medida. Considere que la resolución del cronometro
 * es 1 micro segundo y el maximo error absoluto permitido es de 0.5 micro segundos por segundo.
 *
 * Conclusiones:
 * Maximo error abs = 1 micro segundo ==> 0.000001 s (resolucion del cronometro)
 * Maximo error relativo: 0.5 micro segundos => 0.000005 s (maximo error absoluto)
 */

// Sin errores relativo/absoluto
void EsquemaAdaptativoDirecto()
{

    // Definicion de constantes
    const double dEabs = 0.000001, dErel = 0.000005;
    vector<int> aNaturales;
    int iLongitud = 1000;
    cronometro crono;
    double dTiempo = 0.0;
    long int liRepeticiones = 0;
    while (iLongitud <= 20000)
    {

        // inicializacion del vector
        aNaturales = vector<int>(iLongitud);
        vector<int> aNaturalesOrdenados = vector<int>(iLongitud);
        for (int i = 0; i < iLongitud; ++i)
        {
            aNaturales[i] = i + 1;
            aNaturalesOrdenados[i] = i + 1;
        }

        std::random_shuffle(aNaturales.begin(), aNaturales.end());

        crono.activar();
        std::sort_heap(aNaturales.begin(), aNaturales.end());
        crono.parar();

        dTiempo += crono.tiempo();
        liRepeticiones++;

        iLongitud += 1000;
    }
    cout << dTiempo / liRepeticiones << " tiempo medio" << endl;
}

void EsquemaAdaptativoIndirecto()
{

    // Definicion de constantes
    const double dEabs = 0.000001, dErel = 0.000005;
    vector<int> aNaturales;
    int iLongitud = 1000;
    cronometro crono;
    long int liRepeticiones = 0;
    while (iLongitud <= 20000)
    {

        // inicializacion del vector
        aNaturales = vector<int>(iLongitud);
        vector<int> aNaturalesOrdenados = vector<int>(iLongitud);
        for (int i = 0; i < iLongitud; ++i)
        {
            aNaturales[i] = i + 1;
            aNaturalesOrdenados[i] = i + 1;
        }

        crono.activar();
        do
        {
            std::random_shuffle(aNaturales.begin(), aNaturales.end());
            std::sort(aNaturales.begin(), aNaturales.end());
            liRepeticiones++;
        } while (crono.tiempo() < (dEabs / (dEabs + dErel)));
        crono.parar();

        cout << "Tiempo para " << iLongitud << " = " << crono.tiempo() / liRepeticiones << " segundos" << endl;

        iLongitud += 1000;
    }
}