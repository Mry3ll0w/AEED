#include <iostream>
#include "tads/ListaEnla.h"
#include <cassert>
#include <string>

class simbolo{
private:
    ListaEnla<char> l;
public:
    simbolo()=default;
    ~simbolo()=default;
    std::string simetria_x();
    std::string simetria_y();
    std::string simetria_x_y();
    void add_trazo(char t);
    void deshacer_n_trazos(int n);

};

void simbolo::add_trazo(char t){
    
    assert(t == 'a' || t == 'b' || t == 'd' || t == 'i' );

    l.insertar(t,l.fin());

}

void simbolo::deshacer_n_trazos(int n){

    assert(n > 0);

    auto p = l.fin();

    while (p != l.primera() && n > 0){
        
        n--;
        auto pos = p;//No podemos eliminar directamente la posicion para no dejarla colgando
        p = l.anterior(p);
        l.eliminar(pos);

    }
}

std::string simbolo::simetria_x(){

    std::string res;

    for(auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){

        if (l.elemento(i)== 'a')
            res += 'b';
        else if (l.elemento(i) == 'b')
            res += 'a';
        else
            res +=l.elemento(i);

    }
return res;
}

std::string simbolo::simetria_y(){

    std::string res;

    for(auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){

        if (l.elemento(i)== 'd')
            res += 'i';
        else if (l.elemento(i) == 'i')
            res += 'd';
        else
            res +=l.elemento(i);

    }
return res;
}

std::string simbolo::simetria_x_y(){

    std::string res;

    for(auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){

        switch (l.elemento(i))
        {
        case 'a':
            res +='b';
            break;
        
        case 'b':
            res +='a';
            break;
        
        case 'i':
            res +='d';
            break;
        
        case 'd':
            res +='i';
            break;
        
        default:
            break;
        }
        
    }
return res;
}

