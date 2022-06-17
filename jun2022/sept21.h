#ifndef sept21_h
#define sept21_h

#include <iostream>
#include "ListaEnla.h"

//a) Estructura necesaria para tal
struct funcion {
    int x;
    int y;
    funcion(int x_=1, int y_=1):x(x_),y(y_){}
    //Iremos insertando en orden
    bool operator < (funcion& f){
        return x < f.x;
    }
    
    bool operator == (int x2){
        return x == x2;
    }
    
};
/*
 Especificacion
 
 Usaremos EL T.A.D. escalonada para representar una función escalonada dada por sus valores de coordenada x e y
 almacenados de forma consecutiva, según el corte en x.
 
 Operaciones:
 escalonada():
    Pre==> Recibe un elemento x que sirve para concretar a partir de donde empieza la función.
    Post==> Crea un objeto de clase escalonada vacia.
 
 void add_funcion(funcion & f)
    Precondición=> Recibe una función, o segmento para ser insertado en la grafica.
    Postcondicion=> Inserta el segmento de funcion.
 
 */

class escalonada{
private:
    
    ListaEnla<funcion> l;
    int x_inicial;
    
public:
    
    int posicion_inicial(){return x_inicial;}
    escalonada(int x1):x_inicial(x1){}
    void add_funcion(funcion& f);
    void erase_funcion(int pos_x);
    int valor_punto(int x, int y);
    int minimo(){
        funcion t;
        auto p = l.primera();
        t.x = l.elemento(p).x;
        
        for (; p != l.fin(); p = l.siguiente(p)) {
            if (t.x > l.elemento(p).y) {
                t.x = l.elemento(p).y;
            }
        }
        return t.x;
    }
    
    int maximo(){
        funcion t;
        auto p = l.primera();
        t.x = l.elemento(p).x;
        
        for (; p != l.fin(); p = l.siguiente(p)) {
            if (t.x < l.elemento(p).y) {
                t.x = l.elemento(p).y;
            }
        }
        return t.x;
    }
    
    void desplazar(int w, int z, funcion & f);
    
};

/*
 *-
 */
void escalonada::add_funcion(funcion & f){
    
    //Caso 1 no hay elementos en la lista
    auto p = l.primera();
    
    for (; p != l.fin() && l.elemento(p) < f; p=l.siguiente(p));
    
    //Caso 1
    if (p == l.fin()) {
        l.insertar(f, p);
    }
    else{//La lista no esta vacia
        
        //Insertamos donde toca
        l.elemento(p).x = f.x;
        l.insertar(f, p);
        
    }
    
}

void escalonada::erase_funcion(int pos_x){
    
    //Buscamos que exista
    auto p = l.buscar(pos_x);
    
    if(p == l.anterior(l.fin())){
        l.eliminar(p);
    }
    //Si no es el final, significa que existe una funcion en la posicion x
    else if (p != l.fin()) {
        
        //Caso general (entre 2 funciones)
        auto p_sig = l.siguiente(p);
        
        l.elemento(p_sig).x = pos_x;
        l.eliminar(p);
        
    }
    
    // 1 2 3 4 5
    // 1 <-> 2 <-> _
    
}

int escalonada::valor_punto(int x, int y){
    
    auto p = l.primera();
    int valor = 0;
    funcion ft ;
    ft.x = x;
    
    for(; p != l.fin() && l.elemento(p) < ft; p = l.siguiente(p));
    
    if (p == l.fin()) {
        return valor; // no hay valor asignado en ese punto
    }
    
    if (l.elemento(p).y == y) {
        valor = y;
    }
    
    return valor;
}


void escalonada::desplazar(int w, int z, funcion& f){
    
    auto p = l.primera();
    for (; p != l.fin() && l.elemento(p).x != f.x; p = l.siguiente(p));
    
    if (w == 0) {
        
        if (p != l.fin()){
            
            l.elemento(p).y += z;
            
        }
    }
    else{
        while (p != l.fin()) {
            l.elemento(p).x += w;
            l.elemento(p).y += z;
            p = l.siguiente(p);
        }
    }
    
}

#endif /* sept21_h */
