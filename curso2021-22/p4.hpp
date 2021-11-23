#include "tads_profesorado/pila_enla.h"
#include "tads_profesorado/pila_vec.h"
#include <iostream>
#include <string>
#include <cassert>
/*
 * 1. Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
 * es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
 * separadas por el carácter ‘&’.
 */
bool ej1_p4(const string & input){
    bool es_inversa;
    es_inversa=false;
    //Necesitamos separar la primera parte de la cadena para comprobar si la inversion es igual a la segunda parte
    string split_a;
    for(size_t i = 0 ; i < input.size() && input[i]!='&'; i++){
        split_a += input[i];
    }

    //Una vez obtenida la primera parte comprobaremos si la inversion de split_a esta en la cadena input
    PilaEnla<char> p;
    for (auto i :split_a) { //Insertamos la cadena en una pila para invertirla
        p.push(i);
    }

    //Guardamos en split_a la cadena invertida
    split_a = "";//resetamos split

    while(!p.vacia()){ //Vamos guardando en split la cadena invertida
        split_a+=p.tope();
        p.pop();
    }

    //Comprobamos si esa cadena está dentro de la otra ==> Por tanto estará invertida correctamente
    if (string::npos != input.find(split_a)){
        es_inversa=true; // si no es igual a npos entonces existe esa cadena dentro
    }

    return es_inversa;
}

/*
 *2. Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
 * es de la forma A#B#C#D . . ., donde A, B, C, D,. . . son de la forma X&Y, que a su vez
 * están separados por el carácter ‘#’.
 */
bool ej2_p4(const string & input){
    bool correcta;
    correcta = true;

    //1)Contamos cuantas cadenas hay para crear una pila de x string
    size_t n_cadenas=0;
    for (auto i:input) {
        if (i=='#')
            ++n_cadenas;
    }
    if (n_cadenas == 0){
        return false; //La cadena input no esta en buen formato
    }
    else
        n_cadenas++;//El numero de cadenas es = n de # + 1

    //2)Separamos las subcadenas y las almacenamos en cada una de las
    string temp_str;
    PilaVec<string>p(n_cadenas);

    size_t cont=0;
    size_t i = 0;
    for (; cont< n_cadenas-1; ++i){
        if (input[i] !='#'){
            temp_str+=input[i];
        }
        else{
            if (ej1_p4(temp_str)){//Comprobamos las subcadenas antes de meterlas
                p.push(temp_str);
                temp_str.clear();//limpiamos la cadena
                ++cont;
            }
            else{
                std::cout << "Ta mal una de las subcadenas" << std::endl;
                return false; //Una de las subcadenas no esta bien
            }

        }
    }
    //Terminamos de copiar la ultima cadena
    temp_str.clear();//limpiamos la cadena
    for(;i<input.size(); ++i){
        temp_str += input[i];
    }
    if (ej1_p4(temp_str)){//Comprobamos la ultima cadena
        p.push(temp_str);
    }
    else{
        correcta = false;
    }

    //Comprobamos que la totalidad de la cadena es correcta
    return correcta;
}
