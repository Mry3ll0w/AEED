//
// Created by anton on 05/01/2021, Examen del 4/2/16
//

#ifndef EXAMENES_HOSPITAL_H
#define EXAMENES_HOSPITAL_H
#include "pila_enla.h"
#include "ListaEnla.h"
 typedef struct {
    string NIF;
}Paciente;

typedef struct {
    PilaEnla<Paciente> espera_pacientes;
    string NIF;
}Medico;


class Hospital{
    public:
        Hospital();        //Constructor de la clase
        ~Hospital();       //Destructor de la clase
        void dar_alta_medico(Medico); //errors
        void dar_baja_medico(string);
        void add_lista_espera(Paciente,string);
        void assist_patient(const string& );
        string next_to_be_assisted(string);
        int free_med(string);
    private:
        ListaEnla<Medico> medicos;
        ListaEnla <Medico> :: posicion cursor = medicos.primera();

};

Hospital::Hospital() {
    // Crear una lista de madicos vacia, se realiza en el ambito privado
}

Hospital::~Hospital() {
    medicos.~ListaEnla();// Se llama al destructor para que elimine la instancia de lista de medicos

}

void Hospital::dar_alta_medico(Medico med) {
    medicos.insertar(med, medicos.fin());
}

void Hospital::dar_baja_medico(string oc_med) {
    ListaEnla <Medico> aux;
    ListaEnla <Medico>:: posicion pos = medicos.primera() ;

    while(pos!=medicos.fin()){
        cout << medicos.elemento(pos).NIF <<endl;
        if(medicos.elemento(pos).NIF != oc_med){
            aux.insertar(medicos.elemento(pos),aux.fin()); // si encuentra la ocurrencia pasa a la siguiente
        }
        pos= medicos.siguiente(pos);
    }
    medicos = aux; // copia la lista con el elemento borrado, ya que no podemos usar la funcion buscar
}

string Hospital::next_to_be_assisted(string nif_med) {
    ListaEnla <Medico>::posicion pos = medicos.primera(); // iterador para recorrer la lista
    while (pos != medicos.fin()){
        if (medicos.elemento(pos).NIF == nif_med){
            return medicos.elemento(pos).espera_pacientes.tope().NIF;
        }
        pos = medicos.siguiente(pos);
    }
    return "-1";
}

void Hospital::add_lista_espera(Paciente p, string med) {
    ListaEnla<Medico>::posicion pos = medicos.primera();
    while (pos != medicos.fin()){
        if (medicos.elemento(pos).NIF == med){
            medicos.elemento(pos).espera_pacientes.push(p);
        }
        pos = medicos.siguiente(pos);
    }
}

void Hospital::assist_patient(const string& med) {
    ListaEnla<Medico>::posicion pos = medicos.primera();
    while (pos != medicos.fin()){
        if (medicos.elemento(pos).NIF == med){
            medicos.elemento(pos).espera_pacientes.pop();
        }
        pos = medicos.siguiente(pos);
    }
}

int Hospital::free_med(string med) {
    ListaEnla<Medico>::posicion pos = medicos.primera();
    while (pos != medicos.fin()){
        if (medicos.elemento(pos).NIF == med){
           return medicos.elemento(pos).espera_pacientes.vacia();
        }
        pos = medicos.siguiente(pos);
    }
}

#endif //EXAMENES_HOSPITAL_H
