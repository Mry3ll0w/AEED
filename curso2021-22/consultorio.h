#ifndef CURSO2021_22_CONSULTORIO_H
#define CURSO2021_22_CONSULTORIO_H

#include <iostream>
#include <string>
#include <cassert>
#include "tads_profesorado/ListaEnla.h"
#include "tads_profesorado/Cola_Din.h"

struct medico{
    std::string id_medico;
    ColaDin<std::string>pacientes;
    medico(const std::string& m = " ", const std::string& p = " "):id_medico(m){
        if(p != " "){
            pacientes.push(p);
        }
    }
    bool operator == (const medico& m) const{return id_medico == m.id_medico;}
};

class consultorio{

private:
    ListaEnla<medico>medicos;
public:
    consultorio()=default;
    ~consultorio()=default;
    void dar_alta_medico(const medico& m);
    void dar_baja_medico(const medico& m);
    void add_lista_espera(const std::string& med,const std::string& paciente );
    void atender_paciente(const std::string& med);
    bool medico_libre(const std::string& med);
    void show_consultorio();
};

void consultorio::dar_alta_medico(const medico &m) {
    auto pos = medicos.buscar(medico(m));
    assert(pos == medicos.fin());//Comprobamos que ese medico no este ya en la lista

    medicos.insertar(medico(m),pos);

}

void consultorio::dar_baja_medico(const medico &m) {
    auto pos = medicos.buscar(medico(m));
    assert(pos != medicos.fin());//Comprobamos que ese medico este ya en la lista
    medicos.eliminar(pos);//Si no es igual que medicos.fin(), entonces existe, por tanto lo eliminamos
}

void consultorio::add_lista_espera(const string &med, const string &paciente) {

    auto pos = medicos.buscar(medico(med));
    assert(pos != medicos.fin());
    medicos.elemento(pos).pacientes.push(paciente);//Simplemente metemos el paciente

}

void consultorio::atender_paciente(const string &med) {
    auto pos = medicos.buscar(medico(med));
    assert(pos != medicos.fin());
    medicos.elemento(pos).pacientes.pop();
}

bool consultorio::medico_libre(const string &med) {
    auto pos = medicos.buscar(medico(med));
    assert(pos != medicos.fin());
    return medicos.elemento(pos).pacientes.vacia();
}

void consultorio::show_consultorio() {

    auto pos = medicos.primera();
    while (pos != medicos.fin()){

        auto cola = medicos.elemento(pos).pacientes;
        std::cout<<"Consulta del medico: "<<medicos.elemento(pos).id_medico<<std::endl;
        while(!cola.vacia()){
            std::cout<< cola.frente() << ", ";
            cola.pop();
        }
        std::cout<<std::endl;
        pos = medicos.siguiente(pos);
    }

}


#endif //CURSO2021_22_CONSULTORIO_H
