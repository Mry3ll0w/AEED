#include <iostream>
#include <string>
#include <cassert>
#include "tads/ListaEnla.h"

using namespace std;//Avoid using std:: ....

struct Palabra{
    
    ListaEnla<string> trads_esp;
    
    string P_ing;
    
    Palabra(const string p=""):P_ing(p){}
    
    bool operator == (const Palabra& other ){
        return P_ing == other.P_ing;
    }

};

class Diccionario{

    ListaEnla<Palabra> Palabras;
public:

    void insertar_traduccion(const string& ping, const string& trad){
        
        auto pos = Palabras.buscar(Palabra(ping));
        
        //Existe esa traduccion
        if(pos != Palabras.fin()){
            
            Palabras.elemento(pos).trads_esp.insertar(trad, Palabras.elemento(pos).trads_esp.fin());

        }
        else{//No existe esa traduccion
            Palabra t(ping);
            t.trads_esp.insertar(trad, t.trads_esp.fin());
            Palabras.insertar(t, Palabras.fin());
        }

    }

    void eliminar_trad_esp(const string& ping, const string& pesp){
        
        auto pos = Palabras.buscar(Palabra(ping));

        assert(pos != Palabras.fin());
        
        auto elimina_trads = Palabras.elemento(pos).trads_esp.buscar(pesp);
        
        if (elimina_trads != Palabras.elemento(pos).trads_esp.fin())
            Palabras.elemento(pos).trads_esp.eliminar(elimina_trads);
    }

    void traducciones_esp(const string& s){
        
        auto pos = Palabras.buscar(s);

        assert(pos != Palabras.fin());
        
        for(auto p = Palabras.elemento(pos).trads_esp.primera(); 
            p != Palabras.elemento(pos).trads_esp.fin(); p = Palabras.elemento(pos).trads_esp.siguiente(p)
        ){
            cout << Palabras.elemento(pos).trads_esp.elemento(p) << ", ";
        }
        cout<<endl;
        
    }

    //Destructor predeterminado

};

int main(){
    
return 0;
}