#include <iostream>
#include <cstring>

using namespace std;

struct estudiante
{
    string nombre, nivel;
    int horas, carnet;
};

struct nodo
{
    estudiante datosEst;
    nodo *sig;
};

struct ListaDeAsistencia
{
    string nombre, nivel;
    int carnet;
};

struct nodo2
{
    ListaDeAsistencia datosEst1;
    nodo2 * sig;
};

class TAREALAB03
{
private:
    nodo *pIn;
    nodo2 *pCol;
public:
    TAREALAB03(/* args */);
    ~TAREALAB03();
    void InsertarInicio ();
    void InsIni (estudiante);
    void InsertarListaAsis ();
    void InsFinal (ListaDeAsistencia);
    void MostrarPila ();
    void MostrarCola ();
    void MostrarColaAux (nodo2 *p);
    void BuscarNodo (int numeroCar);
    void BuscarNodoAux (nodo *p , int numeroCar);
};

TAREALAB03::TAREALAB03(/* args */)
{
    pIn = NULL;
    pCol = NULL;
}

TAREALAB03::~TAREALAB03()
{
    nodo *p;
    nodo2 *p1;

    while (pIn != NULL)
    {
     p = pIn;
     pIn = p->sig;
     delete p;   
    }

    while (pCol != NULL)
    {
     p1 = pCol;
     pCol = p1->sig;
     delete p1;   
    }
    
}

void TAREALAB03::InsertarInicio ()
{
    estudiante est;
    int MasDatos = 0;

    do
    {
        cout << "Ingrese el nombre completo del estudiante: "; cin >> est.nombre;
        cin.clear(); cin.ignore(1000, '\n'); 
        cout << endl << "Ingrese el numero de carnet del estudiante: "; cin >> est.carnet;
        cout << endl << "Ingrese el nivel de carrera del estudiante: "; cin >> est.nivel;
        cout << endl << "Ingrese las horas sociales realizadas por el estudiante: "; cin >> est.horas;
        
        InsIni (est);
        
        cout<< endl<< endl<< "Si desea ingresar mas datos presione 1, para terminar presione 0."<< endl;
        cin>> MasDatos;
    
    } while (MasDatos != 0);
}

void TAREALAB03::InsIni (estudiante est)
{
    nodo *nuevo = new nodo;
    nuevo->datosEst = est;
    nuevo->sig = pIn;
    pIn = nuevo;
}

void TAREALAB03::InsertarListaAsis ()
{
    ListaDeAsistencia est1;
    int MasDatos = 0;

    cout << "Ingrese los datos de los estudiantes que asistieron a clase presencial" << endl;
    do
    {
        cout << "Ingrese el nombre completo del estudiante: "; cin >> est1.nombre;
        cin.clear(); cin.ignore(1000, '\n');
        cout << endl << "Ingrese el numero de carnet del estudiante: "; cin >> est1.carnet;
        cout << endl << "Ingrese el nivel de carrera del estudiante: "; cin >> est1.nivel;
        
        InsFinal (est1);
        
        cout << endl << endl << "Si desea ingresar mas datos presione 1, para terminar presione 0." << endl;
        cin >> MasDatos;
    
    } while (MasDatos != 0);
}

void TAREALAB03::InsFinal (ListaDeAsistencia est1)
{
    nodo2 *nuevo1 = new nodo2;
    nuevo1->datosEst1 = est1;
    nuevo1->sig = NULL;

    if (pCol == NULL)
    {
        pCol = nuevo1;
    }
    else
    {
        nodo2 *s = pCol;
        while (s->sig)
            s = s->sig;
        s->sig = nuevo1;
        
    }
}

void TAREALAB03::MostrarPila ()
{
    nodo *p;

    cout<< "Los elementos de la lista son:"<< endl << endl;
    p = pIn;

    while (p != NULL)
    {
        cout << "Nombre: " << p->datosEst.nombre << endl;
        cout << "Carnet: " << p->datosEst.carnet << endl;
        cout << "Nivel de carrera : " << p->datosEst.nivel << endl;
        cout << "Horas sociales : " << p->datosEst.horas << endl << endl;

        p = p->sig;
    }
}

void TAREALAB03::MostrarCola ()
{
    TAREALAB03::MostrarColaAux (pCol);
}

void TAREALAB03::MostrarColaAux (nodo2 *p)
{
    if (p)
    {
        cout << "Nombre: " << p->datosEst1.nombre << endl;
        cout << "Carnet: " << p->datosEst1.carnet << endl;
        cout << "Nivel de carrera : " << p->datosEst1.nivel << endl << endl;    
        MostrarColaAux (p->sig);
    }
}

void TAREALAB03::BuscarNodo (int numeroCar)
{
    return BuscarNodoAux (pIn, numeroCar);
}

void TAREALAB03::BuscarNodoAux (nodo *p, int numeroCar)
{
    if (p && (p->datosEst.carnet != numeroCar))
    {
        BuscarNodoAux(p->sig, numeroCar);
    }
    else
    {
        if (p&& (p->datosEst.carnet == numeroCar))
        {
            cout << "Nombre: " << p->datosEst.nombre << endl;
            cout << "Carnet: " << p->datosEst.carnet << endl;
            cout << "Nivel de carrera: " << p->datosEst.nivel << endl;
        }
        else
            cout << "No se encontro ningun resultado, intentelo de nuevo.";
    }
}

int main(void)
{
    int opc, numeroCar;
    TAREALAB03 objMSL;
    cout<< "Lista de numeros: " << endl;

    do
    {
        cout << "ELIGA UNA DE LAS SIGUIENTESS OPCIONES AL PRESIONAR EL NUMERO CORRESPONDIENTE" << endl;
        cout << "1. Insertar datos en el registro de estudiantes (al inicio)" << endl;
        cout << "2. Tomar lista de asistencia" << endl;
        cout << "3. Mostrar Lista (Pila)" << endl;
        cout << "4. Buscar estudiante por numero de carnet en el registro de estudiantes" << endl;
        cout << "5. Mostrar Lista de estudiantes que asistieron a clase presencial (Cola)" << endl;
        cout << "6. Salir" << endl << endl;

        cin >> opc;

        cout << endl;

        switch (opc)
        {
        case 1:
            objMSL.InsertarInicio();
            break;
        case 2:
            objMSL.InsertarListaAsis();
            break;
        case 3:
            objMSL.MostrarPila();
            break;
        case 4:
            cout << "Ingrese el numero de carnet: "; cin >> numeroCar;
            objMSL.BuscarNodo(numeroCar);
            break;
        case 5:
            objMSL.MostrarCola();
            break;
        }
        
    } while (opc != 6);
    
    return 0;
}
