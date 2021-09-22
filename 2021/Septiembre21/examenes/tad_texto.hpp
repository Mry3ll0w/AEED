#ifndef TAD_TEXTO_HPP
#define TAD_TEXTO_HPP
#include <iostream>
#include <string>
#include "../tads p/ListaEnla.h"
class texto
{
private:
    ListaEnla<std::string>lineas;
public:
    texto(const char*);
    void mostrar_texto();
    void insertar(const char* a){lineas.insertar(std::string(a),lineas.fin());}
    void show_input();
    ~texto()=default;
};

texto::texto(const char* input)
{
    lineas.insertar(std::string(input),lineas.fin());
}
void texto::show_input(){
    auto it = lineas.primera();
    while (it != lineas.fin())
    {
        std::cout<<lineas.elemento(it)<<std::endl;
        it = lineas.siguiente(it);
    }
}

void texto::mostrar_texto(){
    auto it = lineas.primera();
    while (it != lineas.fin())
    {
        if (lineas.elemento(it).find('#')!=string::npos)
        {
            lineas.eliminar(it);//Si tiene una ocurrencia de # se borra la linea
        }
        if(lineas.elemento(it).find('@')!=string::npos){//Si es == a npos no lo ha encontrado
            size_t pos_ar;
            for (size_t i = 0; i < lineas.elemento(it).size(); i++)
            {
                if (lineas.elemento(it)[i]=='@')
                {
                    pos_ar=i;
                }
            }
            char aux_s[lineas.elemento(it).size()];
            for (size_t i = 0; i < lineas.elemento(it).size(); i++)
            {
                if (i!=pos_ar && i!=pos_ar-1)
                {
                    aux_s[i]=lineas.elemento(it)[i];
                }
                
            }
            lineas.elemento(it)=aux_s;
        }
        std::cout<<lineas.elemento(it)<<std::endl;
        it = lineas.siguiente(it);
    }
}


#endif