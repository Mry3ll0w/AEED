#include <iostream>
#include <string>
#include "../Sept2022/tads/ListaEnla.h"
using namespace std; // Avoid using std:: ....

// Si gravedad  entre 1 y 5 ==> UCI, 6 - 9 planta
typedef struct Paciente
{
    int gravedad;
    string id;
    Paciente(const int gr = 0, const string i = "") : gravedad(gr), id(i) {}
    bool operator==(Paciente &p) { return p.id == id; }
    bool operator!=(Paciente p) { return !(p == *this); }
};
class Hospital
{

private:
    int iOcupadosPlanta_, iOcupadosUCI_;
    ListaEnla<Paciente> lPlanta, lUCI, lMorgue;
    bool llenaUCI() { return iOcupadosUCI_ == 50; }
    bool llenaPlanta() { return iOcupadosPlanta_ == 50; }
    ListaEnla<Paciente>::posicion buscarPaciente(Paciente p, ListaEnla<Paciente> &lista)
    {
        auto i = lista.primera();
        for (; i != lista.fin() && lista.elemento(i) != p; i = lista.siguiente(i))
        {
        }
        return i;
    }
    void insercionOrdenada(ListaEnla<Paciente> &l, const Paciente &paciente)
    {
        auto p = l.primera();
        while (p != l.fin() && l.elemento(p).gravedad < paciente.gravedad)
            p = l.siguiente(p);
        l.insertar(paciente, p);
    }

public:
    Hospital() : iOcupadosPlanta_(0), iOcupadosUCI_(0) {}
    void insertarPaciente(const int &gravedad, const string &paciente)
    {
        if (gravedad == 0)
        {
            lMorgue.insertar(Paciente(iOcupadosPlanta_, paciente), lMorgue.fin());
        }
        else if (gravedad >= 1 && gravedad < 5)
        {
            if (llenaUCI())
            {
                // Al ordenar la lista de pacientes en la insercion, el paciente de menor gravedad estara en la ultima posicion de la lista
                //  para almacenar al paciente nuevo
                Paciente pacienteMenorGravedad = lUCI.elemento(lUCI.anterior(lUCI.fin()));
                lUCI.eliminar(lUCI.anterior(lUCI.fin()));
                insercionOrdenada(lUCI, Paciente(gravedad, paciente));
                if (llenaPlanta())
                {
                    Paciente pMenorGravedad = lPlanta.elemento(lPlanta.anterior(lPlanta.fin()));
                    lPlanta.eliminar(lPlanta.anterior(lPlanta.fin()));
                    insercionOrdenada(lPlanta, pacienteMenorGravedad);
                }
                else
                {
                    insercionOrdenada(lPlanta, pacienteMenorGravedad);
                    iOcupadosPlanta_++;
                }
            }
            else
            {
                // Insercion en orden de los pacientes, dejando el de menor gravedad al final
                insercionOrdenada(lUCI, Paciente(gravedad, paciente));
                iOcupadosUCI_++;
            }
        }
        else if (gravedad > 5 && gravedad < 9)
        {
            if (llenaPlanta())
            {
                // Si la planta esta llena se le da el alta al paciente de menor graveda, ultima posicion
                lPlanta.eliminar(lPlanta.anterior(lPlanta.fin()));
                insercionOrdenada(lPlanta, Paciente(gravedad, paciente));
            }
            else
            {
                // Insercion en orden de los pacientes, dejando el de menor gravedad al final
                insercionOrdenada(lPlanta, Paciente(gravedad, paciente));
                iOcupadosPlanta_++;
            }
        }
    }
    void muertePaciente(const int &gravedad, const string sPaciente)
    {
        if (gravedad < 1 || gravedad > 9)
            throw invalid_argument("La gravedad no puede ser menor que 1 ni mayor que 9");
        if (gravedad >= 1 && gravedad <= 5)
        {
            auto pos = buscarPaciente(Paciente(gravedad, sPaciente), lUCI);
            if (pos == lUCI.fin())
                throw std::invalid_argument("Ese paciente no existe");

            Paciente pacienteMuerto = lUCI.elemento(pos);
            lUCI.eliminar(pos);
            lMorgue.insertar(pacienteMuerto, lMorgue.fin());
            iOcupadosUCI_--;
        }
        else if (gravedad >= 6 && gravedad <= 9)
        {
            auto pos = buscarPaciente(Paciente(gravedad, sPaciente), lPlanta);
            if (pos == lPlanta.fin())
                throw std::invalid_argument("Ese paciente no existe");

            Paciente pacienteMuerto = lPlanta.elemento(pos);
            lPlanta.eliminar(pos);
            lMorgue.insertar(pacienteMuerto, lMorgue.fin());
            iOcupadosPlanta_--;
        }
    }
    void AltaPaciente(const string &idPaciente)
    {
        auto pos = buscarPaciente(Paciente(0, idPaciente), lPlanta);
        if (pos == lPlanta.fin())
            throw invalid_argument("Ese paciente no existe en planta");
        lPlanta.eliminar(pos);
        iOcupadosPlanta_--;
    }
    void pacientesUCI()
    {
        for (auto i = lUCI.primera(); i != lUCI.fin(); i = lUCI.siguiente(i))
            cout << lUCI.elemento(i).id << ", ";
        cout << endl;
    }
    void pacientesPlanta()
    {
        for (auto i = lPlanta.primera(); i != lPlanta.fin(); i = lPlanta.siguiente(i))
            cout << lPlanta.elemento(i).id << ", ";
        cout << endl;
    }
    void pacientesGravedad(const int &gravedad)
    {
        if (gravedad < 0 || gravedad > 9)
            throw invalid_argument("La gravedad tiene que estar entre 0 y 9");
        if (gravedad == 0)
        {
            for (auto i = lMorgue.primera(); i != lMorgue.fin(); i = lMorgue.siguiente(i))
                cout << lMorgue.elemento(i).id << ", ";
            cout << endl;
        }
        else if (gravedad >= 1 && gravedad <= 5)
        {
            for (auto i = lUCI.primera(); i != lUCI.fin(); i = lUCI.siguiente(i))
                cout << lUCI.elemento(i).id << ", ";
            cout << endl;
        }
        else
        {
            for (auto i = lPlanta.primera(); i != lPlanta.fin(); i = lPlanta.siguiente(i))
                cout << lPlanta.elemento(i).id << ", ";
            cout << endl;
        }
    }
};

int main()
{

    return 0;
}