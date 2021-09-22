#ifndef SEPTIEMBRE21_CONSULTORIO_H
#define SEPTIEMBRE21_CONSULTORIO_H
#include "../tads p/ListaEnla.h"
#include "../tads p/Cola_Din.h"
#include <string>

struct medico{
    explicit medico(size_t id_=1):id(id_){}
    size_t id;
    ColaDin<std::string> pacientes;
};

class consultorio{
    ListaEnla<medico>medicos;
    ListaEnla<medico>::posicion existe(const size_t& id);
    public:
    consultorio()=default;
    ~consultorio()=default;
    void insertar_med(const medico& m);
    void eliminar_med(const size_t& id);
    void add_lista_espera(const size_t& id,std::string & paciente);
    std::string siguiente_paciente(const size_t& id);
    void atender_paciente(const size_t& id);
    bool lista_espera_vacia(const size_t& id);
};

void consultorio::insertar_med(const medico &m) {
    if (medicos.fin()!=existe(m.id)){
        throw std::runtime_error("Este medico esta en la lista");
    }
    medicos.insertar(m,medicos.fin());
}

ListaEnla<medico>::posicion consultorio::existe(const size_t &id) {
    auto it_med= medicos.primera();
    for(it_med= medicos.primera() ; it_med != medicos.fin()||id == medicos.elemento(it_med).id; it_med = medicos.siguiente(it_med)){

    }
    return it_med;
}

void consultorio::eliminar_med(const size_t &id) {
    auto it = existe(id);
    if (medicos.fin()==it){
        throw std::runtime_error("Este no medico esta en la lista");
    }
    medicos.eliminar(it);
}

void consultorio::add_lista_espera(const size_t &id,std::string & paciente) {
    auto it = existe(id);
    if (medicos.fin()==it){
        throw std::runtime_error("Este no medico esta en la lista");
    }
    medicos.elemento(it).pacientes.push(paciente);
}

std::string consultorio::siguiente_paciente(const size_t &id) {
    auto it = existe(id);
    if (medicos.fin()==it){
        throw std::runtime_error("Este no medico esta en la lista");
    }
    return medicos.elemento(it).pacientes.frente();
}

void consultorio::atender_paciente(const size_t &id) {
    auto it = existe(id);
    if (medicos.fin()==it){
        throw std::runtime_error("Este no medico esta en la lista");
    }
    medicos.elemento(it).pacientes.pop();
}

bool consultorio::lista_espera_vacia(const size_t &id) {
    auto it = existe(id);
    if (medicos.fin()==it){
        throw std::runtime_error("Este no medico esta en la lista");
    }
    return medicos.elemento(it).pacientes.vacia();
}

#endif //SEPTIEMBRE21_CONSULTORIO_H
