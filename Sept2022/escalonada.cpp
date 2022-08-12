#include <iostream>
#include <cassert>
#include "tads/ListaEnla.h"
#include <climits>

using namespace std;//Avoid using std:: ....

struct salto{
    int x, y;
    salto(int x_=0, int y_=0):x(x_), y(y_){}

    //Para ordenar segun la x 
    bool operator < (salto other){
        return x < other.x;
    }

    bool operator == (const salto& other){
        return x == other.x;
    }
};

class Escalonada{

    ListaEnla<salto> Funcion;

public:
    
    Escalonada(const salto& x1){
        Funcion.insertar(x1, Funcion.fin());
    }
    void insertar_salto(const int& x , const int& y);
    void imprimir_funcion();
    void eliminar_salto(const int& x);
    int valor_en_x(const int& x);
    int valor_maximo();
    int valor_minimo();
    void traslacion(const int& w, const int& z);
};


int main(){
    
    Escalonada E(salto(-7,-4));
    E.insertar_salto(-5, 20);
    E.insertar_salto(-6,10);
    E.imprimir_funcion();

    cout<< E.valor_en_x(-8) <<endl;

return 0;
}


/**
 * @brief Añadir un nuevo salto a la funcion f, si existe ya un salto en x lo 
 * sustitimos por el nuevo
 * 
 * @param const int& x, const int& y
 * @return void, inserta el salto dado
 */
void Escalonada::insertar_salto(const int& x, const int& y){
    
    //La funcion esta vacia
    if(Funcion.fin() == Funcion.primera()){
        Funcion.insertar(salto(x,y), Funcion.fin());
    }
    else{
        salto nuevo_salto(x,y);
        //Insertamos en orden segun la X, la cual define como se ha de insertar
        auto p = Funcion.primera();
        
        while (p != Funcion.fin() && Funcion.elemento(p) < nuevo_salto){
            p = Funcion.siguiente(p);
        }
        //Si es igual no insertamos, simplemente lo sustituimos

        if(p != Funcion.fin() && Funcion.elemento(p).x == nuevo_salto.x){
            Funcion.elemento(p).y = nuevo_salto.y;
        }
        else{ // No es igual, insertamos en el orden dado
            Funcion.insertar(nuevo_salto,p);
        }

    }
}

/**
 * @brief Imprime la funcion escalonada
 * @param None
 * @return void
 */
void Escalonada::imprimir_funcion(){
    
    auto i = Funcion.primera();
    while (i != Funcion.fin()){
        cout<< Funcion.elemento(i).x<<", "<<Funcion.elemento(i).y<<endl;
        i = Funcion.siguiente(i);
    }

}   

/**
 * @brief Elimina el salto que corresponda en la posicion x
 * @param const int& x
 * @return void
 */
void Escalonada::eliminar_salto(const int& x){
    auto p = Funcion.buscar(salto(x));
    assert( p != Funcion.fin() && "El salto introducido no esta la funcion");
    Funcion.eliminar(p);
}

/**
 * @brief Devuelve el valor de la funcion en el punto x de la funcion
 * @param const int& x
 * @return int, en caso de no haber valor devuelve INT_MIN
 */
int Escalonada::valor_en_x(const int& x){
    
    auto i = Funcion.primera();
    
    while ( i != Funcion.fin() && Funcion.elemento(i).x < x){
        i = Funcion.siguiente(i);
    }
    
    //Si nos quedamos en el primero entonces no hay valor a la izquierda
    if(i == Funcion.primera())
        return INT_MIN;
    else if (i == Funcion.fin())
        return Funcion.elemento(Funcion.anterior(i)).y;
    else
        return Funcion.elemento(i).y;

}

/**
 * @brief Devuelve el maximo valor que toma Y 
 * @param none
 * @return int, en caso de vacia INT_MIN
 */
int Escalonada::valor_maximo(){

    if(Funcion.primera() == Funcion.fin()){
        //La lista esta vacia, por tanto devuelvo int min
        return INT_MIN;
    }
    else{
        
        auto p = Funcion.primera();
        int maximo;//-INF
        maximo = INT_MIN;
        
        while ( p != Funcion.fin()){
            if( maximo < Funcion.elemento(p).y){
                maximo = Funcion.elemento(p).y;
            }
            p = Funcion.siguiente(p);
        }

        return maximo;
    }

}


/**
 * @brief Devuelve el maximo valor que toma Y 
 * @param none
 * @return int, en caso de vacia INT_MAX
 */
int Escalonada::valor_minimo(){

    if(Funcion.primera() == Funcion.fin()){
        //La lista esta vacia, por tanto devuelvo int min
        return INT_MAX;
    }
    else{
        
        auto p = Funcion.primera();
        int minimo;//-INF
        minimo = INT_MAX;
        
        while ( p != Funcion.fin()){
            if( minimo > Funcion.elemento(p).y){
                minimo = Funcion.elemento(p).y;
            }
            p = Funcion.siguiente(p);
        }

        return minimo;
    }

}

/**
 * @brief Realiza una traslacion w unidades horizontalmente y z unidades verticalmente
 * @param const int& w, const int& z
 * @return none
 */
void Escalonada::traslacion(const int& w, const int& z){

    assert(Funcion.fin() == Funcion.primera() && "La funcion no puede estar vacia");

    auto p = Funcion.primera();
    while ( p != Funcion.fin()){
        
        Funcion.elemento(p).x += w;
        Funcion.elemento(p).y += z;

        p = Funcion.siguiente(p);
    }

}