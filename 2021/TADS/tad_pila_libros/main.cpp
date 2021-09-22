#include <iostream>
#include "libro_pila.h"
#include <cstring>
using namespace std;
int main() {
    l l1,l2;
    unsigned size=2;
    strcpy(l1.titulo,"Mi libro luna de pluton");
    strcpy(l1.autor,"Dross de mi vida");
    strcpy(l1.ISBN,"32342ABN");
    l1.code=1234;
    strcpy(l2.titulo,"Jupiter un dios");
    strcpy(l2.autor,"Pluton");
    strcpy(l2.ISBN,"3235671AN");
    l2.code=2345;

    libros biblio(size);
    biblio.push(l1);
    biblio.push(l2);
    biblio.datos(2);
    biblio.datos(1);
    biblio.pop();
    //biblio.datos(2);
    return 0;
}
