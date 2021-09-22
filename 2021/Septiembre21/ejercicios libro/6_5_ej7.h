#ifndef SEPTIEMBRE21_6_5_EJ7_H
#define SEPTIEMBRE21_6_5_EJ7_H
#include <iostream>
#include <string>
#include "tads p/Cola_Din.h"
#include "tads p/ListaEnla.h"
/*Ej 7 y 8
 * Salen a la venta un numero limitado de entradas para un campeonato
 * de baloncesto, y las peticiones de entradas son atendidas en orden
 * de llegada.
 * Escriba un programa que pueda usar el vendedor para almacenar:
 * - Nombre
 * - direccion
 * - Numero de entradas (han de ser >=4 por persona)
 */
struct persona{
    std::string name;
    std::string surname;
    size_t tickets; //No puede superar a 4
};
class taquilla{

    ListaEnla<persona>ventas;
    ColaDin<persona> cola;
public:
    taquilla()=default;
    void processRow();
    void showSales();
    void addRow(const persona& p){
        cola.push(p);
    }
    ~taquilla()= default;
};

void taquilla::showSales() {
    std::cout<<"Showing the sales of the day"<<std::endl;
    for (ListaEnla<persona>::posicion i = ventas.primera(); i !=ventas.fin(); i = ventas.siguiente(i)) {
        std::cout<<ventas.elemento(i).name<<", "<<ventas.elemento(i).surname<<"bought: "<<ventas.elemento(i).tickets<<std::endl;
    }
}

void taquilla::processRow() {
    while (!cola.vacia()){
        if (cola.frente().tickets < 5){
            ventas.insertar(cola.frente(),ventas.fin());
        }
        cola.pop();
    }
}

#endif //SEPTIEMBRE21_6_5_EJ7_H
