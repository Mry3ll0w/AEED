#include <iostream>
#include <cassert>
#include "tads/pila_enla.h"

using namespace std;//Avoid using std:: ....

typedef int vagon;//Definimos el tipo vagon que tiene 

class Tren{

    PilaEnla<vagon>p_izq, p_der;

public:
    //No es necesario declarar destructor y constructor

    /**
     * @brief Inserta el nuevo vagon desplazando el activo hacia la derecha.
     * @param const vagon& v
     * @return none
     */
    void insertar_vagon(const vagon& V){
        p_der.push(V);
    }

    /**
     * @brief Desplaza a la izquierda el vagon activo siendo el situado a la derecha el nuevo activo.
     * En caso de no existir vagon a la derecha no se hace.
     * 
     * @return none
     * @param none
     */
    void desp_izquierda(){
        assert(!p_der.vacia());
        vagon vt = p_der.tope();
        p_der.pop();

        if(p_der.vacia()){
            p_der.push(vt);//Insertamos el vagon extraido
        }
        else{
            p_izq.push(vt);//Pasamos el antiguo activo sacamos el derecho y lo metemos en el izquierdo
        }

    }

    /**
     * @brief Desplaza a la derecha el tren, siendo el activo el activo el que se encuentra a la izquierda del
     * activo.
     * 
     * @return none
     * @param none
     */
    void desp_derecha(){
        assert(!p_izq.vacia());
        
        vagon vt = p_izq.tope();
        p_izq.pop();
        
        if(p_izq.vacia()){
            p_izq.push(vt);//No se hace nada se deja como estaba
        }
        else{
            p_der.push(vt);
        }

    }

    /**
     * @brief Eliminar el vagon activo
     * @param none
     * @return none(void)
     */
    void eliminar_activo(){
        p_der.pop();
    }

    const vagon activo() const { return p_der.tope();}

    const bool vacio() const {return p_der.vacia();}//Si el derecho esta vacio no hay elementos, 
    //ya que el activo siempre esta con el derecho.

};

int main(){
    
return 0;
}