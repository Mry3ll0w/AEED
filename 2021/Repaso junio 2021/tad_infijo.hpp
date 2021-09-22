#ifndef TAD_INFIJO_HPP
#define TAD_INFIJO_HPP
#include <iostream>
#include <cstring>
#include "tads implementados profesorado/pila_enla.h"
using namespace std;
//NO es un tad como tal ya que es solo una funcion pero la hacemos aparte.
int procesar_infijo(PilaEnla<char>operadores, PilaEnla<int>operandos,int cont){

    if (operadores.vacia()==true || operandos.vacia()==true)
    {
        return 0;
    }
    
    if(cont>1){
        cont=0;
        operadores.pop();
    }
    int t=operandos.tope();
    operandos.pop();
    switch (operadores.tope())
    {
    case '+':
        return t+procesar_infijo(operadores,operandos,cont++);
        break;
        
    case '-':
        return t-procesar_infijo(operadores,operandos,cont++);
        break;

    case '*':
        return t*procesar_infijo(operadores,operandos,cont++);
        break;

    case '/':
        return t/procesar_infijo(operadores,operandos,cont++);
        break;

    default:
        break;
    }
    
}
int op_infjo(const char *cadena){
    PilaEnla<char>operadores;
    PilaEnla<int>operandos;
    for (size_t i=0;i<strlen(cadena);++i)
    {
        if (cadena[i]=='+'||cadena[i]=='-'||cadena[i]=='*'||cadena[i]=='/')
        {
            operadores.push(cadena[i]);
        }
        else{
            int t = cadena[i] - '0';
            operandos.push(t);
        }
                    
    }
    return procesar_infijo(operadores,operandos,0);  
}

#endif