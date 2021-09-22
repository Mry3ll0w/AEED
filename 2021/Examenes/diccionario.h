//
// Created by anton on 19/01/2021.
//
#ifndef EXAMENES_DICCIONARIO_H
#include "ListaEnla.h"
#include <string>
typedef struct traduccion{
    ListaEnla<string>::posicion linker;//Con ella realizamos el bind palabra -> traduccion
    string translation;
}traduccion;


class diccionario{
    public:
        diccionario();
        void insert_translate(const string&,traduccion);//ok
        void insert_word(const string&);//ok
        void erase_tranlation(const string&);//ok?
        void list_tranlation(const string&);
        ~diccionario();
    private:
        ListaEnla<string> palabras;
        ListaEnla<traduccion> traducciones;
};

//Constructor de clase
diccionario::diccionario() {
    //Se crea el diccionario en las partes privadas de la clase por tanto no es necesario implementar nada aqui
}

//Destructor de clase
diccionario::~diccionario() {
    //Se eliminan los espacios creados en memoria por parte de estas funciones
    palabras.~ListaEnla();
    traducciones.~ListaEnla();
}

void diccionario::insert_translate(const string& p_esp, traduccion p_eng) {
    ListaEnla<string>::posicion pos=palabras.primera();
    traducciones.insertar(p_eng,traducciones.fin());
    while(pos!=palabras.fin()){
        if (palabras.elemento(pos)==p_esp){
            p_eng.linker=pos;//se realiza el bindeo
            traducciones.insertar(p_eng,traducciones.fin());
            break;
        }
        pos=palabras.siguiente(pos);
    }
}

void diccionario::insert_word(const string& pal) {
    palabras.insertar(pal,palabras.fin());
}

void diccionario::erase_tranlation(const string& word) {
    ListaEnla<traduccion>::posicion pos=traducciones.primera();

    while(pos!=traducciones.fin()){
        string aux =traducciones.elemento(pos).translation;
        if (aux == word){
            traducciones.eliminar(pos);//Encuentra la traduccion y la elimina, entonces sale del bucle
        }
        pos=traducciones.siguiente(pos);
    }
}

void diccionario::list_tranlation(const string& pal) {
    ListaEnla<string>::posicion pos=palabras.primera();
    ListaEnla<traduccion>::posicion pos_tr=traducciones.primera();
    while(pos!=palabras.fin()){
        if (palabras.elemento(pos)==pal){
            while (pos_tr!=traducciones.fin()){
                if (pos==traducciones.elemento(pos_tr).linker){
                    cout<<traducciones.elemento(pos_tr).translation<<",";
                }
                pos_tr=traducciones.siguiente(pos_tr);
            }
            break;
        }
        pos=palabras.siguiente(pos);
    }
    cout<<endl;
}


#define EXAMENES_DICCIONARIO_H

#endif //EXAMENES_DICCIONARIO_H
