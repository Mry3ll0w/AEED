#include "tads_profesorado/pila_enla.h"
#include "tads_profesorado/pila_vec.h"
#include <iostream>
#include <random>
#include <string>
#include <cassert>
#include <algorithm> //std::reverse
#include <vector>

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
 PilaEnla<t> ej3_p4(const t& a, const t& b, PilaEnla<t> p_input ){//ARREGLAR
     PilaEnla<t> output_pila,pila_izq;
     //Recorremos la pila hasta llegar al elemento a o acabar la pila
     while(!p_input.vacia() && p_input.tope()!=b){
         pila_izq.push(p_input.tope());
         p_input.pop();
     }

    //Si esta vacia entonces devolvemos la pila vacia, ya que ese elemento no se encuentra en la pila
    if (!p_input.vacia()){
        //Metemos en output pila la parte derecha del limite
        while(!p_input.vacia() && p_input.tope()!=a) {
            output_pila.push(p_input.tope());//insertamos en la pila el intervalo hasta llegar al fin o al elemento
            p_input.pop();
        }

        //pasamos los elementos a la pila original
        //1)Copiamos la pila derecha
        while(!pila_izq.vacia()){
            p_input.push(pila_izq.tope());
            pila_izq.pop();
        }
        //2)copiamos la pila derecha
        while(!output_pila.vacia()){
            p_input.push(output_pila.tope());
            output_pila.pop();
        }

    }
    //Para la correcta impresion de la pila deberemos invertirla usando otra auxiliar
    PilaEnla<t>aux;
    while(!p_input.vacia()){
        aux.push(p_input.tope());
        p_input.pop();
    }

    return aux;
 }

 /*--------------------------------------------------------EJERCICIO 4 ---------------------------------------------*/

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
     char disp_cursor();
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
assert(cursor < texto_getter().size() );
assert(texto_getter().size()-(cursor+1) > 0);//Si la resta es menor que 0 al hacer pop se saldria de la pila
    // e p e p l E
    // ^
    ++cursor;
}

//Precondicion==> La pila texto no puede estar vacia, cursor > 0
//Postcondicion==> Incrementa el cursor
void linea_texto::decrement_cursor() {
    assert(!t.vacia());
    assert(cursor > 0);
    --cursor;
}

//Muestra el caracter al cual apunta el cursor
char linea_texto::disp_cursor() {
    PilaEnla<char> temp = t;
    size_t cont = 0;
    while (cont < cursor){
        temp.pop();
        cont++;
    }

    std::cout<<temp.tope()<<std::endl;
return temp.tope();
}


//Precondicion==> La pila no puede estar vacia
//Postcondicion ==> elimina el caracter en la posicion del cursor
void linea_texto::erase_cursor() {
    assert(!t.vacia());//La pila no puede estar vacia , y en consecuencia el cursor tiene que ser > 0
    assert(cursor >= 0);//Cursor mayor que 0

    if(cursor == 0){//Si solo hay un elemento en la pila simplemente sacamos de la misma el tope
        t.pop();
        cursor=-1;//Cuando esta vacio, esta debe apuntar a -1

    }
    else{

        PilaEnla<char> parser_stack;//Nos servira para ir guardar temporalmente el contenido de p
        int cont = 0;//Iterador

        while (cont < cursor){
            parser_stack.push(t.tope());//Metemos los datos que no queremos
            t.pop();
            ++cont;
        }

        //Ya t esta en la posicion del cursor, por tanto simplemente hacemos un pop y metemos el resto en t
        t.pop();
        //Copiamos los caracter anteriores al cursor que estan en parser_stack
        while (!parser_stack.vacia()){
            t.push(parser_stack.tope());
            parser_stack.pop();
        }

    }



}

//Precondicion==> El cursor no puede estar en la posicion primera (cursor>0), la pila no puede estar vacia
//Postcondicion==> Elimina el caracter anterior al cursor
void linea_texto::erase_previous_cursor() {
    assert(cursor >= 1);
    assert(!t.vacia());
    if (cursor == 1){// si el cursor esta en la segunda posicion, simplemente sacamos la anterior con pop
        cursor --;
        t.pop();
    }
    else{//Cursor esta en posicion >= 2

        cursor --;
        erase_cursor();
        std::cout<<t<<std::endl;
    }

}

//Post==>Mueve el cursor hasta el final del texto
void linea_texto::cursor_end() {
    if (t.vacia())
        cursor=-1;
    else
        cursor = texto_getter().size()-1;

}

