#include <iostream>
#include <vector>
#include <cassert>
/* -------------------------------------------------------------------------- */
/*                        OPERACIONES DEL TAD POLINOMIO                       */
/* -------------------------------------------------------------------------- */
/*
polinomio::polinomio (unsigned gradoMax)
Postcondiciones: Crea el polinomio nulo. El objetivo de este método es crear un objeto
polinomio, reservando el espacio necesario e inicializando con el valor nulo.

unsigned polinomio::grado () const
Postcondiciones: Devuelve el grado de un polinomio.

double polinomio::coeficiente (unsigned n) const
Postcondiciones: Devuelve el coeficiente correspondiente al monomio de grado n de
un polinomio. Si n > gradoM ax, devuelve 0.

void polinomio::coeficiente (unsigned n, double c)
Precondiciones: n ≤ gradoM ax
Postcondiciones: Asigna al monomio de grado n el coeficiente c.
*/
class polinomio{

private:
    //No sera necesario el uso de una variable para almacenar el grado, ya que es igual al size
    std::vector<double>cocientes;

public:
    polinomio(unsigned gradoMax);

    unsigned grado()const;

    double coeficiente(const unsigned& n);

    void coeficiente(unsigned n, double c);
    
    //Funciones observadoras
    std::vector<double> cocientes_getter()const{return cocientes;}

};

//Sobrecarga mia para ahorrarme escribir 2838 bucles XDD
std::ostream& operator<<(std::ostream& os,const polinomio& p);