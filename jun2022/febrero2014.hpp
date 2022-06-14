#include "tads/ListaEnla.h"
#include <iostream>
#include <cassert>
#include <string>

/** Teoria
 * Ordenacion de los ordenes (Mayor a menor)
 * n^3n <  n! < 2^n < n^3+n < raiz(n)/2 < n log n
 */

/** m1 {4,2}
 *            2  
 * ---- m1 ----- m2 --------- T
 * 
 * REPRESENTACION DEL TAD COCINA:
 * 1) Resumen ==> El Tad cocina sirve para representar una cocina con una lista de muebles
 * en su pared.
 * 2)Especificaciones:
 * void cocina::eliminar(const size_t posicion):
 *      Precondición==> Recibe una posicion mayor o igual que 0, es decir, valida.
 *      PostCondicion==> elimina el mueble que se encuentra en la posicion iesima, si existe.
 */

struct mueble {
    int posicion, anchura;
    mueble(const int p = -1, int d = -1):posicion(p), anchura(d){}

    bool operator < (mueble b){
        return posicion < b.posicion;
    }
};

class cocina{

private:
    
    ListaEnla<mueble> l;
    int size_cocina;
    int restante;

public:
    cocina(int x):size_cocina(x),restante(x){}
    ~cocina()=default;

    const mueble& devolver(const size_t i);
    void eliminar_mueble(const int i);
    //La posicion es dada por la estructura mueble
    bool cabe(mueble m);

    void add_mueble(mueble m){
        assert(cabe(m));
        auto pos = l.primera();
        for (; pos != l.fin() && l.elemento(pos)<m; pos=l.siguiente(pos));

        l.insertar(m,pos);
    }

    void pegar_mueble(int pos){
        assert(pos >= 1);

        if(pos == 1){
            
            auto p = l.primera();
            //pegar mueble a la izquierda
            l.elemento(p).posicion=0;//pegamos a la izq

            for (;p != l.fin() && pos > 1 ; p = l.siguiente(p))
            {
                auto p_ant = l.anterior(p);
                l.elemento(p).posicion = l.elemento(p_ant).posicion + l.elemento(p_ant).anchura;
                
                pos--;
            }
            


        }
        
    }


};

const mueble& cocina::devolver(const size_t i){

    assert(i > 0);

    //ListaEnla<mueble>::posicion p= l.primera();
    auto p = l.primera();
    int pos = 1;
    
    for(;p != l.fin() || pos == i; p=l.siguiente(p)){pos++;}

    if (p == l.fin())
    {
        return mueble();
    }
    else{
        return l.elemento(p);
    }
    
}

void cocina::eliminar_mueble(const int i){
    assert(i > 0);

    //ListaEnla<mueble>::posicion p= l.primera();
    auto p = l.primera();
    int pos = 1;
    
    for(;p != l.fin() || pos == i; p=l.siguiente(p)){
        pos++;
    }

    if (p != l.fin())
    {
        restante+=l.elemento(p).anchura;
        l.eliminar(p);
    }
    
}

bool cocina::cabe(mueble m){

    assert(m.posicion >= 0 && m.anchura >= 1);
    
    //No  hay espacio para colocar el mueble
    if (l.primera()==l.fin() && m.anchura >= restante)
    {
        return true;
    }
    else if (m.anchura >= restante)
    {
        return false;
    }
    else{//Hay anchura disponible en el espacio de la pared

        auto pos = l.primera();

        for (; pos != l.fin() && l.elemento(pos)<m; pos=l.siguiente(pos));
        //Caso 2: el mueble esta pegado a la pared

    
        //Buscamos si cabe en la posicion dada
        //caso mueble pegado a la pared (es decir cabe un mueble y la pared)
        
        if (m.posicion == 0)//Pared izquierda
        {
            mueble m_sig = l.elemento(pos);
            if(m_sig.posicion > m.anchura){// si la posicion del mueble izquierdo es mayor entonces cabe, ya que es lateral izquierdo
                return true;
            }
            else{
                return false;//En otro caso no cabe
            }
        }
        else{//No esta pegado a la pared

            if (pos == l.fin())
            {
                if ((restante - (l.elemento(pos).anchura + l.elemento(pos).posicion) >= (m.posicion + m.anchura)))
                {
                    return true;
                }
                else
                    return false;
                
            }
            else{//Entre 2 muebles

                auto p_sig = l.siguiente(pos);
                mueble msig = l.elemento(p_sig);
                mueble anterior = l.elemento(pos);

                if (m.anchura <= (msig.posicion - (anterior.posicion + anterior.anchura)))
                {
                    return true;
                }
                else{
                    return false;
                }

            }
            

        }
        
    }

   
    

}