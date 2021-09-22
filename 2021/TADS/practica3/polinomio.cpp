//
// Created by anton on 12/11/2020.
//
#include "polinomio.h"

polinomio::polinomio(int grado,const double cocis[], const unsigned gs[]):grado_max(grado) {
    assert(grado_max!=0);
    cocientes = new double [grado_max];
    grados = new unsigned [grado_max];
    for (int i = 0; i < grado_max ; ++i) {
        cocientes[i]=cocis[i];
        grados[i] = gs[i];
    }

}
//Destructor de la clase (elimina espacio en memoria de
polinomio::~polinomio() {
    delete[] grados;
    delete [] cocientes;
}

void polinomio::print_pol() const{
    polinomio pol(grado_max,cocientes,grados);
    for (int i = 0; i < grado_max; ++i) {
        cout<<pol.cocientes[i]<<"x^"<<pol.grados[i];
        if (i!=grado_max-1){cout<<"+";}
    }
    cout<<endl;
}//ok

void polinomio::coeficiente(unsigned int n, double c) {
    cocientes[n-1]=c;
}

polinomio operator+(polinomio &a, polinomio &b) {
    double *c_res;unsigned *g_res;
    if (a.grado_max==b.grado_max){
        c_res = new double[b.grado_max];
        g_res   = new unsigned [b.grado_max];
        polinomio res(b.grado_max,c_res,g_res);
        for (int i = 0; i < a.grado_max; ++i) {
            res.cocientes[i] = a.cocientes[i] + b.cocientes[i];
        }
        return res;
    }
    else if (a.grado_max<b.grado_max){

        c_res = new double[b.grado_max];
        g_res   = new unsigned [b.grado_max];
        polinomio res(b.grado_max,c_res,g_res);
        for (int i = b.grado_max-a.grado_max; i <0 ; i--) {
            res.grados[i]= b.grados[i];
            res.cocientes[i]=b.cocientes[i];
        }
        for (int i = 0; i <a.grado_max ; ++i) {
            res.cocientes[i] = a.cocientes[i]+b.cocientes[i];
        }
        return res;
    }
    else{

        c_res = new double[a.grado_max];
        g_res   = new unsigned [a.grado_max];
        polinomio res(a.grado_max,c_res,g_res);
        for (int i = a.grado_max-b.grado_max; i <0 ; i--) {
            res.grados[i]= a.grados[i];
            res.cocientes[i]=a.cocientes[i];
        }
        for (int i = 0; i <b.grado_max-a.grado_max ; ++i) {
            res.cocientes[i] = a.cocientes[i]+b.cocientes[i];
        }
        return res;
    }

}
//kk
polinomio operator - (polinomio &a, polinomio &b) {
    double *c_res;unsigned *g_res;
    if (a.grado_max==b.grado_max){
        c_res = new double[b.grado_max];
        g_res   = new unsigned [b.grado_max];
        polinomio res(b.grado_max,c_res,g_res);
        for (int i = 0; i < a.grado_max; ++i) {
            res.cocientes[i] = a.cocientes[i] - b.cocientes[i];
        }
        return res;
    }
    else if (a.grado_max<b.grado_max){

        c_res = new double[b.grado_max];
        g_res   = new unsigned [b.grado_max];
        polinomio res(b.grado_max,c_res,g_res);
        for (int i = b.grado_max-a.grado_max; i <0 ; i--) {
            res.grados[i]= b.grados[i];
            res.cocientes[i]=b.cocientes[i];
        }
        for (int i = 0; i <b.grado_max-a.grado_max ; ++i) {
            res.cocientes[i] = a.cocientes[i]-b.cocientes[i];
        }
        return res;
    }
    else{

        c_res = new double[a.grado_max];
        g_res   = new unsigned [a.grado_max];
        polinomio res(a.grado_max,c_res,g_res);
        for (int i = a.grado_max-b.grado_max; i <0 ; i--) {
            res.grados[i]= a.grados[i];
            res.cocientes[i]=a.cocientes[i];
        }
        for (int i = 0; i <b.grado_max-a.grado_max ; ++i) {
            res.cocientes[i] = a.cocientes[i]-b.cocientes[i];
        }
        return res;
    }

}

polinomio operator*(polinomio &a, polinomio &b) {
    polinomio res(a.grado_max,a.cocientes, a.grados);
    for (int i = 0; i <a.grado_max ; ++i) {
        for (int j = 0; j <b.grado_max ; ++j){
            b.grados[j]=a.grados[i]+b.grados[j];
            b.cocientes[j]=a.cocientes[i]*b.cocientes[j];
        }
    }
    for (int i = 0; i <b.grado_max ; ++i) {
        res.cocientes[i] = b.cocientes[i];
        res.grados[i] = b.grados[i];

    }
    return res;
}




