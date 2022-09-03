#include <iostream>
#include <string>
#include "ListaEnla.h"
using namespace std;//Avoid using std:: ....

struct Sala{
    
    int ID;
    
    ListaEnla<string> espectaculos;
    
    Sala(const int& i = 0):ID(i){}
    
    bool operator == (const Sala& other){
        return ID == other.ID;
    }

    bool operator < (const Sala& other){
        return ID < other.ID;
    }

};

class Carteleras{
    ListaEnla<Sala> Salas;
public:
    
    Carteleras()=default;
    ~Carteleras()=default;
    
    void add_cartelera(const Sala& S){
        
        auto p = Salas.buscar(S);
        if(p == Salas.fin()){
            
            p = Salas.primera();
            //Insercion ordenada
            while(p != Salas.fin() && Salas.elemento(p) < S){

                p = Salas.siguiente(p);
            }

            Salas.insertar(S, Salas.fin());

        }

        
    }

    void add_espectaculo(const Sala & S, const string & e){
        auto p = Salas.buscar(S);
        //Existe esa sala, por tanto comprobamos si el espectaculo esta en la misma
        if(p != Salas.fin()){
            auto p_sala = Salas.elemento(p).espectaculos.buscar(e);
            //El espectacul no esta ya en esa sala
            if(p_sala == Salas.elemento(p).espectaculos.fin()){
                Salas.elemento(p).espectaculos.insertar(e, Salas.elemento(p).espectaculos.fin());
            }
        }
    }

    void erase_sala(const Sala& S){
        auto p = Salas.buscar(S);
        // Existe esa sala, por tanto comprobamos si el espectaculo esta en la misma
        if (p != Salas.fin())
        {
            Salas.eliminar(p);
        }
    }

    void erase_espectaculo(const Sala& S, const string & e){
        auto p = Salas.buscar(S);
        // Existe esa sala, por tanto comprobamos si el espectaculo esta en la misma
        if (p != Salas.fin())
        {
            //Comprobamo si existe el ese espectaculo
            auto p_es = Salas.elemento(p).espectaculos.buscar(e);
            if(p_es != Salas.elemento(p).espectaculos.fin()){
                Salas.elemento(p).espectaculos.eliminar(p_es);
            }

        }
    }

    void salas_del_sistema(){
        for(auto p = Salas.primera(); p != Salas.fin(); p = Salas.siguiente(p)){
            cout<< Salas.elemento(p).ID<< ", ";
        }
        cout << endl;
    }

    void salas_espectaculos(){
        ListaEnla<string> mostrados;

        for (auto i = Salas.primera(); i != Salas.fin(); i = Salas.siguiente(i))
        {
            for (auto j = Salas.elemento(i).espectaculos.primera(); 
                j != Salas.elemento(i).espectaculos.fin(); 
                j = Salas.elemento(i).espectaculos.siguiente(j)
            )
            {
                string actual = Salas.elemento(i).espectaculos.elemento(j);
                auto p = mostrados.buscar(actual);
                if( p == mostrados.fin()){
                    //No se ha mostrado previamente
                    cout << actual << ", ";
                    mostrados.insertar(actual, mostrados.fin());
                }
                
            }
            
        }
        cout << endl;
    }

};

int main(){
    
return 0;
}