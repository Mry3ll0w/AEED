#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>
using namespace std;//Avoid using std:: ....
#include "tads implementados profesorado/pila_enla.h"
/**
 * @brief ejercicio 1
 * Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
 * es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
 * separadas por el carácter ‘&’.
 * @return bool
 */

bool ejercicio1(string str){//abcd & dcba 
    PilaEnla<char>p1;string str_aux;
    for (size_t i = str.find('&')+1; i < str.length(); i++)
    {
        p1.push(str[i]);//d c b a
    }

    for (size_t i = 0; i!=str.find('&'); i++)
    {
        str_aux+=str[i];//a b c d
    }

    str="";//reseteamos str para no crear otra variable
    while (p1.vacia()!=true)
    {
        str+=p1.tope();//d c b a ==> a b c d
        p1.pop();

    }

    return str==str_aux;
    
    
}


/**
 * Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
 * es de la forma A#B#C#D . . ., donde A, B, C, D,. . . son de la forma X&Y , que a su vez
 * están separados por el caráter ‘#’ 
*/
bool ejercicio2(string );//No me gusta repetirme

void ejercicio4(){
    fstream file;
    PilaEnla<double>numeros;
    string n1,n2;
    file.open("f.txt");
    getline(file,n1);
    getline(file,n2);
    numeros.push(stoi(n1));
    numeros.push(stoi(n2));
    double res=0;
    while (numeros.vacia()!=true)
    {
        res+=numeros.tope();
        numeros.pop();
    }
    file<<res<<endl;
}

/* ------------------------------- EJERCICIO 5 ------------------------------ */
/**
 * @brief (resumen)
 * -Resumen TAD Linea Texto==> 
 * El usuario puede introducir y modificar los
 * caracteres en modo interactivo pulsando teclas que le permiten mover el cursor por la línea
 * e insertar y suprimir caracteres.
 * ESPECIFICACION
 *  1) Linea_Texto::Linea_Texto()
 *      -Precondicion==> Ninguna 
 *      -Postcondion ==> Inicializa el objeto con una cadena vacia y una pila de caracteres vacia
 * 
 * 2) Linea_Texto::~Linea_Texto()
 *      - Pre==> no hay
 *      - Post==> Elimina el objeto de la clase Linea_texto y sus elementos privados
 * 
 * 3) void insertar_caracter(char c)
 *      Precondicion==> Exista el objeto cursor y la pila linea_t
 *      Post==> inserta en la posicion del cursor el caracter dado
 * 
 * 4) void avanzar_cursor(size_t posicion)
 *      Precondicion==> posicion tiene que ser menor<= tamaño de la linea-posicion_actual
 *      Postcondicion==> Situa el tope de esa pila en esa posicion
 * 
 *  5) void retrasar_cursor(size_t posicion)
 *      Precondicion==> posicion tiene que ser menor<=0
 *      Postcondicion==> Situa el tope de esa pila en esa posicion
 *  
 */    
template<typename t>       
class Linea_Texto
{
private:
    size_t tam_linea;
    size_t posicion_actual;
    PilaEnla<t> trasCursor;
    PilaEnla<t>linea_t;   
public:
    Linea_Texto():posicion_actual(0),tam_linea(0){}//Vacio ya que no necesita parametros de inicializacion ya que la linea de texto es vacia
    inline void insertar_caracter(char c){linea_t.push(c);tam_linea++;posicion_actual++;}
    void avanzar_cursor(size_t posicion){
        assert(posicion>=0&&"Posicion erronea");
        for (size_t i = 0; i < posicion; i++)
        {
            linea_t.push(trasCursor.tope());
            trasCursor.pop();
        }
    posicion_actual=posicion;
    }

    void retrasar_cursor(size_t posicion){
        //assert(posicion<=(tam_linea-posicion_actual)&&"Posicion erronea");
        for (size_t i = 0; i < posicion; i++)
        {
            trasCursor.push(linea_t.tope());
            linea_t.pop();
        }
        posicion_actual=posicion;
    }

    void show_text(){
        PilaEnla<char> trc=trasCursor;PilaEnla<char>actual=linea_t;
        string salida;
        while (trc.vacia()!=true)
        {
            salida+=trc.tope();
            trc.pop();
        }
        reverse(salida.begin(), salida.end());
        while (actual.vacia()!=true)
        {

            salida+=actual.tope();
            actual.pop();
        }
        reverse(salida.begin(),salida.end());
        cout<<salida<<endl;
    }

    inline void sobreescribir_cursor(t mod)noexcept{
        trasCursor.tope()=mod;
        
    }
   // ~Linea_Texto();
};

//Ejercicio 