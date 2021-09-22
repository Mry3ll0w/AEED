#include <iostream>
#include <cstring>
#include <algorithm>
#include "COLA.h"
#include "PILA.h"
#include "Cola_Din.h"
#include "Pila_dinamica.h"

using namespace std;
//Structs and Types

typedef struct {
    string matricula;
} avioneta;
typedef struct {
    ColaDin<avioneta> pista;
    unsigned espacios = 12;
} aerodromo;
typedef struct {
    string Palo;
    string Numero;
} card;
typedef struct {
    PilaEnla<card> cartas;
    string Palo;
    unsigned oc=4;
} monton;

// Functions Headers

int num_aleatorio(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int ej1(COLA<int>, PILA<int>);

void ej2(COLA<int>, int, int);

void ej5(aerodromo &, char, const avioneta &);

bool ej6(monton *);

//Main

int main() {
    string palo[] = {"Basto", "Espada", "Copas", "Oros"};
    string numero[] = {"AS", "DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE", "SOTA", "CABALLO",
                       "REY"};
    COLA<int> ci(4);
    PILA<int> pi(4);
    COLA<int> c_ej2(9);
    int v1[4] = {1, 2, 4, 9};//Pila
    int v2[4] = {11, 9, 78, 2};//Cola
    int v3[9] = {131, 2, 45, 1, 23, 5, 76, 7, 0};
    for (int i = 0; i < pi.tope(); ++i) {
        ci.push(v2[i]);
        pi.push(v1[i]);
    }
    for (int i = 0; i < c_ej2.size(); ++i) {
        c_ej2.push(v3[i]);
    }

    avioneta avion1, avion2, avion3;
    aerodromo a;
    avion1.matricula = "1234501";
    avion2.matricula = "1234502";
    avion3.matricula = "1234503";
    a.pista.push(avion3);
    a.espacios--;
    a.pista.push(avion2);
    a.espacios--;
    a.pista.push(avion1);
    a.espacios--;
    ej5(a, 'S', avion2);
    for (int i = 0; i < 12 - a.espacios; ++i) {
        cout << a.pista.frente().matricula << endl;
        a.pista.pop();
    }

    monton montones[10];
    card carta_aux;
    for (int i = 0; i < 10; ++i) {
        montones[i].Palo = palo[num_aleatorio(0, 3)];
        for (int j = 0; j < 4; ++j) {
            carta_aux.Numero = numero[num_aleatorio(0, 11)];
            carta_aux.Palo = palo[num_aleatorio(0, 3)];
            montones[i].cartas.push(carta_aux);
        }
    }//Asignar cartas a los montones

    cout << "El resultado de la partida es " << ej6(montones) << endl;
    return 0;
}

//////////////////////////////////////////// IMPLEMENTACION DE LAS FUNCIONES //////////////////////////////////////////

int ej1(COLA<int> cint, PILA<int> pint) {
    assert(cint.size() == pint.tope());
    int isomorfic = 1, it = 0;
    int v_pila[cint.size()], v_cola[cint.size()];
    for (int i = 0; i < cint.size(); i++) {
        v_cola[i] = cint.pop();
        v_pila[i] = pint.pop();
    }
    //Comprobamos si son isomorficas
    while (it < cint.size() - 1) {
        if ((it % 2) != 0) {//La posiciones pares son realmente las impares ya que es n-1
            if (v_cola[it] != v_pila[it - 1]) {
                isomorfic = 0;
            }
        }
        it++;
    }
    return isomorfic;
}//ok implementado con los TADS mios
void ej2(COLA<int> c, int a, int b) {

    int aux[c.size()], aux2[c.size()];
    int li, ls;
    for (int i = 0; i < c.size(); ++i) {
        //Obtenemos los limites superior e inferior
        aux[i] = c.pop();
        if (a == aux[i]) {
            li = i;
        }
        if (b == aux[i]) {
            ls = i;
        }
    }
    //Corregir en caso de que los limites sup/inf esten invertidos
    if (ls < li) {
        int x = li;
        li = ls;
        ls = li;
    }
    //damos la vuelta al vector para realizar la copia
    memcpy(aux2, aux, sizeof aux);
    reverse(aux2, aux2 + c.size());
    for (int j = li; j <= ls; ++j) {
        aux[j] = aux2[j];

    }
    cout << "Valor aux: " << endl;
    for (int i = 0; i < c.size(); ++i) {
        cout << aux[i] << ", ";
    }
    cout << endl;
    //hacemos el push en la pila de nuevo (ya que al hacer el pop anteriormente debería estar vacia)
    for (int i = 0; i < c.size(); ++i) {
        c.push(aux[i]);
    }
    c.contenido();
}//oK implementado con los TADS mios
void ej5(aerodromo &a, char accion, const avioneta &avion) {
    ColaDin<avioneta> c_aux;
    assert((accion == 'E') || (accion == 'S'));
    if (accion == 'E') {
        assert(a.espacios > 0);
        if (!a.pista.vacia()) {
            c_aux = a.pista;
            for (int i = 0; i < 12 - a.espacios; ++i) {
                assert(c_aux.frente().matricula == avion.matricula);
                c_aux.pop();
            }
        }
        a.espacios--;
        a.pista.push(avion);
    } else {
        if (a.pista.frente().matricula == avion.matricula) {
            a.pista.pop();
            a.espacios--;
        } else {
            assert(!a.pista.vacia());
            for (int i = 0; i < 12 - (a.espacios + 1); ++i) {
                if (a.pista.frente().matricula == avion.matricula) {
                    a.pista.pop();
                }
                c_aux.push(a.pista.frente());
                a.pista.pop();
            }
            a.pista = c_aux;
            a.espacios++;
        }
    }
}//ok
bool ej6(monton *m) {
    int n_monton=num_aleatorio(0,10);
    unsigned reyes_corr=0;
    card c_aux[4];
    for (int i = 0; i < 9 ; ++i) {
        if ((m[n_monton].Palo==m[i].Palo)&&(i!=n_monton)){
            for (int j = 0; j < 4 ; ++j) {
                m[i].cartas.push(m[n_monton].cartas.tope());
                m[n_monton].cartas.pop();
                m[n_monton].oc--;
                m[i].oc++;
            }
        }

    }
    for (int i = 0; i < 9 ; ++i) {
        for (int j = 0; j < m[i].oc; ++j) {
            c_aux[i]=m[i].cartas.tope();
            m[i].cartas.pop();
        }
        //Falla aqui ya que hay montones con 4 cartas
        if ((c_aux[i].Numero=="REY")&&(c_aux[i].Palo==m[i].Palo)){
            reyes_corr++;
        }
    }
    if (reyes_corr==4){
        return true;
    }
    else{
        return false;
    }
}



