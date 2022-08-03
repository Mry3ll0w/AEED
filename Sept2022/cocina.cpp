#include <iostream>
#include "tads/ListaEnla.h"
#include <cassert>
using namespace std;//Avoid using std:: ....

//Suponemos que los datos que se reciben del mueble son siempre correctos
//Es decir se recibe un numero > 0 en anchura y posicion >= 0
struct mueble {
    double anchura, posicion;
    mueble (const double& a = 0, const double& p=0):anchura(a), posicion(p) {}
    bool operator ==(const mueble& other){
        return (anchura == other.anchura && posicion == other.posicion);
    }
    bool operator < (const mueble& other){
        return (anchura < other.anchura);
    }
};

class Cocina{
    ListaEnla<mueble> l;
    double espacio;
    double ocupados;
    int n_muebles;
public:
    Cocina(const double& d):espacio(d), ocupados(0), n_muebles(0){}

    //Recibe si cabe o no el mueble en la cocina y ademas devuelve por salida
    //Un booleano que indica si el mueble entra en la cocina, y ademas la posicion donde el mueble va
    pair<bool,ListaEnla<mueble>::posicion> cabe(const mueble& m);
    
    const ListaEnla<mueble> & get_cocina()const {return l;}

    void insertar_mueble(const mueble& m);

    const mueble& devolver_mueble_i(const int& i);

    void eliminar_mueble_i(const int& i);

    void pegar_muebles_i(const int& i);
    
};
ostream& operator<<(ostream& os, const Cocina& c);

int main(){
    Cocina c(20);
    mueble m1(2, 0), m2(7,4), m3(7,1);

    c.insertar_mueble(m1);
    c.insertar_mueble(m2);
    cout<< c<<endl;
    c.insertar_mueble(m3);
    cout<< c;

return 0;
}

//Tiene que caber el mueble en el espacio disponible de la cocina
void Cocina::insertar_mueble(const mueble& m){
    
    assert( (ocupados + m.anchura) <= espacio);

    auto p = cabe(m);

    if ( p.first )//El mueble cabe
    {
        l.insertar(m, p.second);
        ocupados-= m.anchura;
        n_muebles++;
    }
    else{
        std::cout<< 
            "Aunque existe un espacio total disponible, no hay hueco para la anchura del mueble"
        <<endl;
    }
    

}

pair<bool , ListaEnla<mueble>::posicion> Cocina::cabe(const mueble & m){

    if (l.primera() == l.fin())//La Cocina esta vacia
    {
        return pair(true, l.primera());
    }
    else{ // La lista no esta vacia

        //Vemos donde le toca insertarse, segun la poscion ordenamos
        auto p = l.primera();
        for(; p!= l.fin() && l.elemento(p) < m ; p= l.siguiente(p));

        //caso 1 : No tiene muebles a la izquierda
        if(p == l.primera()){
            auto m_der = l.elemento(l.siguiente(p));
            if( (m.posicion + m.anchura) <= m_der.posicion){
                return pair(true, p);
            }
            else
                return pair(false, l.fin());
        }
        //Caso 2 : No hay muebles a la derecha
        else if(p == l.fin()){
            auto mi = l.elemento(l.anterior(p));//Cogemos el mueble inmediatamanete anterior
            if( (mi.posicion + mi.anchura <= m.posicion)){
                return pair(true, p);
            }
            else
                return pair(false, l.fin());
        }
        else{//Caso 3 : entre 2 muebles;
            //Para evitar hacer un if gigante usare la variable x
            auto ma = l.elemento(l.anterior(p));
            auto mb = l.elemento(p);
            cout << mb.posicion<<endl;
            double x = (mb.posicion + mb.anchura) - (ma.posicion + ma.anchura);
            
            if ( 
                x >= (m.anchura + m.posicion)
                &&
                //Comprobamos que la posicion sea valida 
                (
                    (m.posicion + m.anchura) >= (ma.anchura + ma.posicion)
                    &&
                    (m.posicion + m.anchura) <= mb.posicion
                )
            ){
                return pair(true, p);
            }
            else
                return pair(false, l.fin());
        }
        
    }
    

}

//Sustituye al metodo imprimir cocina
ostream& operator<<(ostream& os, const Cocina& c){
    auto l = c.get_cocina();

    for(auto i = l.primera(); i != l.fin(); i= l.siguiente(i)){
        os<< l.elemento(i).posicion << " ";
    }
    os<<endl;
    return os;
}

const mueble& Cocina::devolver_mueble_i(const int& i){
    assert(i <= n_muebles && "No existe esa cantidad de muebles en la cocina");

    auto pos = l.primera();
    int it = 0;

    while(it < i){
        it ++;
        pos = l.siguiente(pos);
    }

    return l.elemento(pos);

}

void Cocina::eliminar_mueble_i(const int & i){
    assert(i <= n_muebles && "No existe esa cantidad de muebles en la cocina");

    auto pos = l.primera();
    int it = 0;

    while(it < i){
        it ++;
        pos = l.siguiente(pos);
    }

    ocupados -= l.elemento(pos).anchura;
    n_muebles --;
    l.eliminar(pos);
    
}

void Cocina::pegar_muebles_i(const int& i){
    
    assert(i <= n_muebles && "No existe esa cantidad de muebles en la cocina");

    
    
    if(i == 1){
        l.elemento(l.primera()).posicion = 0;
    }
    else if(i == n_muebles){
        auto p_ult_mueble = l.anterior(l.fin());
        
        l.elemento(p_ult_mueble). posicion = l.elemento(l.anterior(p_ult_mueble)). anchura + l.elemento(l.anterior(p_ult_mueble)). posicion;

    }
    else{
        //Nos movemos hasta la posicion que se nos ha pedido
        auto pos = l.primera();
        int it = 1;//asumimos que la posicion de entrada que se recibe es <=1 

        while(it < i){
            it ++;
            pos = l.siguiente(pos);
        }

        for(; pos != l.fin(); pos = l.siguiente(pos)){
            auto m_ant = l.elemento(l.anterior(pos));
            l.elemento(pos). posicion = m_ant.posicion + m_ant.anchura;
        }
    }


}