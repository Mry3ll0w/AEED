#include <iostream>
#include "racional.h"
using namespace std;
int main() {
    cout<<"Implementacion basica de un TAD"<<endl;
    racional n1(5,8);
    racional n2(7,9);
    racional n3(1,1);
    racional n4(1,1);


    n4=n3/n1;
    n4.print_rac();
    return 0;
}
