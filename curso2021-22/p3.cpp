#include "p3.hpp"
//IMPLEMENTACION PROPIA DE IMPRESION (IGNORAR)
std::ostream& operator<<(std::ostream& os,const polinomio& p){
    unsigned grado = 0;
    for(auto i: p.cocientes_getter()){
        os<< i <<"x^"<<grado<<"+";
        ++grado;
    }
    return os;
}

polinomio::polinomio(unsigned gradoMax)
    : cocientes(std::vector<double>(gradoMax))
{
    //Reservamos el espacio al vector con el grado maximo del vector
}

unsigned polinomio::grado()const {
    return cocientes.size();
}

double polinomio::coeficiente(const unsigned& n) {
    
    assert(n >= 0 && n < cocientes.size());//n tiene que ser mayor que 0 y ser menor que el grado maximo
    
    return cocientes[n];
}

void polinomio::coeficiente(unsigned n, double c) {
    assert(n >= 0 && n < cocientes.size());//n tiene que ser mayor que 0 y ser menor que el grado maximo
    
    cocientes[n]= c;//Nos situamos en el grado del cociente a modificar y lo actualizamos

}


