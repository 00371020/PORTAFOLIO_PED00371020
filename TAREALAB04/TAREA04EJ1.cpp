#include <iostream>
#include <cstring>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

class Lista
{
private:
    nodo *pIn;
public:
    Lista();
    ~Lista();
    void InsertarInicio();
    void InsIni(int);
    void MostrarPares();
    void MostrarImpares();
    void Eliminacion(int num);
    void ElimAux(int num);
};

Lista::Lista()
{
    pIn = NULL;
}

Lista::~Lista()
{
    nodo *p;

    while (pIn)
    {
        p = pIn;
        pIn = p->sig;
        delete p;
    }
}

void Lista::InsertarInicio()
{
    int otra, numero;

    do
    {
        cout << "Digite un entero" << endl;
        cin >> numero;

        InsIni(numero);

        cout<< endl<< endl<< "Si desea ingresar mas datos presione 1, para terminar presione 0."<< endl;
        cin >> otra;

    } while (otra != 0);
}

void Lista::InsIni(int numero)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = numero;
    nuevo->sig = pIn;
    pIn = nuevo;
}

void Lista::MostrarPares()
{
    nodo *p = pIn;

    while (p != NULL)
    {
        if (p->dato % 2 == 0)
        {
            cout << p->dato << endl;
        }
        p = p->sig;
    }    
    cout << endl << endl;
}


void Lista::MostrarImpares()
{
    nodo *p = pIn;

    while (p != NULL)
    {
        if (p->dato % 2 != 0)
        {
            cout << p->dato << endl;
        }
        p = p->sig;
    }    
    cout << endl << endl;
}


void Lista::Eliminacion(int num)
{
    ElimAux(num);
}

void Lista::ElimAux(int num)
{
    if (!pIn)
    {
        cout << "No hay ningun elemento" << endl;
    }
    else
    {
        nodo *p, *s =pIn;
        
        do
        {
            if (s->dato == num)
            {
                pIn = pIn->sig;
                delete s;
            }
            else
            {
                while (s->sig && (s->sig->dato != num))
                {
                s = s->sig;
                }
                if (!s->sig)
                    cout << "No se encontro ningun elemento con ese numero, por lo cual no se puede eliminar" << endl;
                else
                {
                    p = s->sig;
                    s->sig = s->sig->sig;
                    delete p;
                }
            }
        } while (s->sig);
        
        cout << "El / Los elementos han sido eliminados" << endl;

    }
}

int main()
{
    Lista obj;
    int num = 0, opcion = 0, datoRef = 0;

    cout<< "Lista de numeros: " << endl;

    do
    {
        cout << "ELIGA UNA DE LAS SIGUIENTESS OPCIONES AL PRESIONAR EL NUMERO CORRESPONDIENTE" << endl;
        cout << "1. Insertar datos al inicio" << endl;
        cout << "2. Mostrar los numeros pares de la lista" << endl;
        cout << "3. Mostrar los numeros impares de la lista" << endl;
        cout << "4. Borrar nodos, con el mismo dato, de la lista" << endl;
        cout << "5. Salir" << endl << endl;

        cin >> opcion;

        cout << endl;

        switch (opcion)
        {
        case 1:
            obj.InsertarInicio();
            break;
        case 2:
            obj.MostrarPares();
            break;
        case 3:
            obj.MostrarImpares();
            break;       
        case 4:
            cout << "Ingrese el numero del que desea eliminar de la lista" << endl; cin >> num;
            obj.Eliminacion(num);
            break;   
        }
    } while (opcion != 5);
    
    return 0;
}
