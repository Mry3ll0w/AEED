#include <iostream>
#include <vector>
#include <string>
#include "../Sept2022/tads/Cola_Din.h"
using namespace std; // Avoid using std:: ....

struct Usuario
{
    ColaDin<std::string> cUrgentes, cNoPrioritarios;
};

class GestorImpresion
{
    std::vector<Usuario> vUsuarios;
    ColaDin<int> cOrdenAtencion;

public:
    GestorImpresion(const int &n = 25) : vUsuarios(std::vector<Usuario>(n)) {}

    void addTrabajoUsuario(const int iNumeroUsuario, const std::string &sTrabajo, const bool bUrgencia)
    {
        if (iNumeroUsuario >= vUsuarios.size())
        {
            throw std::invalid_argument("El usuario no esta en el sistema");
        }
        // El usuario esta en el sistema, por lo que simplemente agregamos el trabajo
        if (bUrgencia)
        {
            vUsuarios[iNumeroUsuario].cUrgentes.push(sTrabajo);
        }
        else
        {
            vUsuarios[iNumeroUsuario].cNoPrioritarios.push(sTrabajo);
        }
    }

    void eliminarTrabajo()
    {
        if (cOrdenAtencion.vacia())
            throw std::runtime_error("No hay trabajos a imprimir");

        // La cola tiene elementos en ella
        int iClienteActual = cOrdenAtencion.frente();
        cOrdenAtencion.pop();
        if (!vUsuarios[iClienteActual].cUrgentes.vacia()) // Primero vaciamos la urgente
        {
            vUsuarios[iClienteActual].cUrgentes.pop();
        }
        else if (!vUsuarios[iClienteActual].cNoPrioritarios.vacia()) // Si la urgente esta vacia, vaciamos la no urgente
        {
            vUsuarios[iClienteActual].cNoPrioritarios.pop();
        }
        // Si quedamos vacio las 2 colas no hacemos nada
        if (!vUsuarios[iClienteActual].cNoPrioritarios.vacia() || !vUsuarios[iClienteActual].cUrgentes.vacia())
        {
            cOrdenAtencion.push(iClienteActual); // Como quedan cosas por imprimir lo ponemos al final de la cola
        }
    }

    void cancelarTrabajosUsuario(const int &iUsuario)
    {
        ColaDin<int> cAux;
        while (!cOrdenAtencion.vacia())
        {
            if (iUsuario != cOrdenAtencion.frente())
            {
                cAux.push(cOrdenAtencion.frente());
            }
            cOrdenAtencion.pop();
        }
        cOrdenAtencion = cAux;
    }
};

int main()
{

    return 0;
}