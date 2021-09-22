//
// Created by anton on 09/11/2020.
//
#include"racional.h"
long int racional::mcd(int x, int y){
    long int a;
    // Algoritmo de Euclides
    if (x < y)
    {
        a = x;
        x = y;
        y = a;
    }
    while ((a = x % y))
    {
        x = y;
        y = a;
    }
    return y;
}
//ok
racional::racional(int n, int d) :numerador(n),denominador(d){ //: se usa para asignarle valores a variable privada
    assert(d!=0);
    if(n<0){
        numerador*=-1;//cambiamos de posicion el negativo ya que generalmente es colocado en el
        denominador*=-1;
    }
    //Reduccion de la fraccion
    long int m = mcd(n,d);
    if(m!=1){
        numerador/=m;
        denominador/=m;
    }
}//ok

racional racional::print_rac() const{
    racional e(numerador,denominador);
    cout<<e.num()<<"/"<<e.den()<<endl;
}//ok

long int racional::mcm(int x, int y) {

    int a = max(x,y);
    int b = min(x,y);
    long int mincmmul  = (a/mcd(a,b))*b;
    return mincmmul;
}//ok

racional operator + (const racional &a, const racional &b) {
    racional res(1,1);
    if(a.denominador==b.denominador){
        res.numerador=a.numerador+b.numerador;
        res.denominador=a.denominador;
        return res;
    }
    else{

        long int minmul=racional::mcm(a.denominador,b.denominador);
        long int mul1 = minmul/a.denominador;
        long int mul2 = minmul/b.denominador;
        res.numerador = (a.numerador * mul1) + (b.numerador * mul2);
        res.denominador = minmul;

    }
    return res;
}//ok

racional operator - (const racional &a, const racional &b) {
    racional res(1,1);
    if(a.denominador==b.denominador){
        res.numerador=a.numerador-b.numerador;
        res.denominador=a.denominador;
        return res;
    }
    else{

        long int minmul=racional::mcm(a.denominador,b.denominador);
        long int mul1 = minmul/a.denominador;
        long int mul2 = minmul/b.denominador;
        res.numerador = (a.numerador * mul1) - (b.numerador * mul2);
        res.denominador = minmul;

    }
    return res;
}//ok

racional operator *(const racional &a, const racional &b) {
    racional res (1,1);
    res.numerador  = a.numerador * b.numerador;
    res.denominador = a.denominador * b.denominador;
    return res;
}

racional operator / (const racional &a, const racional &b) {
    racional res (1,1);
    res.numerador = a.numerador *b.denominador;
    res.denominador = a.denominador * b.numerador;

    return res;
}//Ready



