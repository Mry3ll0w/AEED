#include <iostream>
#include "tads/Cola_Din.h"
#include "tads/ListaEnla.h"
#include <string>
#include <cassert>

using namespace std;//Avoid using std:: ....

struct Medico{
    string nombre;
    ColaDin<string>C_Pacientes;
    Medico(const string& n):nombre(n){}
    bool operator = (const Medico& other){
        return nombre == other.nombre;
    }
};

class Consultorio{
    ListaEnla<Medico>Lista_medicos;
public:
    
    Consultorio()=default;
    
    ~Consultorio()=default;
    /**
     * @brief Inserta el medico dado en la lista de medicos de la consulta, en caso de no existir ya en la lista
     * 
     * @exception Si el medico se encuentra en la lista se lanza una excepcion
     * 
     * @param const Medico& m
     * 
     * @return void (none)
     */
    void dar_alta_medico(const Medico& m ){
        auto p = Lista_medicos.buscar(m);
        assert(p == Lista_medicos.fin() && "El medico ya esta en la lista");
        Lista_medicos.insertar(m,p);//Si el medico no existre devuelve fin, donde se insertta el nuevo elemento
    }

    /**
     * @brief Da de baja a un medico dado, en caso de no existir se lanza una excepcion.
     * @param const Medico& m
     * @exception En caso de no existir el medico
     * @return none
     */
    void elimina_medico(const Medico& m){
        auto p = Lista_medicos.buscar(m);
        assert(p != Lista_medicos.fin() && "El medico no esta en la lista");
        Lista_medicos.eliminar(p);
    }

    /**
     * @param Agregar a un paciente a la cola de pacientes del medico dado
     * @return none
     * @param const Medico& m, const string& p
     * @exception En caso de no existir el medico en la lista.
     */
    void agregar_paciente(const Medico& m, const string& paciente){

        auto p = Lista_medicos.buscar(m);
        assert(p != Lista_medicos.fin());
        Lista_medicos.elemento(p).C_Pacientes.push(paciente);
        
    }

    /**
     * @brief Atiende al paciente que le toca en la cola del medico dado.
     * @return none
     * @exception En caso de no existir el medico en la lista.
     * @param const Medico& m
     */
    void atender_paciente(const Medico& m){
        
        auto p = Lista_medicos.buscar(m);
        
        assert(p != Lista_medicos.fin());

        Lista_medicos.elemento(p).C_Pacientes.pop();
    }

    /**
     * @brief Muestra al paciente que le toca ser atendido en el medico m dado.
     * @return const string&
     * @exception En caso de no existir el medico dado.
     * @param const Medico& m
     */
    const string& siguiente(const Medico& m){
        auto p = Lista_medicos.buscar(m);

        assert(p != Lista_medicos.fin());

        Lista_medicos.elemento(p).C_Pacientes.frente();
    }

    /**
     * @brief Muestra si el medico m tiene algun paciente en cola.
     * @return const bool
     * @param const Medico& m
     * @exception En caso de no existir un medico
     */
    bool cola_vacia(const Medico& m){
        auto p = Lista_medicos.buscar(m);

        assert(p != Lista_medicos.fin());

        Lista_medicos.elemento(p).C_Pacientes.vacia();
    }

};

int main(){
    
return 0;
}