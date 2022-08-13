#include <iostream>
#include <string>
#include "tads/ListaEnla.h"

using namespace std;//Avoid using std:: ....

struct Texto {
    ListaEnla<ListaEnla<string>> Lineas;
    Texto(ListaEnla<ListaEnla<string>>& L):Lineas(L){}
};

void tratar_texto(Texto& T){

    auto it_lineas = T.Lineas.primera();

    while(it_lineas != T.Lineas.fin()){

        auto iterador_linea_act = T.Lineas.elemento(it_lineas).primera();
        
        //Comprobamos que no existea #
        bool existe_almohadilla = false;

        while(iterador_linea_act != T.Lineas.elemento(it_lineas).fin() && !existe_almohadilla){
            
            if (T.Lineas.elemento(it_lineas).elemento(iterador_linea_act).find('#') != string::npos)
            {
                existe_almohadilla = true;
            }
            
            iterador_linea_act = T.Lineas.elemento(it_lineas).siguiente(iterador_linea_act);
        }
        
        if(existe_almohadilla){ 
            T.Lineas.eliminar(it_lineas);//Si hay almohadilla eliminamos la linea
        }
        //No existe la almohadilla
        else{
            cout<<"No hay almohadilla"<<endl;
            //Tratamos las @
            iterador_linea_act = T.Lineas.elemento(it_lineas).primera();//Iteramos de nuevo las palabras en la linea
            
            while(iterador_linea_act != T.Lineas.elemento(it_lineas).fin() && !existe_almohadilla){
            
            size_t posicion_arroba = T.Lineas.elemento(it_lineas).elemento(iterador_linea_act).find('@');
            if ( posicion_arroba != string::npos)
            {

                //Existe un @ en esa palabra, tratamos el primero
                string t;
                for(int i = 0; 
                    i < T.Lineas.elemento(it_lineas).elemento(iterador_linea_act).size(); 
                    i++
                ){
                    //Metemos en t todos los elementos que no sean iguales a donde esta el @ y su anterior
                    if(posicion_arroba != 0){

                        if(i != posicion_arroba && i != posicion_arroba-1){
                            t+=T.Lineas.elemento(it_lineas).elemento(iterador_linea_act)[i];
                        }

                    }
                    else{
                        //Si es 0 eliminamos simplemente el primer @
                        if(i != posicion_arroba){
                            t+=T.Lineas.elemento(it_lineas).elemento(iterador_linea_act)[i];
                        }
                    }

                }
                //Tras tratar la palabra la actualizamos dentro de la lista
                T.Lineas.elemento(it_lineas).elemento(iterador_linea_act) = t;

            }
            
            iterador_linea_act = T.Lineas.elemento(it_lineas).siguiente(iterador_linea_act);
        }

        }

        //Puede darse el caso de eliminar la unica linea con las almohadillas
        if(it_lineas != T.Lineas.fin()){
            it_lineas = T.Lineas.siguiente(it_lineas);
        }
        
    }

}

void imprimir_texto(const Texto& T){
    for(auto i = T.Lineas.primera(); i!= T.Lineas.fin(); i = T.Lineas.siguiente(i)){
        for(
            auto j = T.Lineas.elemento(i).primera();
            j != T.Lineas.elemento(i).fin();
            j = T.Lineas.elemento(i).siguiente(j)
        )
        {
            cout<< T.Lineas.elemento(i).elemento(j)<< " ";
        }
        cout<<endl;
    }
}

int main(){
    
    string l1 = "ejem@plo@";
    string l2 = "adadad";

    string l3 = "ejem@plo@";
    string l4 = "adadad#";

    ListaEnla<string> lt,lt2 ;
    lt.insertar(l1, lt.fin());
    lt.insertar(l2, lt.fin());
    
    lt2.insertar(l3,lt2.fin());
    lt2.insertar(l4,lt2.fin());


    ListaEnla<ListaEnla<string>> l;
    l.insertar(lt, l.fin());
    l.insertar(lt2,l.fin());
    
    Texto T(l);
    tratar_texto(T);
    imprimir_texto(T);
    

return 0;
}
