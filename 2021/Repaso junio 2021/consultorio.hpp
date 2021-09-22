#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP
#include "tads implementados profesorado/Cola_Din.h"
#include "tads implementados profesorado/ListaEnla.h"
#include <string>
#include <iostream>
typedef struct{
    std::string DNI;
    std::string nombre;
} paciente;
class medic{
    private:
        std::string nombre;
        ColaDin<paciente> pacientes;
    public:
        medic(std::string n):nombre(n){}
        ~medic();
        void add_paciente(paciente& p);
        bool estado_pacientes(){return pacientes.vacia();}
        paciente frente()const{return pacientes.frente(); }
        void sacar_paciente(){pacientes.pop();}
};
class consultorio
{
private:
    ListaEnla<medic>medicos;
public:
    consultorio();
    void dar_alta_medico(medic& m);
    void dar_baja_medico(medic& m);
    paciente siguiente_paciente(medic& m);
    void atender_paciente(medic& m);
    bool pacientes_espera(medic& m);
    ~consultorio();
};

void medic::add_paciente(paciente& p){
    pacientes.push(p);
}

void consultorio::dar_alta_medico(medic& m){
    if (medicos.buscar(m)!=medicos.fin())//Si es igual al fin el medico ya esta en la lista por tanto no se hace nada
    {
        medicos.insertar(m,medicos.fin());
    }
}

void consultorio::dar_baja_medico(medic& m){
    medicos.eliminar(medicos.buscar(m));
}

void consultorio::atender_paciente(medic& m){
    medicos.elemento(medicos.buscar(m)).sacar_paciente();
}

paciente consultorio::siguiente_paciente(medic& m){
    return medicos.elemento(medicos.buscar(m)).frente();
}

bool consultorio::pacientes_espera(medic& m){
    return medicos.elemento(medicos.buscar(m)).estado_pacientes();
}



#endif