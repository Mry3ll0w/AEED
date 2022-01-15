#include <iostream>
#include "p3.hpp"
#include "p4.hpp"
#include "p5.h"
#include "p6.h"
#include "Escalonada.h"
#include "texto.h"
#include "ej4_parcial2022.h"
#include "texto_feb21.h"
#include "cubilete.h"
#include "hospital.h"
#include "tads_profesorado/listavec.h"
#include "diccionario.h"
int main() {
//srand(time(0));//SOLO DEBE SER LLAMADA UNA Única vez por mainº
//solitario();
//solitario_reyes();
diccionario d;
d.insertar_traduccion("book","libro");

d.insertar_traduccion("hello","hola");
d.insertar_traduccion("hello","saludos");
d.insertar_traduccion("hello","buenas");
d.show_trad("hello");
d.eliminar_traduccion_al_esp("hello","saludos");




return 0;
}

