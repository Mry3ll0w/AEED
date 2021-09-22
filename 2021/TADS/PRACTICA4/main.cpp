#include <iostream>
#include "PILA.h"
#include "pila_enla.h"
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
bool ej1(PILA<char> cad);//EJ 2 similar a EJ1 (no merece la pena hacerlo)
void ej3(PILA<int> p1,int a,int b);
void ej4(PILA<string>p);
void ej6();
int random_number(int a, int b){return (rand()%(b-a+1)+a);}

int main() {
    ej6();

    return 0;
}

//Ejercicio 1: determine y devuelva si una secuencia de caracteres de entrada
//es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
//separadas por el carácter ‘&’
bool ej1(PILA<char>cad) {
    char aux[sizeof(cad)/sizeof(char)];
    for (char & i : aux) {
        i = cad.pop();
    }
    char *aux2 = strrev(aux);
    cout<<aux2<<endl;
    if (strcmp(aux,aux2)==0){
        return true;
    }
    else{
        return false;
    }
}//ok

void ej3(PILA<int> p1, int a, int b) {
    int aux[p1.tope()],aux2[p1.tope()];
    int li,ls;
    for (int i = 0; i <p1.tope() ; ++i) {
        //Obtenemos los limites superior e inferior
        aux[i]=p1.pop();
        if (a==aux[i]){
            li=i;
        }
        if (b==aux[i]){
            ls=i;
        }
    }
    //Corregir en caso de que los limites sup/inf esten invertidos
    if (ls<li){
        int x = li;
        li=ls;
        ls=li;
    }
    //damos la vuelta al vector para realizar la copia
    memcpy(aux2,aux,sizeof aux);
    reverse(aux2,aux2+p1.tope());
    for (int j = li; j <=ls ; ++j) {
        aux[j]=aux2[j];
    }
    //hacemos el push en la pila de nuevo (ya que al hacer el pop anteriormente debería estar vacia)
    for (int i = 0; i < p1.tope(); ++i) {
        p1.push(aux[i]);
    }
}//ok

void ej4(PILA<string>p) {
    string linea,l2;
    PILA<string>aux(3);
    ifstream file("C:\\Users\\anton\\Documents\\Proyectos-universidad\\AEED\\TADS\\PRACTICA4\\fich.txt");
    if(file.is_open()){
        while (getline(file,linea)){
            cout<< linea <<endl;
            aux.push(linea);
            l2+=linea;
        }
        aux.push(l2);
        aux.copia(aux,p);
        file.close();
    }
    else{
        cout<<"Fallo de Lectura"<<endl;
    }
}

//El ejercicio 5 se basa en realizar añadidos a la pila

void ej6() {
    unsigned num[]={1,2,3,4,5,6,7,8,9,10,11,12};
    string palo[]={"Espada","Basto","Oro","Copas"};
    typedef struct{
        unsigned numero;
        string palo;
    }carta;
    typedef struct{
        carta *card;
        string palo;
        unsigned n_cartas=0;
    }bas;
    typedef struct{
        PilaEnla<carta>cards;
        unsigned n_cartas_mazo=0;
    }baraja;

    carta card[40];
    baraja mazo,descarte;
    bas bases[4];

    //Asignamos los palos a las bases
    for (int i = 0; i < 4; ++i) {
        bases[i].palo = palo[i];
    }

    //Asignamos los elementos de las cartas del mazo
    for (int i = 0; i <40 ; ++i) {
        card[i].palo = palo[random_number(0,3)];
        card[i].numero = num[random_number(0,11)];
        mazo.cards.push(card[i]);
        mazo.n_cartas_mazo++;
    }

    //Iniciamos el algoritmo de la partida de solitario
    while (mazo.n_cartas_mazo!=0){
        if ((mazo.n_cartas_mazo%2)==0){
            //Comprueba que el nºcartas es par
            for (int i = 0; i < 2 ; ++i ) {
                descarte.cards.push(mazo.cards.tope());
                descarte.n_cartas_mazo ++;
                mazo.cards.pop();
                mazo.n_cartas_mazo --;
            }
        }
        else{
            descarte.cards.push(mazo.cards.tope());
            mazo.n_cartas_mazo--;
            descarte.n_cartas_mazo++;
        }
        for (int i = 0; i < 4 ; ++i) {
            if (bases[i].palo==descarte.cards.tope().palo){
                if ((bases[i].n_cartas==0)&&(descarte.cards.tope().numero==1)){
                    bases[i].card[bases[i].n_cartas]=descarte.cards.tope();
                    bases[i].n_cartas ++;
                }
                else if ((bases[i].n_cartas!=0)&&((bases[i].card[bases[i].n_cartas].numero)+1==descarte.cards.tope().numero)){
                    bases[i].card[bases[i].n_cartas]=descarte.cards.tope();
                    bases[i].n_cartas ++;
                }
            }
        }
    }
    if (descarte.n_cartas_mazo==0){
        cout<<"Exito"<<endl;
    }
    else if (descarte.n_cartas_mazo>0){
        cout<<"Fallo"<<endl;
    }

}
//ok





