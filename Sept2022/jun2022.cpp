#include <iostream>
#include <string>
#include <cassert>
#include "tads/ListaEnla.h"
using namespace std;//Avoid using std:: ....

typedef double Trama;//Por definirlo de algun tipo ya que en el examen existe

struct maquina{

    string nombre;
    Trama T;
    bool tiene_token;//Inicialmente el token es true, ya que cuando entra en la red la maquina tiene el token
    

    maquina(string n = "", bool t = true):tiene_token(false), nombre(n), T(0){
        if(n.size() > 8){
            throw invalid_argument("El nombre de la maquina no puede tener mas de 8 caracteres");
        }
    }

    bool operator ==(const maquina& other){
        return nombre == other.nombre;
    }

    

};

class TokenBus{

    ListaEnla<maquina>red;
    size_t ocupados;
public:
    
    TokenBus(const maquina& m):ocupados(1){

        red.insertar(m, red.fin());
    }

    /**
     * @brief Inserta un nuevo ordenador a la red en anillo, dandole el token al nuevo insertado
     * @param const maquina& m
     * @return none (void)
     */
    void insertar_ordenador(const maquina& m){
        
        assert(ocupados + 1 <= 25);
        
        //Pasamos el token de comunicacion al ultimo que entro en la lista
        
        //Encontramos quien tiene el token y se lo quitamos
        auto pos_token = red.buscar(maquina(tiene_token()));
        
        red.elemento(pos_token).tiene_token = false;

        red.insertar(m, red.fin());
        
    }

    /**
     * @brief Muestra el nombre de quien tiene el token dentro de la red
     * 
     * @param none
     * 
     * @return string
     */
    string tiene_token(){
        
        auto p = red.primera();
        bool found=false;
        while (p != red.fin() && !found){

            if(red.elemento(p).tiene_token)
                found = true;

            p = red.siguiente(p);
        }

        return red.elemento(p).nombre;//Nunca va a llegar a fin, ya que siempre existe al menos uno con el token
    }

    /**
     * @brief Elimina el primer computador que entro en la red, si el eliminado tiene el token, pasa al siguiente
     * 
     * @param none
     * 
     * @return none (void)
     */
    void sacar_computador(){
        
        assert(ocupados - 1 > 0 );

        ocupados ++;
        //Miramos quien tiene el token
        auto pos = red.primera();
        
        //En caso de que el primero tenga el token se le pasa al siguiente antes de eliminarlo
        if(red.elemento(pos).nombre == tiene_token()){
            red.elemento(red.siguiente(pos)).tiene_token == true;
            //Siempre va a existir un siguiente, ya que para eliminar de la red deben existir al menos 2 elementos
        }

        //Eliminamos el primero, ya que nos hemos cercionado de que no tenga el token
        red.eliminar(pos);
        

    }

    /**
     * @brief Pasa el token al siguiente de la lista, al ser una red en anillo si llegamos al ultimo
     * el siguiente sera el primero.
     * 
     * @param none 
     * 
     * @return none (void)
     */
    void pasar_token(){
        
        assert(ocupados > 1);//si solo hay un elemento no podemos pasarselo a nadie mas 
        
        //Localizamos el token
        auto pos_token = red.buscar(maquina(tiene_token()));

        //Si estamos en la ultima posicion se la pasamos al primero
        if(red.siguiente(pos_token) == red.fin()){
            
            red.elemento(pos_token).tiene_token = false;
            red.elemento(red.primera()).tiene_token = true;

        }
        else{//El token no esta en la ultima posicion, se lo pasamos sin mas al siguiente
            red.elemento(pos_token).tiene_token = false;
            red.elemento(red.siguiente(pos_token)).tiene_token = true;
        }
    }

    /**
     * @brief Mover trama (tipo de dato previamente definido, lo declaro como template) desde un ordenador A
     * que tiene que tener el token a un ordenador B, el cual acaba con el token.
     * 
     * @return none (void)
     * 
     * @param const maquina& A, const maquina& B
     * 
     */
    void mover_trama(const maquina& A, const maquina& B, Trama T)
    {
        assert(red.elemento(red.buscar(A)).tiene_token && "Sin token no puede transmitir");//Tiene que existir token y A

        auto p = red.buscar(B);

        assert( p != red.fin() && " La maquina B no existen en la red");

                //Aqui no se si se tiene que pasar internamente el token en la implementacion o nos 
        //podemos mover directamente a B, ya que sea como sea el token acaba en B

        //Para realizarlo asi hacer un bucle y recorrer desde A hasta B, pero en caso de que B sea
        //anterior a A, habria que pasar de la posicion fin de la lista a posicion primera

        //Yo por eficiencia lo paso directamente pero no se si a DLH le va a gustar
        red.elemento(p).tiene_token = true;
        red.elemento(p).T = T;
    
    }
    
};



int main(){
    
return 0;
}
