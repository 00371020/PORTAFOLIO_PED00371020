#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class TAREA04EJ2
{
private:
    nodo *pInicio;
public:
    TAREA04EJ2();
    ~TAREA04EJ2();
    void insertarEnLista(void);
    void InsCola(int);
    void mostrarLista(void);
    void Eliminacion(int datoRef);
    bool ElimAux(nodo *p, int datoRef);
};

TAREA04EJ2::TAREA04EJ2()
{
    pInicio = NULL;
}

TAREA04EJ2::~TAREA04EJ2()
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void TAREA04EJ2::insertarEnLista(void)
{
    int numero = 0, otra = 0;

    do
    {
        cout << "Digite un entero" << endl;
        cin >> numero;

        InsCola(numero);

        cout<< endl<< endl<< "Si desea ingresar mas datos presione 1, para terminar presione 0."<< endl;
        cin >> otra;

    } while (otra != 0);
}

void TAREA04EJ2::InsCola(int numero)
{
    nodo *nuevo = new nodo;
    nuevo->dato = numero;
    nuevo->sig = NULL;

    if (!pInicio)
    {   
        pInicio = nuevo;
        pInicio->ant = NULL;
    }
    else
    {
        nodo *s = pInicio;
        while (s->sig)
            s = s->sig;
        s->sig = nuevo;
        nuevo->ant = s;
    }
}

void TAREA04EJ2::mostrarLista(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p->sig){
        cout << p->dato << endl;
        p = p->sig;
    }
    cout << p->dato << endl;
    cout << "Fin de mostrar lista" << endl << endl;
}

void TAREA04EJ2::Eliminacion(int datoRef)
{
    if(ElimAux(pInicio, datoRef))
        cout << "El nodo fue eliminado" << endl << endl;
    else
        cout << "El nodo no fue eliminado" << endl << endl;
}

bool TAREA04EJ2::ElimAux(nodo *p, int datoRef)
{
    nodo *s;

    if (p && (p->sig->dato != datoRef))
        ElimAux(p->sig, datoRef);
    else if (p && (p->sig->dato == datoRef))
    {
        s = p->ant;
        s->sig = p->sig;
        s->sig->ant = p->sig->ant;
        delete p;
        return true;
    }    
    else
        return false;
}

int main()
{
    TAREA04EJ2 obj;
    int opcion = 0, datoRef = 0;

    cout<< "Lista de numeros: " << endl;

    do
    {
        cout << "ELIGA UNA DE LAS SIGUIENTESS OPCIONES AL PRESIONAR EL NUMERO CORRESPONDIENTE" << endl;
        cout << "1. Insertar datos en la lista" << endl;
        cout << "2. Mostrar los numeros de la lista" << endl;
        cout << "3. Borrar el nodo anterior al dato de referencia" << endl;
        cout << "4. Salir" << endl << endl;

        cin >> opcion;

        cout << endl;

        switch (opcion)
        {
        case 1:
            obj.insertarEnLista();
            break;
        case 2:
            obj.mostrarLista();
            break;
        case 3:
            cout << "Digite el elemento de referencia: "; cin >> datoRef;
            obj.Eliminacion(datoRef);
            break;   
        }
    } while (opcion != 4);
    
    return 0;
}
