#include <iostream>
#include <string>
#include <cassert>
#include "tads/ListaEnla.h"
using namespace std;//Avoid using std:: ....

class Binario{
    
    ListaEnla<int> l;
    size_t n;

public:
    
    Binario(const char* s = ""){
        
        string str(s);
        n = str.size();
        
        if(n != 0){
        
            for (auto i : str)
            {

                if (i == '1')
                {
                    l.insertar(1, l.fin());
                }
                else
                {
                    l.insertar(0, l.fin());
                }
            }

        }
        else{
            l.insertar(0, l.fin());
        }
        
        
    }

    void NOT(){
        
        for(auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){
            
            if(l.elemento(i) == 1){
                l.elemento(i) = 0;
            }
            else{
                l.elemento(i) = 1;
            }

        }
    
    }

    void AND(const Binario& b){

        for(auto i = l.primera(); i != l.fin() ; i = l.siguiente(i)){
            
            for (auto j = b.l.primera(); j < b.l.fin(); j = b.l.siguiente(j)){

                if(l.elemento(i) != b.l.elemento(j)){
                    l.elemento(i) = 0;
                }

            }

        }
        
    }

    void OR(const Binario& b){

        for (auto i = l.primera(); i != l.fin(); i = l.siguiente(i))
        {
            for (auto j = b.l.primera(); j < b.l.fin(); j = b.l.siguiente(j))
            {
                if (l.elemento(i) != b.l.elemento(j) && b.l.elemento(j) == 1 )
                {
                    l.elemento(i) = 1;
                }
            }
        }

    }

    void XOR(const Binario& b){
        for (auto i = l.primera(); i != l.fin(); i = l.siguiente(i))
        {
            for (auto j = b.l.primera(); j < b.l.fin(); j = b.l.siguiente(j))
            {
                if (l.elemento(i) != b.l.elemento(j) && b.l.elemento(j) == 1)
                {
                    l.elemento(i) = 1;
                }
                else if(l.elemento(i) == b.l.elemento(j) && b.l.elemento(j) == 1){
                    l.elemento(i) = 0;
                }
            }
        }
    }

    void desp_iz(const int& pos){
        assert(pos <= n);
        //Primera
        auto i = l.primera();
        int it = 0;

        //Nos movemos al pos
        while( it < pos && i != l.fin()){
            i = l.siguiente(i);
            it ++;
        }

        for(; l.anterior(i) != l.primera(); i = l.anterior(i)){

            l.elemento(i) = l.elemento(l.anterior(i));

        }   

    }

    void desp_der(const int& pos){
        
        assert(pos <= n);
        // Primera
        auto i = l.primera();
        int it = 0;

        // Nos movemos al pos
        while (it < pos && i != l.fin())
        {
            i = l.siguiente(i);
            it++;
        }

        for(; l.siguiente(i) != l.fin(); i = l.siguiente(i)){
            l.elemento(i) = l.elemento(l.siguiente(i));
        }

    }

    void print(){
        for(auto i = l.primera(); i != l.fin(); i = l.siguiente(i)){
            cout<< l.elemento(i);
        }
        cout<<endl;
    }
};

int main(){
    
    Binario b("1010100"),a("1111111");

    b.XOR(a);

    b.print();

return 0;
}