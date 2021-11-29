#include "tads_profesorado/pila_enla.h"
#include "tads_profesorado/pila_vec.h"
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm> //std::reverse


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

/**
 * Escriba una función que dados dos elementos a y b y una pila, invierta la secuencia
 * delimitada por ambos dentro de ella.Dado que la pila puede tener elementos repetidos,
 * se invertirá la secuencia delimitada por la primera ocurrencia de a y de b.
 * Ejemplos: a=1, b=2
 * Pila original: 4789918679624893210
 * Pila final: 4789926976814893210
 */
 template <class t>
 PilaEnla<t> ej3_p4(const t& a, const t& b, PilaEnla<t> p_input ){
     PilaEnla<t> output_pila;
     //Recorremos la pila hasta llegar al elemento a o acabar la pila
     while(!p_input.vacia() && p_input.tope()!=a)
         p_input.pop();

    //Si esta vacia entonces devolvemos la pila vacia, ya que ese elemento no se encuentra en la pila
    if (!p_input.vacia()){

        while(!p_input.vacia() && p_input.tope()!=b) {
            output_pila.push(p_input.tope());//insertamos en la pila el intervalo hasta llegar al fin o al elemento
            p_input.pop();
        }

     }
     return output_pila;
 }

 //El 4 lo va a hacer tu vieja (pereza), el 5 tiene mas chicha

 /* --------------------------------------------------------EJERCICIO 5---------------------------------------------*/
 class linea_texto{
 private:
     PilaEnla<char>t;
     size_t cursor;

 public:
     explicit linea_texto(const std::string&);
     const std::string texto_getter()const;
     void increment_cursor();
     void decrement_cursor();
     void erase_cursor();
     void erase_previous_cursor();
     void cursor_end();
     void cursor_start();
     void insert_in_cursor(const char& c);
     void overwrite_cursor(const char& c);

 };

 //Ctor de clase
 // inicializa la pila con la linea de texto deseada y el cursor se colocar en el primer char de la linea
 //Tiene que recibir al menos una cadena inicializada, no existe el concepto linea_texto vacia
linea_texto::linea_texto(const string & str):cursor(0){
    for(auto i: str)
        t.push(i);

}

//Precondicion==> La linea de texto no puede estar vacia
const std::string linea_texto::texto_getter() const{
    assert(!t.vacia());//aserto

    std::string output;
    PilaEnla<char>parser_pila;//Para no modificar la pila del tad
    parser_pila = t;
    //Insertamos en la cadena la pila actual

    while(!parser_pila.vacia()){
        output+=parser_pila.tope();
        parser_pila.pop();
    }
    std::reverse(output.begin(),output.end());//Hay que darle la vuelta ya que la pila esta invertida

    return output;
}

//Al ser una pila incrementar implica decrementar por tanto ==> incrementar -> y decrementar <-
//Precondicion==> La pila texto no puede estar vacia, el cursor tiene que ser menor al size de la linea
//Postcondicion==> Incrementa el cursor
void linea_texto::increment_cursor() {
assert(!t.vacia());
assert(cursor < texto_getter().size());
    // e p e p l E
    // ^
    ++cursor;
}

//Precondicion==> La pila texto no puede estar vacia, cursor > 0
//Postcondicion==> Incrementa el cursor
void linea_texto::decrement_cursor() {
    assert(!t.vacia());
    assert(cursor < 0);
    --cursor;
}






