#include <iostream>
#include "ListaEnla.h"
#include "Cola_Din.h"
#include <string>
using namespace std;//Avoid using std:: ....

/**
 * Gravedad 1 - 5 ==> UCI
 * Gravedad 6 - 9 ==> Planta
 * Gravedad 0 ==> Morgue
 */
struct Paciente{
    
    Paciente(size_t g =0,string i = ""):gravedad(g), id(i){}
    
    size_t gravedad;

    string id;
    
    bool operator == (Paciente & other){
        return id == other.id;
    }

};

class Hospital{

    ListaEnla<Paciente> UCI, Morgue, Planta;
    size_t cap_uci, cap_planta, ocupados_uci, ocupados_planta;



public:
    
    Hospital(const size_t t_uci = 1, const size_t t_planta = 1):cap_uci(t_uci), cap_planta(t_planta),
    ocupados_planta(0), ocupados_uci(0){}
    
    void ingresar_paciente(const size_t& gravedad, const Paciente& paciente){
        //Caso UCI
        if(gravedad >= 1 && gravedad <= 5){

            if(ocupados_uci < cap_uci){//Hay capacidad para insertar
                ocupados_uci ++;
                UCI.insertar(paciente, UCI.fin());
            }
            else{//No cabe en UCI ==> Sacamos de uci y metemos en planta

                //Obtenemos el de menor gravedad
                size_t menor = 99;
                
                Paciente t(99);

                for(auto i = UCI.primera(); i != UCI.fin(); i= UCI.siguiente(i)){
                    
                    if(UCI.elemento(i).gravedad < t.gravedad){
                        t = UCI.elemento(i);
                    }

                }

                //METEMOS EN PLANTA
                if(ocupados_planta < cap_planta){
                    ocupados_planta ++;
                    Planta.insertar(t,Planta.fin());
                    UCI.insertar(paciente,UCI.fin());
                }
                else{//No cabe en planta
                    //Sacamos al menor de la planta
                    Paciente t(99);

                    for (auto i = Planta.primera(); i != Planta.fin(); i = Planta.siguiente(i))
                    {

                        if (Planta.elemento(i).gravedad < t.gravedad)
                        {
                            t = Planta.elemento(i);
                        }

                    }

                    //Sacamos de planta
                    Planta.eliminar(Planta.buscar(t));
                    Planta.insertar(paciente, Planta.fin());


                }

            }

        }//Caso Planta
        else if(gravedad >= 6 && gravedad <=9 ){
            
            if(ocupados_planta < cap_planta ){
                Planta.insertar(paciente, Planta.fin());
                ocupados_planta ++;
            }
            else{
                // Sacamos al menor de la planta
                Paciente t(99);

                for (auto i = Planta.primera(); i != Planta.fin(); i = Planta.siguiente(i))
                {

                    if (Planta.elemento(i).gravedad < t.gravedad)
                    {
                        t = Planta.elemento(i);
                    }
                }

                // Sacamos de planta
                Planta.eliminar(Planta.buscar(t));
                Planta.insertar(paciente, Planta.fin());
            }

        }
        else{
            Morgue.insertar(paciente, Morgue.fin());
        }
    }

    void dar_alta(const Paciente& P){
        auto pos = Planta.buscar(P);
        
        assert(pos != Planta.fin());//Si esta vacia devulve fin en cualquier caso
        cap_planta ++;
        Planta.eliminar(pos);
    }

    const ListaEnla<Paciente> Pacientes_Gravedad(const size_t& G){
        ListaEnla<Paciente> R, L;

        if(G == 0){
            return Morgue;
        }
        else if(G >= 1 && G <= 5){
            L = UCI;
        }
        else if(G >5 && G <= 9){
            L = Planta;
        }

        //Metemos los pacietnes de esa gravedad
        auto p = L.primera();
        while( p != L.fin()){
            
            auto t = (L.elemento(p).gravedad == G) ? L.elemento(p) : Paciente(-1); 
            
            if(t.gravedad != -1){
                cout<< t.gravedad<<endl;
                R.insertar(t, R.fin());
            }
            p = L.siguiente(p);
        }

        return R;

    }


};

int main(){
    
return 0;
}