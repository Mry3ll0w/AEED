#include "racional.h"
#include "polinomio.h"
using namespace std;
int main() {
    int gmax=4;
    unsigned g[]={1,2,3,4};
    unsigned g2[]={3,2,1,4,5};
    double c[]={1,2,3,4};
    double c2[]={2,4,5,6,2.3};
    polinomio p1(gmax+1,c2,g2);
    polinomio p2(gmax,c,g);
    polinomio p3(gmax+1,c2,g2);
    p1.print_pol();
    p3 = p1 * p2;
    p3.print_pol();
    p1.~polinomio();
    return 0;
}
