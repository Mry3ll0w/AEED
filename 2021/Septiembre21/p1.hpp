#ifndef P1_HPP
#define P1_HPP
#include<iostream>
#include "tads p/pila_enla.h"
#include<string>
/* EJERCICIO 5 
El modo de operación habitual es el siguiente:
El cursor se puede situar en cualquier posición desde el primer carácter de la línea
hasta la posición siguiente al último carácter de la línea.
Cada vez que se introduce un carácter, el cursor avanza a la siguiente posición a la
derecha.
En modo inserción los caracteres que están en la posición del cursor y siguientes se
desplazarán para dejar sitio al nuevo.
En modo sobreescritura se sustituye el carácter de la posición del cursor por el nuevo.
En ambos modos de escritura, si el cursor está en la última posición de la línea,
simplemente se añaden al texto los caracteres introducidos y el cursor continúa en la
última posición.
a) Defina una estructura de datos basada en el TAD Pila para representar una línea de
texto de cualquier longitud.
b) Escriba funciones que realicen con la estructura definida las siguientes operaciones:
– avanzar el cursor una posición        – borrar el carácter de la posición del cursor
– retrasar el cursor una posición       – borrar el carácter anterior al cursor
– ir al final de la línea               – insertar un carácter en la posición del cursor
– ir al principio de la línea           – sobreescribir el carácter del curso
        izq      der
        a z      b c d e f
          ^
*/
class texto
{
private:
    PilaEnla<char>izq, der;

public:
    texto(){}
    ~texto(){}
    void avanzar_cursor();      //donete
    void retrasar_cursor();     //Donete
    void move_endline();        //Entiendo que es mover al final el cursor
    void move_beginline();      //Entiendo que es mover al ppio el cursor
    void borrar_cursor();       //ok
    void borrar_anterior_cursor();//ta weno
    void insertar_en_cursor(const char&);//finiquitado de wanna wana kikon
    void sobre_escribe_cursor(const char&);//finiquitado
};

void texto::avanzar_cursor(){
    char aux;
    aux = izq.tope();
    izq.pop();
    der.push(aux);
}

void texto::retrasar_cursor(){
    char aux;
    aux = der.tope();
    der.pop();
    izq.push(aux);
}

void texto::move_endline(){
    while (der.vacia()!=true)
    {
        izq.push(der.tope());
        der.pop();
    }
}

void texto::move_beginline(){
   while (izq.vacia()!=true)
    {
        der.push(izq.tope());
        izq.pop();
    }
    izq.push(der.tope());
    der.pop();
}

void texto::borrar_cursor(){
    izq.pop();
}

void texto::borrar_anterior_cursor(){
    der.push(izq.tope());
    izq.pop(); //borra cursor temporal
    izq.pop(); //borra anterior borrar_cursor
    /* Restablecer cursor */
    izq.push(der.tope());
    der.pop();
}

void texto::insertar_en_cursor(const char& a){
    izq.push(a);
}

void texto::sobre_escribe_cursor(const char& a){
    izq.pop();
    izq.push(a);
}

#endif