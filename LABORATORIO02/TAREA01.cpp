#include <iostream>
#include <cmath>

using namespace std;

int FuncionMCDxRecursion(int a, int b)
{
    if (b == 0) return a;
    else
    return FuncionMCDxRecursion(b, a%b);
}
int FuncionMCDxIteracion(int a, int b)
{   
    int c = 0, aux;
    while (b != 0)
    {
        c = a%b;
        aux = b;
        a = aux;
        b = c;
    }
    
    return a;
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    cout<< "PROGRAMA PARA ENCONTRAR EL MCD DE DOS NUMEROS POR MEDIO DEL ALGORITMO DE EUCLIDES"<< endl;
    cout<< "DIGITE DOS ENTEROS"<< endl;
    cin>> n1>> n2;

    cout<< "EL MCD DE AMBOS NUMEROS ES: "<< endl;
    cout<< "Por recursion: "<< FuncionMCDxRecursion(n1, n2)<< endl;
    cout<< "Por iteracion: "<< FuncionMCDxIteracion(n1, n2)<< endl;

    return 0;
}

// Las diferencias entre el algoritmo de Euclides por iteracion y por recursion no es mucha.
// En ambos casos existe un tipo de condicion, en la forma recursiva es el "if" mientras que en la forma recursiva
// es el "while".

//Para reasignar el valor de las variables en la funcion recursiva se invoca la funcion al ver que "b" es distinto de 0,
// pero b toma el lugar de "a" y "a%b" toma el valor de "b". Esto se da hasta que "b" sea igual a 0 y retorne "a", que en este caso es el MCD.

//Para reasignar el valor de las variables en la funcion iterativa, la condicion establecida en el lazo "while" al ver que "b" es distinto de 0,
// repite la operacion "a%b" y reasigna los valores de "a" y "b" hasta que el valor de "b" sea cero. 
//Una vez finalizado el lazo, la funcion devuelve el valor de "a" que es igual al MCD. 