void linea_texto::cursor_start() {
    if (t.vacia())
        cursor=-1;
    else
        cursor=0;
}

//Postcondicion==> Inserta un nuevo caracter en la posicion del cursor y desplaza el resto
void linea_texto::insert_in_cursor(const char &c) {

    if (cursor == 0){//Si esta en la posicion inicial solo sacamos un elemento y lo volvemos a guardar despues
        char parser_char=t.tope();
        t.pop();
        t.push(c);
        t.push(parser_char);

    }
    else{//Si cursor > 0 entonces necesitamos una pila extra para guardar temporalmente el contenido de t
        PilaEnla<char> temp_stack;
        int cont =0;
        while (cont <= cursor){
            //Guardamos en la pila todos los caracteres desde el principio hasta el cursor incluyendo a este
            temp_stack.push(t.tope());
            t.pop();
            cont++;
        }
        t.push(c);//Metemos el nuevo caracter

        while(!temp_stack.vacia()){//Recuperamos el contenido
            t.push(temp_stack.tope());
            temp_stack.pop();
        }

    }

}

void linea_texto::overwrite_cursor(const char &c) {
    size_t cont = 0;
    PilaEnla<char>parser_stack;
    while (cont < cursor){
        parser_stack.push(t.tope());
        t.pop();
        ++cont;
    }
    //Sacamos el elemento del cursor y metemos el nuevo caracter
    t.pop();
    t.push(c);
    //Copiamos los caracteres anteriores
    while(!parser_stack.vacia()){
        t.push(parser_stack.tope());
        parser_stack.pop();
    }
}

/*
 * Solitario
 */
//Defino este procedimiento a modo de main para el solitario y tal
void solitario(){
    //Definicion de variables
    enum palo{basto, espada, copa, oro};
    string palos[] ={"basto","espada","copa","oro"};
    int colocadas[4]={0,0,0,0};
    struct carta{
        int n;
        unsigned p;
        carta(int n_=0,unsigned p_=0):n(n_),p(p_) {}
    };
    std::vector<carta> baraja;
    PilaVec<carta>maze(48),descarte(48);
    bool coloca=false;
    size_t vuelta = 0;//para contar las vueltas

    //inicializamos la baraja
    for (int i = 0; i < 4 ; ++i) {//De cada palo
        for(int j = 1; j <=12 ; ++j){
            baraja.emplace_back(carta(j,i));
        }
    }
    //Hacemos un random shuffle a la baraja para mezclar las cartas (esta es la version mas segura de random shuffle)
    std::shuffle(baraja.begin(), baraja.end(), std::random_device());
    //Tras haber barajado las cartas empezaremos el algoritmo de colocacion

    //1) Pasamos a pila la baraja
    for(auto i: baraja)
        maze.push(i);


    while(true){
        //Mientras que queden cartas en el mazo sacamos
        coloca=false;//reset de coloca
        while(!maze.vacia()){


            //Comprobamos si se puede colocar
            if (maze.tope().n-1 == colocadas[maze.tope().p]){

                //Si es la carta anterior la que esta en el mazo entonces coloca la carta
                colocadas[maze.tope().p]=maze.tope().n;
                coloca=true;
            }
            else{//Si no se corresponde entonces colocala en descarte
                descarte.push(maze.tope());
            }

            maze.pop();
        }

        vuelta++;//Aumentamos la vuelta, ya que si en vuelta < 1 y no se ha colocado se sale

        //comprobamos si todas las cartas se han colocado
        if(colocadas[0]==12 && colocadas[1]==12 &&colocadas[2]==12 &&colocadas[3]==12)
            break;

        if(vuelta >= 1 && !coloca){//Si no ha colocado entonces salimos en la segunda vuelta
            break;
        }

        //Miramos si se ha colocado
        if (coloca){
            //Si se ha colocado volcamos el descarte en los mazos
            while(!descarte.vacia()){
                maze.push(descarte.tope());
                descarte.pop();
            }

        }

    }

    //Si se ha ganado el descarte estara vacio, al igual que el mazo
    if (descarte.vacia() && maze.vacia()){
        std::cout<<"Victoria"<<std::endl;
    }
    else{
        std::cout<<"Has perdido"<<std::endl;
        std::cout<<"Estado de las cartas: "<<colocadas[0]<<' '<<colocadas[1]<<' '<<colocadas[2]<<' '<< colocadas[3]<<std::endl;
    }


}





