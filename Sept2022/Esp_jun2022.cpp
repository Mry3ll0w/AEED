#include <iostream>
#include <string>
#include "tads/Cola_Din.h"
#include "tads/ListaEnla.h"
#include <cassert>

using namespace std;

typedef std::string codigo;
struct Usuario{
    ColaDin<codigo> Normal,Prioridad;
    string ID;
    bool operator==(const Usuario& other) const { return (ID == other.ID);}
    bool operator!=(const Usuario& other) const { return !(*this == other); }
};

class Impresora{
    ColaDin<Usuario> c;
    int max_usuarios, ocupados;//Se debe hacer usando cola vect pero no tengo la implementacion
public:
    Impresora(int n):max_usuarios(n),ocupados(0) { }
    void insertar_trabajo(Usuario& u, const std::string & t,bool urgencia);
    void eliminar_trabajo_a_imprimir();
    void cancelar_trabajos_usuario(const Usuario& u);
};


int main(int argc, char **argv){
    return 0;
}

void Impresora::insertar_trabajo(Usuario& u,const std::string & i, bool urgencia){
    

    //Comprobamos que el usuario no exista
    ColaDin<Usuario> t = c;

    while ( !t.vacia() && t.frente() != u)
        t.pop();
    
    if (t.vacia()){//Si t esta vacia el usuario no existe

        if(ocupados < max_usuarios){
            ocupados ++;
            if(urgencia){
                u.Prioridad.push(i);
            }
            else{
                u.Normal.push(i);
            }
            c.push(u);
        }
        else{
            cout<<"No hay espacio para el usuario en la cola de impresion";
        }

    }
    else {//El usuario ya esta en la cola de impresion

        ColaDin<Usuario> parser;

        while(!c.vacia() && c.frente() == u)
            parser.push(c.frente());c.pop();
        
        u = c.frente();//Metemos el elemento usuario, para obtener las colas

        if(urgencia){
                u.Prioridad.push(i);
        }
        else{
            u.Normal.push(i);
        }
        c.pop();//Sacamos el usuario buscado
        parser.push(u);
        //Metemos el resto de los elementos en la cola original
        while (!c.vacia()){
            parser.push(c.frente());
            c.pop();
        }

        c = parser;//Metemos la pila lista con los elementos en orden y actualizado
    }
    

}

void Impresora::eliminar_trabajo_a_imprimir(){
    
    assert(!c.vacia()); //No puede estar vacia
    auto u = c.frente();//Sacamos al primero de la cola
    c.pop();
    ocupados --;

    //Imprimimos según prioridad
    if(!u.Prioridad.vacia()){
        u.Prioridad.pop();
    }
    else{
        u.Normal.pop();
    }

    //Tras imprimir el trabajo que toca, si no esta vacias las listas volvemos el user al final
    if(!u.Prioridad.vacia() || !u.Normal.vacia()){
        c.push(u);
    }
}

void Impresora::cancelar_trabajos_usuario(const Usuario& u){
    ColaDin<Usuario> parser;

        while(!c.vacia() && c.frente() == u)
            parser.push(c.frente());c.pop();
    
        
        c.pop();//Sacamos el usuario buscado
        //Metemos el resto de los elementos en la cola original
        while (!c.vacia()){
            parser.push(c.frente());
            c.pop();
        }

        c = parser;//Metemos la pila lista con los elementos en orden y actualizado
}    

