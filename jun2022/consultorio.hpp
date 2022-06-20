#include <iostream>
#include <string>
#include "tads/ListaEnla.h"
#include "tads/Cola_Din.h"
#include <cassert>

struct medico{
    std::string c;
    ColaDin<std::string>espera;
    medico(const std::string c_ = ""):c(c_){}
    bool operator == (medico m){
        return c == m.c;
    }
    bool operator == (std::string s){
        return c == s;
    }
};

class consultorio{
private:

    ListaEnla<medico> medicos;
public:

    consultorio()=default;
    ~consultorio()=default;
    void dar_alta_medico(std::string m);
    void dar_baja_medico(std::string m);
    void add_lista_espera(std::string m, std::string p);
    void atender_paciente(std::string m);
    bool tiene_pacientes(std::string m );

};

bool consultorio::tiene_pacientes(std::string m){
    
    assert(m != "");

    auto pos = medicos.buscar(medico(m));

    if (pos != medicos.fin())
    {
        return medicos.elemento(pos).espera.vacia();
    }
    
    return false;
}

void consultorio::add_lista_espera(std::string m ,std::string p){

    assert(m != "");
    auto pos = medicos.buscar(medico(m));
    if (pos != medicos.fin())
    {
        medicos.elemento(pos).espera.push(p);
    }

}

void consultorio::dar_baja_medico(std::string m){

    assert(m != "");

    auto p = medicos.buscar(medico(m));
    if (p != medicos.fin())
    {
        medicos.eliminar(p);
    }
    

}

//Atiende al paciente que le toca al medico m
void consultorio::atender_paciente(std::string m){
    assert(m != "");

    auto p = medicos.buscar(medico(m));
    if (p != medicos.fin())
    {
        medicos.elemento(p).espera.pop();
    }

}

void consultorio::dar_alta_medico(std::string m ){

    auto pos = medicos.buscar(medico(m));
    assert(pos == medicos.fin() && "Este medico ya esta registrado");
    
    medicos.insertar(medico(m), pos);
    

}