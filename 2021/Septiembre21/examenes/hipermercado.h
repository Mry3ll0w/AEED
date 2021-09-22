#ifndef SEPTIEMBRE21_HIPERMERCADO_H
#define SEPTIEMBRE21_HIPERMERCADO_H
#include<iostream>
#include <string>
struct caja{
    size_t id;
    bool activa;
    std::string id_caj;
    double facturacion;
    caja():activa(false),facturacion(0.00){}
};
class hipermercado{
    caja linea_caja[50];
    double total_dia;
    size_t check_activa();
public:
    hipermercado(){
        for (int i = 0; i <50 ; ++i) {
            linea_caja[i].id = i+1; //simplemente metemos el id para que tenga cierto sentido
        }
    }
    ~hipermercado()=default;
    //assert en todo lo que tenga id debe ser >0 y <50
    void abrir_caja(size_t id,std::string id_cajero);
    double cerrar_caja(size_t id);
    void cobrar_caja(size_t id,double cobro);
    void sustituye_cajero(size_t id,std::string new_id);//debe estar activa
    double cambiar_turno();
    double cerrar_hipermercado();


};

void hipermercado::abrir_caja(size_t id, std::string id_cajero) {
    assert(id>0 && id<50);
    if (linea_caja[id-1].activa)
        linea_caja[id-1].id_caj=id_cajero;
    else{
        linea_caja[id-1].id_caj=id_cajero;
        linea_caja[id-1].activa=true;
    }
}

double hipermercado::cerrar_caja(size_t id) {
    //check <10
    assert(id>0 && id<50 && check_activa()>10);
    if (!linea_caja[id-1].activa)
        linea_caja[id-1].id_caj=" ";//vaciamos el id del cajero
    else{
        linea_caja[id-1].id_caj=" ";
        linea_caja[id-1].activa=false;
    }
    double temp =linea_caja[id-1].facturacion;
    linea_caja[id-1].facturacion = 0;
    return temp;
}

void hipermercado::cobrar_caja(size_t id, double cobro) {
    assert(id>0 && id<50);
    linea_caja[id-1].facturacion+=cobro;
}

void hipermercado::sustituye_cajero(size_t id, std::string new_id) {
    assert(id>0 && id<50 && linea_caja[id-1].activa);
    linea_caja[id-1].id_caj=new_id;
}

double hipermercado::cambiar_turno() {
    double total_t=0;
    for (int i = 0; i < 50; ++i) {
        if (linea_caja[i].activa){
            total_t+= linea_caja[i].facturacion;//corregir el desfase por eso de 1 a 51
            linea_caja[i].facturacion=0;
        }
    }
    //Sumamos al total la recaudacion
    total_dia+=total_t;
    return total_t;
}

double hipermercado::cerrar_hipermercado() {
    for (int i = 0; i < 50 ; ++i) {
        if (linea_caja[i].activa)
            total_dia += cerrar_caja(i);
    }
    return total_dia;
}

size_t hipermercado::check_activa() {
    size_t cont=0;
    for(auto &i :linea_caja ){
        if (i.activa)
            ++cont;
    }
    return cont;
}

#endif //SEPTIEMBRE21_HIPERMERCADO_H
